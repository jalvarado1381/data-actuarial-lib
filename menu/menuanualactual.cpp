#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <cstdlib>
#include <string>
	using std::string;

#include "../actualAnualidad/anualidadA.h"

#include "menu.h"

bool menuAnualidadActual(){

	string opcion;
	anualidadA a;
	
	do{
		system ("clear");
		
		cout << '\n';
		a.trazarLinea( 30 );
		cout << "\nMENU ANUALIDAD VALOR ACTUAL\n";
		a.trazarLinea( 30 );
		cout << "\n 1 -  VALOR ACTUAL ANUALIDAD SIMPLE.\n"
	     	<< " 2 -  RENTA ANUALIDAD SIMPLE.\n"
			<< " 3 -  TASA ANUALIDAD SIMPLE.\n"
			<< " 4 -  TIEMPO ANUALIDAD SIMPLE.\n"
			<< " 5 -  TABLA AMORTIZACION.\n"
			<< " 6 -  RETROCEDER.\n";
		a.trazarLinea( 30 );		
		cout  << "\nINTRODUZCA UNA OPCION: ";			
		cin >> opcion;
		
		if ( !a.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarAnualidadA( atoi( opcion.data() ) ) );
		
	
}

bool seleccionarAnualidadA( int opcion ){

	anualidadA i;
	
	if ( opcion == 1 ) 
		i.calcActualVS();
	else if( opcion == 2 ) 
		i.calcRentaMontoVS();	
	else if( opcion == 3 ) 
		i.calcTasaMontoVS();	
	else if( opcion == 4 ) 
		i.calcPeriodosMontoVS();
	else if( opcion == 5 ) 
		i.calcAmortizacion();
	else if( opcion == 6 )
		return true;
	else
		return false;
		
	return false;
	
}

