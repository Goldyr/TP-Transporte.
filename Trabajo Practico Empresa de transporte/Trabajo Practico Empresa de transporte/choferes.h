#pragma once

//Da alta a un chofer.
bool agregarChofer();

//Modificar(Solicita DNI del chofer y se modifica la fecha de vencimiento de la licencia)
void modificarChofer();

//Lista todos los choferes en orden de ingreso.
void listarChoferes();

// Mostrar un chofer por DNI
void mostrarChoferDNI();

//Mostrar un chofer// Uso pos para que los datos no se sobrepongan en caso de mostrar mas de 1 en caso de solo mostrar 1 dato poner 0.
void mostrarChofer(choferes regChof, int pos);

//Elimina un chofer por DNI
void eliminarChofer();

//Verificar si una cadena está vacia
bool isEmpty(char* p, int tam);

//Se carga una cadena de caracteres
void cargarChar(char* p, int tam);

//Se compara la fecha con respecto al sistema
int fechacmp(int dia, int mes, int anio, FECHAS opcion);

//Muestro los titulos para cuando voy a listar datos. ejm DNI TELEFONO CUIT
void titulosListadoChofer();