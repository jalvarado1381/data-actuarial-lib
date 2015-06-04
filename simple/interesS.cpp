#include "interesS.h"

//INTERES SIMPLE
float interesS::interesSimple(float p, float i, float t){
	
	return  p * i * t;
	
}

float interesS::valorPresenteSimple(float I, float i, float t){
	
	return  I / ( i * t );
	
}

float interesS::tasaSimple(float I, float p, float t){
	
	return  I / ( p * t );
	
}

float interesS::tiempoSimple(float I, float p, float i){
	
	return  I / ( p * i );
	
}

// MONTO SIMPLE

float interesS::montoSimple(float p, float i, float t){

	return p * ( 1 + i * t);

}

float interesS::montoVPSimple(float s, float i, float t){

	return s / ( 1 + i * t);

}

float interesS::montoTiempoSimple(float s, float p, float i){

	return ( ( s / p ) - 1 ) / i;
	
}

float interesS::montoTasaSimple(float s, float p, float t){
	
	return ( ( s / p ) - 1 ) / t;
	
}

