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

void menuChoferes() {
	int opcion;
	int col = columnas() / 3 + 3;
	int row = filas() / 5;
	bordes(8, FALSE);
	setlocale(LC_CTYPE, "Spanish");

	locate(col, row + 1);
	cout << "MENU CHOFERES" << endl;
	locate(col, row +3);
	cout << "1. NUEVO CHOFER" << endl;
	locate(col, row + 4);
	cout << "2. MODIFICAR CHOFER" << endl;
	locate(col, row + 5);
	cout << "3. LISTAR CHOFER POR DNI" << endl;
	locate(col, row + 6);
	cout << "4. LISTAR TODOS LOS CHOFERES" << endl;
	locate(col, row + 7);
	cout << "5. ELIMINAR CHOFER" << endl;
	locate(col, row + 8);
	cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
	locate(col, row + 10);
	cout << "INGRESAR OPCION:   ";

	hidecursor();
	cin >> opcion;
	cin.ignore();
	cls();
	showcursor();

	switch (opcion) {
	case 1:
		if (agregarChofer() == true) {
			locate(1, 12);
			cout << "Se ha agregado correctamente." << endl;
		}
		else {
			locate(1, 12);
			cout << "Error al crear/agregar registro." << endl;
		}
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
		return;
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;
	}
	system("pause");
	return;
}

void menuViajes() {
	int opcion;
	int col = columnas() / 3 + 3;
	int row = filas() / 5;
	bordes(7, FALSE);
	setlocale(LC_CTYPE, "Spanish");
	locate(col, row + 1);
	cout << "MENU VIAJES" << endl;
	locate(col, row + 3);
	cout << "1. NUEVO VIAJE" << endl;
	locate(col, row + 4);
	cout << "2. LISTAR VIAJE POR IDVIAJE" << endl;
	locate(col, row + 5);
	cout << "3. LISTAR TODOS LOS VIAJES" << endl;
	locate(col, row + 6);
	cout << "4. ELIMINAR VIAJE" << endl;;
	locate(col, row + 7);
	cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
	locate(col, row + 9);
	cout << "INGRESAR OPCION:   ";
	hidecursor();
	cin >> opcion;
	cin.ignore();
	cls();
	showcursor();
	switch (opcion) {
	case 1:
		if (agregarViaje()) {
			locate(1, 12);
		cout << "Se ha agregado correctamente." << endl;
		}
		else
		{
			locate(1, 12);
			cout << "Error al crear/agregar registro." << endl; // Done
		}
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
		return;
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;
	}
	system("pause");
	return;
}

void menuReportes() {
	int opcion;
	int col = columnas() / 3 + 3;
	int row = filas() / 5;
	bordes(6, FALSE);
	setlocale(LC_CTYPE, "Spanish");
	locate(col, row + 1);
	cout << "MENU REPORTES" << endl;
	locate(col, row + 3);
	cout << "1) REPORTE 1" << endl;
	locate(col, row + 4);
	cout << "2) REPORTE 2" << endl;
	locate(col, row + 5);
	cout << "3) REPORTE 3" << endl;
	locate(col, row + 6);
	cout << "0) VOLVER AL MENU PRINCIPAL" << endl;
	locate(col, row + 8);
	cout << "INGRESAR OPCION:   ";
	hidecursor();
	cin >> opcion;
	cin.ignore();
	cls();
	showcursor();

	switch (opcion) {
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 0:
		return;
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;

	}
	system("pause");
	return;
}

void menuConfig() {
	int opcion;
	int col = columnas() / 3 + 3;
	int row = filas() / 5;
	bordes(6, FALSE);

	setlocale(LC_CTYPE, "Spanish");
	locate(col, row + 1);
	cout << "MENU CONFIGURACION" << endl;
	locate(col, row + 3);
	cout << "1. REALIZAR BACKUP" << endl;
	locate(col, row + 4);
	cout << "2. RESTAURAR BACKUP" << endl;
	locate(col, row + 5);
	cout << "3. CARGAR DATOS DE INICIO" << endl;
	locate(col, row + 6);
	cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
	locate(col, row + 8);
	cout << "INGRESAR OPCION:   ";
	hidecursor();
	cin >> opcion;
	cin.ignore();
	cls();
	showcursor();

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
		if (cargarDInicio()) cout << "Datos de inicio cargados!" << endl;
		else cout << "Error al cargar datos de inicio" << endl;
		break;
	case 0:
		return;
		break;
	default:
		cout << "Opcion incorrecta. " << endl;
		break;

	}
	system("pause");
	return;
}