#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
#include <cstdlib>
#include <iomanip>
	using std::setprecision;

#include "anualidadM.h"
#include "../menu/menu.h"

void anualidadM::calcMontoVS(){

	anualidadM MontoA;
	char opcion;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float tasa;
	
	MontoA.denominador = 1;
	MontoA.tiempo = -1;
	MontoA.frecueM = 1;
	MontoA.capturaRenta(MontoA);
	MontoA.capturaTasa(MontoA);
	MontoA.tipoTasa(MontoA);
	
	if (MontoA.nominal)
			elegirTsaNominal( MontoA );
	
	cout << setprecision(3) << fixed;

	tipoTiempo = menuTipoTiempo();
	
	if ( tipoTiempo == 1 ){
		
		do{
		
			MontoA.capturaFechas(MontoA);
			
			
		} while ( MontoA.tiempo <= 0 );
		
	}
	else if ( tipoTiempo == 2 ){
	
		do{
		
			MontoA.capturaTiempoPredeterminado( tipoPeriodo, MontoA );
			
		} while( MontoA.tiempo <= 0 );
		
	}
	
	if ( tipoPeriodo == '1' ){
	
		tipoInteres = menuTipoInteres();
	
		if ( tipoInteres == 1 ){
		
			MontoA.denominador = 365;
		
		}
		else if ( tipoInteres == 2 ){
		
			MontoA.denominador = 360;
		
		}
		
		system("clear");	
		cout << "Para una renta de $" << MontoA.renta
			<< "\ny una Tasa de " << MontoA.tasa;
		MontoA.printTipoNominal(MontoA);
		
		if ( tipoTiempo == 1 )     
			cout << "\n\nDesde el " << MontoA.diaI << '/'
				<< MontoA.mesI << '/' << MontoA.anoI
				<< "\nHasta el " << MontoA.diaF << '/'
				<< MontoA.mesF << '/' << MontoA.anoF
				<< "Para un total de " << (MontoA.tiempo/MontoA.denominador)
				<<"año(s).\n";
		else
			cout << "\nen un tiempo de " << MontoA.tiempo << " dias,";
			
			cout << "\nEl monto obtenido es de $";
			if ( !MontoA.nominal ){
				cout << MontoA.montoAnualidadVS(MontoA.renta,
									       (MontoA.tasa/100),
									       (MontoA.tiempo/MontoA.denominador) );
			}
			else{
				cout << MontoA.montoAnualidadVS( MontoA.renta,
									        (MontoA.tasa/100) / MontoA.frecueM,
									        (MontoA.tiempo/MontoA.denominador) * MontoA.frecueM );
			}
	}
	else if ( tipoPeriodo == '2' ){
	
		MontoA.denominador = 12;
				
		system("clear");	
		cout << "Para un renta de $" << MontoA.renta
			<< "\nuna Tasa de " << MontoA.tasa;
		MontoA.printTipoNominal(MontoA);
		cout << "\nen un tiempo de " << MontoA.tiempo << " meses,"
	     	<< "\nEl monto obtenido es de $";
			
			if ( !MontoA.nominal ){
				cout << MontoA.montoAnualidadVS(MontoA.renta,
									       (MontoA.tasa/100),
									       (MontoA.tiempo/MontoA.denominador) );
			}
			else{
				cout << MontoA.montoAnualidadVS( MontoA.renta,
									        (MontoA.tasa/100) / MontoA.frecueM,
									        (MontoA.tiempo/MontoA.denominador) * MontoA.frecueM );
			}
		
	}
	else if( tipoPeriodo == '3' ){
		
		system("clear");	
		cout << "Para una renta de $" << MontoA.renta
			<< "\nuna Tasa de " << MontoA.tasa;
		MontoA.printTipoNominal(MontoA);
		cout << "\ny un tiempo de " << MontoA.tiempo << " año(s),"
	     	<< "\nEl monto obtenido es de $";
			
			if ( !MontoA.nominal ){
				cout << MontoA.montoAnualidadVS(MontoA.renta,
									       (MontoA.tasa/100),
									       (MontoA.tiempo/MontoA.denominador) );
			}
			else{
				cout << MontoA.montoAnualidadVS( MontoA.renta,
									        (MontoA.tasa/100) / MontoA.frecueM,
									        (MontoA.tiempo/MontoA.denominador) * MontoA.frecueM );
			}
	}
	
	printAcumulacion( MontoA );
	
}

