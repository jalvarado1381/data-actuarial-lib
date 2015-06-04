#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
#include <cstdlib>
#include <iomanip>
	using std::setprecision;

#include "anualidadM.h"
#include "../menu/menu.h"


void anualidadM::calcPeriodosMontoVS(){

	anualidadM MontoA;
	float tiempo;
	int tipomonto;
	float denominador = 1;
	
	MontoA.frecueM = 1;
	MontoA.capturaRenta(MontoA);
	MontoA.capturaMonto(MontoA);
	MontoA.capturaTasa(MontoA);
	MontoA.tipoTasa(MontoA);
	
	if (MontoA.nominal)
			elegirTsaNominal( MontoA );
		
	if ( menuTipoInteres() == 1 ){
		system( "clear" );	
		cout << setprecision(2) << fixed
			<< "Para obtener un monto de $" << MontoA.monto << endl
			<< "con una renta de $" << MontoA.renta << endl
			<< "a una tasa del " << MontoA.tasa;
		MontoA.printTipoNominal(MontoA);
		
		cout << "\nEl tiempo(t) es de: ";
		if ( !MontoA.nominal ){
			cout << MontoA.periodosAnualidadVS( MontoA.monto,
							                MontoA.renta,
								           (MontoA.tasa/100) );
			tiempo = MontoA.periodosAnualidadVS( MontoA.monto,
							                 MontoA.renta,
								            (MontoA.tasa/100) );
		}
		else{
			cout << MontoA.periodosAnualidadVS( MontoA.monto,
										 MontoA.renta,
										 (MontoA.tasa/100)/MontoA.frecueM ) / MontoA.frecueM ;
			tiempo = MontoA.periodosAnualidadVS( MontoA.monto,
										  MontoA.renta,
										  (MontoA.tasa/100)/MontoA.frecueM ) / MontoA.frecueM ;
		}

	}
	else {
		system("clear");	
		cout << setprecision(2) << fixed
			<< "Para obtener un monto de $" << MontoA.monto << endl
			<< "con una renta de $" << MontoA.renta << endl
			<< "a una tasa del " << MontoA.tasa;
		MontoA.printTipoNominal(MontoA);
		
		cout << "\nEl tiempo(t) es de: ";
		
		if ( !MontoA.nominal ){
			cout << MontoA.periodosAnualidadVS( MontoA.monto,
							                MontoA.renta,
								           (MontoA.tasa/100) );
			tiempo = MontoA.periodosAnualidadVS( MontoA.monto,
							                 MontoA.renta,
								            (MontoA.tasa/100) );
		}
		else{
			cout << MontoA.periodosAnualidadVS( MontoA.monto,
										 MontoA.renta,
										 (MontoA.tasa/100)/MontoA.frecueM ) / MontoA.frecueM;
			tiempo = MontoA.periodosAnualidadVS( MontoA.monto,
										  MontoA.renta,
										  (MontoA.tasa/100)/MontoA.frecueM ) / MontoA.frecueM ;
		}
		
		
	}
	
	cout << " AÑOS"  << endl
			<< "\tEquivalentes a " << tiempo * 12 << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 360 << " DIAS." << endl
			<< "La cantidad de pagos, retiros o depositos\n"
			<< "que debe realizar es de: " << tiempo * MontoA.frecueM;
	
	MontoA.tiempo = tiempo;
	MontoA.denominador = denominador;
	printAcumulacion(MontoA);
	
}
