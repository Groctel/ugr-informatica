#ifndef TUPLASG_HPP
#define TUPLASG_HPP

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <limits>

namespace tuplas {
const unsigned
	X = 0,
	Y = 1,
	Z = 2,

	R = 0,
	G = 1,
	B = 2;

const float f  = 0;
const double d = 0;

template <class T, unsigned n>
class Tupla {
protected:
	T elementos[n];

public:
	inline Tupla ();
	inline Tupla (const T * elem);

	inline T & operator [] (const unsigned indice);
	inline T & operator () (const unsigned indice);
	inline const T & operator () (const unsigned indice) const;

	inline operator T * () noexcept;
	inline operator const T * () const noexcept;

	inline Tupla<T,n> operator + (const Tupla & otra) const noexcept;
	inline Tupla<T,n> operator - (const Tupla & otra) const noexcept;
	inline Tupla<T,n> operator - () const noexcept;
	inline Tupla<T,n> operator * (const Tupla & otra) const noexcept;
	inline Tupla<T,n> operator * (const T & escalar) const noexcept;
	inline Tupla<T,n> operator / (const T & escalar) const noexcept;

	template <class C, unsigned u>
	inline bool operator == (const Tupla<C,u> & otra) const;
	template <class C, unsigned u>
	inline bool operator != (const Tupla<C,u> & otra) const;

	template <class C, unsigned u>
	inline friend Tupla<C,u> operator * (const C & escalar, const Tupla<C,u> & tupla);
	template <class C, unsigned u>
	inline friend std::ostream & operator << (std::ostream & os, const Tupla<C,u> & tupla);

	T operator | (const Tupla & der) const;
	T lengthSq() const ;
	Tupla<T,n> normalized() const;
};

template <class T>
class Tupla2 : public Tupla<T,2> {
public:
	Tupla2 ();
	Tupla2 (const T & elem0, const T & elem1);
	Tupla2 (const Tupla<T,2> & otra);

	Tupla2<T> operator = (const Tupla<T,2> & otra);
};

typedef Tupla2<double>   Tupla2d;
typedef Tupla2<float>    Tupla2f;
typedef Tupla2<int>      Tupla2i;
typedef Tupla2<unsigned> Tupla2u;

template <class T>
class Tupla3 : public Tupla<T,3> {
public:
	Tupla3 ();
	Tupla3 (const T & elem0, const T & elem1, const T & elem2);
	Tupla3 (const Tupla<T,3> & otra);

	void operator = (const Tupla<T,3> & otra);
	void operator = (const Tupla<T,4> & otra);

	Tupla3<T> ProductoCartesiano (const Tupla3 <T> & otra) const;
};

typedef Tupla3<double>   Tupla3d;
typedef Tupla3<float>    Tupla3f;
typedef Tupla3<unsigned> Tupla3u;
typedef Tupla3<int>      Tupla3i;

template <class T>
class Tupla4 : public Tupla<T,4> {
public:
	Tupla4 ();
	Tupla4 (const T & elem0, const T & elem1, const T & elem2, const T & elem3);
	Tupla4 (const Tupla<T,4> & otra);

