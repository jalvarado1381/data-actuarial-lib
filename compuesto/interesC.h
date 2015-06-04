#ifndef INTERESC_H
#define INTERESC_H

#include "../interes.h"

class interesC : public interes{
 
	public:
	//FUNCIONES DE FORMULAS 
		
		
		//FUNCIONES DE FORMULAS PARA INTERES COMPUESTO
			double interesCompuesto(float, float, float);
			float valorPICompuesto(float, float, float);
			float tasaICompuesto(float, float, float);
			float tiempoICompuesto(float, float, float);
			float montoICompuesto(float, float, float);
		
		//FUNCIONES DE FORMULAS PARA INTERES COMPUESTO NOMINAL
			float interesCompuestoN(float, float, float, float);
			float valorPICompuestoN(float, float, float, float);
			float tasaICompuestoN(float, float, float, float);
			float tiempoICompuestoN(float, float, float, float);
			float montoICompuestoN(float, float, float, float);
			
		//FUNCIONES PARA EL PROCESO DEL CACULO DEL INTERES Y MONTO
		//COMPUESTOS
			void calcularIC();
			void calcularMontoC();
			void calcularMontoVPC();
			void calcularMontoTC();
			void calcularMontoTasaC();	
			
			
};

#endif
