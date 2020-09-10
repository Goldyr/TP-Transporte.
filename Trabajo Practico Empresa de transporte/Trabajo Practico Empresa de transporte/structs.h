


struct fecha {
	int dia;
	int mes;
	int año;

};

struct choferes {
	char DNI[10];
	char apellido[50];
	char nombre[50];
	fecha fechaingreso;
	char CUIT[20];
	int registro;
	fecha vencimiento;
	char telefono[15];
	bool propietario;
	bool estado;

};