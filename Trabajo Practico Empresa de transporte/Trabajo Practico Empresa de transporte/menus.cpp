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

void menuReportes() {
	int opcion;
	cout << "MENÚ REPORTES" << endl;
	cout << "------------------" << endl;
	cout << "1) REPORTE 1" << endl;
	cout << "2) REPORTE 2" << endl;
	cout << "3) REPORTE 3" << endl;
	cout << "--------------------------------" << endl;
	cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
	
	cin >> opcion;
	cin.ignore();
	cls();

	switch (opcion) {
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 0:
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;

	}

}

void menuConfig() {
	int opcion;
	cout << "MENÚ CONFIGURACION" << endl;
	cout << "------------------" << endl;
	cout << "1) REALIZAR BACKUP" << endl;
	cout << "2) RESTAURAR BACKUP" << endl;
	cout << "3) CARGAR DATOS DE INICIO" << endl;
	cout << "--------------------------------" << endl;
	cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;

	cin >> opcion;
	cin.ignore();
	cls();

	switch (opcion) {
	case 1:
		if (backupFiles() == true) {
			cout << "Se ha generado la copia de seguridad con exito" << endl;

		}
		else {
			cout << "Error al generar la copia de seguridad " << endl;
		}
		break;
	case 2:
		if (restaurarFiles() == true) {
			cout << "Se ha restaurado con exito" << endl;
		}
		else {
			cout << "Error al restaurar" << endl;
		}
		break;
	case 3:
		break;
	case 0:
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;

	}

}