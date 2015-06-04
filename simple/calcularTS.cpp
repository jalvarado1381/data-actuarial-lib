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


void interesS::calcularTiempoSimple(){

	interesS Simple;
	float tiempo;		
	int tipoInteres;
	float denominador;
	float capital;
	float tasa;	
	
	Simple.capturaValorPresente(Simple);
	Simple.capturaInteres(Simple);
	Simple.capturaTasa(Simple);		
		
	if (menuTipoInteres() == 1){
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << Simple.capital << endl
			<< "un Interes de $" << Simple.interesG << endl
			<< "a una tasa del " << Simple.tasa << "% Simple"
			<< "\nEl tiempo(t) es de: ";
		tiempo = Simple.tiempoSimple( Simple.interesG, Simple.capital,
							   ( Simple.tasa / 100 ) );
		cout << tiempo << " AÑOS"  << endl
			<< "\tEquivalentes a " << tiempo * 12  << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 365 << " DIAS." << endl;
	}
	else {
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << Simple.capital << endl
			<< "un Interes de $" << Simple.interesG << endl
			<< "a una tasa del " << Simple.tasa << "% Simple"
	     	<< "\nEl tiempo(t) es de: ";
		tiempo = Simple.tiempoSimple( Simple.interesG, Simple.capital,
							   ( Simple.tasa ) / 100 );
		cout << tiempo << " AÑOS"  << endl
			<< "\tEquivalentes a " << tiempo * 12 << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 360 << " DIAS." << endl;
	}
	
	cout << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
