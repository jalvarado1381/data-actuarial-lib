#include <iostream>
		using std::cout;
#include <cstdlib>

#include "financiera.h"

bool Financiera::verificarFecha(int diaI, int mesI, int anoI, 
                           int diaF, int mesF, int anoF){
     
	if ( diaI > 31 || diaF > 31){
		cout << "ERROR: Los dias no pueden ser mayores de 31."; 
		return true;       
	}
	else if ( diaI <= 0 || diaF <= 0){
		cout << "ERROR: Los dias no pueden ser menores o igual a CERO.";
		return true;        
	}     
     
	if ( mesI > 12 || mesF > 12){
		cout << "ERROR: Los meses no pueden ser mayores de 12.";
		return true;        
	}
	else if ( mesI <= 0 || mesF <= 0){
		cout << "ERROR: Los meses no pueden ser menores o igual CERO.";  
		return true;      
	}    

	if(anoF < anoI){
		cout << "ERROR: El ano inicial no puede ser mayor que ano final.";
		return true;     
	}
	else if (anoF == anoI && mesF < mesI ){
		cout << "ERROR: En un mismo ano, el mes final no puede "  
			<< "\nser menor que el mes inicial.";
		return true;
	}
	else if (anoF == anoI && mesF == mesI && diaF < diaI ){
		cout << "ERROR: En un mismo ano y mes, el dia final no puede "  
			<< "\nser menor que el dia inicial.";
		return true;
	}
	
	return false;
}

float Financiera::fechaAproximada(int diaI, int mesI, int anoI, 
                           int diaF, int mesF, int anoF){
	int diaT;
	int mesT;
	int anoT; 
	int tiempoT;    
     
	if (verificarFecha(diaI, mesI, anoI, diaF, mesF, anoF)){
                              
		salir();
		return -1;
		
	}
	else{
           
		if ( diaF < diaI){
			diaF += 30;
			mesF--;
			diaT = diaF - diaI;
		}
		else{
			diaT = diaF - diaI;
		}
                
		if ( mesF < mesI){
			mesF += 12;
			anoF--;
			mesT = mesF - mesI; 
		}
		else{
			mesT = mesF - mesI;
		}

		anoT = anoF - anoI;
	}
     
	tiempoT = diaT + ( mesT * 30 ) + (anoT * 360);
	
	return tiempoT;

}
