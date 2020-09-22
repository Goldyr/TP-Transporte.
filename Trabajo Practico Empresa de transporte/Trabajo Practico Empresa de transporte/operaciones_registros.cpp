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

bool leer_choferes(choferes *reg, int pos)
{
	FILE* pf;
	bool leer_choferes;
	pf = fopen("../Debug/choferes.dat", "rb");
	if (pf == NULL)
	{
		cout << "Leer registro" << endl;
		return false;
	}
	fseek(pf, sizeof(choferes) * pos, 0);
	leer_choferes = fread(reg, sizeof(choferes), 1, pf);
	fclose(pf);
	return leer_choferes;
}

int searchreg_viajes(int c)
{
	viajes reg;
	int pos = 0;
	FILE* pf;
	pf = fopen("../Debug/viajes.dat", "rb");
	if (pf == NULL)
	{
		cout << "Buscar posicion viajes" << endl;
		return -1;
	}
	while (fread(&reg, sizeof(viajes), 1, pf) == 1)
	{
		if (c == reg.IDViaje && reg.estado == true)
		{
			fclose(pf);
			return pos;
		}
		pos++;
	}
	fclose(pf);
	return -1;
}

bool leer_viajes(viajes* reg, int pos)
{
	bool leer_viaje;
	FILE* pf;
	pf = fopen("../Debug/viajes.dat", "rb");
	if (pf == NULL)
	{
		cout << "Leer viajes" << endl;
		return false;
	}
	fseek(pf, sizeof(viajes)*pos, 0);
	leer_viaje = fread(reg, sizeof(viajes), 1, pf);
	return leer_viaje;
}

int searchreg_ch(char *c, BUSCAR_REGISTRO buscar)
{

	choferes reg;
	int pos = 0;
	FILE* pf;
	pf = fopen("../Debug/choferes.dat", "rb");
	if (pf == NULL)
	{
		cout << "Buscar posicion choferes" << endl;
		return -1;
	}
	switch (buscar)
	{
	case DNI:
		while (fread(&reg, sizeof(choferes), 1, pf) == 1)
		{
			if (strcmp(reg.DNI, c) == 0 && reg.estado == true)
			{
				fclose(pf);
				return pos;
			}
			pos++;
		}
		break;
	case CUIT:
		while (fread(&reg, sizeof(choferes), 1, pf) == 1)
		{
			if (strcmp(reg.CUIT, c) == 0 && reg.estado == true)
			{
				fclose(pf);
				return pos;
			}
			pos++;
		}
		break;
	case NOMBRE:
		while (fread(&reg, sizeof(choferes), 1, pf) == 1)
		{
			if (strcmp(reg.nombre, c) == 0 && reg.estado == true)
			{
				fclose(pf);
				return pos;
			}
			pos++;
		}
		break;
	case APELLIDO:
		while (fread(&reg, sizeof(choferes), 1, pf) == 1)
		{
			if (strcmp(reg.apellido, c) == 0 && reg.estado == true)
			{
				fclose(pf);
				return pos;
			}
			pos++;
		}
		break;
	case TELEFONO:
		while (fread(&reg, sizeof(choferes), 1, pf) == 1)
		{
			if (strcmp(reg.telefono, c) == 0 && reg.estado == true)
			{
				fclose(pf);
				return pos;
			}
			pos++;
		}
		break;
	default: break;
	}

	fclose(pf);
	return -1;
}

bool modificar_choferes(choferes reg, int pos)
{
	bool saved;
	FILE* pf;
	pf = fopen("../Debug/choferes.dat", "rb+");
	if (pf == NULL)
	{
		cout << "Modificar registro";
		return false;
	}
	fseek(pf, sizeof(choferes) * pos, 0);
	saved = fwrite(&reg, sizeof(choferes), 1, pf);
	fclose(pf);
	return saved;
}

bool modificar_viaje(viajes reg, int pos)
{
	bool saved;
	FILE* pf;
	pf = fopen("../Debug/viajes.dat", "rb+");
	if (pf == NULL)
	{
		cout << "Modificar registro";
		return false;
	}
	fseek(pf, sizeof(viajes) * pos, 0);
	saved = fwrite(&reg, sizeof(viajes), 1, pf);
	fclose(pf);
	return saved;
}

bool guardar_choferes(choferes regChof, const char* direccion) {
	FILE* p;
	p = fopen(direccion, "ab");
	if (p == NULL) {
		cout << "Error al abrir el archivo" << endl;
		cout << "guardar_choferes" << endl;
		return false;
	}
	fwrite(&regChof, sizeof(regChof), 1, p);

	fclose(p);

	return true;
}

bool guardar_viajes(viajes regViaj, const char* direccion) {
	FILE* p;
	p = fopen(direccion, "ab");
	if (p == NULL) {
		cout << "Error al abrir el archivo" << endl;
		cout << "guardar_choferes" << endl;
		fclose(p);
		return false;
	}
	fwrite(&regViaj, sizeof(regViaj), 1, p);
	fclose(p);

	return true;
}