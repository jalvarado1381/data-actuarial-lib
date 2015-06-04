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


void interesC::calcularMontoTC(){

	interesC MontoC;
	float tiempo;
	int tipomonto;
	float denominador = 1;
	
	MontoC.frecueM = 1;
	MontoC.capturaValorPresente(MontoC);
	MontoC.capturaMonto(MontoC);
	MontoC.capturaTasa(MontoC);
	MontoC.tipoTasa(MontoC);
	
	if (MontoC.nominal)
			elegirTsaNominal( MontoC );
		
	if ( menuTipoInteres() == 1 ){
		system( "clear" );	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << MontoC.capital << endl
			<< "un monto de $" << MontoC.monto << endl
			<< "a una tasa del " << MontoC.tasa;
		MontoC.printTipoNominal(MontoC);
		
		cout << "\nEl tiempo(t) es de: ";
		if ( !MontoC.nominal ){
			cout << MontoC.tiempoICompuesto( MontoC.monto,
							             MontoC.capital,
								        MontoC.tasa/100 );
			tiempo = MontoC.tiempoICompuesto( MontoC.monto,
								         MontoC.capital,
								         MontoC.tasa/100 );
		}
		else{
			cout << MontoC.tiempoICompuestoN( MontoC.monto,
								               MontoC.capital,
								               MontoC.tasa/100,
									          MontoC.frecueM );
			tiempo = MontoC.tiempoICompuestoN( MontoC.monto,
								          MontoC.capital,
								          MontoC.tasa/100,
									     MontoC.frecueM );
		}
		cout << " AÑOS" << endl
			<< "\tEquivalentes a " << tiempo * 12  << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 365 << " DIAS." << endl;
	}
	else {
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para un capital de $" << MontoC.capital << endl
			<< "un monto de $" << MontoC.monto << endl
			<< "a una tasa del " << MontoC.tasa;
		MontoC.printTipoNominal(MontoC);
		
		cout << "\nEl tiempo(t) es de: ";
		
		if ( !MontoC.nominal ){
		
			cout << MontoC.tiempoICompuesto( MontoC.monto,
								        MontoC.capital,
								        MontoC.tasa/100 );
			tiempo = MontoC.tiempoICompuesto( MontoC.monto,
								         MontoC.capital,
								         MontoC.tasa/100 );
		}
		else{
			cout << MontoC.tiempoICompuestoN( MontoC.monto,
								         MontoC.capital,
								         MontoC.tasa/100,
									    MontoC.frecueM );
									    
			tiempo = MontoC.tiempoICompuestoN( MontoC.monto,
								          MontoC.capital,
								          MontoC.tasa/100,
									     MontoC.frecueM );
		}
		cout << " AÑOS"  << endl
			<< "\tEquivalentes a " << tiempo * 12 << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 360 << " DIAS." << endl;
	}
	
	cout << "PRESIONE <ENTER> PARA REGRESAR AL MENU...";
	cin.ignore();
	getchar();
	
}
