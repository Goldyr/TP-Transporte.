#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale> 
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;
using namespace rlutil;


const char* ARCHIVO_VIAJES = "../Debug/viajes.dat";

#include "structs.h"
#include "menus.h"
#include "operaciones_registros.h"
#include "choferes.h"
#include "viajes.h"



bool agregarViaje() {

	viajes regViaj;

	//Ingresar datos
	//TODO: FALTA HACER QUE EL ID VIAJE SEA AUTONUMERICO
	cout << "Ingresar ID del viaje " << endl;
	cin >> regViaj.IDViaje;

	do
	{
		cout << "Ingresar el DNI del chofer" << endl;
		cin >> regViaj.DNI_Chofer;
	}
	// Verificacion
	while (searchreg_ch(regViaj.DNI_Chofer, DNI) == -1);

	cout << "Ingresar el ID del cliente" << endl;
	cin >> regViaj.IDCliente;

	do
	{
		cout << "Ingresar fecha del viaje (dia/mes/año)" << endl;
		cin >> regViaj.fechaviaje.dia;
		cin >> regViaj.fechaviaje.mes;
		cin >> regViaj.fechaviaje.año;
	}
	// Verificacion
	while (fechacmp(regViaj.fechaviaje.dia, regViaj.fechaviaje.mes, regViaj.fechaviaje.año, MENOR) == -1);

	do
	{
		cout << "Ingresar hora de salida " << endl;
		cin >> regViaj.horasalida;
	} while (regViaj.horasalida < 0 || regViaj.horasalida >23);

	do
	{
		cout << "Ingresar Kilometraje " << endl;
		cin >> regViaj.kilometraje;
	} while (regViaj.kilometraje <= 0);

	do
	{
		cout << "Ingresar Importe " << endl;
		cin >> regViaj.importe;
	} while (regViaj.importe <= 0);

	cin.ignore();

	do
	{
		cout << "Ingresar patente" << endl;
		cargarChar(regViaj.patente, 10);
	} while (isEmpty(regViaj.patente, 10) == true);

	do
	{
		cout << "Ingresar calificacion" << endl;
		cin >> regViaj.calificacion;
	} while (regViaj.calificacion < 0 || regViaj.calificacion>5);

	regViaj.estado = true;

	//Guarda registro
	guardar_viajes(regViaj, ARCHIVO_VIAJES);
		

	return true;
}
void listarViajes() {
	viajes regViaj;
	FILE* p;
	p = fopen(ARCHIVO_VIAJES, "rb");
	if (p == NULL)
	{
		cout << "Error al abrir el archivo/ o no existe" << endl;
		cout << "listarViajes" << endl;
		system("pause");
		return;
	}
	while (fread(&regViaj, sizeof(viajes), 1, p)) {
		if (regViaj.estado == true) {
			mostrarViaje(regViaj);
			cout << "-----------FIN VIAJE----------" << endl;
		}
	}
	fclose(p);
	return;

}
void mostrarViaje(viajes regViaj) {
	cout << "ID del viaje " << endl;
	cout << regViaj.IDViaje<< endl;

	cout << "DNI del chofer" << endl;
	cout << regViaj.DNI_Chofer<< endl;

	cout << "ID del cliente" << endl;
	cout << regViaj.IDCliente<< endl;

	cout << "Fecha del viaje (dia/mes/año)" << endl;
	cout << regViaj.fechaviaje.dia<< endl;
	cout << regViaj.fechaviaje.dia<< endl;
	cout << regViaj.fechaviaje.año<< endl;

	cout << "Hora de salida " << endl;
	cout << regViaj.horasalida<< endl;

	cout << "Kilometraje " << endl;
	cout << regViaj.kilometraje<< endl;

	cout << "Importe " << endl;
	cout << regViaj.importe<< endl;

	cout << "Patente" << endl;
	cout << regViaj.patente<< endl;

	cout << "Calificacion" << endl;
	cout << regViaj.calificacion<< endl;


}

void eliminarViaje()
{
	// Basicamente copy paste del eliminarChoferes
	viajes regViaje;
	int id, pos;
	char opc;
	cout << "Ingresa el ID del viaje para dar de baja" << endl;
	cin >> id;
	pos = searchreg_viajes(id);
	if (pos == -1)
	{
		cout << "El ID ingresado no existe, ingrese otro" << endl;
		return;
	}
	if (leer_viajes(&regViaje, pos) == false)
	{
		cout << "Error al leer el archivo de viajes" << endl;
		return;
	}
	cout << endl;

	cout << "Se encontro el siguiente registro: " << endl;

	mostrarViaje(regViaje);

	cout << endl;

	cout << "Desea darlo de baja? (S/n) " << endl;

	cin >> opc;
	
	switch (opc)
	{
	case 's':
		cls();
		regViaje.estado = false;

		if (modificar_viaje(regViaje, pos) == false)
		{
			cout << "Error al modificar el registro" << endl;
			return;
		}
		cout << "El registro se dio de baja correctamente" << endl;
		break;
	case 'S':
		cls();
		regViaje.estado = false;

		if (modificar_viaje(regViaje, pos) == false)
		{
			cout << "Error al modificar el registro" << endl;
			return;
		}
		cout << "El registro se dio de baja correctamente" << endl;
		break;
	case 'n':
		return;
		break;
	case 'N':
		return;
		break;
	default:
		cout << "Opcion incorrecta" << endl;
		return;
	}


}

void mostrarViaje_ID()
{
	int id, pos;
	viajes viajeReg;
	cout << "Ingrese el ID del viaje" << endl;
	cin >> id;
	pos = searchreg_viajes(id);
	if (pos == -1)
	{
		cout << "No se encontro el ID, ingrese otro" << endl;
	}
	if (leer_viajes(&viajeReg, pos) == false)
	{
		cout << "Error al leer el registro de viajes" << endl;
	}
	cls();
	mostrarViaje(viajeReg);
}