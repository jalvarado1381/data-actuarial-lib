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
#include "anualidadA.h"


float anualidadA::actualAnualidadVS( float R, float i, float n ){
	
	capital = R * ( ( 1 -  pow ( ( 1 + i ), (-n)  )  ) / i );
	return  capital;

}

float anualidadA::rentaAnualidadVS( float A, float i, float n){
	
	renta = A / ( ( 1 -  pow ( ( 1 + i ), n * (-1) )  ) / i );
	return renta;

}
float anualidadA::periodosAnualidadVS( float A, float R, float i ){

	return  ( log10( (  1 - ( A * i ) / R )  ) / log10( 1 + i ) ) * (-1);

}
float anualidadA::tasaAnualidadVS( float A, float R, float n ){

	float cociente;	
	float limI = 0;
	float limS = 100;
	float i = 100;
	cociente = A / R;
	
	do{
		if ( cociente1( i/100, n ) < cociente ){
			limS = i;
			i = limS / 2;
		}
		else if( cociente1( i/100, n ) > cociente ){
			limI = i;
			i = ( limI + limS ) / 2;
		}
	}while(cociente1( i/100, n ) != cociente);
	
	tasa = i;
	return i;
	
}

float anualidadA::cociente1(float i, float n){

	return ( 1 - pow( 1 + i, n * (-1) ) ) / i;

}

float anualidadA::amortizacion(anualidadA &ActualA){
	
	float nPeriodo;
	float balance;	
	float interes;
	float amortiza;
	ostringstream salida;
	string salida1;
	
	nPeriodo = (ActualA.tiempo/ActualA.denominador) * ActualA.frecueM;
	balance = ActualA.capital;
	
	salida << "\nPERIODOS       RENTA        AMORTIZACION       INTERESES       BALANCE\n";
	salida << setprecision(2) << fixed
		  << setw(3)  << right << 0 
		  << setw(17) << right << 0
		  << setw(17) << right << 0
		  << setw(17) << right << 0 
		  << setw(17) << right << balance << endl;	
		  	
	for ( int i = 1; i < ( nPeriodo + 1 ); i++){
		
		interes = ( (ActualA.tasa/100) / ActualA.frecueM ) * balance;
		amortiza = ActualA.renta - interes;
		balance -= amortiza;
		
		salida << setprecision(2)   << fixed
			  << setw(3)  << right << i 
			  << setw(17) << right << ActualA.renta 
			  << setw(17) << right << amortiza
			  << setw(17) << right << interes 
			  << setw(17) << right << balance << endl;

	}
	
	trazarLinea(60);
	cout  << endl << salida.str();
	salida1 = salida.str();
	if ( deseaGuardar() ) {
		ActualA.guardarFile( salida1 );
	}
}

void anualidadA::printAmortizacion( anualidadA &ActualA ){
	
	char opcion ;
	cout << endl;
	trazarLinea(60);
	cout << endl << "\n¿DESEA PRESENTAR LA TABLA DE AMORTIZACION? (S/N): ";
	
	cin.ignore();
	do{
				
		opcion = getchar();
		
		if ( opcion == 's' || opcion == 'S' ){
			ActualA.amortizacion(ActualA);
			cout << endl << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
			cin.ignore();
			getchar();
		}else if ( opcion == 'n' || opcion == 'N' ){
			cout << endl << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
			cin.ignore();
			getchar();
		}else{
			cout << "OPCION INCORRECTA, TRATE DE NUEVO.";
			opcion = 'f';
		}
	}while( opcion == 'f' );

}

bool anualidadA::deseaGuardar(){

	char opcion;
	
	cout << endl;
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
