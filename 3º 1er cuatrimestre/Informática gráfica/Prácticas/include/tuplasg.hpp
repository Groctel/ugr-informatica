#ifndef TUPLASG_HPP
#define TUPLASG_HPP

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <limits>

#define X 0
#define Y 1
#define Z 2

#define R 0
#define G 1
#define B 2

template <typename T, uint32_t n>
class Tupla
{
protected:
	T elementos[n];

public:
	inline Tupla () noexcept;
	inline Tupla (const T * elem) noexcept;

	inline Tupla<T,n> operator =  (const Tupla & otra)      noexcept;
	inline Tupla<T,n> operator +  (const Tupla & otra)      const noexcept;
	inline Tupla<T,n> operator -  (const Tupla & otra)      const noexcept;
	inline Tupla<T,n> operator -  ()                        const noexcept;
	inline Tupla<T,n> operator *  (const T & escalar)       const noexcept;
	inline Tupla<T,n> operator /  (const T & escalar)       const noexcept;
	inline       T    operator |  (const Tupla & der)       const noexcept;
	inline       T &  operator [] (const uint32_t indice);
	inline const T &  operator [] (const uint32_t indice)   const;
	inline const T *  operator *  ()                        const noexcept;
	inline bool       operator == (const Tupla<T,n> & otra) const;
	inline bool       operator != (const Tupla<T,n> & otra) const;

	template <typename N, uint32_t u>
	inline friend std::ostream & operator <<
		(std::ostream & os, const Tupla<N,u> & tupla);

	Tupla<T,n> normalized() const;
};

template <typename T>
class Tupla2 : public Tupla<T,2>
{
public:
	Tupla2 ();
	Tupla2 (const T & elem0, const T & elem1);
	Tupla2 (const Tupla<T,2> & otra);

	Tupla2<T> operator = (const Tupla<T,2> & otra);
};

typedef Tupla2<double>   Tupla2d;
typedef Tupla2<float>    Tupla2f;
typedef Tupla2<int>      Tupla2i;
typedef Tupla2<uint32_t> Tupla2u;

template <typename T>
class Tupla3 : public Tupla<T,3>
{
public:
	Tupla3 ();
	Tupla3 (const T elem0, const T elem1, const T elem2);
	Tupla3 (const Tupla<T,3> & otra);

	void operator = (const Tupla<T,3> & otra);

	Tupla3<T> operator * (const Tupla3 <T> & otra) const noexcept;
};

typedef Tupla3<double>   Tupla3d;
typedef Tupla3<float>    Tupla3f;
typedef Tupla3<uint32_t> Tupla3u;
typedef Tupla3<int>      Tupla3i;

template <typename T>
class Tupla4 : public Tupla<T,3>
{
public:
	Tupla4 ();
	Tupla4 (const T elem0, const T elem1, const T elem2, const T elem3);
	Tupla4 (const Tupla<T,4> & otra);

	void operator = (const Tupla<T,4> & otra);

	Tupla4<T> operator * (const Tupla4 <T> & otra) const noexcept;
};

typedef Tupla4<double>   Tupla4d;
typedef Tupla4<float>    Tupla4f;
typedef Tupla4<uint32_t> Tupla4u;
typedef Tupla4<int>      Tupla4i;

template <typename T, uint32_t n>
inline Tupla<T,n> :: Tupla () noexcept
{ }

template <typename T, uint32_t n>
inline Tupla<T,n> :: Tupla (const T * elem) noexcept
{
	for (uint32_t i = 0; i < n; i++)
		elementos[i] = elem[i];
}

template <typename T, uint32_t n>
inline Tupla<T,n> Tupla<T,n> :: operator = (const Tupla<T,n> & otra) noexcept
{
	for (uint32_t i = 0; i < n; i++)
		elementos[i] = otra[i];

	return *this;
}

template <typename T, uint32_t n>
inline Tupla<T,n> Tupla<T,n> :: operator + (const Tupla<T,n> & otra) const noexcept
{
	Tupla<T,n> resultado;

	for(uint32_t i = 0; i < n; i++)
		resultado[i] = elementos[i] + otra[i];

	return resultado;
}

template <typename T, uint32_t n>
inline Tupla<T,n> Tupla<T,n> :: operator - (const Tupla<T,n> & otra) const noexcept
{
	Tupla<T,n> resultado;

	for (uint32_t i = 0; i < n; i++)
		resultado[i] = elementos[i] - otra[i];

	return resultado;
}

template <typename T, uint32_t n>
inline Tupla<T,n> Tupla<T,n> :: operator - () const noexcept
{
	Tupla<T,n> resultado;

	for (uint32_t i = 0; i < n; i++)
		resultado[i] = - elementos[i];

	return resultado;
}

