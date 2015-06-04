#ifndef ANUALIDADA_H
#define ANUALIDADA_H

#include "../interes.h"

class anualidadA : public interes{
      
	public:
	//FUNCIONES DE FORMULAS
		
		//FUNCIONES DE FORMULAS PARA MONTO ANUALIDAD
			float actualAnualidadVS( float, float, float );
			float rentaAnualidadVS( float, float, float);
			float periodosAnualidadVS( float, float, float );
			float tasaAnualidadVS( float, float, float );
			float cociente1(float, float );
			float amortizacion( anualidadA &);
		
		//FUNCIONES PARA EL PROCESO DEL CACULO DEL INTERES Y MONTO
		//COMPUESTOS
			void calcActualVS();
			void calcRentaMontoVS();
			void calcPeriodosMontoVS();
			void calcTasaMontoVS();
			void calcAmortizacion();
			void printAmortizacion( anualidadA &);
			bool deseaGuardar();

};

#endif
