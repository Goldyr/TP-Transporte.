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




int main() {
	int opcion;
	setlocale(LC_CTYPE, "Spanish");
	while (true) {
		cls();
		cout << "MENÚ PRINCIPAL" << endl;
		cout << "--------------" << endl;
		cout << "1) CHOFERES" << endl;
		cout << "2) VIAJES" << endl;
		cout << "3) REPORTES" << endl;
		cout << "4) CONFIGURACION" << endl;
		cout << "----------------------" << endl;
		cout << "0) SALIR DEL PROGRAMA" << endl;
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
				break;
			case 4:
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "Opcion incorrecta. " << endl;
				system("pause");
				break;
		}
		system("pause");
	}
	
	return 0;
}