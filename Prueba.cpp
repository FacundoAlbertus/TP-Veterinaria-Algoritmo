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
						reg(v);
						break;
					}
					case 2:
					{
						printf("\nRegistrar Usuario Asistente\n");
						usu(u);
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

void reg(veterinario v);
void reg(veterinario v)
{
	FILE *vet;
	vet = fopen("veter.dat", "a+b");
	printf("Registrar al veterinario\n");
	printf("\nIngrese el nombre y apellido del veterinario: ");
	_flushall();
	gets(v.apynom);
	
	printf("\nIngrese la matricula: ");
	scanf("%d", v.matricula);
	
	printf("\nIngrese la contrasenia para el veterinario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contrasenia:");
	_flushall();
	gets(v.contrasenia);
	aceptar=false;
		while(aceptar==false){
		
				if(strstr(v.contrasenia,"Q")==NULL &&strstr(v.contrasenia,"W")==NULL && strstr(v.contrasenia,"E")==NULL && strstr(v.contrasenia,"R")==NULL && strstr(v.contrasenia,"T")==NULL && strstr(v.contrasenia,"Y")==NULL && strstr(v.contrasenia,"U")==NULL && strstr(v.contrasenia,"I")==NULL && strstr(v.contrasenia,"O")==NULL && strstr(v.contrasenia,"P")==NULL && strstr(v.contrasenia,"A")==NULL && strstr(v.contrasenia,"S")==NULL && strstr(v.contrasenia,"D")==NULL && strstr(v.contrasenia,"F")==NULL && strstr(v.contrasenia,"G")==NULL && strstr(v.contrasenia,"H")==NULL && strstr(v.contrasenia,"J")==NULL && strstr(v.contrasenia,"K")==NULL && strstr(v.contrasenia,"L")==NULL && strstr(v.contrasenia,"Ñ")==NULL && strstr(v.contrasenia,"Z")==NULL && strstr(v.contrasenia,"X")==NULL && strstr(v.contrasenia,"C")==NULL && strstr(v.contrasenia,"V")==NULL && strstr(v.contrasenia,"B")==NULL && strstr(v.contrasenia,"N")==NULL && strstr(v.contrasenia,"M")==NULL)
				{
					printf("La contrasenia no posee mayuscula, ingrese de nuevo la contrasenia: ");
					_flushall;
					gets(v.contrasenia);
				}
				else
				{
					if(strstr(v.contrasenia,"q")==NULL &&strstr(v.contrasenia,"w")==NULL && strstr(v.contrasenia,"e")==NULL && strstr(v.contrasenia,"r")==NULL && strstr(v.contrasenia,"t")==NULL && strstr(v.contrasenia,"y")==NULL && strstr(v.contrasenia,"u")==NULL && strstr(v.contrasenia,"i")==NULL && strstr(v.contrasenia,"o")==NULL && strstr(v.contrasenia,"p")==NULL && strstr(v.contrasenia,"a")==NULL && strstr(v.contrasenia,"s")==NULL && strstr(v.contrasenia,"d")==NULL && strstr(v.contrasenia,"f")==NULL && strstr(v.contrasenia,"g")==NULL && strstr(v.contrasenia,"h")==NULL && strstr(v.contrasenia,"j")==NULL && strstr(v.contrasenia,"k")==NULL && strstr(v.contrasenia,"l")==NULL && strstr(v.contrasenia,"ñ")==NULL && strstr(v.contrasenia,"z")==NULL && strstr(v.contrasenia,"x")==NULL && strstr(v.contrasenia,"c")==NULL && strstr(v.contrasenia,"v")==NULL && strstr(v.contrasenia,"b")==NULL && strstr(v.contrasenia,"n")==NULL && strstr(v.contrasenia,"m")==NULL)
					{
						printf("La contrasenia no posee minuscula, ingrese de nuevo la contrasenia: ");
						_flushall;
						gets(v.contrasenia);
					}
					else
					{
						if(strstr(v.contrasenia,"0")==NULL && strstr(v.contrasenia,"1")==NULL && strstr(v.contrasenia,"2")==NULL && strstr(v.contrasenia,"3")==NULL && strstr(v.contrasenia,"4")==NULL && strstr(v.contrasenia,"5")==NULL && strstr(v.contrasenia,"6")==NULL && strstr(v.contrasenia,"7")==NULL && strstr(v.contrasenia,"8")==NULL && strstr(v.contrasenia,"9")==NULL)
						{
							printf("La contrasenia no posee numeros, ingrese de nuevo la contrasenia: ");
							_flushall;
							gets(v.contrasenia);
						}
						else
						{
							if(strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,".")!=NULL && strstr(v.contrasenia,"-")!=NULL && strstr(v.contrasenia,"á")!=NULL && strstr(v.contrasenia,"é")!=NULL && strstr(v.contrasenia,"í")!=NULL && strstr(v.contrasenia,"ó")!=NULL && strstr(v.contrasenia,"ú")!=NULL && strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,"Á")!=NULL && strstr(v.contrasenia,"É")!=NULL && strstr(v.contrasenia,"Í")!=NULL && strstr(v.contrasenia,"Ó")!=NULL && strstr(v.contrasenia,"Ú")!=NULL)
							{
								printf("La contrasenia posee signos de puntuacion, ingrese de nuevo la contrasenia: ");
								_flushall;
								gets(v.contrasenia);
							}
							else
							{
								if(strlen(v.contrasenia)<6)
								{
									printf("La contrasenia es muy corta, ingrese de nuevo la contrasenia: ");
									_flushall;
									gets(v.contrasenia);
								}
								else
								{
									if(strlen(v.contrasenia)>32)
									{
										printf("La contrasenia es muy larga, ingrese de nuevo la contrasenia: ");
										_flushall;
										gets(v.contrasenia);
									}
									else
									{
										for(i=0;i<strlen(v.contrasenia);i++)
										{
											if((v.contrasenia[i+2]==v.contrasenia[i+1]+1) && (v.contrasenia[i+1]==v.contrasenia[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese de nuevo la contrasenia: ");
												_flushall();
												gets(v.contrasenia);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("\nContrasenia aceptada\n");
											
										}
									}
								}
							}
						}
					}
				}
			}
	
	printf("\nIngrese el DNI: ");
	scanf("%d", v.dni);
	
	printf("\nIngrese el numero de telefono: ");
	_flushall();
	gets(v.telefono);
	
}

void usu(usuario u)
{
		char i [30];
		FILE *usu
		usu = fopen("usuario.dat" , "a+b");
		bool f1=false, f2=false, f3=false, f4=false, f5=false;
		printf("\nRegistrar al usuario\n");
		printf("\nIngrese el nombre del usuario\n\nCondiciones:\n1-Tiene que comenzar con minuscula\n2-Tener al menos dos mayusculas\n3-No mas de tres digitos");
		_flushall();
		gets(i);
		//f1==Sea unico para cada usuario
		//f2==Comenzar con una letra minuscula
 		//f3==Tener al menos 2 letras mayusculas
 		//f4==Tener como maximo 3 digitos
 		//f5==Cantidad de caracteres
		
		while(f1==false && f2==false && f3==false && f4==false && f5==false)
		{
			rewind(usu);
			fread(&u,sizeof(usuario), 1, usu);
			while(!feof(usu))
			{
				if(strcmp(i,u.usu)== 0)
				{
					printf("\nUsuario existente, ingrese otro\n");
					gets(i);
					
				}
				else
				{
					f1=true;
				}				
			}
			if(if(i[0]=='q'     i[0]=='w'  i[0]=='e'  i[0]=='r'  i[0]=='t'  i[0]=='y'  i[0]=='u'  i[0]=='i'  i[0]=='o'  i[0]=='p'  i[0]=='a'  i[0]=='s'  i[0]=='d'  i[0]=='f'  i[0]=='g'  i[0]=='h'  i[0]=='j'  i[0]=='k'  i[0]=='l'  i[0]=='ñ'  i[0]=='z'  i[0]=='x'  i[0]=='c'  i[0]=='v'  i[0]=='b'  i[0]=='n'  i[0]=='m'))
			{
				f2=true;
			}
			else
			{
				f2=false;
				printf("\nEl nombre que ingreso no comienza con minuscula, ingrese otro\n")
				gets(i);
				
			}
			for(int n=0;i<20;n++)
			{
            	if(i[n]=='A'i[n]=='B'i[n]=='C'i[n]=='D'i[n]=='E'i[n]=='F'i[n]=='G'i[n]=='H'i[n]=='I'i[n]=='J'i[n]=='K'i[n]=='L'i[n]=='M'i[n]=='N'i[n]=='O'i[n]=='P'i[n]=='Q'i[n]=='R'i[n]=='S'i[n]=='T'i[n]=='U'i[n]=='V'i[n]=='W'i[n]=='X'i[n]=='Y'||i[n]=='Z')
				{
                     cm++;
                }
            }
		}
	
}

