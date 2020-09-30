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
#include "grafica.h"



bool agregarChofer() {

	bordes(0, TRUE);
	int col = columnas();
	int row = filas();

	int newc = col / 3; // X
	int newr = row / 5;	// Y

	newc = col - (col - 2);

	setColor(CYAN);
	locate(newc+1, newr+1);
	cout << "DNI";
	locate(newc + 11, newr + 1);
	cout << "APELLIDO(S)";
	locate(newc + 31, newr + 1);
	cout << "NOMBRE(S)";
	locate(newc + 51, newr + 1);
	cout << "INGRESO";
	locate(newc + 62, newr + 1);
	cout << "CUIT";
	locate(newc + 78, newr + 1);
	cout << "TIPO";
	locate(newc + 87, newr + 1);
	cout << "VTO";
	locate(newc + 95, newr + 1);
	cout << "TELEFONO";
	locate(newc + 106, newr + 1);
	cout << "PROPTRIO";
	setColor(WHITE);
	int k = 0;
	setlocale(LC_ALL, "C");

	for (int i = 0; i < col - 5; i++)
	{
		k++;
		locate(newc + k, newr + 2);
		cout << (char)205;
	}

	// FIN DE DECLARACIONES PARA LA PARTE GRAFICA
	
	setlocale(LC_ALL, "Spanish");
	int prop;
	choferes regChof;
	// 1. Ingreso DNI
	do
	{	
		locate(newc + 1, newr + 3);
		cout << "         ";
		locate(newc+1, newr+3);
		cargarChar(regChof.DNI, 10);

	}
	//
	// Validacion
	//
	// 1. No este vacio el array tipo char
	// 2. El DNI es unico en el archivo
	while (isEmpty(regChof.DNI, 10) == true || searchreg_ch(regChof.DNI, BUSCAR_REGISTRO::DNI) != -1);

	
	// 2. Ingreso apellido
	do
	{
		locate(newc + 11, newr + 3);
		cout << "                  ";
		locate(newc + 11, newr + 3);
		cargarChar(regChof.apellido, 50);
	}
	//
	// Validacion
	//
	while (isEmpty(regChof.apellido, 50) == true);

	// 3. Ingreso nombre
	do
	{
		locate(newc + 31, newr + 3);
		cout << "                  ";
		locate(newc + 31, newr + 3);
		cargarChar(regChof.nombre, 50);

	}
	//
	// Validacion
	//
	while (isEmpty(regChof.nombre, 50) == true);

	// 4. Ingreso de fecha de ingreso
	do
	{
		locate(newc + 51, newr + 3);
		cout << "          ";
		locate(newc + 51, newr + 3);
		cin >> regChof.fechaingreso.dia;
		locate(newc + 53, newr + 3);
		cout << "/";
		locate(newc + 54, newr + 3);
		cin >> regChof.fechaingreso.mes;
		locate(newc + 56, newr + 3);
		cout << "/";
		locate(newc + 57, newr + 3);
		cin >> regChof.fechaingreso.anio;
	}	while (fechacmp(regChof.fechaingreso.dia, regChof.fechaingreso.mes, regChof.fechaingreso.anio, FECHAS::MENOR) == -1);

	cin.ignore();
	// 5. Ingreso de CUIT

	do
	{
		locate(newc + 62, newr + 3);
		cout << "                   ";
		locate(newc + 62, newr + 3);
		cargarChar(regChof.CUIT, 20);
	}
	//
	// Validacion
	// 
	while (isEmpty(regChof.CUIT, 20) == true || searchreg_ch(regChof.CUIT, BUSCAR_REGISTRO::CUIT) != -1);


	do {
		locate(newc + 78, newr + 3);
		cout << "   ";
		locate(newc + 78, newr + 3);
		cin >> regChof.registro;
	} while (regChof.registro < 1 || regChof.registro>3);
	

	do
	{
		locate(newc + 84, newr + 3);
		cout << "          ";
		locate(newc + 84, newr + 3);
		cin >> regChof.vencimiento.dia;
		locate(newc + 86, newr + 3);
		cout << "/";
		locate(newc + 87, newr + 3);
		cin >> regChof.vencimiento.mes;
		locate(newc + 89, newr + 3);
		cout << "/";
		locate(newc + 90, newr + 3);
		cin >> regChof.vencimiento.anio;
	} while (fechacmp(regChof.vencimiento.dia, regChof.vencimiento.mes, regChof.vencimiento.anio, FECHAS::VENCIMIENTO) == -1);

	

	locate(newc + 95, newr + 3);
	cin >> regChof.telefono;

	do
	{
		locate(newc + 108, newr + 3);
		cout << "  ";
		locate(newc + 108, newr + 3);
		cin >> prop;
		switch (prop)
		{
		case 1:
			regChof.propietario = true;
			break;
		case 0:
			regChof.propietario = false;
			break;
		default: break;
		}
	} while (prop < 0 || prop > 1);
	
	regChof.estado = true;
	guardar_choferes(regChof,ARCHIVO_CHOFERES);
	
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
	pos = searchreg_ch(ingreso_DNI, BUSCAR_REGISTRO::DNI);
	// Si no existe
	if (pos == -1)
	{
		cout << "El DNI no corresponde a ningun registro" << endl;
		// Salir
		return;
	}
	// Si existe
	if (leer_choferes(&reg, pos) == false)
	{
		cout << "No se pudo leer el registro" << endl;
		// Salir
		return;
	}
	cls();
	mostrarChofer(reg,0);
	
}

