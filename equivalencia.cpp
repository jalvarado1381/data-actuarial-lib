#include "financiera.h"

float Financiera::meses(float dias){
		
	return  dias / 30 ;
	
}

float Financiera::trimestres(float dias){
	
	return  meses(dias) / 3;
	
}

float Financiera::cuatrimestres(float dias){

	return meses(dias) / 4;

}

float Financiera::semestres(float dias){

	return meses(dias) / 6;

}

float Financiera::anos(float dias){

	return (float) dias / 360;

}
