#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale> 

using namespace std;
#include "rlutil.h"
#include "structs.h"
#include "menus.h"
#include "choferes.h"

int main() {
	int opcion;
	setlocale(LC_CTYPE, "Spanish");
	while (true) {
		cout << "MENÚ PRINCIPAL" << endl;
		cout << "--------------" << endl;
		cout << "1) CHOFERES" << endl;
		cout << "2) VIAJES" << endl;
		cout << "3) REPORTES" << endl;
		cout << "4) CONFIGURACION" << endl;
		cout << "----------------------" << endl;
		cout << "0) SALIR DEL PROGRAMA" << endl;
		cin >> opcion;

		switch (opcion) {
			case 1:
				rlutil::cls();
				menuChoferes();
				break;
			case 2:
				
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
		rlutil::cls();
	}
	



	return 0;
}