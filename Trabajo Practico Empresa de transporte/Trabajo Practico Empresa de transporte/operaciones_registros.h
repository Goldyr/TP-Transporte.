#pragma once


// Se lee un registro en la posicion indicada y lo guarda en la variable que se envía
bool read(choferes *reg, int pos);

// Busca y devuelve la posicion de un registro que se pida
int searchreg(char *c, BUSCAR_REGISTRO buscar);

// Se modifica el registro sabiendo la posicion dentro del archivo
bool modifyfile(choferes reg, int pos);

//Guarda un registro depende el registro y direccion de archivo que mandes
//Guarda registro de choferes
bool guardarRegistro(choferes regChof,const char* direccion);
//Guarda registro de viajes
bool guardarRegistro(viajes regViaj, const char* direccion);


