#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
#include <cstdlib>
#include <iomanip>
	using std::setprecision;

#include "interesS.h"
#include "../menu/menu.h"


void interesS::calcularVPSimple(){

	interesS Simple;	
	int tipoTiempo;	
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador;
	
	
	Simple.capturaInteres(Simple);
	Simple.capturaTasa(Simple);
	
	Simple.tiempo = -1;
	tipoTiempo = menuTipoTiempo();
	
	if ( tipoTiempo == 1 ){
		
		do{
		
			Simple.capturaFechas(Simple);
			
			
		} while ( Simple.tiempo <= 0 );
		
	}
	else if ( tipoTiempo == 2 ){
	
		do{
		
			Simple.capturaTiempoPredeterminado( tipoPeriodo, Simple );
			
		} while( Simple.tiempo <= 0 );
		
	}
	
	if ( tipoPeriodo == '1' ){
	
		tipoInteres = menuTipoInteres();
	
		if ( tipoInteres == 1 ){
		
			denominador = 365;
		
		}
		else if ( tipoInteres == 2 ){
		
			denominador = 360;
		
		}
		
		system("clear");	
		cout << "Para un interes de $" << Simple.interesG
			<< "\ny una Tasa de " << Simple.tasa << "%";
			
		if ( tipoTiempo == 1 )     
			cout << "\n\nDesde el " << Simple.diaI << '/'
				<< Simple.mesI << '/' << Simple.anoI
				<< "\nHasta el " << Simple.diaF << '/'
				<< Simple.mesF << '/' << Simple.anoF
				<< "Para un total de " << (Simple.tiempo/denominador)
				<<"año(s).\n";
		else
			cout << "\nen un tiempo de " << Simple.tiempo << " dias,";
			
			cout << setprecision(2) << fixed 
				<< "\nEl capital invertido es de $"
				<< Simple.valorPresenteSimple( Simple.interesG,
									Simple.tasa / 100,
									( Simple.tiempo/denominador ) )
				<< endl;
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;
				
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un interes de $" << Simple.interesG
			<< "\nuna Tasa de " << Simple.tasa  << "% "
			<< "\nen un tiempo de " << Simple.tiempo << " meses,"
	     	<< "\nEl capital invertido es de $"
			<< Simple.valorPresenteSimple(Simple.interesG, 
									Simple.tasa / 100,
			   						(Simple.tiempo/denominador) )
			<< endl;
		
	}
	else if( tipoPeriodo == '3' ){
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un Interes de $" << Simple.interesG
			<< "\nuna Tasa de " << Simple.tasa  << "% "
			<< "\ny un tiempo de " << Simple.tiempo << " año(s),"
	     	<< "\nEl capital invertido es de $"
			<< Simple.valorPresenteSimple( Simple.interesG, 
									Simple.tasa / 100,
									(Simple.tiempo) )
			<< endl;
	}
	
	cout << endl << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
