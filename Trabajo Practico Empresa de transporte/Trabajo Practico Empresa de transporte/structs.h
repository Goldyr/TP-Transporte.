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

struct viajes {
	int IDViaje;
	char DNI_Chofer[10];
	int IDCliente;
	fecha fechaviaje;
	int horasalida;
	float kilometraje;
	float importe;
	char patente[10];
	int calificacion;
	bool estado;

};

enum BUSCAR_REGISTRO
{
	DNI,
	CUIT,
	NOMBRE,
	APELLIDO,
	TELEFONO
};

enum FECHAS
{
	MENOR,
	VENCIMIENTO
};