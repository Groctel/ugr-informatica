template <class KEY, class DEF>
void Diccionario<KEY,DEF> :: Copiar (const Diccionario<KEY,DEF> & otro) {
	typename std::list<Termino<KEY,DEF> >::iterator it=datos.begin();
	typename std::list<Termino<KEY,DEF> >::const_iterator it_otro;

	datos.assign(otro.datos.begin(), otro.datos.end());

	for (it_otro=otro.datos.begin(); it_otro!=otro.datos.end();++it_otro,++it)
		datos.insert(it,*it_otro);
}

template <class KEY, class DEF>
void Diccionario<KEY,DEF> :: Borrar () {
	datos.erase(datos.begin(),datos.end());
}

template <class KEY, class DEF>
Diccionario<KEY,DEF> :: Diccionario ()
	:datos (std::list<Termino<KEY,DEF> >())
{ }

template <class KEY, class DEF>
Diccionario<KEY,DEF> :: Diccionario (const Diccionario & otro) {
	Copiar(otro);
}

template <class KEY, class DEF>
Diccionario<KEY,DEF> :: ~Diccionario () { }

template <class KEY, class DEF>
Diccionario<KEY,DEF> & Diccionario<KEY,DEF> :: operator =
                                          (const Diccionario<KEY,DEF> & otro) {
	if (this != &otro) {
		Borrar();
		Copiar(otro);
	}

	return *this;
}

template <class KEY, class DEF>
bool Diccionario<KEY,DEF> :: definida (const KEY & palabra,
                                       typename std::list<Termino<KEY,DEF> >
                                                   ::iterator & it) {
	bool lo_esta = false;

	if (datos.size() > 0) {
		typename std::list<Termino<KEY,DEF> >::iterator it_local;

		for (it_local=datos.begin();
		     it_local!=datos.end() && !((*it_local).palabra > palabra);
		     ++it_local, it = it_local)                              {

			if ((*it_local).palabra == palabra)
				lo_esta = true;
		}
	}
	else {
		it = datos.end();
	}

	return lo_esta;
}

template <class KEY, class DEF>
void Diccionario<KEY,DEF> :: insertar (const KEY & palabra,
                                       const std::list<DEF> & definiciones) {
	typename std::list<Termino<KEY,DEF> >::iterator it;

	if (!definida(palabra, it)) {
		Termino<KEY,DEF> termino;
		termino.palabra = palabra;
		termino.definiciones = definiciones;

		datos.insert(it, termino);
	}
}

template <class KEY, class DEF>
void Diccionario<KEY,DEF> :: definir (const KEY & palabra,
                                      const DEF & definicion) {
	typename std::list<Termino<KEY,DEF> >::iterator it;

	if (!definida(palabra, it))
		datos.insert(it, palabra);

	(*it).definiciones.insert((*it).definiciones.end(),definicion);
}

template <class KEY, class DEF>
std::list<DEF> Diccionario<KEY,DEF> :: definiciones (const KEY & palabra) {
	typename std::list<Termino<KEY,DEF> >::iterator it;

	if (!definida(palabra, it))
		return std::list<DEF>();
	else
		return (*it).definiciones;
}

template <class KEY, class DEF>
unsigned Diccionario<KEY,DEF> :: size() const {
	return datos.size();
}

template <class KEY, class DEF>
typename std::list<Termino<KEY,DEF> >::iterator &
                                       Diccionario<KEY,DEF> :: begin () {
	datos.begin();
}

template <class KEY, class DEF>
typename std::list<Termino<KEY,DEF> >::iterator &
                                       Diccionario<KEY,DEF> :: end () {
	datos.end();
}
/*
template <class KEY, class DEF>
typename std::list<Termino<KEY,DEF> >::const_iterator &
                                       Diccionario<KEY,DEF> :: begin() const {
	datos.begin();
}

template <class KEY, class DEF>
typename std::list<Termino<KEY,DEF> >::const_iterator &
                                       Diccionario<KEY,DEF> :: end() const {
	datos.end();
}
*/

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
std::ostream & operator << (std::ostream & os,
                            const Diccionario<std::string,std::string> & dic) {
	std::list<Termino<std::string,std::string> >::const_iterator it;

	for (it=dic.begin(); it!=dic.end(); ++it) {
		std::list<std::string>::const_iterator it_s;

		os << std::endl << (*it).palabra
		   << std::endl << " Definiciones:"
		   << std::endl;

		for (it_s=(*it).definiciones.begin(); it_s!=(*it).definiciones.end();
		     ++it_s)
			os << (*it_s) << std::endl;

		os << "**************************************" << std::endl;
	}

	return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

std::istream & operator >> (std::istream & is,
                            Diccionario<std::string,std::string> & dic) {
	unsigned np;
	Diccionario<std::string,std::string> dic_aux;

	is >> np;
	is.ignore(); //quitamos \n

	for (unsigned i=0; i<np; i++) {
		unsigned ns;
		std::string palabra;
		std::list<std::string> lista;

		getline(is, palabra);
		is >> ns;
		is.ignore(); //quitamos \n

		for (unsigned j=0; j<ns; j++) {
			std::string s;
			getline(is, s);

			lista.insert(lista.end(), s);
		}

		dic_aux.insertar(palabra, lista);
	}

	dic = dic_aux;

	return is;
}
