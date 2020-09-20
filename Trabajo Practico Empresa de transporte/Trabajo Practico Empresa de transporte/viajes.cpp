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



bool agregarViaje(){

	viajes regViaj;

	//Ingresar datos
	//TODO: FALTA VALIDAR TODO
	cout << "Ingresar ID del viaje " << endl;
	cin >> regViaj.IDViaje;

	cout << "Ingresar el DNI del chofer" << endl;
	cin >> regViaj.DNI_Chofer;

	cout << "Ingresar el ID del cliente" << endl;
	cin >> regViaj.IDCliente;

	cout << "Ingresar fecha del viaje (dia/mes/año)" << endl;
	cin >> regViaj.fechaviaje.dia;
	cin >> regViaj.fechaviaje.dia;
	cin >> regViaj.fechaviaje.año;

	cout << "Ingresar hora de salida " << endl;
	cin >> regViaj.horasalida;

	cout << "Ingresar Kilometraje " << endl;
	cin >> regViaj.kilometraje;

	cout << "Ingresar Importe " << endl;
	cin >> regViaj.importe;

	cout << "Ingresar patente" << endl;
	cin >> regViaj.patente;

	cout << "Ingresar calificacion" << endl;
	cin >> regViaj.calificacion;

	regViaj.estado = true;

	//Guarda registro
	guardarRegistro(regViaj, ARCHIVO_VIAJES);
		

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
			cout << "-----------FIN USUARIO-----------" << endl;
		}
	}
	system("pause");
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