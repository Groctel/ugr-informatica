#include <map>
#include <iostream>
#include <string>
#include "guiatlf.hpp"

std::istream & operator >> (std::istream & is,
                            std::pair<std::string,std::string> & d) {
	getline(is, d.first, '\t');
	getline(is, d.second);

	return is;
}

std::ostream & operator << (std::ostream & os,
                            const std::pair<const std::string,
                                                  std::string> & d) {
	os << d.first  << '\t'
      << d.second << std::endl;

	return os;
}

std::string & GuiaTlf :: operator [] (const std::string & nombre) {
	return datos[nombre];
}

std::string GuiaTlf :: get_tlf (const std::string & nombre) {
	std::map<std::string,std::string>::iterator it = datos.find(nombre);
	std::string resultado = "";

	if (it != datos.end())
		resultado = (*it).second;

	return resultado;
}

std::pair<std::map<std::string,std::string>::iterator,bool>
     GuiaTlf :: insert (std::string nombre, std::string tlf) {
	std::pair<std::string,std::string> contacto (nombre,tlf);

	return insert(contacto);
}

/** @brief Insert un nuevo telefono
  *
  * @param p: pair con el nombre y el telefono asociado
  * @return : un pair donde first apunta al nuevo elemento insertado y bool es
  * true si se ha insertado el nuevo tlf o false en caso contrario
  */

std::pair<std::map<std::string,std::string>::iterator,bool>
     GuiaTlf :: insert (std::pair<std::string,std::string> contacto) {
	std::pair<std::map<std::string,std::string>::iterator,bool> ret;

	ret = datos.insert(contacto);
	return ret;
}

/** @brief Borrar un telefono
  *
  * @param nombre: nombre que se quiere borrar
  * @note: en caso de que fuese un multimap borraria todos con ese nombre
  */

void GuiaTlf :: borrar (const std::string & nombre) {
	std::map<std::string,std::string>::iterator low = datos.lower_bound(nombre);
	std::map<std::string,std::string>::iterator up  = datos.upper_bound(nombre);

	datos.erase(low, up);
}

/** @brief Borrar un telefono
  *
  * @param nombre: nombre que se quiere borrar y telefono asociado
  * @note: esta funcion nos permite borrar solamente aquel que coincida en
  * nombre y tlf
  */

void GuiaTlf :: borrar (const std::string & nombre, const std::string & tlf) {
	std::map<std::string,std::string>::iterator low = datos.lower_bound(nombre);
	std::map<std::string,std::string>::iterator up  = datos.upper_bound(nombre);
	std::map<std::string,std::string>::iterator it;
	bool salir =false;

	for (it=low; it!=up && !salir; ++it) {
		if ((*it).second == tlf) {
			datos.erase(it);
			salir =true;
		}
	}
}

/** @brief Número de telefonos
  * @return el numero de telefonos asociados
  */

int GuiaTlf :: size () const {
	return datos.size();
}

/** @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
  * @param nombre: nombre sobre el que queremos consultar
  * @return numero de telefonos asociados a un nombre
  */

unsigned GuiaTlf :: contabiliza (const std::string & nombre) {
	return datos.count(nombre);
}

/** @brief Limpia la guia
  */

void GuiaTlf :: clear () {
	datos.clear();
}

/** @brief Union de guias de telefonos
  *
  * @param g: guia que se une
  * @return: una nueva guia resultado de unir el objeto al que apunta this y
  * guia
  */

GuiaTlf GuiaTlf :: operator + (const GuiaTlf & guia) {
	std::map<std::string,std::string>::const_iterator it;
	GuiaTlf aux(*this);

	for (it=guia.datos.begin(); it!=guia.datos.end(); ++it)
		aux.insert((*it).first,(*it).second);

	return aux;
}

/** @brief Diferencia de guias de telefonos
  *
  * @param g: guia a restar
  * @return: una nueva guia resultado de la diferencia del objeto al que apunta
  * this y guia
  */

GuiaTlf GuiaTlf :: operator - (const GuiaTlf & guia) {
	std::map<std::string,std::string>::const_iterator it;
	GuiaTlf aux(*this);

	for (it=guia.datos.begin(); it!=guia.datos.end(); ++it)
		aux.borrar((*it).first,(*it).second);

	return aux;
}

/** @brief  Obtiene una guia con los nombre previos a uno dado
  *
  * @param nombre: nombre delimitador
  * @param tlf: telefono asociado a nombre
  *
  * @return nueva guia sin nombres mayores que \a  nombre
  */

GuiaTlf GuiaTlf :: previos (const std::string & nombre,
                            const std::string & tlf)    {
	std::map<std::string,std::string>::value_compare vc = datos.value_comp();
	std::map<std::string,std::string>::iterator it = datos.begin();
	std::pair<std::string,std::string> contacto (nombre, tlf);
	GuiaTlf aux;

	while (vc(*it,contacto))
		aux.insert(*it++);

	return aux;
}

/** @brief Escritura de la guia de telefonos
  *
  * @param os: flujo de salida. Es MODIFICADO
  * @param g: guia de telefonos que se escribe
  *
  * @return el flujo de salida
  */

std::ostream & operator << (std::ostream & os, GuiaTlf & guia) {
	std::map<std::string,std::string>::iterator it;

	for (it=guia.datos.begin(); it!=guia.datos.end(); ++it)
		os << (*it).first  << "\t"
		   << (*it).second << std::endl;

	return os;
}

/** @brief Lectura de  la guia de telefonos
  *
  * @param is: flujo de entrada. ES MODIFICADO
  * @param g: guia de telefonos. ES MODIFICADO
  *
  * @return el flujo de entrada
  */

std::istream & operator >> (std::istream & is, GuiaTlf & guia) {
	std::pair<std::string,std::string> contacto;
	GuiaTlf aux;

	while (is >> contacto)
		aux.insert(contacto);

	guia = aux;

	return is;
}

std::map<std::string,std::string>::iterator & GuiaTlf :: iterator :: operator ++ () {
	return ++it;
}

std::map<std::string,std::string>::iterator & GuiaTlf :: iterator :: operator -- () {
	return --it;
}

std::pair<const std::string, std::string> & GuiaTlf :: iterator ::
                                                       operator * () {
	return *it;
}

bool GuiaTlf :: iterator :: operator == (const iterator & i) {
	return i.it == it;
}

bool GuiaTlf :: iterator :: operator != (const iterator & i) {
	return i.it != it;
}

/** @brief Inicializa un iterator al comienzo de la guia
  */

GuiaTlf::iterator GuiaTlf :: begin () {
	iterator i;

	i.it = datos.begin();

	return i;
}

/** @brief Inicializa un iterator al final de la guia
  */

GuiaTlf::iterator GuiaTlf :: end () {
	iterator i;

	i.it=datos.end();

	return i;
}
