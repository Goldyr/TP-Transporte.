#pragma once

//Da alta a un chofer.
bool agregarChofer();

//Modificar(Solicita DNI del chofer y se modifica la fecha de vencimiento de la licencia)
void modificarChofer();

//Lista todos los choferes en orden de ingreso.
void listarChoferes();

//Mostrar un chofer
void mostrarChofer(choferes regChof);

// Mostrar un chofer por DNI
void mostrarChoferDNI();

//Elimina un chofer por DNI
void eliminarChofer();