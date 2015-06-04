#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <cstdlib>
#include <string>
	using std::string;

#include "../simple/interesS.h"
#include "menu.h"

bool menuSimple(){

	string opcion;
	interesS a;
	
	do{
		system ("clear");
		
		cout << '\n';		
		a.trazarLinea( 30 );		
		cout << "\nMENU INTERES SIMPLE\n";	
		a.trazarLinea( 30 );
		cout << "\n 1 -  CALCULAR INTERES.\n"
	     	<< " 2 -  CALCULAR CAPITAL.\n"
			<< " 3 -  CALCULAR TASA.\n"
			<< " 4 -  CALCULAR TIEMPO.\n"
			<< " 5 -  RETROCEDER.\n";		
		a.trazarLinea( 30 );		
		cout  << endl << "INTRODUZCA UNA OPCION: ";		
		cin >> opcion;
			
		if ( !a.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarS( atoi( opcion.data() ) ) );
		
	
}

bool seleccionarS( int opcion ){

	interesS i;
	
	if ( opcion == 1 ) 
		i.calcularInteresS();
	else if( opcion == 2 ) 
		i.calcularVPSimple();
	else if( opcion == 3 ) 
		i.calcularTasaSimple();
	else if( opcion == 4 ) 
		i.calcularTiempoSimple();
	else if( opcion == 5 )
		return true;
	else
		return false;
	
	return false;
	
}
