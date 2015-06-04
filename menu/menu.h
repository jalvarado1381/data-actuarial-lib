#include "../interes.h"

void menuPrincipal();
bool menuSimple();
bool menuMontoS();
bool menuCompuesto();
bool menuAnualidad();
bool menuAnualidadMonto();
bool menuAnualidadActual();
//bool menuAmortizacion();
//bool menuAcumulacion();

int  menuTipoInteres();
int  menuTipoTiempo();
bool seleccionarMenu(int);
bool seleccionarS(int);
bool seleccionarMS(int);
bool seleccionarC(int);
void elegirTsaNominal( interes &);
//bool seleccionarMS(char);
//bool seleccionarMC(char);
int  seleccionarTI(int);
int  seleccionarTT(int);
bool seleccionarTipoT( int, interes & );
bool seleccionarAnualidad(int);
bool seleccionarAnualidadM(int);
bool seleccionarAnualidadA(int);
