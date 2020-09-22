#pragma once

//
// FUNCIONES VIAJES
//

// Busca y devuelve la posicion de un registro char que se pida
int searchreg_viajes(int id);

// Se lee un registro en la posicion indicada y lo guarda en la variable que se envía
bool leer_viajes(viajes* reg, int pos);

//Guarda registro de viajes
bool guardar_viajes(viajes regViaj, const char* direccion);

// Se modifica el registro sabiendo la posicion dentro del archivo
bool modificar_viaje(viajes reg, int pos);

// -----------------------------------------

//
// FUNCIONES CHOFERES
//

// Se lee un registro en la posicion indicada y lo guarda en la variable que se envía
bool leer_choferes(choferes *reg, int pos);

// Se modifica el registro sabiendo la posicion dentro del archivo
bool modificar_choferes(choferes reg, int pos);

// Busca y devuelve la posicion de un registro char que se pida (Choferes)
int searchreg_ch(char *c, BUSCAR_REGISTRO buscar);

//Guarda registro de choferes
bool guardar_choferes(choferes regChof, const char* direccion);

//Guarda un registro depende el registro y direccion de archivo que mandes

// ----------------------------------------


