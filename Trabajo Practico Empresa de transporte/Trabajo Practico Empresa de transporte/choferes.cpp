#include <iostream>
#include <clocale> 
#include <cstdlib>
#include <cstdio>


using namespace std;
#include "rlutil.h"
#include "structs.h"
#include "menus.h"
#include "choferes.h"

bool agregarChofer() {

	FILE* p;
	choferes regChof;
	p = fopen("choferes.dat", "ab");
	
	if (p == NULL) {
		cout << "Error al abrir el archivo" << endl;
		cout << "agregarChofer" << endl;
		system("pause");
		fclose(p);
		return false;
	}
	
	cout << "Ingresar DNI: " << endl;
	cin >> regChof.DNI;


	cout << "Ingresar Nombre: " << endl;
	cin >> regChof.nombre;

	cout << "Ingresar Apellido: " << endl;
	cin >> regChof.apellido;
	
	cout << "Ingresar fecha de ingreso(dia/mes/año):" << endl;
	cin >> regChof.fechaingreso.dia;
	cin >> regChof.fechaingreso.mes;
	cin >> regChof.fechaingreso.año;
	
	cout << "Ingresar CUIT: " << endl;
	cin >> regChof.CUIT;
	do {
		cout << "Ingresar registro (1,2 o 3): " << endl;
		cin >> regChof.registro;
	} while (regChof.registro < 1 || regChof.registro>3);
	
	cout << "Ingresar fecha de vencimiento (dia,mes,año): " << endl;
	cin >> regChof.vencimiento.dia;
	cin >> regChof.vencimiento.mes;
	cin >> regChof.vencimiento.año;
	
	cout << "Ingresar numero de telefono: " << endl;
	cin >> regChof.telefono;

	regChof.propietario = true;
	regChof.estado = true;

	fwrite(&regChof, sizeof(regChof), 1, p);

	fclose(p);


	rlutil::cls();



	return true;
}



bool modificarChofer() {



	return false;
}

void listarChoferes() {
	FILE* p;
	choferes regChof;

	p = fopen("choferes.dat", "rb");
	if (p == NULL)
	{
		cout << "Error al abrir el archivo/ o no existe" << endl;
		cout << "listarChoferes" << endl;
		system("pause");
		return;
	}
	while (fread(&regChof, sizeof(choferes), 1, p)) {
		if (regChof.estado == true) {
			mostrarChofer(regChof);
			cout << "-----------FIN USUARIO-----------" << endl;
		}
	}
	system("pause");

	fclose(p);


	return;
}

void mostrarChofer(choferes regChof) {
	
	cout << "DNI: " << regChof.DNI << endl;
	cout << endl;
	cout << "NOMBRE: " << regChof.nombre << endl;
	cout << endl;
	cout << "APELLIDO: " << regChof.apellido << endl;
	cout << endl;
	cout << "FECHA DE INGRESO: " << regChof.fechaingreso.dia << "/" << regChof.fechaingreso.mes << "/" << regChof.fechaingreso.año << endl;
	cout << endl;
	cout << "CUIT: " << regChof.CUIT << endl;
	cout << endl;
	cout << "N DE REGISTRO: " << regChof.registro << endl;
	cout << endl;
	cout << "FECHA DE VENCIMIENTO" << regChof.vencimiento.dia << "/" << regChof.vencimiento.mes << "/" << regChof.vencimiento.año << endl;
	cout << endl;
	cout << "TELEFONO" << regChof.telefono << endl;
	cout << endl;


	return;
}