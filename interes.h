#ifndef INTERES_H
#define INTERES_H

#include "financiera.h"
#include <string>
	using std::string;
#include <sstream>
	using std::ostringstream;

class interes : public Financiera{
	public:
	
	//ATRIBUTOS
		double interesG,
			  capital,
			  tiempo,
			  tasa,
			  monto,
			  frecueM,
			  renta,
			  denominador;
		bool nominal;
			 
	//Captura de Datos
		void capturaFechas( interes & );
		void capturaTiempoPredeterminado(char &, interes &);
		void capturaValorPresente( interes & );
		void capturaTasa( interes & );
		void capturaInteres( interes &);
		void capturaMonto( interes & );
		void capturaRenta( interes & );
	//FUNCIONES GENERALES
		float asignarValor();
		bool esNumerico( string );
		bool tipoTasa( interes & );
		void printTipoNominal( interes & );
		void trazarLinea( int );
		void guardarFile( string );
	
};

#endif
