#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
	using std::right;
	using std::left;	
#include <cstdlib>
#include <iomanip>
	using std::setw;
	using std::setprecision;
	using std::setfill;
#include <string>
	using std::string;
#include <sstream>
	using std::ostringstream;
	
#include <cmath>
	
#include "anualidadM.h"

float anualidadM::montoAnualidadVS( float R, float i, float n ){

	return  R * ( ( pow ( ( 1 + i), n ) - 1 ) / i );

}

float anualidadM::rentaAnualidadVS( float S, float i, float n){
	
	renta = S / ( ( pow ( ( 1 + i), n ) - 1 ) / i );
	return renta;

}
float anualidadM::periodosAnualidadVS( float S, float R, float i ){

	tiempo = log10( ( ( S * i ) / R ) + 1 ) / log10( 1 + i );
	return  tiempo;

}
float anualidadM::tasaAnualidadVS( float S, float R, float n ){

	float cociente;	
	float limI = 0;
	float limS = 100;
	float i = 100;
	cociente = S / R;
	
	do{
		if ( cociente1( i/100, n ) > cociente ){
			limS = i;
			i = limS/2;
		}
		else if( cociente1( i/100, n ) < cociente ){
			limI = i;
			i = ( limI + limS ) / 2;
		}
	}while( cociente1( i/100, n ) != cociente );
	
	tasa = i;
	return tasa;
}

float anualidadM::cociente1(float i, float n){

	return ( pow( 1 + i, n ) - 1 ) / i;

}

float anualidadM::acumulacion( anualidadM &MontoA ){

	float nPeriodo;
	float balance;
	float acumulacion;
	float interes = 0;
	ostringstream salida;
	string salida1;
	nPeriodo = (MontoA.tiempo/MontoA.denominador) * MontoA.frecueM;	
	balance = MontoA.renta;
	acumulacion = MontoA.renta;	
	
	salida << "PERIODOS       PAGO        INTERESES        ACUMULACION        BALANCE" << endl;
	
	for ( int i = 1; i < ( nPeriodo + 1 ); i++){
			
		salida << setprecision(2) << fixed     
			  << setw(3)   << right << i 
			  << setw(17)  << right << MontoA.renta 
			  << setw(17)  << right << interes 
			  << setw(17)  << right << acumulacion
			  << setw(17)  << right << balance << endl;
			
		interes = ( (MontoA.tasa/100) / MontoA.frecueM ) * balance;
		acumulacion = MontoA.renta + interes;
		balance += acumulacion;		
		
	}
	
	cout  << salida.str();
	salida1 = salida.str();
	if ( deseaGuardar() ) {
		MontoA.guardarFile( salida1 );
	}
}
void anualidadM::printAcumulacion( anualidadM &MontoA ){
	
	char opcion;
	cout << endl;
	MontoA.trazarLinea(60);
	cout << endl << "\n¿DESEA PRESENTAR LA TABLA DE ACUMULACION? (S/N): ";	
		
	cin.ignore();
	do{		
		opcion = getchar();
		
		if ( opcion == 's' || opcion == 'S' ){
			MontoA.acumulacion(MontoA);
			cout << endl << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
			cin.ignore();
			getchar();
		}
		else if ( opcion == 'n' || opcion == 'N' ){
			cout << endl << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
			cin.ignore();
			getchar();
		}
		else{
			cout << "OPCION INCORRECTA, TRATE DE NUEVO.";
			opcion = 'f';
		}
	}while( opcion == 'f' );
	
}
bool anualidadM::deseaGuardar(){

	char opcion;	
	trazarLinea(60);
	cout << "\nDESEA GUARDAR ESTA TABLA EN UN ARCHIVO? (S/N) ";
	
	cin.ignore();
	do{
		
		opcion = getchar();
		
		if ( opcion == 's' || opcion == 'S' ){
			return true;
		}
		else if ( opcion == 'n' || opcion == 'N' ){
			return false;
		}
		else{
			cout << "OPCION INCORRECTA, TRATE DE NUEVO.";
			opcion = 'f';
		}
	}while( opcion == 'f' );
}
