#include <iostream>
#include <cmath>
	//using std::pow;
#include "interesC.h"


//INTERES CCOMPUESTO
double interesC::interesCompuesto(float p, float i, float n){
	
	float b;
	float power;
	
	b = 1 + i;
	power = pow(b,n);
	
	return  p * ( power - 1 );
	
}

// VALOR PRESENTE INTERES COMPUESTO
float interesC::valorPICompuesto(float S, float i, float n){
	
	return  S / pow( ( 1 + i ), n) ;
	
}

// TASA INTERES COMPUESTO
float interesC::tasaICompuesto(float S, float p, float n){
	
	return  pow( (S/p), 1/n ) - 1 ;
	
}

// TIEMPO INTERES COMPUESTO
float interesC::tiempoICompuesto(float S, float p, float i){
	
	return  log10(S/p) / log10(i + 1);
	
}

// MONTO INTERES COMPUESTO
float interesC::montoICompuesto(float p, float i, float n){

	return p * pow ( ( 1 + i), n );

}

//INTERES COMPUESTO NOMINAL
float interesC::interesCompuestoN(float p, float i, float n, float m){
	
	return  p * ( pow( ( 1 + i/m ), n * m) - 1 );
	
}

// VALOR PRESENTE INTERES COMPUESTO NOMINAL
float interesC::valorPICompuestoN(float S, float i, float n, float m){
	
	return  S / pow( ( 1 + i/m ), n * m) ;
	
}

// TASA INTERES COMPUESTO
float interesC::tasaICompuestoN(float S, float p, float n, float m){
	
	return  m * ( pow( (S/p), 1/(n*m) ) - 1 ) ;
	
}

// TIEMPO INTERES COMPUESTO
float interesC::tiempoICompuestoN(float S, float p, float j, float m){
	
	return  log10(S/p) / ( log10( 1 + ( j/m ) )  * m );
	
}

// MONTO INTERES COMPUESTO
float interesC::montoICompuestoN(float p, float i, float n, float m){

	return p * pow ( ( 1 + i/m), n*m );

}
