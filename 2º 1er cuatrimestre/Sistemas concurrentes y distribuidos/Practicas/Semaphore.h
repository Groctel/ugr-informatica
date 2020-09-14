// *****************************************************************************
//
// Semaphores implementation using C++11 concurrency features.
// (public interface declarations)
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

#ifndef SEMAPHORES_HPP
#define SEMAPHORES_HPP

#include <iostream>
#include <sstream>
#include <string>

namespace SEM
{

// incomplete declaration of the implementation class
class SemaphoreRepr ;

// *****************************************************************************
// Classic semaphore objects
// it is a reference to a Semaphore implementation object

class Semaphore
{
   public:

   // initialization
   Semaphore( unsigned init_value );
   Semaphore( unsigned init_value, const std::string & p_name );

   // explicitly dissallow default constructor
   Semaphore() = delete ;

   // dissallow copy constructor and assignements
   // (cannot 'copy' the state from another existing semaphore,
   //  which may have been already used by threads)
   // this forbids creating semaphores aliases
   Semaphore( const Semaphore & sem ) = delete ;
   void operator = (Semaphore & sem ) = delete ;

   // Move constructor:
   // allows to copy state from a semaphore which is not in use
   // this allows:
   //      Semaphore sem = Semaphore(0) ;
   //      sem_vector.push_back( Semaphore(46) );
   Semaphore( Semaphore && sem ) ;

   // delete...
   ~Semaphore() ;

   // operations (member methods)
   void     sem_wait();
   void     sem_signal() ;

   // operations (non member functions)
   friend inline void sem_wait  ( Semaphore & s ) { s.sem_wait()  ; }
   friend inline void sem_signal( Semaphore & s ) { s.sem_signal(); }

   private:
   SemaphoreRepr * repr = nullptr; // pointer to semaphore implementation

   // debug methods:
   inline void * get_ptr_repr() { return repr; }
   int get_value() ;

   // function which can access the private methods
   friend void test_semaforos();

} ; // end class Semaphore

// ***************************************************************************************
// debug log related functions and macro


//--------
// class 'StringBuilder' from:
// https://stackoverflow.com/questions/19665458/use-an-anonymous-stringstream-to-construct-a-string

class StringBuilder
{
   public:
      template <typename T> inline StringBuilder& operator<<(const T& t)
      {
         mStream << t;
         return * this;
      }
      inline std::string get()       const { return mStream.str(); }
      inline operator std::string () const { return get(); }

   private:
      std::stringstream mStream;
};


void set_debug_log( const bool new_do_debug_log );


void LogImpl( const std::string & file, const std::string & func, const unsigned line,
              const StringBuilder & msg_sb );

#define LOGM( m )  LogImpl( __FILE__, __FUNCTION__, __LINE__, (StringBuilder() << m))

// total number of semaphores instances (for debug)
extern int num_instances  ;

// ***************************************************************************************

}      // end namespace SEM


#endif // ifndef SEMAPHORES_HPP
