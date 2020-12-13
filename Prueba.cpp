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
int menu ();
int menu ()
{
    int opcion=-1
    printf("\t\tMenu principal\n\n");
    printf("1-Modulo Consultorio Veterinario");
    printf("2-Modulo del asistente");
    printf("3-Modulo Administracion");
    printf("\n4-Cerrar el programa\n");

    printf("\nIngrese la opcion: ");
    scanf("%d", opcion);

}
int menuconsult();
int menuconsult()
{
    int opcion=-1

    printf("\t\tMenu  Consultorio Veterinario");
    printf("1-Iniciar Secion");
    printf("2-Visualizar Lista de Espera de Turnos");
    printf("3-Registrar Evolución de la Mascota");
    printf("\n4-Cerrar el programa");

    printf("\nIngrese la opcion: ");
    scanf("%d", opcion);

}

