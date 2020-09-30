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
#include "grafica.h"


bool agregarViaje() {

	bordes(0, TRUE);
	int col = columnas();
	int row = filas();

	int newc = col / 3; // X
	int newr = row / 5;	// Y

	newc = col - (col - 2);

	setColor(CYAN);
	locate(newc + 1, newr + 1);
	cout << "DNI CHOFER";
	locate(newc + 15, newr + 1);
	cout << "ID CLIENTE";
	locate(newc + 27, newr + 1);
	cout << "FECHA VIAJE";
	locate(newc + 40, newr + 1);
	cout << "HORA SALIDA";
	locate(newc + 54, newr + 1);
	cout << "KM";
	locate(newc + 62, newr + 1);
	cout << "IMPORTE";
	locate(newc + 70, newr + 1);
	cout << "PATENTE";
	locate(newc + 85, newr + 1);
	cout << "CALIFICACION";
	setColor(WHITE);
	// FIN DE DECLARACIONES PARA LA PARTE GRAFICA
	setlocale(LC_ALL, "C");
	int k = 0;
	for (int i = 0; i < col - 5; i++)
	{
		k++;
		locate(newc + k, newr + 2);
		cout << (char)205;
	}


	setlocale(LC_ALL, "Spanish");

	viajes regViaj;

	//Ingresar datos

	do
	{
		locate(newc + 1, newr + 3);
		cout << "            ";
		locate(newc + 1, newr + 3);
		cin >> regViaj.DNI_Chofer;
	}
	// Verificacion
	while (searchreg_ch(regViaj.DNI_Chofer, DNI) == -1);

	
	locate(newc + 15, newr + 3);
	cin >> regViaj.IDCliente;

	do
	{
		locate(newc + 27, newr + 3);
		cout << "            ";
		locate(newc + 27, newr + 3);
		cin >> regViaj.fechaviaje.dia;
		locate(newc + 29, newr + 3);
		cout << "/";
		locate(newc + 30, newr + 3);
		cin >> regViaj.fechaviaje.mes;
		locate(newc + 32, newr + 3);
		cout << "/";
		locate(newc + 33, newr + 3);
		cin >> regViaj.fechaviaje.anio;
	}
	// Verificacion
	while (fechacmp(regViaj.fechaviaje.dia, regViaj.fechaviaje.mes, regViaj.fechaviaje.anio, MENOR) == -1);

	do
	{
		locate(newc + 40, newr + 3);
		cout << "       ";
		locate(newc + 40, newr + 3);
		cin >> regViaj.horasalida;
	} while (regViaj.horasalida < 0 || regViaj.horasalida >23);

	do
	{
		locate(newc + 54, newr + 3);
		cout << "      ";
		locate(newc + 54, newr + 3);
		cin >> regViaj.kilometraje;
	} while (regViaj.kilometraje <= 0);

	do
	{
		locate(newc + 62, newr + 3);
		cout << "          ";
		locate(newc + 62, newr + 3);
		cin >> regViaj.importe;
	} while (regViaj.importe <= 0);

	cin.ignore();

	do
	{
		locate(newc + 70, newr + 3);
		cout << "          ";
		locate(newc + 70, newr + 3);
		cargarChar(regViaj.patente, 10);
	} while (isEmpty(regViaj.patente, 10) == true);

	do
	{
		locate(newc + 85, newr + 3);
		cout << "   ";
		locate(newc + 85, newr + 3);
		cin >> regViaj.calificacion;
	} while (regViaj.calificacion < 0 || regViaj.calificacion>5);

	regViaj.estado = true;

	

	//Esto es para la autonumeracion del ID de viaje, basicamente cuenta los registros y le asigna ese valor a el ID
	regViaj.IDViaje = contar_registros();
	if (regViaj.IDViaje == -1) regViaj.IDViaje += 1;

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
	int pos = 1;

	titulosListadoViajes();
	while (fread(&regViaj, sizeof(viajes), 1, p)) {
		if (regViaj.estado == true) {
			mostrarViaje(regViaj,pos);
			pos++;
		}
	}
	fclose(p);
	return;

}
void mostrarViaje(viajes regViaj, int pos) {
	pos ++;
	gotoxy(1,pos);cout << regViaj.IDViaje;
	gotoxy(10,pos);cout <<  regViaj.DNI_Chofer;
	gotoxy(25,pos);cout << regViaj.IDCliente;
	gotoxy(40,pos);cout << regViaj.fechaviaje.dia << "/" << regViaj.fechaviaje.mes << "/" << regViaj.fechaviaje.anio;
	gotoxy(55,pos);cout << regViaj.horasalida;
	gotoxy(70,pos);cout << regViaj.kilometraje;
	gotoxy(80,pos);cout << regViaj.importe;
	gotoxy(90,pos);cout << regViaj.patente;
	gotoxy(100,pos);cout << regViaj.calificacion;
	cout << endl;
}

void titulosListadoViajes() {
	system("cls");
	gotoxy(1, 1); cout << "ID VIAJE";
	gotoxy(10, 1); cout << "DNI";
	gotoxy(25, 1); cout << "ID CLIENTE";
	gotoxy(40, 1); cout << "FECHA VIAJ";
	gotoxy(55, 1); cout << "HORA SALIDA";
	gotoxy(70, 1); cout << "KM";
	gotoxy(80, 1); cout << "IMPORTE";
	gotoxy(90, 1); cout << "PATENTE";
	gotoxy(100, 1); cout << "CALIFICACION";
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

	mostrarViaje(regViaje,5);

	cout << endl;

	cout << "Desea darlo de baja? (S/n) " << endl;

	cin >> opc;
	
	switch (opc)
	{
	case 's':
		break;
	case 'S':	
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
	cls();
	regViaje.estado = false;

	if (modificar_viaje(regViaje, pos) == false)
	{
		cout << "Error al modificar el registro" << endl;
		return;
	}
	cout << "El registro se dio de baja correctamente" << endl;

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
		return;
	}
	if (leer_viajes(&viajeReg, pos) == false)
	{
		cout << "Error al leer el registro de viajes" << endl;
	}
	cls();
	titulosListadoViajes();
	mostrarViaje(viajeReg,2);
}

