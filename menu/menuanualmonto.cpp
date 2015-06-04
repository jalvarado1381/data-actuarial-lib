#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <cstdlib>
#include <string>
	using std::string;

#include "../montoAnualidad/anualidadM.h"

#include "menu.h"

bool menuAnualidadMonto(){

	string opcion;
	anualidadM a;
	
	do{
		system ("clear");
		
		cout << '\n';
		a.trazarLinea( 30 );
		cout << "\nMENU ANUALIDAD MONTO\n";
		a.trazarLinea( 30 );
		cout << "\n 1 -  MONTO ANUALIDAD SIMPLE.\n"
	     	<< " 2 -  RENTA ANUALIDAD SIMPLE.\n"
			<< " 3 -  TASA ANUALIDAD SIMPLE.\n"
			<< " 4 -  TIEMPO ANUALIDAD SIMPLE.\n"
			<< " 5 -  TABLA ACUMULACION.\n"
			<< " 6 -  RETROCEDER.\n";
		a.trazarLinea( 30 );
		cout  << endl << "INTRODUZCA UNA OPCION: ";
		cin >> opcion;
			
		if ( !a.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarAnualidadM( atoi( opcion.data() ) ) );
		
	
}

bool seleccionarAnualidadM( int opcion ){

	anualidadM i;
	
	if ( opcion == 1 ) 
		i.calcMontoVS();
	else if( opcion == 2 ) 
		i.calcRentaMontoVS();
	else if( opcion == 3 ) 
		i.calcTasaMontoVS();
	else if( opcion == 4 ) 
		i.calcPeriodosMontoVS();
	else if( opcion == 5 ) 
		i.calcAcumulacion();
	else if( opcion == 6 )
		return true;
	else
		return false;
	
	return false;
	
}

