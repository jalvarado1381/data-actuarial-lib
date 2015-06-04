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


void interesS::calcularMontoTasaS(){

	interesS MontoS;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador;
	float capital;
	float tasa;
	
	MontoS.tiempo = -1;
	MontoS.capturaValorPresente(MontoS);
	MontoS.capturaMonto(MontoS);	
	tipoTiempo = menuTipoTiempo();
	
	if ( tipoTiempo == 1 ){
		
		do{
		
			MontoS.capturaFechas(MontoS);
		
		} while ( MontoS.tiempo <= 0 );
		
	}
	else if ( tipoTiempo == 2 ){
	
		do{
		
			MontoS.capturaTiempoPredeterminado( tipoPeriodo, MontoS );
			
		} while( MontoS.tiempo <= 0 );
		
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
		cout << "Para un capital de $" << MontoS.capital
		     << "\ny un monto de $" << MontoS.monto; 
		
		if ( tipoTiempo == 1 )     
			cout << "\n\nDesde el " << MontoS.diaI << '/'
				<< MontoS.mesI << '/' << MontoS.anoI
				<< "\nHasta el " << MontoS.diaF << '/'
				<< MontoS.mesF << '/' << MontoS.anoF;
		else
			cout << "\nEquivalente a: " << MontoS.tiempo  << " dias,"
				<< endl << "Equivalente a: " << MontoS.tiempo / 30
				<< " meses."
				<< endl << "Equivalente a: " << MontoS.tiempo / 365
				<< " años."
				<< endl;
			
		cout << setprecision(2) << fixed << "\nLa Tasa (i) es de "
		     << MontoS.montoTasaSimple(MontoS.monto,MontoS.capital,
							(MontoS.tiempo/denominador) ) * 100
			<< "%";
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "\nPara que un capital de $" << MontoS.capital
			<< "\nproduzca un monto de $" << MontoS.monto
			<< "\nen un tiempo de " << MontoS.tiempo / 12 << " meses,"
	     	<< "\nLa Tasa (i) debe ser de un:"
		     << MontoS.montoTasaSimple(MontoS.monto,MontoS.capital,
							( MontoS.tiempo / 12 ) ) * 100
			<< "%" << " anual"<< endl;
		
	}
	else if(tipoPeriodo == '3'){		
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "\nPara que un capital de $" << MontoS.capital
			<< "\nproduzca un monto de $" << MontoS.monto
			<< "\nen un tiempo de " << MontoS.tiempo << " años,"
	     	<< "\nLa Tasa (i) debe ser de un: "
		     << MontoS.montoTasaSimple(MontoS.monto,MontoS.capital,
							( MontoS.tiempo/360 ) ) * 100
			<< "%" << " anual." << endl;
	}
	
	cin.ignore();
	getchar();
	
}
