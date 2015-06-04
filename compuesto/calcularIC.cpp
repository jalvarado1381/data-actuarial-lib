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


void interesC::calcularIC(){

	interesC Compuesto;	
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador = 1;
	float capital;
	float tasa;
	
	Compuesto.tiempo = -1;
	Compuesto.frecueM = 1;
	Compuesto.capturaValorPresente(Compuesto);
	Compuesto.capturaTasa(Compuesto);
	Compuesto.tipoTasa(Compuesto);
	
	if (Compuesto.nominal)
			elegirTsaNominal( Compuesto );
	
	
	tipoTiempo = menuTipoTiempo();
	
	if ( tipoTiempo == 1 ){
		
		do{
		
			Compuesto.capturaFechas(Compuesto);
		
		} while ( Compuesto.tiempo <= 0 );
		
	}
	else if ( tipoTiempo == 2 ){
	
		do{
		
			Compuesto.capturaTiempoPredeterminado( tipoPeriodo, Compuesto );
			
		} while( Compuesto.tiempo <= 0 );
		
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
		cout << "\nPara un capital de $" << Compuesto.capital
		     << "\ny una Tasa de " << Compuesto.tasa;
		Compuesto.printTipoNominal(Compuesto);
			
		if ( tipoTiempo == 1 )     
			cout << "\nDesde el " << Compuesto.diaI << '/'
				<< Compuesto.mesI << '/' << Compuesto.anoI
				<< "\nHasta el " << Compuesto.diaF << '/'
				<< Compuesto.mesF << '/' << Compuesto.anoF;
		else
			cout << "\nen un tiempo de " << Compuesto.tiempo 
				<< " dias,";
				
			cout << setprecision(2) << fixed << "\nEl interes es de $";
				
			if ( !Compuesto.nominal ){
				cout << Compuesto.interesCompuesto(Compuesto.capital,
										     (Compuesto.tasa/100),
										     (Compuesto.tiempo/denominador) );
			}
			else{
				cout << Compuesto.interesCompuestoN(Compuesto.capital,
										      (Compuesto.tasa/100),
										      (Compuesto.tiempo/denominador),
											 Compuesto.frecueM );
			}
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << Compuesto.capital
			<< "\ny una Tasa de " << Compuesto.tasa;
		Compuesto.printTipoNominal(Compuesto);
			
		cout << "\ny un tiempo de " << Compuesto.tiempo << " meses,"
	     	<< "\nEl interes producido es de $";
			if ( !Compuesto.nominal ){
				cout << Compuesto.interesCompuesto(Compuesto.capital,
										     (Compuesto.tasa/100),
										     (Compuesto.tiempo/denominador) );
			}
			else{
				cout << Compuesto.interesCompuestoN(Compuesto.capital,
										      (Compuesto.tasa/100),
										      (Compuesto.tiempo/denominador),
											 Compuesto.frecueM);
			}
		
	}
	else if(tipoPeriodo == '3'){		
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "\nPara un capital de $" << Compuesto.capital
			<< "\ny una Tasa de " << Compuesto.tasa;
		Compuesto.printTipoNominal(Compuesto);
		
		cout << "\ny un tiempo de " << Compuesto.tiempo << " año(s),"
			<< "\nEl interes compuesto producido es de $";
			if ( !Compuesto.nominal ){
				cout << Compuesto.interesCompuesto(Compuesto.capital,
										     (Compuesto.tasa/100),
										     (Compuesto.tiempo/denominador) );
			}
			else{
				cout << Compuesto.interesCompuestoN(Compuesto.capital,
										      (Compuesto.tasa/100),
										      (Compuesto.tiempo/denominador),
											  Compuesto.frecueM );
			}
	}
	
	cout << endl << "PRESIONES <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