	void operator = (const Tupla<T,4> & otra);
};

typedef Tupla4<double>   Tupla4d;
typedef Tupla4<float>    Tupla4f;
typedef Tupla4<int>      Tupla4i;
typedef Tupla4<unsigned> Tupla4u;

template <class T, unsigned n>
inline Tupla<T,n> :: Tupla ()
{ }

template <class T, unsigned n>
inline Tupla<T,n> :: Tupla (const T * elem)
{
	for (unsigned i = 0; i < n; i++)
		elementos[i] = elem[i];
}


template <class T, unsigned n>
inline T & Tupla <T,n> :: operator [] (const unsigned indice)
{
	if (indice > n)
		throw std::out_of_range("Error de acceso [] a tupla");
	return elementos[indice];
}

template <class T, unsigned n>
inline const T & Tupla<T,n> :: operator () (const unsigned indice) const
{
	if (indice > n)
		throw std::out_of_range("Error de acceso () a tupla");
	return elementos[indice];
}

template <class T, unsigned n>
inline T & Tupla<T,n> :: operator () (const unsigned indice)
{
	if (indice > n)
		throw std::out_of_range("Error de acceso () constante a tupla");
	return elementos[indice];
}

template <class T, unsigned n>
inline Tupla<T,n> :: operator  T * () noexcept
{
	return elementos;
}

template <class T, unsigned n>
inline Tupla<T,n> :: operator const T * () const noexcept
{
	return elementos;
}

template <class T, unsigned n>
inline Tupla<T,n> Tupla<T,n> :: operator + (const Tupla<T,n> & otra) const noexcept
{
	Tupla<T,n> resultado;

	for(unsigned i = 0; i < n; i++)
		resultado[i] = this(i) + otra(i);

	return resultado;
}

template <class T, unsigned n>
inline Tupla<T,n> Tupla<T,n> :: operator - (const Tupla<T,n> & otra) const noexcept
{
	Tupla<T,n> resultado;

	for (unsigned i = 0; i < n; i++)
		resultado[i] = this(i) - otra(i);

	return resultado;
}

template <class T, unsigned n>
inline Tupla<T,n> Tupla<T,n> :: operator - () const noexcept
{
	Tupla<T,n> resultado;

	for (unsigned i = 0; i < n; i++)
		resultado[i] = -this(i);

	return resultado;
}

template <class T, unsigned n>
inline Tupla<T,n> Tupla<T,n> :: operator * (const T & escalar) const noexcept
{
	Tupla<T,n> resultado;

	for (unsigned i = 0; i < n; i++)
		resultado[i] = this(i) * escalar;

	return resultado;
}

template <class T, unsigned n>
inline Tupla<T,n> Tupla<T,n> :: operator / (const T & escalar) const noexcept
{
	Tupla<T,n> resultado;

	for( unsigned i = 0; i < n; i++)
		resultado[i] = this(i) / escalar;

	return resultado;
}

template <class T, unsigned n> template <class C, unsigned u>
inline bool Tupla<T,n> :: operator == (const Tupla<C,u> & otra) const
{
	bool son_iguales = typeid(T) == typeid(C);

	for (unsigned i = 0; son_iguales && i < n; i++) {
			son_iguales = std::fabs((*this)(i) - otra(i))
				< std::numeric_limits<double>::epsilon();
	}

	return son_iguales;
}

template <class T, unsigned n> template <class C, unsigned u>
inline bool Tupla<T,n> :: operator != (const Tupla<C,u> & otra) const
{
	return !(this == otra);
}

template <class C, unsigned u>
inline Tupla<C,u> operator * (const C & escalar, const Tupla<C,u> & tupla)
{
	Tupla<C,u> resultado;

	for (unsigned i = 0; i < u; i++)
		resultado[i] = escalar * tupla(i);

	return resultado;
}

template <class C, unsigned u>
inline std::ostream & operator << (std::ostream & os, const Tupla<C,u> & tupla)
{
	os << "(" << tupla(0);
	for (unsigned i = 1; i < u; i++)
		os << "," << tupla(i);
	os << ")";

	return os;
}

template< class T, unsigned n > inline
T Tupla<T,n>::lengthSq( ) const
{
   return T( this->dot( *this ) ) ;
}

//----------------------------------------------------------------------
// operador binario para producto escalar

template< class T, unsigned n > inline
T Tupla<T,n>::operator | ( const Tupla & der ) const
{
   return this->dot( der ) ;
}

// ---------------------------------------------------------------------

template< class T, unsigned n > inline
Tupla<T,n> Tupla<T,n>::normalized() const
{
   T lenSq = T(0.0) ;
   for( unsigned i = 0 ; i < n ; i++ )
      lenSq += (*this)(i) * (*this)(i) ;

   if ( ! ( lenSq > 0.0 ) )
   {  using namespace std ;
      cout << "lenSq == " << lenSq << endl << flush ;
   }

   assert( lenSq > 0.0 ) ;

   return (*this)*(T(1.0/sqrt(double(lenSq)))) ;

}

// *********************************************************************
//
// plantilla de clase:
//
//   Tupla2<T>
//
// *********************************************************************


template< class T > inline
Tupla2<T>::Tupla2(  )
{

}

// ---------------------------------------------------------------------

template< class T > inline
Tupla2<T>::Tupla2( const Tupla<T,2> & ini )
{
   (*this)[0] = ini(0) ;
   (*this)[1] = ini(1) ;
}

// ---------------------------------------------------------------------

template< class T > inline
Tupla2<T> Tupla2<T>::operator = ( const Tupla<T,2> & otra)
{
   (*this)[0] = otra(0) ;
   (*this)[1] = otra(1) ;
}

// ---------------------------------------------------------------------

template< class T > inline
Tupla2<T>::Tupla2( const T & c0, const T & c1 )
{
   (*this)[0] = c0 ;
   (*this)[1] = c1 ;
}

// *********************************************************************
//
// plantilla de clase:
// Tupla3<T>
//
// *********************************************************************


template< class T > inline
Tupla3<T>::Tupla3(  )
{

}

// ---------------------------------------------------------------------

template< class T > inline
Tupla3<T>::Tupla3( const Tupla<T,3> & ini )
{
   (*this)[0] = ini(0) ;
   (*this)[1] = ini(1) ;
   (*this)[2] = ini(2) ;
}

// ---------------------------------------------------------------------

template< class T > inline
void Tupla3<T>::operator = ( const Tupla<T,3> & der )
{
   (*this)[0] = der(0) ;
   (*this)[1] = der(1) ;
   (*this)[2] = der(2) ;
}

// ---------------------------------------------------------------------

template< class T > inline
void Tupla3<T>::operator = ( const Tupla<T,4> & der )
{
   (*this)[0] = der(0) ;
   (*this)[1] = der(1) ;
   (*this)[2] = der(2) ;
}

// ---------------------------------------------------------------------

template< class T > inline
Tupla3<T>::Tupla3( const T & c0, const T & c1, const T & c2 )
{
   (*this)[0] = c0 ;
   (*this)[1] = c1 ;
   (*this)[2] = c2 ;
}

// ---------------------------------------------------------------------


template< class T > inline
Tupla3<T> Tupla3<T>::ProductoCartesiano( const Tupla3<T> & v2 ) const
{
   // cuidado: no hay acceso a 'elementos' tal cual, mirar:
   // http://stackoverflow.com/questions/7281072/accessing-public-members-of-base-class-fails

   return Tupla3<T>(  (*this)(1)*v2(2) -  (*this)(2)*v2(1),
                       (*this)(2)*v2(0) -  (*this)(0)*v2(2),
                       (*this)(0)*v2(1) -  (*this)(1)*v2(0)
                     );
}

template <class T>
inline Tupla4<T> :: Tupla4 ()
{ }

template <class T>
inline Tupla4<T> :: Tupla4 (const Tupla<T,4> & otra)
{
	*this = otra;
}

// ---------------------------------------------------------------------

template <class T>
inline void Tupla4<T> :: operator = (const Tupla<T,4> & otra)
{
	(*this)[0] = otra(0);
	(*this)[1] = otra(1);
	(*this)[2] = otra(2);
	(*this)[3] = otra(3);
}

// ---------------------------------------------------------------------

template <class T> inline
Tupla4<T> :: Tupla4 (const T & c0, const T & c1, const T & c2, const T & c3 )
{
	(*this)[0] = c0;
	(*this)[1] = c1;
	(*this)[2] = c2;
	(*this)[3] = c3;
}
template< class T, unsigned n >
inline Tupla<T,n> operator *  ( const T & a, const  Tupla<T,n> & der ) ;

template< class T, unsigned n >
inline std::ostream & operator <<  ( std::ostream & os, const Tupla<T,n> & der ) ;

} // namespace tuplas

#endif
