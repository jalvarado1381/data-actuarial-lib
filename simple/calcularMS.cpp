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


void interesS::calcularMontoS(){

	interesS MontoS;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador;
	float capital;
	float tasa;
	
	MontoS.tiempo = -1;
	MontoS.capturaValorPresente(MontoS);
	MontoS.capturaTasa(MontoS);
	
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
		     << "\ny una Tasa de " << MontoS.tasa << "%";
			
		if ( tipoTiempo == 1 )     
			cout << "\nDesde el " << MontoS.diaI << '/'
				<< MontoS.mesI << '/' << MontoS.anoI
				<< "\nHasta el " << MontoS.diaF << '/'
				<< MontoS.mesF << '/' << MontoS.anoF;
		else
			cout << "\nen un tiempo de " << MontoS.tiempo << " dias,";
			
		cout << setprecision(2) << fixed << "\nEl monto es de $"
		     << MontoS.montoSimple(MontoS.capital, MontoS.tasa/100,
						   (MontoS.tiempo/denominador) );
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << MontoS.capital
			<< "\ny una Tasa de " << MontoS.tasa << "%"
			<< "\ny un tiempo de " << MontoS.tiempo << " meses,"
	     	<< "\nEl monto producido es de $"
			<< MontoS.montoSimple(MontoS.capital,MontoS.tasa / 100,
						   (MontoS.tiempo/denominador) )
			<< endl;
		
	}
	else if(tipoPeriodo == '3'){		
		
		system("clear");	
		cout << setprecision(2) << fixed
			<< "\nPara un capital de $" << MontoS.capital
			<< "\ny una Tasa de " << MontoS.tasa << "%"
			<< "\ny un tiempo de " << MontoS.tiempo << " año(s),"
	     	<< "\nEl monto producido es de $"
			<< MontoS.montoSimple( MontoS.capital, MontoS.tasa / 100,
						          MontoS.tiempo )
			<< endl;
	}
	
	cout << endl << "PRESIONES <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
