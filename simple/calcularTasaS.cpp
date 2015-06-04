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


void interesS::calcularTasaSimple(){

	interesS Simple;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador;
	float capital;
	float tasa;
	
	Simple.tiempo = -1;
	Simple.capturaValorPresente(Simple);
	Simple.capturaInteres(Simple);
	
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
		cout << "Para un capital de $" << Simple.capital
		     << "\ny un Interes de $" << Simple.interesG; 
		
		if ( tipoTiempo == 1 )     
			cout << "\n\nDesde el " << Simple.diaI << '/'
				<< Simple.mesI << '/' << Simple.anoI
				<< "\nHasta el " << Simple.diaF << '/'
				<< Simple.mesF << '/' << Simple.anoF;
		else
			cout << "\nEquivalente a: " << Simple.tiempo  << " dias,"
				<< endl << "Equivalente a: " << Simple.tiempo / 30
				<< " meses."
				<< endl << "Equivalente a: " << Simple.tiempo / 365
				<< " años."
				<< endl;
			
		cout << setprecision(2) << fixed << "\nLa Tasa (i) es de "
		     << Simple.tasaSimple(Simple.interesG,Simple.capital,
							(Simple.tiempo/denominador) ) * 100
			<< "%";
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << Simple.capital
			<< "\ny un Interes de $" << Simple.interesG
			<< "\nen un tiempo de " << Simple.tiempo / 12 << " meses,"
	     	<< "\nLa Tasa (i) es de "
		     << Simple.tasaSimple(Simple.interesG,Simple.capital,
							( Simple.tiempo / 12 ) ) * 100
			<< "%" << endl;
		
	}
	else if(tipoPeriodo == '3'){		
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << Simple.capital
			<< " y un Interes de $" << Simple.interesG
			<< "en un tiempo de " << Simple.tiempo << " meses,"
	     	<< "\nLa Tasa (i) es de "
		     << Simple.tasaSimple(Simple.interesG,Simple.capital,
							( Simple.tiempo/360 ) ) * 100
			<< "%" << endl;
	}
	
	cin.ignore();
	getchar();
	
}
