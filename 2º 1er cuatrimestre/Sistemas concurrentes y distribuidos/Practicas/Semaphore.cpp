// *****************************************************************************
//
// Semaphores implementation using C++11 concurrency features.
// (private implementation)
// Copyright (C) 2017  Carlos Ureña Almagro
//
// April, 2017    : created
// Sept, 15, 2017 : removed reference count, now 'std::shared_ptr' is used instead
// July, 15, 2018 : implemented guaranteed FIFO order
// Oct, 11, 2019  : added move constructor and explicitly deleted copy and
//                  assignement constructors, so no semaphore aliases are created and
//                  'shared_ptr' is no longer needed
// Oct, 25, 2019  : solved a bug in the LOGM macro (didn't compile in g++)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// *****************************************************************************

#include <iostream>
#include <string>
#include <cassert>
#include <deque>
#include <mutex>
#include <condition_variable>

#include "Semaphore.h"

// *****************************************************************************

namespace SEM
{

int num_instances = 0 ;
bool log_semaphores = false ;

using namespace std ;

// *****************************************************************************
// representation of semaphores (not public)

class SemaphoreRepr
{
   friend class Semaphore ;

   public:
   // create with an initial unsigned value
   SemaphoreRepr( unsigned init_value ) ;
   SemaphoreRepr( unsigned init_value, const std::string & p_name );
   ~SemaphoreRepr() ;

   private:

   unsigned
      value ,     // current semaphore value
      num_wt ;    // current number of waiting threads
   std::mutex *
      mtx ;       // for mutual exclusion in semaphore updating
   std::deque<condition_variable *>
      cvs_queue ; // FIFO queue with condition_variables
   std::string
      name ;      // name of the semaphore (can used for debugging)