void modificarChofer() {

	char ingreso_DNI[10], opc;
	int pos;
	choferes reg;
	cout << "Ingresar el numero de DNI a modificar: ";
	cin >> ingreso_DNI;

	// Se busca la posicion del registro con el DNI
	pos = searchreg_ch(ingreso_DNI, BUSCAR_REGISTRO::DNI);
	cout << endl << endl;
	// Si no existe
	if (pos == -1)
	{
		cout << "El DNI no corresponde a un registro" << endl;
		// Salir
		return;
	}
	// Si existe pero no se puede leer el registro
	if (leer_choferes(&reg, pos) == false)
	{
		cout << "No se pudo leer el registro" << endl;
		// Salir
		return;
	}
	// Existe y se pudo leer el registro
	cout << "Se encontro el siguiente registro: " << endl;
	// Se da a conocer el registro en pantalla
	mostrarChofer(reg,5);
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
		cout << "anio: ";
		cin >> reg.vencimiento.anio;
		// Se modifica
		if (modificar_choferes(reg, pos) == true)
		{
			// Verifico si se sobreescribio correctamente
			cout << "El registro se modifico correctamente" << endl;
			titulosListadoChofer();
			mostrarChofer(reg,0);
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
		cout << "anio: ";
		cin >> reg.vencimiento.anio;
		// Se modifica
		if (modificar_choferes(reg, pos) == true)
		{
			// Verifico si se sobreescribio correctamente
			cout << "El registro se modifico correctamente" << endl;
			titulosListadoChofer();
			mostrarChofer(reg,0);
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

	p = fopen(ARCHIVO_CHOFERES, "rb");
	if (p == NULL)
	{
		cout << "Error al abrir el archivo/ o no existe" << endl;
		cout << "listarChoferes" << endl;
		system("pause");
		return;
	}
	int pos = 1;

	 titulosListadoChofer();
	while (fread(&regChof, sizeof(choferes), 1, p)) {
		
		if (regChof.estado == true) {
			mostrarChofer(regChof,pos);
			pos++;
		}
	}

	fclose(p);


	return;
}

void mostrarChofer(choferes regChof,int pos) {
	pos ++;
	gotoxy(1, pos); cout <<  regChof.DNI;
	gotoxy(10, pos); cout  << regChof.nombre;
	gotoxy(30, pos); cout <<  regChof.apellido;
	gotoxy(50, pos); cout <<  regChof.fechaingreso.dia << "/" << regChof.fechaingreso.mes << "/" << regChof.fechaingreso.anio;
	gotoxy(70, pos); cout  << regChof.CUIT;
	gotoxy(85, pos); cout  << regChof.registro;
	gotoxy(95, pos); cout  << regChof.vencimiento.dia << "/" << regChof.vencimiento.mes << "/" << regChof.vencimiento.anio;
	gotoxy(106, pos); cout  << regChof.telefono;
	cout << endl;

	return;
}

void titulosListadoChofer() {
	system("cls");
	gotoxy(1, 1); cout << "DNI";
	gotoxy(10, 1); cout << "NOMBRE";
	gotoxy(30, 1); cout << "APELLIDO";
	gotoxy(50, 1); cout << "FECHA/ING";
	gotoxy(70, 1); cout << "CUIT";
	gotoxy(85, 1); cout << "REGISTRO";
	gotoxy(95, 1); cout << "FECHA/VENC";
	gotoxy(106, 1); cout << "TELEFONO";
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
	pos=searchreg_ch(ingreso_DNI, BUSCAR_REGISTRO::DNI);
	cout << endl << endl;
	// En caso de que no exista
	if (pos == -1)
	{
		cout << "El DNI no corresponde a un registro" << endl;
		// Salir
		return;
	}
	// Si existe pero no se puede leer el registro
	if (leer_choferes(&reg, pos) == false)
	{
		cout << "No se pudo leer el registro" << endl;
		// Salir
		return;
	}
	// Existe y se pudo leer el registro
	cout << "Se encontro el siguiente registro: " << endl;
	// Muestro el registro a dar de baja
	mostrarChofer(reg,5);
	cout << endl;
	//Estas seguro de que queres darlo de baja? 
	cout << "Deseas darlo de baja? (S/n)  "<< endl;
	cin >> opc;
	switch (opc)
	{
		// Si
	case 'S':
		// Se limpia la pantalla
		cls();
		//Se da de baja
		reg.estado = false;
		if (modificar_choferes(reg, pos) == true)
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
		if (modificar_choferes(reg, pos) == true)
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
	for (i = 0; i < tam; i++)
	{
		p[i] = cin.get();
		if (p[i] == '\n') break;
	}
	p[i] = '\0';
	fflush(stdin);
}

int fechacmp(int c_dia, int c_mes, int c_anio, FECHAS opcion)
{
	// Declaracion de variables de ctime
	int mes, dia, anio;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	anio = 1900 + ltm->tm_year;
	mes = 1 + ltm->tm_mon;
	dia = ltm->tm_mday;
	// Swtich de enum de opcion
	switch (opcion)
	{
	// La fecha a comparar tiene que ser menor a la del sistema
	case MENOR:
		// Pregunto si el año para comparar es mayor
		if (c_anio > anio)
		{
			return -1;
		}
		// Si es el mismo año pregunto si el mes es mayor
		if (c_anio == anio)
		{
			if (c_mes > mes) return -1;
		}
		// Si es el mismo anio y mes pregunto si el dia es mayor
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
		if (c_anio < anio)
		{
			return -1;
		}
		// El mes es menor?
		if (c_anio == anio)
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
