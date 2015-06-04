#ifndef INTERESS_H
#define INTERESS_H

#include "../interes.h"

class interesS : public interes{
	public:	
		 
	//FUNCIONES DE FORMULAS 
		
		//FUNCIONES DE FORMULAS PARA INTERES SIMPLE
			float interesSimple(float, float, float);
			float valorPresenteSimple(float, float, float);
			float tasaSimple(float, float, float);
			float tiempoSimple(float, float, float);			
		
		//FUNCIONES PARA MONTO SIMPLE
			float montoSimple(float, float, float);
			float montoVPSimple(float, float, float);
			float montoTiempoSimple(float, float, float);
			float montoTasaSimple(float, float, float);
		
		//FUNCIONES EL PROCESO DEL CACULO DEL INTERES SIMPLE
			void calcularInteresS();
			void calcularVPSimple();
			void calcularTasaSimple();
			void calcularTiempoSimple();
		
		//FUNCIONES PARA EL PROCESO DEL CACULO DEL MONTO SIMPLE
			void calcularMontoS();
			void calcularMontoVPS();
			void calcularMontoTS();
			void calcularMontoTasaS();
			
};

#endif
