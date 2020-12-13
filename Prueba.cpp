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
	int op=-1,opcon = -1;
	turnos t; mascota m; usuario u; veterinario v;
	do{
		op=menu();
		system ("cls");
		switch(op)
		{
		case 1: 
		{	
			do
			{
				opcon = -1;
				opcon = menuconsult();
				system ("cls");
				switch(opcon)
				{
					case 1:
					{
						printf ("\nIniciar sesion\n");
						break;
					}
					case 2: 
					{
						printf("\nVisualizar Lista de Espera de Turnos\n");
						break;
					}
					case 3:
					{
						printf("\nRegistrar Evolución de la Mascota\n");
						break;
					}
					case 4:
					{
						printf("\nEl programa finalizo\n");
						break;
					}
					default 
					{
						printf("Opcion seleccionada incorrecta");
						break;
					}
				
				}
	
			}
			break;
		}
		case 2:
		{
			do
			{
				opasis = -1;
				opasis = menuasistente();
				system("cls");
				switch (opasis)
				{
				
				case 1:
				{
					printf("\nIniciar Sesión\n");
					break;
				}	
				case 2:
				{
					printf("\nRegistrar Mascota\n");
					break;
				}
				case 3:
				{
					printf("\nListado de Atenciones por Veterinario y Fecha\n")
					break;
				}
				case 4:
				{
					printf("\nListado de Atenciones por Veterinario y Fecha\n");
					break;
				}
				case 5:
				{
					printf("\nEl programa finalizo\n");
					break;
				}
				default
				{
					printf("Opcion seleccionada incorrecta");
					break;
				}
				
			}
			break;
				
			}
		}
		case 3:
		{
			do
			{
				opad = -1;
				opad = menuadmin();
				system ("cls");
				switch(opad)
				{
					case 1:
					{
						printf("\nRegistrar Veterinario\n");
						break;
					}
					case 2:
					{
						printf("\nRegistrar Usuario Asistente\n");
						break;
					}
					case 3:
					{
						printf("\nAtenciones por Veterinarios\n");
						break;
					}
					case 4:
					{
						printf("\nEl programa finalizo\n");
						break;
					}
					default
					{
						printf("Opcion seleccionada incorrecta");
						break;
					}
				}
				
			}
			
			break;
		}
			
		}
	 
	
	
	}while
}

int menu ();
int menu ()
{
    int opcion=-1;
    printf("\t\tMenu principal\n\n");
    printf("1-Modulo Consultorio Veterinario");
    printf("2-Modulo del asistente");
    printf("3-Modulo Administracion");
    printf("\n4-Cerrar el programa\n");

    printf("\nIngrese la opcion: ");
    scanf("%d", &opcion);

}

void menuadmin();
void menuadmin()
{
	int opcadmin=-1;
	printf("\t\tMenu Administracion\n\n");
	printf("1-Registrar Veterinario");
	printf("2-Registrar Usuario Asistente");
	printf("3-Atenciones por Veterinarios");
	printf("\n4-Cerrar la aplicación");
	
	printf("\nIngrese una opcion");
	scanf("%d", &opcadmin);
}




void menuconsult();
void menuconsult()
{
    int opcconsult=-1;

    printf("\t\tMenu Consultorio Veterinario\n\n");
    printf("1-Iniciar Secion");
    printf("2-Visualizar Lista de Espera de Turnos");
    printf("3-Registrar Evolución de la Mascota");
    printf("\n4-Cerrar el programa");

    printf("\nIngrese la opcion: ");
    scanf("%d", &opcconsult);

}

void menuasistente();
void menuasistente()
{
	int opcasist=-1;
	printf("\t\tMenu del asistente\n\n");
	
	printf("1-Iniciar Sesión");
	printf("2-Registrar Mascota");
	printf("3-Registrar Turno");
	printf("4-Listado de Atenciones por Veterinario y Fecha");
	printf("\n5-Cerrar la aplicación");
	
	printf("\nIngrese la opcion: ");
	scanf("%d", &opcasist);	
}

void reg()
{
	int i;
	
	
}

