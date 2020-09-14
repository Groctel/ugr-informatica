#include <map>
#include <iostream>
#include <string>

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H

/**
 * @ file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

/**
  *  @brief T.D.A. GuiaTlf
  *
  * Una instancia @e c del tipo de datos abstracto @c GuiaTlf es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por la el primer elemento del par denominado clave o key. No existen
  * elementos repetidos.
  *
  *
  * Un ejemplo de su uso:
  *
  *
  * @author Rosa Rodríguez
  * @date Marzo 2012
  */

class GuiaTlf {
private:
	std::map<std::string,std::string> datos;
public:
	std::string & operator [] (const std::string & nombre);
	std::string get_tlf (const std::string & nombre);
	std::pair<std::map<std::string,std::string>::iterator,bool>
	     insert (std::string nombre, std::string tlf);
	std::pair<std::map<std::string,std::string>::iterator,bool>
	     insert (std::pair<std::string,std::string> p);
	void borrar (const std::string & nombre);
	void borrar (const std::string & nombre, const std::string & tlf);
	int size () const;
	unsigned contabiliza (const std::string & nombre);
	void clear ();
	GuiaTlf operator + (const GuiaTlf & g);
	GuiaTlf operator - (const GuiaTlf & g);
	GuiaTlf previos (const std::string & nombre, const std::string & tlf);
	friend std::ostream & operator << (std::ostream & os, GuiaTlf & g);
	friend std::istream & operator >> (std::istream & is, GuiaTlf & g);

	class iterator {
	private:
		std::map<std::string,std::string>::iterator it;
	public:
		std::map<std::string,std::string>::iterator & operator ++ ();
		std::map<std::string,std::string>::iterator & operator -- ();
		std::pair<const std::string,std::string> & operator * ();
		bool operator == (const iterator & i);
		bool operator != (const iterator & i);
		friend class GuiaTlf;
	};

	iterator begin ();
	iterator end ();
};

#endif

