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

void menuChoferes() {
	int opcion;
	cout << "MENÚ CHOFERES" << endl;
	cout << "------------------" << endl;
	cout << "1) NUEVO CHOFER" << endl;
	cout << "2) MODIFICAR CHOFER" << endl;
	cout << "3) LISTAR CHOFER POR DNI" << endl;
	cout << "4) LISTAR TODOS LOS CHOFERES" << endl;
	cout << "5) ELIMINAR CHOFER" << endl;
	cout << "--------------------------------" << endl;
	cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
	
	cin >> opcion;
	cin.ignore();
	cls();

	switch (opcion) {
	case 1:
		if (agregarChofer() == true) {
			cout << "Se ha agregado correctamente." << endl;
		}
		else cout << "Error al crear/agregar registro." << endl;
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

void menuViajes() {
	int opcion;
	cout << "MENÚ VIAJES" << endl;
	cout << "------------------" << endl;
	cout << "1) NUEVO VIAJE" << endl;
	cout << "2) LISTAR VIAJE POR IDVIAJE" << endl;
	cout << "3) LISTAR TODOS LOS VIAJES" << endl;
	cout << "4) ELIMINAR VIAJE" << endl;;
	cout << "--------------------------------" << endl;
	cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;

	cin >> opcion;
	cin.ignore();
	cls();

	switch (opcion) {
	case 1:
		if (agregarViaje()) {
		cout << "Se ha agregado correctamente." << endl;
		}
		else cout << "Error al crear/agregar registro." << endl; // Done
		break;
	case 2:
		mostrarViaje_ID(); // Done
		break;
	case 3:
		listarViajes(); // Done 
		break;
	case 4:
		eliminarViaje(); // Done
		break;
	case 0:
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;
	}

	return;
}