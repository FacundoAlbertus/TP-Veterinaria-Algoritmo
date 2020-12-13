#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct veterinario
{
    char apynom[60];
    int matricula;
    char contrasenia[10]; 
    int dni;
    char telefono[25];
};

struct usuario
{
    char usu[60];
    char contrasenia[60];
    char apynom[60];
    int cp;
};

struct turnos
{
    int mat;
    fecha fn;
    int dni;
    char detalle[380];
};

struct mascota
{
    char apynom[60];
    char domicilio[60];
    int dni;
    char localidad[60];
    fecha fec;
    float peso;
    char tel[25];
};


main ()
{
	
}

	
}
