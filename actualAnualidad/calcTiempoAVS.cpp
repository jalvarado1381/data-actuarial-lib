#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::fixed;
#include <cstdlib>
#include <iomanip>
	using std::setprecision;

#include "anualidadA.h"
#include "../menu/menu.h"


void anualidadA::calcPeriodosMontoVS(){

	anualidadA ActualA;
	float tiempo;	
	float denominador = 1;
	
	ActualA.frecueM = 1;
	ActualA.capturaRenta(ActualA);
	ActualA.capturaValorPresente(ActualA);
	ActualA.capturaTasa(ActualA);
	ActualA.tipoTasa(ActualA);
	
	if (ActualA.nominal)
			elegirTsaNominal( ActualA );
	cout << setprecision(3) << fixed;
		
	if ( menuTipoInteres() == 1 ){
		system( "clear" );	
		cout << "Para una renta de $" << ActualA.renta << endl
			<< "un capital Actual de $" << ActualA.capital << endl
			<< "a una tasa del " << ActualA.tasa;
		ActualA.printTipoNominal(ActualA);
		
		cout << "\nEl tiempo(t) es de: ";
		if ( !ActualA.nominal ){
			cout << ActualA.periodosAnualidadVS( ActualA.capital ,
							                ActualA.renta,
								           (ActualA.tasa/100) );
			tiempo = ActualA.periodosAnualidadVS( ActualA.capital,
							                 ActualA.renta,
								            (ActualA.tasa/100) );
		}
		else{
			cout << ActualA.periodosAnualidadVS( ActualA.capital,
								           ActualA.renta,
								           (ActualA.tasa/100)/ActualA.frecueM );
			tiempo = ActualA.periodosAnualidadVS( ActualA.capital,
								           ActualA.renta,
								           (ActualA.tasa/100)/ActualA.frecueM );
		}
		
	}
	else {
		system("clear");	
		cout << "Para una renta de $" << ActualA.renta << endl
			<< "un capital Actual de $" << ActualA.capital << endl
			<< "a una tasa del " << ActualA.tasa;
		ActualA.printTipoNominal(ActualA);
		
		cout << "\nEl tiempo(t) es de: ";
		
		if ( !ActualA.nominal ){
			cout << ActualA.periodosAnualidadVS( ActualA.capital,
							                ActualA.renta,
								           (ActualA.tasa/100) );
			tiempo = ActualA.periodosAnualidadVS( ActualA.capital,
							                 ActualA.renta,
								            (ActualA.tasa/100) );
		}
		else{
			cout << ActualA.periodosAnualidadVS( ActualA.capital,
								           ActualA.renta,
								           (ActualA.tasa/100)/ActualA.frecueM ) / ActualA.frecueM;
			tiempo = ActualA.periodosAnualidadVS( ActualA.capital,
								            ActualA.renta,
								            (ActualA.tasa/100)/ActualA.frecueM ) / ActualA.frecueM;
		         }
		
	}
	
	cout << " AÑOS"  << endl
			<< "\tEquivalentes a " << tiempo * 12 << " MESES."  << endl
			<< "\tEquivalentes a " << tiempo * 360 << " DIAS." << endl
			<< "La cantidad de pagos, retiros o depositos\n"
			<< "que debe realizar es de: " << tiempo * ActualA.frecueM;
	
	ActualA.tiempo = tiempo;
	ActualA.denominador = denominador;
	ActualA.printAmortizacion( ActualA );
	
	
}
