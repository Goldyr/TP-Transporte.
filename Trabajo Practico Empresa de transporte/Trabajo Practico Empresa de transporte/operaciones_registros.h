#pragma once


// Se lee un registro en la posicion indicada y lo guarda en la variable que se envía
bool read(choferes *reg, int pos);

// Busca y devuelve la posicion de un registro enviando como parametro el dni
int searchreg(char *dni);

// Se modifica el registro sabiendo la posicion dentro del archivo
bool modifyfile(choferes reg, int pos);