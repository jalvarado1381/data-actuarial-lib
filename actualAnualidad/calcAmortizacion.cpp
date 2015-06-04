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

void anualidadA::calcAmortizacion(){

	anualidadA ActualA;
	int tipoTiempo;
	char tipoPeriodo = '1'; // 1-dias, 2-meses, 3-anos
	int tipoInteres;
	float denominador = 1;
	float renta;
	float balance;
	float interes;
	float amortizacion;
	float nPeriodo;
	
	ActualA.tiempo = -1;
	ActualA.frecueM = 1;
	ActualA.capturaValorPresente(ActualA);
	ActualA.capturaTasa(ActualA);
	ActualA.tipoTasa(ActualA);
	
	if (ActualA.nominal)
			elegirTsaNominal( ActualA );

	tipoTiempo = menuTipoTiempo();
	
	if ( tipoTiempo == 1 ){
		
		do{
		
			ActualA.capturaFechas(ActualA);
			
			
		} while ( ActualA.tiempo <= 0 );
		
	}
	else if ( tipoTiempo == 2 ){
	
		do{
		
			ActualA.capturaTiempoPredeterminado( tipoPeriodo, ActualA );
			
		} while( ActualA.tiempo <= 0 );
		
	}
	
	if ( tipoPeriodo == '1' ){
	
		tipoInteres = menuTipoInteres();
	
		if ( tipoInteres == 1 ){
		
			denominador = 365;
		
		}
		else if ( tipoInteres == 2 ){
		
			denominador = 360;
		
		}
		
			if ( !ActualA.nominal ){
				renta = ActualA.rentaAnualidadVS(ActualA.capital,
									       (ActualA.tasa/100),
									       (ActualA.tiempo/denominador) );
			}
			else{
				renta = ActualA.rentaAnualidadVS( ActualA.capital,
									        (ActualA.tasa/100) / ActualA.frecueM,
									        (ActualA.tiempo/denominador) * ActualA.frecueM );
			}
	}
	else if ( tipoPeriodo == '2' ){
	
		denominador = 12;
				
		
			
			if ( !ActualA.nominal ){
				renta = ActualA.rentaAnualidadVS(ActualA.capital,
									       (ActualA.tasa/100),
									       (ActualA.tiempo/denominador) );
			}
			else{
				renta = ActualA.rentaAnualidadVS( ActualA.capital,
									        (ActualA.tasa/100) / ActualA.frecueM,
									        (ActualA.tiempo/denominador) * ActualA.frecueM );
			}
		
	}
	else if( tipoPeriodo == '3' ){
		
		
			
			if ( !ActualA.nominal ){
				renta = ActualA.rentaAnualidadVS(ActualA.capital,
									       (ActualA.tasa/100),
									       (ActualA.tiempo/denominador) );
			}
			else{
				renta = ActualA.rentaAnualidadVS( ActualA.capital,
									        (ActualA.tasa/100) / ActualA.frecueM,
									        (ActualA.tiempo/denominador) * ActualA.frecueM );
			}
	}
	
	cout << fixed;
	ActualA.denominador = denominador;	
	ActualA.amortizacion(ActualA);
	
}

