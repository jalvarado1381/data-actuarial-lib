#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <cstdlib>
#include <string>
	using std::string;

#include "../compuesto/interesC.h"
#include "menu.h"

bool menuCompuesto(){

	string opcion;
	interesC a;
	
	do{
		system ("clear");
		
		cout << '\n';		
		a.trazarLinea( 30 );		
		cout << "\nMENU INTERES COMPUESTO\n";	
		a.trazarLinea( 30 );	
		cout << "\n 1 -  CALCULAR INTERES COMPUESTO.\n"
			<< " 2 -  CALCULAR MONTO COMPUESTO.\n"
	     	<< " 3 -  CALCULAR CAPITAL COMPUESTO.\n"
			<< " 4 -  CALCULAR TASA COMPUESTA.\n"
			<< " 5 -  CALCULAR TIEMPO COMPUESTO.\n"
			<< " 6 -  RETROCEDER.\n";		
		a.trazarLinea( 30 );
		
		cout  << "\nINTRODUZCA UNA OPCION: ";
		cin >> opcion;
		
		if ( !a.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarC( atoi( opcion.data() ) ) );
		
	
}

bool seleccionarC( int opcion ){

	interesC i;
	
	if ( opcion == 1 ) 
		i.calcularIC();
	else if( opcion == 2 ) 
		i.calcularMontoC();
	else if( opcion == 3 ) 
		i.calcularMontoVPC();
	else if( opcion == 4 ) 
		i.calcularMontoTasaC();
	else if( opcion == 5 )
		i.calcularMontoTC();
	else if( opcion == 6 )
		return true;
	else
		return false;
		
	return false;
	
}
