#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#include <cstring>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

#include "structs.h"
#include "menus.h"
#include "operaciones_registros.h"
#include "choferes.h"

void menuChoferes() {
	int opcion;
	cout << "MEN� CHOFERES" << endl;
	cout << "------------------" << endl;
	cout << "1) NUEVO CHOFER" << endl;
	cout << "2) MODIFICAR CHOFER" << endl;
	cout << "3) LISTAR CHOFER POR DNI" << endl;
	cout << "4) LISTAR TODOS LOS CHOFERES" << endl;
	cout << "5) ELIMINAR CHOFER" << endl;
	cout << "--------------------------------" << endl;
	cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
	
	cin >> opcion;
	cls();

	switch (opcion) {
	case 1:
		if (agregarChofer() == true) {
			cout << "Se ha agregado correctamente." << endl;
		}
		else cout << "Error al crear/agregar registro." << endl;
		system("pause");
		break;
	case 2:
		modificarChofer();
		break;
	case 3:
		mostrarChoferDNI();
		break;
	case 4:
		listarChoferes();
		break;
	case 5:
		eliminarChofer();
		break;
	case 0:
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;
	}
	return;
}
