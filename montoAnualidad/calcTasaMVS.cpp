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


void anualidadM::calcTasaMontoVS(){

	anualidadM MontoA;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador = 1;	
	
	MontoA.tiempo = -1;
	MontoA.frecueM = 1;
	MontoA.capturaRenta(MontoA);
	MontoA.capturaMonto(MontoA);	
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
		
			denominador = 365;
		
		}
		else if ( tipoInteres == 2 ){
		
			denominador = 360;
		
		}
		
		system("clear");	
		cout << "Para obtener un monto de $" << MontoA.monto
			<< "\ncon una renta de " << MontoA.renta;
				
		if ( tipoTiempo == 1 )     
			cout << "\n\nDesde el " << MontoA.diaI << '/'
				<< MontoA.mesI << '/' << MontoA.anoI
				<< "\nHasta el " << MontoA.diaF << '/'
				<< MontoA.mesF << '/' << MontoA.anoF
				<< "Para un total de " << (MontoA.tiempo/denominador)
				<<"año(s).\n";
		else
			cout << "\nen un tiempo de " << MontoA.tiempo << " dias,";
			
			cout << "\nLa tasa es de ";
			if ( !MontoA.nominal ){
				cout << MontoA.tasaAnualidadVS( MontoA.monto,
									       MontoA.renta,
									       (MontoA.tiempo/denominador) );
				MontoA.tasa = MontoA.tasaAnualidadVS( MontoA.monto,
											   MontoA.renta,
											   ( MontoA.tiempo/denominador) );
			}
			else{
				cout << MontoA.frecueM * MontoA.tasaAnualidadVS( MontoA.monto,
													    MontoA.renta,
													    ( MontoA.tiempo/denominador) * MontoA.frecueM );
				MontoA.tasa = MontoA.frecueM * MontoA.tasaAnualidadVS( MontoA.monto,
															MontoA.renta,
															( MontoA.tiempo/denominador) * MontoA.frecueM );
			
			}
			
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;
				
		system("clear");	
		cout << "Para obtener un monto de $" << MontoA.monto
			<< "\ncon una renta de " << MontoA.renta;
		
		cout << "\nen un tiempo de " << MontoA.tiempo << " meses,"
	     	<< "\nLa tasa  es de ";
			
			if ( !MontoA.nominal ){
				cout << MontoA.tasaAnualidadVS( MontoA.monto,
									       MontoA.renta,
									       (MontoA.tiempo/denominador) );
				MontoA.tasa = MontoA.tasaAnualidadVS( MontoA.monto,
											   MontoA.renta,
											   ( MontoA.tiempo/denominador) );
			}
			else{
				cout << MontoA.frecueM * MontoA.tasaAnualidadVS( MontoA.monto,
													    MontoA.renta,
													    ( MontoA.tiempo/denominador) * MontoA.frecueM );
				MontoA.tasa = MontoA.frecueM * MontoA.tasaAnualidadVS( MontoA.monto,
															MontoA.renta,
															( MontoA.tiempo/denominador) * MontoA.frecueM );
			
			}
		
	}
	else if( tipoPeriodo == '3' ){
		
		system("clear");	
		cout << "Para obtener un monto de $" << MontoA.monto
			<< "\ncon una renta de " << MontoA.renta;
		
		cout << "\nen un tiempo de " << MontoA.tiempo << " año(s),"
	     	<< "\nLa tasa  es de ";
			
			if ( !MontoA.nominal ){
				cout << MontoA.tasaAnualidadVS( MontoA.monto,
									       MontoA.renta,
									       (MontoA.tiempo/denominador) );
				MontoA.tasa = MontoA.tasaAnualidadVS( MontoA.monto,
											   MontoA.renta,
											   ( MontoA.tiempo/denominador) );
			}
			else{
				cout << MontoA.frecueM * MontoA.tasaAnualidadVS( MontoA.monto,
													    MontoA.renta,
													    ( MontoA.tiempo/denominador) * MontoA.frecueM );
				MontoA.tasa = MontoA.frecueM * MontoA.tasaAnualidadVS( MontoA.monto,
															MontoA.renta,
															( MontoA.tiempo/denominador) * MontoA.frecueM );
			
			}
		
	}	
	MontoA.printTipoNominal(MontoA);
	
	MontoA.denominador = denominador;
	printAcumulacion(MontoA);
	
}
