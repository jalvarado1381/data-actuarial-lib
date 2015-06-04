#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
#include <cstdlib>
#include <iomanip>
	using std::setprecision;

#include "interesC.h"
#include "../menu/menu.h"

void interesC::calcularMontoVPC(){

	interesC MontoC;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador = 1;
	float tasa;
	
	MontoC.tiempo = -1;
	MontoC.frecueM = 1;
	MontoC.capturaMonto(MontoC);
	MontoC.capturaTasa(MontoC);
	MontoC.tipoTasa(MontoC);
	
	if (MontoC.nominal)
			elegirTsaNominal( MontoC );

	tipoTiempo = menuTipoTiempo();
	
	if ( tipoTiempo == 1 ){
		
		do{
		
			MontoC.capturaFechas(MontoC);
			
			
		} while ( MontoC.tiempo <= 0 );
		
	}
	else if ( tipoTiempo == 2 ){
	
		do{
		
			MontoC.capturaTiempoPredeterminado( tipoPeriodo, MontoC );
			
		} while( MontoC.tiempo <= 0 );
		
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
		cout << "Para un monto de $" << MontoC.monto
			<< "\ny una Tasa de " << MontoC.tasa;
		MontoC.printTipoNominal(MontoC);
		
		if ( tipoTiempo == 1 )     
			cout << "\n\nDesde el " << MontoC.diaI << '/'
				<< MontoC.mesI << '/' << MontoC.anoI
				<< "\nHasta el " << MontoC.diaF << '/'
				<< MontoC.mesF << '/' << MontoC.anoF
				<< "Para un total de " << (MontoC.tiempo/denominador)
				<<"año(s).\n";
		else
			cout << "\nen un tiempo de " << MontoC.tiempo << " dias,";
			
			cout << setprecision(2) << fixed 
				<< "\nEl capital invertido es de $";
			if ( !MontoC.nominal ){
				cout << MontoC.valorPICompuesto(MontoC.monto,
									       (MontoC.tasa/100),
									      (MontoC.tiempo/denominador) );
			}
			else{
				cout << MontoC.valorPICompuestoN( MontoC.monto,
									        (MontoC.tasa/100),
									        (MontoC.tiempo/denominador),
										   MontoC.frecueM );
			}
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;
				
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un monto de $" << MontoC.monto
			<< "\nuna Tasa de " << MontoC.tasa;
		MontoC.printTipoNominal(MontoC);
		cout << "\nen un tiempo de " << MontoC.tiempo << " meses,"
	     	<< "\nEl capital invertido es de $";
			
			if ( !MontoC.nominal ){
				cout << MontoC.valorPICompuesto( MontoC.monto,
										   (MontoC.tasa/100),
										   (MontoC.tiempo/denominador) );
			}
			else{
				cout << MontoC.valorPICompuestoN( MontoC.monto,
										  (MontoC.tasa/100),
										  (MontoC.tiempo/denominador),
										  MontoC.frecueM );
			}
		
	}
	else if( tipoPeriodo == '3' ){
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un monto de $" << MontoC.monto
			<< "\nuna Tasa de " << MontoC.tasa;
		MontoC.printTipoNominal(MontoC);
		cout << "\ny un tiempo de " << MontoC.tiempo << " año(s),"
	     	<< "\nEl capital invertido es de $";
			
			if ( !MontoC.nominal ){
				cout << MontoC.valorPICompuesto(MontoC.monto,
										  (MontoC.tasa/100),
										  (MontoC.tiempo/denominador) );
			}
			else{
				cout << MontoC.valorPICompuestoN(MontoC.monto,
										   (MontoC.tasa/100),
										   (MontoC.tiempo/denominador),
										    MontoC.frecueM);
			}
	}
	
	cout << endl << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
