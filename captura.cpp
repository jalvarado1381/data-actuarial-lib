#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
	using std::ios;
#include <cstdlib>
#include <string>
	using std::string;
#include <sstream>
	using std::ostringstream;
#include <fstream>
	using std::ofstream;
#include <cctype>

#include "interes.h"

void interes::capturaFechas(interes &Captura){

	system("clear");
	
	cout << "\nCAPTURA FECHAS.\n\n";
	cout << "FECHA FINAL   ( DD MM AAAA) ( 99 99 9999) : ";
	Captura.diaF = (long) asignarValor();
	Captura.mesF = (long) asignarValor();
	Captura.anoF = (long) asignarValor();
	
	cout << "FECHA INICIAL ( DD MM AAAA) ( 99 99 9999) : ";
	Captura.diaI = (long) asignarValor();
	Captura.mesI = (long) asignarValor();
	Captura.anoI = (long) asignarValor();
	
	Captura.tiempo = Captura.fechaAproximada(Captura.diaI, Captura.mesI, 
									  Captura.anoI, Captura.diaF,
									  Captura.mesF,Captura.anoF);

}

void interes::capturaTiempoPredeterminado(char &opcion, interes &Captura ){
	
	system("clear");
	
	trazarLinea(20);
	cout << "\nCAPTURA TIEMPO\n";
	trazarLinea(20);
	cout << "\n1 - DIAS.\n" 
		<< "2 - MESES.\n"
		<< "3 - AÑOS. \n";
	trazarLinea(20);
	cout << "\nSELECCIONE UNA OPCION: ";
	cin.ignore();
	cin >> opcion;
	
	if (opcion == '1'){	
		cout << "Introduzca la cantidad de Dias: ";
		Captura.tiempo = asignarValor();	
	}
	else if (opcion == '2'){	
		cout << "Introduzca la cantidad de meses: ";
		Captura.tiempo = asignarValor();		
	}
	else if (opcion == '3'){	
		cout << "Introduzca la cantidad de años: ";
		Captura.tiempo = asignarValor();
	}
	
}

void interes::capturaValorPresente( interes &Captura ){
	
	cout << "Introduzca el Valor Presente(p): ";
	Captura.capital = asignarValor();	
	
}

void interes::capturaTasa(interes &Captura){
	
	cout << "Introduzca la tasa (i) (0% - 100%): ";
	Captura.tasa = asignarValor();
	
}

void interes::capturaInteres(interes &Captura){
	
	cout << "Introduzca el interes (I): ";
	Captura.interesG = asignarValor();
	
}

void interes::capturaMonto(interes &Captura){	
	
	cout << "Introduzca el Monto: ";
	Captura.monto = asignarValor();
	
}

void interes::capturaRenta(interes &Captura){	
	
	cout << "Introduzca el Renta: ";
	Captura.renta = asignarValor();
	
}

float interes::asignarValor(){
	
	string valor;
	
	do {
			cin.ignore();
			cin >> valor;
			if ( esNumerico(valor) == true)
				return atof( valor.data() );
			else 
				cout << "ERROR: Este no es un verdadero valor númerico."
					<< "\nIntente de nuevo: ";
	}while( !esNumerico( valor ) );

}

bool interes::esNumerico( string sNumero ){

	bool digito = true;
	int punto = 0;
	
	for( int i = 0; i < sNumero.length(); i++ ){
		if ( isdigit( sNumero[i] ) ){}			
		else if ( sNumero[i] == '.' ){
			++punto;
			if ( punto == 2 ){
				digito = false;
				break;
			}
		}
		else {
			digito = false;
		}
	}
	
	return digito;
}

bool interes::tipoTasa(interes &tipo){

	char opcion;
	do{
		system("clear");
		cout << "Esta usando tasa nominal? (S/N): ";
		cin >> opcion;
		if ( opcion == 's' || opcion == 'S' )
			tipo.nominal = true;
		else if ( opcion == 'n' || opcion == 'N')
			tipo.nominal = false;
		else {
			cout << "\nOPCION ERRONEA PRESIONE <ENTER> E INTENTE DE NUEVO.";
			opcion = '0';
			getchar();
		}
	}while(opcion == '0');

}

void interes::printTipoNominal( interes &nominal){
	if (nominal.nominal){
			cout << "% nominal";
			if(nominal.frecueM == 12)
				cout << " mensual.";
			if(nominal.frecueM == 2)
				cout << " semestral.";
			if(nominal.frecueM == 4)
				cout << " trimestral.";
			if(nominal.frecueM == 3)
				cout << " cuatrimestral.";
			if(nominal.frecueM == 52)
				cout << " semanal.";
			if(nominal.frecueM == 24)
				cout << " quincenal.";
		}else {
			cout << " % anual.";
		}
}

		
void interes::trazarLinea( int tam ){

	for ( int i = 0; i < tam; i++)
		cout << '*';

}

void interes::guardarFile( string OutString ){

	string fileName;

	cout << "\nESCRIBA EL NOMBRE DEL ARCHIVO: ";
	cin >> fileName;
	
	ofstream OutFile( fileName.c_str(), ios::out );
	if( !OutFile ){
		cout << "\nNO SE PUDO ABRIR EL ARCHIVO.\n";
		exit(1);
	}
	else {
		OutFile << OutString;
		cout <<"EL ARCHIVO HA SIDO GUARDADO.\n"
			<<"PARA VER EL CONTENIDO DE ESTE, ABRALO\n"
			<<"CON UN EDITOR DE TEXTO (VI, KATE, ETC...).\n";
		trazarLinea(25);
		cout << "\nPRESIONE <ENTER> PARA CONTINUAR.\n";			
	}
	OutFile.close();
	cin.ignore();
	getchar();
}
