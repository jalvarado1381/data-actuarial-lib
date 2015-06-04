#ifndef FINANCIERA
#define FINANCIERA

#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;

#include <cstdlib>
#include <cstdio>

class Financiera{

	public:
		Financiera(){}
		
		long diaI, mesI, anoI, diaF, mesF, anoF;
		
		void salir(){
			cout << endl << "PRESIONE UNA TECLA PARA CONTINUAR.";
			cin.ignore();
			getchar();
			system("clear");          
		} 
		
		//Tiempo
		float meses(float);	     
		float trimestres(float);
		float cuatrimestres(float);
		float semestres(float);
		float anos(float);
		bool  verificarFecha(int, int, int, int, int, int);
		float fechaAproximada(int, int, int, int, int, int);      

};

#endif