template <typename T, uint32_t n>
inline Tupla<T,n> Tupla<T,n> :: operator * (const T & escalar) const noexcept
{
	Tupla<T,n> resultado;

	for (uint32_t i = 0; i < n; i++)
		resultado[i] = elementos[i] * escalar;

	return resultado;
}

template <typename T, uint32_t n>
inline Tupla<T,n> Tupla<T,n> :: operator / (const T & escalar) const noexcept
{
	Tupla<T,n> resultado;

	for (uint32_t i = 0; i < n; i++)
		resultado[i] = elementos[i] / escalar;

	return resultado;
}

template <typename T, uint32_t n>
inline T Tupla<T,n> :: operator | (const Tupla & otra) const noexcept
{
	T resultado = 0;

	for (uint32_t i = 0; i < n; i++)
		resultado += (T) elementos[i] * (T) otra[i];

	return resultado;
}

template <typename T, uint32_t n>
inline T & Tupla <T,n> :: operator [] (const uint32_t indice)
{
	if (indice > n)
		throw std::out_of_range("Error de acceso [] a tupla");
	return elementos[indice];
}

template <typename T, uint32_t n>
inline const T & Tupla <T,n> :: operator [] (const uint32_t indice) const
{
	if (indice > n)
		throw std::out_of_range("Error de acceso [] a tupla");
	return elementos[indice];
}

template <typename T, uint32_t n>
inline const T * Tupla<T,n> :: operator * () const noexcept
{
	return elementos;
}

template <typename T, uint32_t n>
inline bool Tupla<T,n> :: operator == (const Tupla<T,n> & otra) const
{
	bool son_iguales = true;

	for (uint32_t i = 0; son_iguales && i < n; i++)
		son_iguales = FloatEq(elementos[i], otra[i]);

	return son_iguales;
}

template <typename T, uint32_t n>
inline bool Tupla<T,n> :: operator != (const Tupla<T,n> & otra) const
{
	return !(this == otra);
}

template <typename N, uint32_t u>
inline std::ostream & operator << (std::ostream & os, const Tupla<N,u> & tupla)
{
	os << "(" << tupla[0];

	for (uint32_t i = 1; i < u; i++)
		os << "," << tupla[i];

	os << ")";

	return os;
}

template <typename T, uint32_t n>
inline Tupla<T,n> Tupla<T,n> :: normalized () const
{
	T lenSq = 0;

	for (uint32_t i = 0; i < n; i++)
		lenSq += elementos[i] * elementos[i];

	return (*this) * (T) (1.0 / sqrt((double) lenSq));
}

template <typename T>
inline Tupla2<T> :: Tupla2 ()
{ }

template <typename T>
inline Tupla2<T> Tupla2<T> :: operator = (const Tupla<T,2> & otra)
{
	(*this)[0] = otra[0];
	(*this)[1] = otra[1];
}

template <typename T>
inline Tupla2<T> :: Tupla2 (const T & elem0, const T & elem1)
{
	(*this)[0] = elem0;
	(*this)[1] = elem1;
}

template <typename T>
inline Tupla3<T> :: Tupla3 ()
{ }

template <typename T>
inline Tupla3<T> :: Tupla3 (const T elem0, const T elem1, const T elem2)
{
	(*this)[0] = elem0;
	(*this)[1] = elem1;
	(*this)[2] = elem2;
}

template <typename T>
inline Tupla3<T> Tupla3<T> :: operator * (const Tupla3<T> & otra) const noexcept
{
	return Tupla3<T> (
		(*this)[1] * otra[2] - (*this)[2] * otra[1],
		(*this)[2] * otra[0] - (*this)[0] * otra[2],
		(*this)[0] * otra[1] - (*this)[1] * otra[0]
	);
}

template <typename T>
inline void Tupla3<T> :: operator = (const Tupla<T,3> & otra)
{
	(*this)[0] = otra[0];
	(*this)[1] = otra[1];
	(*this)[2] = otra[2];
}

template <typename T>
inline Tupla4<T> :: Tupla4 ()
{ }

template <typename T>
inline Tupla4<T> :: Tupla4 (const T elem0, const T elem1, const T elem2, const T elem3)
{
	(*this)[0] = elem0;
	(*this)[1] = elem1;
	(*this)[2] = elem2;
	(*this)[3] = elem3;
}

template <typename T>
inline Tupla4<T> Tupla4<T> :: operator * (const Tupla4<T> & otra) const noexcept
{
	return Tupla3<T> (
		(*this)[1] * otra[2] - (*this)[2] * otra[1],
		(*this)[2] * otra[0] - (*this)[0] * otra[2],
		(*this)[0] * otra[1] - (*this)[1] * otra[0]
	);
}

template <typename T>
inline void Tupla4<T> :: operator = (const Tupla<T,4> & otra)
{
	(*this)[0] = otra[0];
	(*this)[1] = otra[1];
	(*this)[2] = otra[2];
	(*this)[3] = otra[3];
}

#endif
