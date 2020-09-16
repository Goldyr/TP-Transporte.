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

int searchreg(char *dni)
{
	int pos = 0;
	choferes reg;
	FILE* pf;
	pf = fopen("../Debug/choferes.dat", "rb");
	if (pf == NULL)
	{
		cout << "Buscar posicion" << endl;
		return -1;
	}
	while (fread(&reg, sizeof(choferes), 1, pf) == 1)
	{
		if (strcmp(reg.DNI, dni) == 0 && reg.estado == true)
		{
			fclose(pf);
			return pos;
		}
		pos++;
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