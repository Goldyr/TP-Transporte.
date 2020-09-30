#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

#include "structs.h"
#include "menus.h"
#include "operaciones_registros.h"
#include "choferes.h"
#include "viajes.h"
#include "grafica.h"

int main() {

	int opcion;
	int col = columnas()/3 + 3;
	int row = filas()/5;
	
	setConsoleTitle("Empresa de viajes");

		while (true) {
		cls();
		bordes(7, FALSE);
		setlocale(LC_CTYPE, "Spanish");
		locate(col, row+1);
		cout << "MENÚ PRINCIPAL" << endl;
		locate(col, row + 3);
		cout << "1. CHOFERES" << endl;
		locate(col, row + 4);
		cout << "2. VIAJES" << endl;
		locate(col, row + 5);
		cout << "3. REPORTES" << endl;
		locate(col, row + 6);
		cout << "4. CONFIGURACION" << endl;
		locate(col, row + 7);
		cout << "0. SALIR DEL PROGRAMA" << endl;
		locate(col, row + 9);
		cout << "INGRESAR OPCION:   ";
		hidecursor();
		cin >> opcion;
		cin.ignore();
		cls();
		switch (opcion) {
			case 1:
				menuChoferes();
				break;
			case 2:
				menuViajes();
				break;
			case 3:
				menuReportes();
				break;
			case 4:
				menuConfig();
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "Opcion incorrecta. " << endl;
				system("pause");
				break;
		}
	}
	
	return 0;
}