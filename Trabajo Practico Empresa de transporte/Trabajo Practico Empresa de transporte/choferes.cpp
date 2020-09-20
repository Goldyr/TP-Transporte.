#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale> 
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;
using namespace rlutil;


const char* ARCHIVO_CHOFERES = "../Debug/choferes.dat";

#include "structs.h"
#include "menus.h"
#include "operaciones_registros.h"
#include "choferes.h"
#include "viajes.h"



bool agregarChofer() {
	choferes regChof;
	
	// 1. Ingreso DNI
	do
	{	
		cout << "Ingresar DNI: " << endl;
		cargarChar(regChof.DNI, 10);

	}
	//
	// Validacion
	//
	// 1. No este vacio el array tipo char
	// 2. El DNI es unico en el archivo
	while (isEmpty(regChof.DNI, 10) == true || searchreg(regChof.DNI, BUSCAR_REGISTRO::DNI) != -1);
	

	// 2. Ingreso Nombre
	do
	{
		cout << "Ingresar Nombre: " << endl;
		cargarChar(regChof.nombre, 50);
	}
	//
	// Validacion
	//
	while (isEmpty(regChof.nombre, 50) == true);

	// 3. Ingreso Apellido
	do
	{
		cout << "Ingresar Apellido: " << endl;
		cargarChar(regChof.apellido, 50);

	}
	//
	// Validacion
	//
	while (isEmpty(regChof.apellido, 50) == true);

	// 4. Ingreso de fecha de ingreso
	do
	{

		cout << "Ingresar fecha de ingreso(dia/mes/año):" << endl;
		cin >> regChof.fechaingreso.dia;
		cin >> regChof.fechaingreso.mes;
		cin >> regChof.fechaingreso.año;
	}	while (fechacmp(regChof.fechaingreso.dia, regChof.fechaingreso.mes, regChof.fechaingreso.año, FECHAS::MENOR) == -1);

	cin.ignore();
	// 5. Ingreso de CUIT

	do
	{
		cout << "Ingresar CUIT: " << endl;
		cargarChar(regChof.CUIT, 20);
	}
	//
	// Validacion
	// 
	while (isEmpty(regChof.CUIT, 20) == true || searchreg(regChof.CUIT, BUSCAR_REGISTRO::CUIT) != -1);


	do {
		cout << "Ingresar registro (1,2 o 3): " << endl;
		cin >> regChof.registro;
	} while (regChof.registro < 1 || regChof.registro>3);
	

	do
	{

		cout << "Ingresar fecha de vencimiento(dia/mes/año):" << endl;
		cin >> regChof.vencimiento.dia;
		cin >> regChof.vencimiento.mes;
		cin >> regChof.vencimiento.año;
	} while (fechacmp(regChof.vencimiento.dia, regChof.vencimiento.mes, regChof.vencimiento.año, FECHAS::VENCIMIENTO) == -1);

	


	cout << "Ingresar numero de telefono: " << endl;
	cin >> regChof.telefono;

	regChof.propietario = true;
	regChof.estado = true;
	
	guardarRegistro(regChof,ARCHIVO_CHOFERES);
	
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
	pos = searchreg(ingreso_DNI, BUSCAR_REGISTRO::DNI);
	pos = searchreg(ingreso_DNI, BUSCAR_REGISTRO::DNI);
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
	pos = searchreg(ingreso_DNI, BUSCAR_REGISTRO::DNI);
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
		cout << "año: ";
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
		cout << "año: ";
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

bool isEmpty(char* p, int tam)
{
	// C cuenta cuantos vacíos hay
	int c = 0;
	for (int i = 0; i < tam; i++)
	{
			// Si en la primera o segunda posicion hay un 0, esta vacia
			if (p[0] == NULL || p[1] == NULL) return true;
			// Tambien cuenta los espacios
			if (p[i] == 32) c++;
		
	}
	// Si se contaron 2 o mas, se cuenta como una cadena vacia
	if (c >= 2)return true;
	return false;
}

void eliminarChofer() {
	choferes reg;
	char ingreso_DNI[10],opc;
	int pos;
	//Ingreso DNI
	cout << "Ingrese el DNI del chofer que desea dar de baja" << endl;
	cin >> ingreso_DNI;
	//BUSCO POS
	pos=searchreg(ingreso_DNI, BUSCAR_REGISTRO::DNI);
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
	cout << "Deseas darlo de baja? (S/n)  ";
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

void cargarChar(char* p, int tam)
{
	int i;
	fflush(stdin);
	for (i = 0; i < 10; i++)
	{
		p[i] = cin.get();
		if (p[i] == '\n') break;
	}
	p[i] = '\0';
	fflush(stdin);
}

int fechacmp(int c_dia, int c_mes, int c_año, FECHAS opcion)
{
	// Declaracion de variables de ctime
	int mes, dia, año;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	año = 1900 + ltm->tm_year;
	mes = 1 + ltm->tm_mon;
	dia = ltm->tm_mday;
	// Swtich de enum de opcion
	switch (opcion)
	{
	// La fecha a comparar tiene que ser menor a la del sistema
	case MENOR:
		// Pregunto si el año para comparar es mayor
		if (c_año > año)
		{
			return -1;
		}
		// Si es el mismo año pregunto si el mes es mayor
		if (c_año == año)
		{
			if (c_mes > mes) return -1;
		}
		// Si es el mismo año y mes pregunto si el dia es mayor
		if (c_mes == mes)
		{
			if (c_dia > dia) return -1;
		}
		// Verificacion de dias con respecto a los meses
		switch (c_mes)
		{
		case 1:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
				break;
		case 2:
			if (c_dia >= 1 && c_dia <= 29)return 0;
			else return -1;
				break;
		case 3:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
				break;
		case 4:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
				break;
		case 5:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
				break;
		case 6:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
				break;
		case 7:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
				break;
		case 8:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
				break;
		case 9:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
				break;
		case 10:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
				break;
		case 11:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
				break;
		case 12:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
				break;
		default: return -1;
			break;
		}
		break;
	// La fecha a comparar tiene que ser mayor a la del sistema
	case VENCIMIENTO:
		// Pregunto si el año a comparar es menor
		if (c_año < año)
		{
			return -1;
		}
		// El mes es menor?
		if (c_año == año)
		{
			if (c_mes < mes) return -1;
		}
		// Mismo año, mismo mes el dia es menor? 
		if (c_mes == mes)
		{
			if (c_dia < dia) return -1;
		}
		// Verificacion de dias con respecto a los meses
		switch (c_mes)
		{
		case 1:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
			break;
		case 2:
			if (c_dia >= 1 && c_dia <= 29)return 0;
			else return -1;
			break;
		case 3:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
			break;
		case 4:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
			break;
		case 5:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
			break;
		case 6:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
			break;
		case 7:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
			break;
		case 8:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
			break;
		case 9:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
			break;
		case 10:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
			break;
		case 11:
			if (c_dia >= 1 && c_dia <= 30)return 0;
			else return -1;
			break;
		case 12:
			if (c_dia >= 1 && c_dia <= 31)return 0;
			else return -1;
			break;
		default: return -1;
			break;
		}
		break;
	default:
		return -1;
		break;
	}
}