   void     sem_wait();             // wait operation
   bool     sem_signal();           // signal operation (returns true if there was any waiting thread)

} ;

// ******************************************************************************
// debug functions and macro

static bool do_debug_log = false ;

// -----------------------------------------------------------------------------

void set_debug_log( const bool new_do_debug_log )
{
   do_debug_log = new_do_debug_log ;
}
// -----------------------------------------------------------------------------

// std::stringstream operator"" _ss ( const char* str, const unsigned long l )
// {
//    std::stringstream ss ;
//    ss << str ;
//    return ss ;
// }
// // -----------------------------------------------------------------------------
//
// void LogImpl( const std::string & file, const std::string & func, const unsigned line,
//               const std::stringstream & msg_ss )
// {
//    LogImpl( file, func, line, (msg_ss.str()).c_str() );
// }
// -----------------------------------------------------------------------------

void LogImpl( const std::string & file, const std::string & func, const unsigned line,
               const StringBuilder & msg_sb )
{
   if ( do_debug_log )
   {
      using namespace std ;
      cout << file << " (" << line << "), function " << func  << ": " << (msg_sb.get()) << endl << flush ;
   }
}

// void LogImpl2( const std::string & file, const std::string & func, const unsigned line ) //,
//                //const std::stringstream & msg_ss  )
// {
//    LogImpl( file, func, line, "(desconocido)" );
// }

// *****************************************************************************
// implementation of 'Semaphore' interface

Semaphore::Semaphore( unsigned init_value )
{
   LOGM( "begins Semaphore::Semaphore( int == " << init_value << ")" );

   assert( repr == nullptr );
   repr = new SemaphoreRepr( init_value );
   assert( repr != nullptr );

   LOGM( "ends" );
}
// -----------------------------------------------------------------------------

Semaphore::Semaphore( unsigned init_value, const std::string & p_name )
{
   LOGM( "begins Semaphore::Semaphore( int == " << init_value << ")" );

   assert( repr == nullptr );
   repr = new SemaphoreRepr( init_value, p_name );
   assert( repr != nullptr );

   LOGM( "ends" );
}
// -----------------------------------------------------------------------------

Semaphore::Semaphore( Semaphore && sem )
{
  LOGM( "begins Semaphore::Semaphore( Semaphore && sem )" );

  assert( sem.repr != nullptr );
  LOGM( "     sem.value == " << sem.repr->value << ", sem.num_wt == " << sem.repr->num_wt );

  // move the pointer this object
  repr = sem.repr ;
  sem.repr = nullptr ;

  LOGM( "ends" );
}

// -----------------------------------------------------------------------------

Semaphore::~Semaphore()
{
   LOGM( "begins Semaphore::~Semaphore(), repr == " << repr );

   if ( repr != nullptr )
      delete repr ;

   repr = nullptr ; // useful at all ????
   LOGM( "ends"  );
}
// -----------------------------------------------------------------------------

void Semaphore::sem_wait(  )
{
   assert( repr != nullptr );
   repr->sem_wait();
}
// -----------------------------------------------------------------------------

void Semaphore::sem_signal(  )
{
   assert( repr != nullptr );
   repr->sem_signal() ;
}

// -----------------------------------------------------------------------------
// Private access method, just used for debugging

int Semaphore::get_value()
{
   return repr != nullptr ? repr->value : -1 ;
}

// *****************************************************************************
// Implementation of (private) semaphore representation methods

SemaphoreRepr::SemaphoreRepr( unsigned init_value )
{
  LOGM( "begins SemaphoreRepr::SemaphoreRepr( int == " << init_value << ")" );

  mtx    = new std::mutex ;
  value  = init_value ;
  name   = "(semaphore's name not given)" ;
  num_wt = 0 ;

  num_instances ++  ;
  LOGM( "ends" );
}
// -----------------------------------------------------------------------------

SemaphoreRepr::SemaphoreRepr( unsigned init_value, const std::string & p_name )
{
  LOGM( "begins  SemaphoreRepr::SemaphoreRepr( int == " << init_value << ", name = " << p_name << ")" );

  mtx    = new std::mutex ;
  value  = init_value ;
  name   = p_name ;
  num_wt = 0 ;

  num_instances++ ;
  LOGM( "ends" );
}

// -----------------------------------------------------------------------------

void SemaphoreRepr::sem_wait()
{
   assert( mtx != nullptr );

   // gain mutex
   std::unique_lock<std::mutex> lock( *mtx );

   // check queue size is coherent with the registered number of waiting threads
   assert( cvs_queue.size() == num_wt );

   if ( value == 0 )      // if the current value is 0, we must wait
   {
      // register new waiting thread
      num_wt += 1 ;

      // create and insert new cond. var. at the end (back) of cond. vars. queue
      condition_variable * cv_ptr = new condition_variable ;
      assert( cv_ptr != nullptr );
      cvs_queue.push_back( cv_ptr );

      // wait until signaled and value > 0
      while ( value == 0 )
         cv_ptr->wait( lock ); // release mutex when waiting, re-gain after

      // as this thread was waiting in the beginning (front) node, remove that node and free cv. memory
      assert( cvs_queue.size() == num_wt ) ; assert( cv_ptr != nullptr ) ;
      cv_ptr = cvs_queue.front();
      cvs_queue.pop_front();
      delete cv_ptr;

      // register the thread is no longer waiting
      num_wt -= 1 ;
   }

   // decrease value
   assert( 0 < value );
   value -= 1 ;

   // release mutex (implicit)
}
// -----------------------------------------------------------------------------

bool SemaphoreRepr::sem_signal()
{
  assert( mtx != nullptr );

  // gain mutex
  std::unique_lock<std::mutex> lock( *mtx );

  // check queue size is coherent with the registered number of waiting threads
  assert( cvs_queue.size() == num_wt );

  // increase value
  value += 1 ;

  // signal one waiting thread, if any
  if ( 0 < num_wt )
  {
      assert( cvs_queue.size() > 0 ); // cond. vars. queue must be non-empty
      condition_variable * cv_ptr = cvs_queue.front() ; // get cond.var. at the first queue node
      assert( cv_ptr != nullptr );
      cv_ptr->notify_one() ; // wake up the thread waiting in that cond.var.
                             // that thread will release memory used by the cond.var. and remove the front node
      return true ;
  }
  return false ;

}
// -----------------------------------------------------------------------------

SemaphoreRepr::~SemaphoreRepr()
{
  using namespace std ;
  //cout << "begins ~SemaphoreRepr( value == " << value << ") ...." << endl << flush ;
  assert( mtx != nullptr );

  delete mtx ;
  mtx = nullptr ;
  num_instances -- ;
  //cout << "ends" << endl ;
}

} // end namespace SCD
