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

bool agregarChofer() {

	FILE* p;
	choferes regChof;
	p = fopen("../Debug/choferes.dat", "ab");
	
	if (p == NULL) {
		cout << "Error al abrir el archivo" << endl;
		cout << "agregarChofer" << endl;
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

	return true;
}

void mostrarChoferDNI()
{
	int pos;
	char ingreso_DNI[10];
	choferes reg;
	// Pido el dni
	cout << "Ingresar el numero de DNI del chofer para mostrar: ";
	cin >> ingreso_DNI;
	// Busco la posicion del DNI
	pos = searchreg(ingreso_DNI);
	// Si no existe
	if (pos == -1)
	{
		cout << "El DNI no corresponde a ningun registro" << endl;
		// Salir
		return;
	}
	// Si existe
	if (read(&reg, pos) == false)
	{
		cout << "No se pudo leer el registro" << endl;
		// Salir
		return;
	}
	cls();
	mostrarChofer(reg);
	
}

void modificarChofer() {

	char ingreso_DNI[10], opc;
	int pos;
	choferes reg;
	cout << "Ingresar el numero de DNI a modificar: ";
	cin >> ingreso_DNI;

	// Se busca la posicion del registro con el DNI
	pos = searchreg(ingreso_DNI);
	cout << endl << endl;
	// Si no existe
	if (pos == -1)
	{
		cout << "El DNI no corresponde a un registro" << endl;
		// Salir
		return;
	}
	// Si existe pero no se puede leer el registro
	if (read(&reg, pos) == false)
	{
		cout << "No se pudo leer el registro" << endl;
		// Salir
		return;
	}
	// Existe y se pudo leer el registro
	cout << "Se encontro el siguiente registro: " << endl;
	// Se da a conocer el registro en pantalla
	mostrarChofer(reg);
	cout << endl << endl;
	// Se pregunta si se desea modificar
	cout << "Deseas modificarlo? (s/n)  ";
	cin >> opc;
	switch (opc)
	{
		// Si
	case 'S':
		// Se limpia la pantalla
		cls();
		// Se pide ingresar la nueva fecha de vencimiento
		cout << "Ingresar la nueva fecha de vencimiento" << endl; 
		cout << "Dia: ";
		cin >> reg.vencimiento.dia;
		cout << "Mes: ";
		cin >> reg.vencimiento.mes;
		cout << "Año: ";
		cin >> reg.vencimiento.año;
		// Se modifica
		if (modifyfile(reg, pos) == true)
		{
			// Verifico si se sobreescribio correctamente
			cout << "El registro se modifico correctamente" << endl;
			mostrarChofer(reg);
		}
		else
		{
			cout << "Hubo un error al modificar el registro" << endl;
		}
		break;
		
	case 's':
		// Se limpia la pantalla
		cls();
		// Se pide ingresar la nueva fecha de vencimiento
		cout << "Ingresar la nueva fecha de vencimiento" << endl;
		cout << "Dia: ";
		cin >> reg.vencimiento.dia;
		cout << "Mes: ";
		cin >> reg.vencimiento.mes;
		cout << "Año: ";
		cin >> reg.vencimiento.año;
		// Se modifica
		if (modifyfile(reg, pos) == true)
		{
			// Verifico si se sobreescribio correctamente
			cout << "El registro se modifico correctamente" << endl;
			mostrarChofer(reg);
		}
		else
		{
			cout << "Hubo un error al modificar el registro" << endl;
		}
		break;
		// No
	case 'n':
		return;
		break;
	case 'N':
		return;
		break;
		// Opcion incorrecta
	default: cout << "Opcion incorrecta." << endl;
		return;
	}
}

void listarChoferes() {
	FILE* p;
	choferes regChof;																																   

	p = fopen("../Debug/choferes.dat", "rb");
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
	cout << "FECHA DE VENCIMIENTO: " << regChof.vencimiento.dia << "/" << regChof.vencimiento.mes << "/" << regChof.vencimiento.año << endl;
	cout << endl;
	cout << "TELEFONO: " << regChof.telefono << endl;
	cout << endl;


	return;
}

void eliminarChofer() {
	choferes reg;
	char ingreso_DNI[10],opc;
	int pos;
	//Ingreso DNI
	cout << "Ingrese el DNI del chofer que desea dar de baja" << endl;
	cin >> ingreso_DNI;
	//BUSCO POS
	pos=searchreg(ingreso_DNI);
	cout << endl << endl;
	// En caso de que no exista
	if (pos == -1)
	{
		cout << "El DNI no corresponde a un registro" << endl;
		// Salir
		return;
	}
	// Si existe pero no se puede leer el registro
	if (read(&reg, pos) == false)
	{
		cout << "No se pudo leer el registro" << endl;
		// Salir
		return;
	}
	// Existe y se pudo leer el registro
	cout << "Se encontro el siguiente registro: " << endl;
	// Muestro el registro a dar de baja
	mostrarChofer(reg);
	cout << endl;
	//Estas seguro de que queres darlo de baja? 
	cout << "Deseas modificarlo? (S/n)  ";
	cin >> opc;
	switch (opc)
	{
		// Si
	case 'S':
		// Se limpia la pantalla
		cls();
		//Se da de baja
		reg.estado = false;
		if (modifyfile(reg, pos) == true)
		{
			// Verifico si se dio de baja correctamente
			cout << "El registro se dio de baja correctamente" << endl;
		}
		else
		{
			cout << "Hubo un error al dar de baja el registro" << endl;
		}
		break;

	case 's':
		// Se limpia la pantalla
		cls();
		//Se da de baja
		reg.estado = false;
		if (modifyfile(reg, pos) == true)
		{
			// Verifico si se dio de baja correctamente
			cout << "El registro se dio de baja correctamente" << endl;
		}
		else
		{
			cout << "Hubo un error al dar de baja el registro" << endl;
		}
		break;
		// No
	case 'n':
		return;
		break;
	case 'N':
		return;
		break;
		// Opcion incorrecta
	default: cout << "Opcion incorrecta." << endl;
		return;
	}


}