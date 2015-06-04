#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <string>
	using std::string;
#include <cstdlib>

#include "menu.h"
#include "../interes.h"

void menuPrincipal(){
	string opcion;
	interes a;
	do{
		system ("clear");
	
		cout << endl;
		
		a.trazarLinea( 30 );
		
		cout <<"\nMENU PRINCIPAL " << endl;
	
		a.trazarLinea( 30 );
	
		cout << endl 
			<< "  1 -  INTERES SIMPLE.\n"
	     	<< "  2 -  MONTO SIMPLE.\n"
			<< "  3 -  INTERES COMPUESTO.\n"
			<< "  4 -  ANUALIDADES.\n"
			<< "  5 -  SALIR.\n";
		
		a.trazarLinea( 30 );
		
		cout  << endl << "INTRODUZCA UNA OPCION: ";
		cin >> opcion;
		if ( !a.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarMenu( atoi( opcion.data() ) ) );
	
}

bool seleccionarMenu( int opcion ){

	if ( opcion == 1 )
		menuSimple();
	else if( opcion == 2 )
		menuMontoS();
	else if( opcion == 3 )
		menuCompuesto();
	else if( opcion == 4 ){
		menuAnualidad();
	}
	else if( opcion == 5 )
		return true;
	else
		return false;
}
