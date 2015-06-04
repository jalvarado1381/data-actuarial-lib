#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <cstdlib>
#include <string>
	using std::string;

#include "../interes.h"

#include "menu.h"

bool menuAnualidad(){

	string opcion;
	interes a;
	
	do{
		system ("clear");
		
		cout << '\n';
		a.trazarLinea( 30 );
		cout << "\nMENU ANUALIDADES\n";
		a.trazarLinea( 30 );
		cout << "\n 1 -  MONTO ANUALIDAD.\n"
	     	<< " 2 -  VALOR ACTUAL ANUALIDAD.\n"
			<< " 5 -  RETROCEDER.\n";
		a.trazarLinea( 30 );
		cout  << endl << "INTRODUZCA UNA OPCION: ";		
		cin >> opcion;
		
		if ( !a.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarAnualidad( atoi( opcion.data() ) ) );


}

bool seleccionarAnualidad( int opcion ){

	
	if ( opcion == 1 ) 
		menuAnualidadMonto();
	else if( opcion == 2 ) {
		menuAnualidadActual();
	}
	else if( opcion == 5 )
		return true;
	else
		return false;
	
	return false;
	
}

