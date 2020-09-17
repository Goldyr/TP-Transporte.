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

bool read(choferes *reg, int pos)
{
	FILE* pf;
	bool read;
	pf = fopen("../Debug/choferes.dat", "rb");
	if (pf == NULL)
	{
		cout << "Leer registro" << endl;
		return false;
	}
	fseek(pf, sizeof(choferes) * pos, 0);
	read = fread(reg, sizeof(choferes), 1, pf);
	fclose(pf);
	return read;
}

int searchreg(char *c, BUSCAR_REGISTRO buscar)
{

	choferes reg;
	int pos = 0;
	FILE* pf;
	pf = fopen("../Debug/choferes.dat", "rb");
	if (pf == NULL)
	{
		cout << "Buscar posicion" << endl;
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

bool modifyfile(choferes reg, int pos)
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
