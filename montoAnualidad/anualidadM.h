#ifndef ANUALIDADM_H
#define ANUALIDADM_H

#include "../interes.h"

class anualidadM : public interes{
      
	public:
	//FUNCIONES DE FORMULAS
		
		//FUNCIONES DE FORMULAS PARA MONTO ANUALIDAD
			float montoAnualidadVS( float, float, float );
			float rentaAnualidadVS( float, float, float);
			float periodosAnualidadVS( float, float, float );
			float tasaAnualidadVS( float, float, float );
			float cociente1(float , float );
			float acumulacion( anualidadM &);
		
		//FUNCIONES PARA EL PROCESO DEL CACULO DEL MONTO ANUALIDADES 
		//VENCIDAS SIMPLES
			void calcMontoVS();
			void calcRentaMontoVS();
			void calcPeriodosMontoVS();
			void calcTasaMontoVS();
			void calcAcumulacion();
			void printAcumulacion( anualidadM &);
			bool deseaGuardar();

};

#endif
