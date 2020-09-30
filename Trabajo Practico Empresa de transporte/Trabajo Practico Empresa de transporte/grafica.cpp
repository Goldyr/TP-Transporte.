#include <iostream>
#include <cstdlib>
#include <windows.h>
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

void bordes(int n_info, bool lista)
{
	setlocale(LC_ALL, "C");
	// n_info +4 para tener un espaciado entre lo que va a entrar en el cuadro

	n_info += 4;

	// Se consigue la informacion de la consola

	int columns, rows, newc, newr;
	int char_imp; // Numero ASCII del caracter a imprimr
	int modificador;
	columns = columnas();
	rows = filas();

	//
	// Valores predeterminados
	//
	// columns 120
	// rows 30

	// Si divido entre 2 me da valores que estan mas cerca al centro, mientras mas altos los valores en los que divida mas separado del centro


	newc = columns / 3; // X
	newr = rows / 5;	// Y
	

	// Primero imprime los caracteres de las esquinas

	if (lista)
	{
		modificador = 2;
		// Borde sup. izq.
		locate(columns-(columns-2), newr);
		char_imp = 201;				// Se le asigna el numero de ASCII al int
		cout << (char)char_imp;		// Se imprime el casteo a char
		// Borde sup. der.
		locate(columns-2, newr);
		char_imp = 187;
		cout << (char)char_imp;
		// Borde inf. izq.
		locate(columns - (columns - 2), newr + n_info);
		char_imp = 200;
		cout << (char)char_imp;
		// Borde inf. der.
		locate(columns-2, newr + n_info);
		char_imp = 188;
		cout << (char)char_imp;
	}
	else
	{
		modificador = 3;
		// Borde sup. izq.
		locate(newc, newr);
		char_imp = 201;				// Se le asigna el numero de ASCII al int
		cout << (char)char_imp;		// Se imprime el casteo a char
		// Borde sup. der.
		locate(newc + columns / modificador, newr);
		char_imp = 187;
		cout << (char)char_imp;
		// Borde inf. izq.
		locate(newc, newr + n_info);
		char_imp = 200;
		cout << (char)char_imp;
		// Borde inf. der.
		locate(newc + columns / modificador, newr + n_info);
		char_imp = 188;
		cout << (char)char_imp;
	}
	// Variables auxiliares
	int dibX, dibY = newr + n_info;

	char_imp = 205;

	// Luego los bordes superiores e inferiores

	if (lista)
	{
		dibX = columns - (columns - 2);
		while (dibX + 1 < columns - 2)
		{
			dibX++;
			locate(dibX, newr);
			cout << (char)char_imp;
			locate(dibX, dibY);
			cout << (char)char_imp;
		}
	}
	else
	{
		dibX = newc;
		while (dibX + 1 < newc + columns / modificador)
		{
			dibX++;
			locate(dibX, newr);
			cout << (char)char_imp;
			locate(dibX, dibY);
			cout << (char)char_imp;
		}
	}

	

	// Por ultimo el izquierdo y el derecho
	char_imp = 186;
	dibY = newr;

	if (lista)
	{
		dibX = columns - (columns - 2);
		while (dibY + 1 < newr + n_info)
		{
			dibY++;
			locate(dibX, dibY);
			cout << (char)char_imp;
			locate(columns-2, dibY);
			cout << (char)char_imp;
		}
	}
	else
	{
		dibX = newc;
		while (dibY + 1 < newr + n_info)
		{
			dibY++;
			locate(dibX, dibY);
			cout << (char)char_imp;
			locate(newc + columns / modificador, dibY);
			cout << (char)char_imp;
		}
	}

	
}

int columnas()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return columns;
}

int filas()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return rows;
}

void linea_hor(int tam, int ch)
{
	setlocale(LC_ALL, "C");
	for (int i = 0; i < tam; i++);
	{
		cout << (char)ch;
	}
	setlocale(LC_ALL, "Spanish");
}
