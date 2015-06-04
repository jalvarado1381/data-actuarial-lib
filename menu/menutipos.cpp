 #include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include <cstdlib>
#include <string>
	using std::string;

#include "menu.h"
#include "../interes.h"
	interes a;
	
int menuTipoInteres(){
	
	int tipo;
	int opcion;
	
	do{
	
		system ("clear");
	
		cout << '\n';		
		a.trazarLinea( 30 );		
		cout << "\nMENU TIPO INTERES\n";	
		a.trazarLinea( 30 );	
		cout << "\n 1 -  INTERES EXACTO.\n"
	     	<< " 2 -  INTERES ORDINARIO.\n";			
		a.trazarLinea( 30 );		
		cout  << "\nINTRODUZCA UNA OPCION: ";
		
		cin.clear();
		cin.ignore();
		cin >> opcion;
		tipo = seleccionarTI( opcion );
		
	}while(tipo == 0);

	return tipo;	
}

int menuTipoTiempo(){

	int tipo;
	int opcion;

	do{
		system ("clear");
		
		cout << '\n';		
		a.trazarLinea( 30 );		
		cout << "\nMENU TIPO TIEMPO\n";	
		a.trazarLinea( 30 );	
		cout << "\n 1 -  TIEMPO DADA 2 FECHAS.\n"
	     	<< " 2 -  TIEMPO PREDETERMINADO.\n"
			<< " 5 -  SALIR.\n";		
		a.trazarLinea( 30 );		
		cout  << "\nINTRODUZCA UNA OPCION: ";
		
		cin.clear();
		cin.ignore();
		cin >> opcion;
		tipo = seleccionarTT( opcion );
		
	} while( tipo == 0 );

	return tipo;

}

int seleccionarTI( int opcion ){

	if ( opcion == 1 ) 
		return 1;
	else if( opcion == 2 ) 
		return 2;
	else if( opcion == 5 ) 
		return 5;
	else
		return 0;

}



int seleccionarTT( int opcion ){

	if ( opcion == 1 ) 
		return 1;
	else if( opcion == 2 ) 
		return 2;
	else if( opcion == 5 ) 
		return 5;
	else
		return 0;

}

void elegirTsaNominal( interes &nominal ){

	string opcion;
	do{
		system("clear");
		
		a.trazarLinea( 30 );
		cout << "\nTIPO TASA NOMINAL.\n";
		a.trazarLinea( 30 );
		cout	<< "\n 1 - SEMANAL."
			<< "\n 2 - QUINCENAL."
			<< "\n 3 - MENSUAL."
			<< "\n 4 - BIMENSUAL."
			<< "\n 5 - TRIMESTRAL."
			<< "\n 6 - CUATRIMESTRAL."
			<< "\n 7 - SEMESTRAL.\n";		
		a.trazarLinea( 30 );			
		cout  << "\nINTRODUZCA UNA OPCION: ";
		cin >> opcion;
		
		if ( !nominal.esNumerico( opcion ) )
			continue;
		
	}while(  !seleccionarTipoT( atoi( opcion.data() ), nominal ) );
		
	
}

bool seleccionarTipoT( int opcion, interes &i){	
	
	if ( opcion == 1 ) 
		i.frecueM = 52;
	else if( opcion == 2 ) 
		i.frecueM = 24;
	else if( opcion == 3 ) 
		i.frecueM = 12;
	else if( opcion == 4 ) 
		i.frecueM = 6;
	else if( opcion == 5 )
		i.frecueM = 4;
	else if( opcion == 6 )
		i.frecueM = 3;
	else if( opcion == 7 )
		i.frecueM = 2;
	else{		
		return false;
	}
	return true;
}
