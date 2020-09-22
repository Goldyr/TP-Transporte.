#pragma once

//Da alta a un chofer.
bool agregarChofer();

//Modificar(Solicita DNI del chofer y se modifica la fecha de vencimiento de la licencia)
void modificarChofer();

//Lista todos los choferes en orden de ingreso.
void listarChoferes();

// Mostrar un chofer por DNI
void mostrarChoferDNI();

//Mostrar un chofer
void mostrarChofer(choferes regChof);

//Elimina un chofer por DNI
void eliminarChofer();

//Verificar si una cadena est� vacia
bool isEmpty(char* p, int tam);

//Se carga una cadena de caracteres
void cargarChar(char* p, int tam);

//Se compara la fecha con respecto al sistema
int fechacmp(int dia, int mes, int a�o, FECHAS opcion);