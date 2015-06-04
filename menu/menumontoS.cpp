#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <cstdlib>
#include <string>
	using std::string;

#include "../simple/interesS.h"
#include "menu.h"

bool menuMontoS(){

	string opcion;
	interesS a;
	
	do{
		system ("clear");
		
		cout << '\n';
		a.trazarLinea( 30 );
		cout << "\nMENU MONTO SIMPLE\n";	
		a.trazarLinea( 30 );
		cout << "\n 1 -  CALCULAR MONTO SIMPLE.\n"
	     	<< " 2 -  CALCULAR CAPITAL.\n"
			<< " 3 -  CALCULAR TASA.\n"
			<< " 4 -  CALCULAR TIEMPO.\n"
			<< " 5 -  RETROCEDER.\n";
		a.trazarLinea( 30 );		
		cout << "\nINTRODUZCA UNA OPCION: ";		
		cin >> opcion;
		
		if ( !a.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarMS( atoi( opcion.data() ) ) );
		
	
}

bool seleccionarMS( int opcion ){

	interesS i;
	
	if ( opcion == 1 ) 
		i.calcularMontoS();
	else if( opcion == 2 ) 
		i.calcularMontoVPS();
	else if( opcion == 3 ) 
		i.calcularMontoTasaS();
	else if( opcion == 4 ) 
		i.calcularMontoTS();
	else if( opcion == 5 )
		return true;
	else
		return false;
	
	return false;
}
