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


void interesS::calcularMontoTS(){

	interesS MontoS;
	float tiempo;		
	int tipomonto;
	float denominador;
	float capital;
	float tasa;	
	
	MontoS.capturaValorPresente(MontoS);
	MontoS.capturaMonto(MontoS);
	MontoS.capturaTasa(MontoS);		
		
	if (menuTipoInteres() == 1){
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << MontoS.capital << endl
			<< "un monto de $" << MontoS.monto << endl
			<< "a una tasa del " << MontoS.tasa << "% MontoS"
			<< "\nEl tiempo(t) es de: ";
		tiempo = MontoS.montoTiempoSimple( MontoS.monto, MontoS.capital,
							   ( MontoS.tasa / 100 ) );
		cout << tiempo << " AÑOS"  << endl
			<< "\tEquivalentes a " << tiempo * 12  << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 365 << " DIAS." << endl;
	}
	else {
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << MontoS.capital << endl
			<< "un monto de $" << MontoS.monto << endl
			<< "a una tasa del " << MontoS.tasa << "% MontoS"
	     	<< "\nEl tiempo(t) es de: ";
		tiempo = MontoS.montoTiempoSimple( MontoS.monto, MontoS.capital,
							   ( MontoS.tasa ) / 100 );
		cout << tiempo << " AÑOS"  << endl
			<< "\tEquivalentes a " << tiempo * 12 << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 360 << " DIAS." << endl;
	}
	
	cout << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
