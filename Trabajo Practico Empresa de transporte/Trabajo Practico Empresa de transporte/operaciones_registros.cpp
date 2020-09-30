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
#include "grafica.h"

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
		if (c == reg.IDViaje && reg.estado)
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
	fclose(pf);
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
		return false;
	}
	fwrite(&regViaj, sizeof(regViaj), 1, p);
	fclose(p);

	return true;
}

int contar_registros()
{
	FILE* pf;
	viajes viaj;
	int c = 0;
	pf = fopen("../Debug/viajes.dat", "rb");
	if (pf == NULL) return -1;
	while (fread(&viaj, sizeof viaj, 1, pf) == 1) c++;
	fclose(pf);
	return c;
}

bool backupFiles() { 
	//Confirmacion de usuario
	char opcion;
	cout << "Desea hacer una copia de seguridad S/N " << endl;
	cin >> opcion;
	switch (opcion) {
	case'n':
		return false;
		break;
	case'N':
		return false;
		break;
	case 's':
		break;
	case'S':
		break;
	default:
		return false;
		break;
	}

	choferes reg;
	viajes reg2;

	FILE* pChof;
	FILE* pViaj;
	FILE* pbkp;
	FILE* pbkp2;

	//Abro los 4 archivos .dat en rb .bkp en wb
	pChof = fopen("../Debug/choferes.dat", "rb");
	pbkp = fopen("../Debug/choferes.bkp", "wb");
	pViaj = fopen("../Debug/viajes.dat", "rb");
	pbkp2 = fopen("../Debug/viajes.bkp", "wb");

	// Me aseguro de que se hayan abierto ambos correctamente
	if (pChof == NULL){
		fclose(pbkp);
		fclose(pbkp2);
		fclose(pViaj);
		cout << "Error abriendo choferes.dat" << endl;
		return false;
	}
	if (pbkp == NULL) {
		fclose(pChof);
		fclose(pbkp2);
		fclose(pViaj);
		cout << "Error abriendo choferes.bkp" << endl;
		return false;
	}
	if (pViaj == NULL) {
		fclose(pChof);
		fclose(pbkp2);
		fclose(pbkp);
		cout << "Error abriendo viajes.dat" << endl;
		return false;
	}
	if (pbkp2 == NULL) {
		fclose(pChof);
		fclose(pbkp);
		fclose(pViaj);
		cout << "Error abriendo viajes.bkp" << endl;
		return false;
	}

	// Mientras pueda leer registros en el .dat los escribo en el .bkp
	while (fread(&reg, sizeof(choferes), 1, pChof)){
		if(reg.estado) fwrite(&reg, sizeof(choferes), 1, pbkp);
	}

	while (fread(&reg2, sizeof(viajes), 1, pViaj)) {
		if(reg2.estado)fwrite(&reg2, sizeof(viajes), 1, pbkp2);
	}

	//Cierro los archivos y retorno verdadero para saber que salio bien.
	fclose(pChof);
	fclose(pbkp);
	fclose(pViaj);
	fclose(pbkp2);



	return true;
}

bool restaurarFiles() {
	//Confirmacion de usuario
	char opcion;
	cout << "Desea restaurar los archivos backup S/N " << endl;

	cin >> opcion;
	switch (opcion) {
	case'n':
		return false;
		break;
	case'N':
		return false;
		break;
	case 's':
		break;
	case'S':
		break;
	default:
		return false;
		break;
	}

	choferes reg;
	viajes reg2;
	FILE* pChof;
	FILE* pbkp;
	FILE* pViaj;
	FILE* pbkp2;

	//Abro los 2 archivos .bkp en rb .dat en wb
	pbkp = fopen("../Debug/choferes.bkp", "rb");
	pChof = fopen("../Debug/choferes.dat", "wb");
	pbkp2 = fopen("../Debug/viajes.bkp", "rb");
	pViaj = fopen("../Debug/viajes.dat", "wb");

	// Me aseguro de que se hayan abierto ambos correctamente
	if (pChof == NULL) {
		fclose(pbkp);
		fclose(pbkp2);
		fclose(pViaj);
		cout << "Error abriendo choferes.dat" << endl;
		return false;
	}
	if (pbkp == NULL) {
		fclose(pChof);
		fclose(pbkp2);
		fclose(pViaj);
		cout << "Error abriendo choferes.bkp" << endl;
		return false;
	}
	if (pViaj == NULL) {
		fclose(pChof);
		fclose(pbkp2);
		fclose(pbkp);
		cout << "Error abriendo viajes.dat" << endl;
		return false;
	}
	if (pbkp2 == NULL) {
		fclose(pChof);
		fclose(pbkp);
		fclose(pViaj);
		cout << "Error abriendo viajes.bkp" << endl;
		return false;
	}

	// Mientras pueda leer registros en el .bkp los escribo en el .dat
	while (fread(&reg, sizeof(choferes), 1, pbkp)) {
		fwrite(&reg, sizeof(choferes), 1, pChof);
	}
	while (fread(&reg2, sizeof(viajes), 1, pbkp2)) {
		fwrite(&reg2, sizeof(viajes), 1, pViaj);
	}

	//Cierro los archivos y retorno verdadero para saber que salio bien.
	fclose(pChof);
	fclose(pbkp);
	fclose(pViaj);
	fclose(pbkp2);



	return true;
}

bool cargarDInicio()
{
	//Confirmacion de usuario
	char opcion;
	cout << "Desea cargar los datos de inicio? S/N" << endl;

	cin >> opcion;
	switch (opcion) {
	case'n':
		return false;
		break;
	case'N':
		return false;
		break;
	case 's':
		break;
	case'S':
		break;
	default:
		return false;
		break;
	}

	choferes reg;
	viajes reg2;

	FILE* pChof;
	FILE* pini;
	FILE* pViaj;
	FILE* pini2;

	//Abro los 2 archivos .bkp en rb .dat en wb
	pini = fopen("../Debug/choferes.ini", "rb");
	pChof = fopen("../Debug/choferes.dat", "wb");
	pini2 = fopen("../Debug/viajes.ini", "rb");
	pViaj = fopen("../Debug/viajes.dat", "wb");

	// Me aseguro de que se hayan abierto ambos correctamente
	if (pChof == NULL) {
		fclose(pini);
		fclose(pini2);
		fclose(pViaj);
		cout << "Error abriendo choferes.dat" << endl;
		return false;
	}
	if (pini == NULL) {
		fclose(pChof);
		fclose(pini2);
		fclose(pViaj);
		cout << "Error abriendo choferes.ini" << endl;
		return false;
	}
	if (pViaj == NULL) {
		fclose(pChof);
		fclose(pini2);
		fclose(pini);
		cout << "Error abriendo viajes.dat" << endl;
		return false;
	}
	if (pini2 == NULL) {
		fclose(pChof);
		fclose(pini);
		fclose(pViaj);
		cout << "Error abriendo viajes.ini" << endl;
		return false;
	}

	// Mientras pueda leer registros en el .bkp los escribo en el .dat
	while (fread(&reg, sizeof(choferes), 1, pini)) {
		fwrite(&reg, sizeof(choferes), 1, pChof);
	}
	while (fread(&reg2, sizeof(viajes), 1, pini2)) {
		fwrite(&reg2, sizeof(viajes), 1, pViaj);
	}

	//Cierro los archivos y retorno verdadero para saber que salio bien.
	fclose(pChof);
	fclose(pini);
	fclose(pViaj);
	fclose(pini2);



	return true;

}