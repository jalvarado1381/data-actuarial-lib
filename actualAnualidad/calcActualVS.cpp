#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
#include <cstdlib>
#include <iomanip>
	using std::setprecision;

#include "anualidadA.h"
#include "../menu/menu.h"

void anualidadA::calcActualVS(){

	anualidadA ActualA;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador = 1;
	float tasa;
	
	ActualA.tiempo = -1;
	ActualA.frecueM = 1;
	ActualA.capturaRenta(ActualA);
	ActualA.capturaTasa(ActualA);
	ActualA.tipoTasa(ActualA);
	
	if (ActualA.nominal)
			elegirTsaNominal( ActualA );
	
	tipoTiempo = menuTipoTiempo();
	
	if ( tipoTiempo == 1 ){
		
		do{
		
			ActualA.capturaFechas(ActualA);
			
			
		} while ( ActualA.tiempo <= 0 );
		
	}
	else if ( tipoTiempo == 2 ){
	
		do{
		
			ActualA.capturaTiempoPredeterminado( tipoPeriodo, ActualA );
			
		} while( ActualA.tiempo <= 0 );
		
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
		cout << "Para una renta de $" << ActualA.renta
			<< "\ny una Tasa de " << ActualA.tasa;
		ActualA.printTipoNominal(ActualA);
		
		if ( tipoTiempo == 1 )     
			cout << "\n\nDesde el " << ActualA.diaI << '/'
				<< ActualA.mesI << '/' << ActualA.anoI
				<< "\nHasta el " << ActualA.diaF << '/'
				<< ActualA.mesF << '/' << ActualA.anoF
				<< "Para un total de " << (ActualA.tiempo/denominador)
				<<"año(s).\n";
		else
			cout << "\nen un tiempo de " << ActualA.tiempo << " dias,";
			
			cout << setprecision(2) << fixed 
				<< "\nEl valor actual es de $";
			if ( !ActualA.nominal ){
				cout << ActualA.actualAnualidadVS(ActualA.renta,
									       (ActualA.tasa/100),
									       (ActualA.tiempo/denominador) );
			}
			else{
				cout << ActualA.actualAnualidadVS( ActualA.renta,
									        (ActualA.tasa/100) / ActualA.frecueM,
									        (ActualA.tiempo/denominador) * ActualA.frecueM );
			}
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;
				
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un renta de $" << ActualA.renta
			<< "\nuna Tasa de " << ActualA.tasa;
		ActualA.printTipoNominal(ActualA);
		cout << "\nen un tiempo de " << ActualA.tiempo << " meses,"
	     	<< "\nEl valor actual es de $";
			
			if ( !ActualA.nominal ){
				cout << ActualA.actualAnualidadVS(ActualA.renta,
									       (ActualA.tasa/100),
									       (ActualA.tiempo/denominador) );
			}
			else{
				cout << ActualA.actualAnualidadVS( ActualA.renta,
									        (ActualA.tasa/100) / ActualA.frecueM,
									        (ActualA.tiempo/denominador) * ActualA.frecueM );
			}
		
	}
	else if( tipoPeriodo == '3' ){
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para una renta de $" << ActualA.renta
			<< "\nuna Tasa de " << ActualA.tasa;
		ActualA.printTipoNominal(ActualA);
		cout << "\ny un tiempo de " << ActualA.tiempo << " año(s),"
	     	<< "\nEl valor actual es de $";
			
			if ( !ActualA.nominal ){
				cout << ActualA.actualAnualidadVS(ActualA.renta,
									         (ActualA.tasa/100),
									         (ActualA.tiempo/denominador) );
			}
			else{
				cout << ActualA.actualAnualidadVS( ActualA.renta,
									          (ActualA.tasa/100) / ActualA.frecueM,
									          (ActualA.tiempo / denominador) * ActualA.frecueM );
			}
	}
	
	cout << "\nEl valor actual es de $" << ActualA.capital;
	ActualA.denominador = denominador;
	ActualA.printAmortizacion(ActualA);
	
}

