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


void interesC::calcularMontoTasaC(){

	interesC MontoC;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador = 1;
	float capital;
	
	
	MontoC.tiempo = -1;
	MontoC.frecueM = 1;
	MontoC.capturaValorPresente(MontoC);
	MontoC.capturaMonto(MontoC);	
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
		cout << "Para un capital de $" << MontoC.capital
		     << "\ny un monto de $" << MontoC.monto; 
		
		
			cout << "\n\nDesde el " << MontoC.diaI << '/'
				<< MontoC.mesI << '/' << MontoC.anoI
				<< "\nHasta el " << MontoC.diaF << '/'
				<< MontoC.mesF << '/' << MontoC.anoF;
		
			cout << "\nEquivalente a: " << MontoC.tiempo  << " dias,"
				<< endl << "Equivalente a: " << MontoC.tiempo / 30
				<< " meses."
				<< endl << "Equivalente a: " << MontoC.tiempo / 365
				<< " años."
				<< endl;
			
		cout << setprecision(2) << fixed << "\nLa Tasa (i) es de ";
		if ( !MontoC.nominal ){
			cout << 100 * MontoC.tasaICompuesto( MontoC.monto,
								            MontoC.capital,
								            (MontoC.tiempo/denominador) );
		}
		else{
			cout << 100 * MontoC.tasaICompuestoN( MontoC.monto,
								             MontoC.capital,
								             (MontoC.tiempo/denominador),
									        MontoC.frecueM );
		}
		
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "\nPara que un capital de $" << MontoC.capital
			<< "\nproduzca un monto de $" << MontoC.monto
			<< "\nen un tiempo de " << MontoC.tiempo / 12 << " meses,"
	     	<< "\nLa Tasa (i) debe ser de un:";
			if ( !MontoC.nominal ){
				cout << 100 * MontoC.tasaICompuesto( MontoC.monto,
									            MontoC.capital,
									            (MontoC.tiempo/denominador) );
			}
			else{
				cout << 100 * MontoC.tasaICompuestoN( MontoC.monto,
									             MontoC.capital,
									             (MontoC.tiempo/denominador),
										        MontoC.frecueM );
			}
			   
		
	}
	else if(tipoPeriodo == '3'){
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "\nPara que un capital de $" << MontoC.capital
			<< "\nproduzca un monto de $" << MontoC.monto
			<< "\nen un tiempo de " << MontoC.tiempo << " años,"
	     	<< "\nLa Tasa (i) debe ser de un: ";
		     if ( !MontoC.nominal ){
				cout << 100 * MontoC.tasaICompuesto( MontoC.monto,
										       MontoC.capital,
									            (MontoC.tiempo/denominador) );
			}
			else{
				cout << 100 * MontoC.tasaICompuestoN( MontoC.monto,
									             MontoC.capital,
									             (MontoC.tiempo/denominador),
										        MontoC.frecueM );
			}
			
	}	
	MontoC.printTipoNominal(MontoC);
	
	cout << endl << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
