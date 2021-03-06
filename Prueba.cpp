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
    char apynom[60];
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

int menu ();
int menu ()
{
    int opcion=-1;
    printf("\t\tMenu principal\n\n");
    printf("\n\n1-Modulo Consultorio Veterinario\n\n");
    printf("\n\n2-Modulo del asistente\n\n");
    printf("\n\n3-Modulo Administracion\n\n");
    printf("\n\n4-Cerrar el programa\n\n");

    printf("\nIngrese la opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

int menuadmin();
int menuadmin()
{
	int opcadmin=-1;
	printf("\t\tMenu Administracion\n\n");
	system("cls");
	printf("\n\n1-Registrar Veterinario\n\n");
	printf("\n\n2-Registrar Usuario Asistente\n\n");
	printf("\n\n3-Atenciones por Veterinarios\n\n");
	printf("\n\n4-Ranking de Veterinarios por Atenciones\n\n");
	printf("\n\n5-Cerrar la aplicacion\n\n");
	
	printf("\nIngrese una opcion: ");
	scanf("%d", &opcadmin);
	return opcadmin;
}

int menuconsult();
int menuconsult()
{
    int opcconsult=-1;
	system("cls");
    printf("\t\tMenu Consultorio Veterinario\n\n");
    printf("\n\n1-Iniciar Secion\n\n");
    printf("\n\n2-Visualizar Lista de Espera de Turnos\n\n");
    printf("\n\n3-Registrar Evoluci�n de la Mascota\n\n");
    printf("\n\n4-Cerrar el programa\n\n");

    printf("\nIngrese la opcion: ");
    scanf("%d", &opcconsult);
	return opcconsult;
}

int menuasistente();
int menuasistente()
{
	int opcasist=-1;
	printf("\t\tMenu del asistente\n\n");
	system("cls");
	printf("\n\n1-Iniciar Sesi�n\n\n");
	printf("\n\n2-Registrar Mascota\n\n");
	printf("\n\n3-Registrar Turno\n\n");
	printf("\n\n4-Listado de Atenciones por Veterinario y Fecha\n\n");
	printf("\n\n5-Cerrar la aplicacion\n\n");
	
	printf("\nIngrese la opcion: ");
	scanf("%d", &opcasist);	
	return opcasist;
}
//FUNCIONES MODULO CONSULTA
int Datosvet (FILE *vet, veterinario v, char pass[10]);
int Datosvet (FILE *vet, veterinario v, char pass[10])
{
   			int mat;
			bool band;	
			vet= fopen("Veterinarios.dat","r+b");
			system("cls");
			printf("Inicio de sesion:");
			printf("\nIngrese su matricula: ");
			scanf("%d",&mat);
			fread(&v,sizeof(veterinario),1,vet);
			band=false;
			while(band==false)
			{
				while(!feof(vet))
				{
					if(mat==v.matricula)
					{
						band=true;
						fread(&v,sizeof(veterinario),1,vet);
					}
					else
					{
						fread(&v,sizeof(veterinario),1,vet);
					}
				
				}
				rewind(vet);
				if(band==false)
				{
					printf("\nMatricula incorrecta, por favor ingrese su matricula de nuevo: ");
					scanf("%d",&mat);
				}
				
			}
			printf("\nMatricula correcta, ingrese su contrasenia porfavor: ");
			_flushall();
			gets(pass);
			rewind(vet);
			fread(&v,sizeof(veterinario),1,vet);
			band=false;
			while(band==false)
			{
				while(!feof(vet))
				{
					if(strcmp(pass,v.contrasenia)==0)
					{
						band=true;
						fread(&v,sizeof(veterinario),1,vet);
					}
					else
					{
						fread(&v,sizeof(veterinario),1,vet);
					}
				}
				rewind(vet);
				if(band==false)
				{
					printf("\nContrasenia incorrecta, porfavor ingresar su contrasenia otra vez: ");
					_flushall();
					gets(pass);
				}
			}
			
			printf("\nContrasenia aceptada\nSesion iniciada con exito!");
			fclose(vet);
			return mat;
			system("pause");
			system("cls");

			
			
}
void Turnomasc (FILE *tur, FILE *vet, FILE *mas, veterinario v, turnos t, mascota m, int mm);
void Turnomasc (FILE *tur, FILE *vet, FILE *mas, veterinario v, turnos t, mascota m, int mm)
{
	int i= 1;
	tur=fopen("turnos.dat","r+b");
	vet=fopen("Veterinarios.dat","r+b");
	
	rewind(tur);	
	fread(&t,sizeof(turnos),1,tur);
	
	while(!feof(tur))
	{

		if(mm == t.mat)
		{
		
			printf("\n Turno numero %d \n" , i);
			printf("\n --------- \n");
			printf("\nFecha:");
			printf("\n\tDia: %d", t.fn.dia);
			printf("\n\tMes: %d", t.fn.mes);
			printf("\n\tA%co: %d",164, t.fn.anio);
			printf("\nDNI del due�o: %d", t.dni);
			printf("\nNombre y Apellido del due�o: %s", t.apynom);
			printf("\n --------- \n");
			i++;
			
			fread(&t,sizeof(turnos),1,tur);
		}
		else
		{
		
			fread(&t,sizeof(turnos),1,tur);	
		
		}		

	}

}
void regeva (FILE *tur, turnos t);
void regeva (FILE *tur, turnos t)
{
    int op;
    tur=fopen("turnos.dat","r+b");
    _flushall();
    printf("\nRegistre la evolucion de la mascota: ");
    gets(t.detalle);
    printf ("\nSe registro con exito la evolucion de su mascota\n");
    fwrite(&t, sizeof(turnos), 1,tur);
}
//FUNCIONES MODULO ADMINISTRACION 
void reg(veterinario v,FILE *vet);
void reg(veterinario v,FILE *vet)
{
	system("cls");
	int aceptar=false;
	vet = fopen("Veterinarios.dat", "a+b");
	//printf("Registrar al veterinario\n");
	printf("\nIngrese el nombre y apellido del veterinario: ");
	_flushall();
	gets(v.apynom);
	
	printf("\nIngrese la matricula: ");
	scanf("%d", &v.matricula);
	
	printf("\nIngrese la contrasenia para el veterinario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contrasenia:");
	_flushall();
	gets(v.contrasenia);
	aceptar=false;
		while(aceptar==false){
		
				if(strstr(v.contrasenia,"Q")==NULL &&strstr(v.contrasenia,"W")==NULL && strstr(v.contrasenia,"E")==NULL && strstr(v.contrasenia,"R")==NULL && strstr(v.contrasenia,"T")==NULL && strstr(v.contrasenia,"Y")==NULL && strstr(v.contrasenia,"U")==NULL && strstr(v.contrasenia,"I")==NULL && strstr(v.contrasenia,"O")==NULL && strstr(v.contrasenia,"P")==NULL && strstr(v.contrasenia,"A")==NULL && strstr(v.contrasenia,"S")==NULL && strstr(v.contrasenia,"D")==NULL && strstr(v.contrasenia,"F")==NULL && strstr(v.contrasenia,"G")==NULL && strstr(v.contrasenia,"H")==NULL && strstr(v.contrasenia,"J")==NULL && strstr(v.contrasenia,"K")==NULL && strstr(v.contrasenia,"L")==NULL && strstr(v.contrasenia,"�")==NULL && strstr(v.contrasenia,"Z")==NULL && strstr(v.contrasenia,"X")==NULL && strstr(v.contrasenia,"C")==NULL && strstr(v.contrasenia,"V")==NULL && strstr(v.contrasenia,"B")==NULL && strstr(v.contrasenia,"N")==NULL && strstr(v.contrasenia,"M")==NULL)
				{
					printf("La contrasenia no posee mayuscula, ingrese de nuevo la contrasenia: ");
					_flushall;
					gets(v.contrasenia);
				}
				else
				{
					if(strstr(v.contrasenia,"q")==NULL &&strstr(v.contrasenia,"w")==NULL && strstr(v.contrasenia,"e")==NULL && strstr(v.contrasenia,"r")==NULL && strstr(v.contrasenia,"t")==NULL && strstr(v.contrasenia,"y")==NULL && strstr(v.contrasenia,"u")==NULL && strstr(v.contrasenia,"i")==NULL && strstr(v.contrasenia,"o")==NULL && strstr(v.contrasenia,"p")==NULL && strstr(v.contrasenia,"a")==NULL && strstr(v.contrasenia,"s")==NULL && strstr(v.contrasenia,"d")==NULL && strstr(v.contrasenia,"f")==NULL && strstr(v.contrasenia,"g")==NULL && strstr(v.contrasenia,"h")==NULL && strstr(v.contrasenia,"j")==NULL && strstr(v.contrasenia,"k")==NULL && strstr(v.contrasenia,"l")==NULL && strstr(v.contrasenia,"�")==NULL && strstr(v.contrasenia,"z")==NULL && strstr(v.contrasenia,"x")==NULL && strstr(v.contrasenia,"c")==NULL && strstr(v.contrasenia,"v")==NULL && strstr(v.contrasenia,"b")==NULL && strstr(v.contrasenia,"n")==NULL && strstr(v.contrasenia,"m")==NULL)
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
							if(strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,".")!=NULL && strstr(v.contrasenia,"-")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,",")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL && strstr(v.contrasenia,"�")!=NULL)
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
										for(int i=0;i<strlen(v.contrasenia);i++)
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
	scanf("%d", &v.dni);
	
	printf("\nIngrese el numero de telefono: ");
	_flushall();
	gets(v.telefono);
	fwrite(&v,sizeof(veterinario),1,vet);
	system("cls");
	
}
void usur(FILE *usu , usuario u);
void usur(FILE *usu , usuario u)
{
		char au [30];
		int aceptar;
		int cm,cn;
		usu = fopen("usuario.dat" , "a+b");
		bool f1=false, f2=false, f3=false, f4=false, f5=false;
		printf("\nRegistrar al usuario\n");
		printf("\nIngrese el nombre del usuario\n\nCondiciones:\n1-Tiene que comenzar con minuscula\n2-Tener al menos dos mayusculas\n3-No mas de tres digitos \n");
		_flushall();
		gets(au);
		//f1==Sea unico para cada usuario
		//f2==Comenzar con una letra minuscula
 		//f3==Tener al menos 2 letras mayusculas
 		//f4==Tener como maximo 3 digitos
 		//f5==Cantidad de caracteres
		
		while(f1==false && f2==false && f3==false && f4==false && f5==false)
		{
			
			if(au[0]=='q' || au[0]=='w' || au[0]=='e' || au[0]=='r' ||  au[0]=='t' ||  au[0]=='y' ||  au[0]=='u' || au[0]=='i' || au[0]=='o' ||  au[0]=='p' || au[0]=='a' ||  au[0]=='s' ||  au[0]=='d' ||  au[0]=='f' ||  au[0]=='g' ||  au[0]=='h' ||  au[0]=='j' || au[0]=='k' ||  au[0]=='l' ||  au[0]=='�' || au[0]=='z'  || au[0]=='x' ||  au[0]=='c' ||  au[0]=='v' ||  au[0]=='b' ||  au[0]=='n' ||  au[0]=='m')
			{
				f2=true;
			}
			else
			{
				f2=false;
				printf("\nEl nombre que ingreso no comienza con minuscula, ingrese otro: ");
				gets(au);
				
			}
			for(int i=0;i<20;i++)
			{
            	if(au[i]=='A' || au[i]=='B' || au[i]=='C' || au[i]=='D' || au[i]=='E' || au[i]=='F' || au[i]=='G' || au[i]=='H' || au[i]=='I' || au[i]=='J' || au[i]=='K' || au[i]=='L' || au[i]=='M' || au[i]=='N' || au[i]=='O' || au[i]=='P' || au[i]=='Q' || au[i]=='R' || au[i]=='S' || au[i]=='T' || au[i]=='U' || au[i]=='V' || au[i]=='W' || au[i]=='X' || au[i]=='Y'||au[i]=='Z')
				{
					cm++;
                }
                
            }
            if(cm<2)
			{
				printf("\nNo posee 2 mayusculas o mas, Ingrese otro:  ");
				gets(au);	
				f3=false;
			}
			else
			{
				f3=true;
			}
			for(int i=0;i<20;i++)
			{
						if(au[i]=='1')
						{
							cn++;
						}
						else
						{
							if(au[i]=='2')
							{
								cn++;
							}
							else
							{
								if(au[i]=='3')
								{
									cn++;
								}
								else
								{
									if(au[i]=='4'){
										cn++;	
						   			}
						   			else
									   {
						   				if(au[i]=='5')
										   {
						   					cn++;
									    	}
									    else
										{
									    	if(au[i]=='6')
											{
									    		cn++;
											}
											else{
												if(au[i]=='7')
												{
													cn++;
												}
												else
												{
													if(au[i]=='8')
													{
														cn++;
													}
													else
													{
														if(au[i]=='9')
														{
															cn++;
														}
														else
														{
															if(au[i]=='0')
															{
																cn++;
															}
														}
													}
												}
											}
										}
								    }
								}
							}
						}
			}
			if(cn>3)
			{
				printf("\nEl maximo de digitos permitidos es 3, Ingresar de nuevo: ");
				gets(au);
				
				f4=false;
			}
			else
			{
				f4 = true;
			}
			if(strlen(au)>10 && strlen(au)<6)
			{
				printf("\nEl tamanio del nombre no es valido, por favor digite otro: ");
				gets(au);
				f5=false;
			}
			else
			{
				f5=true;
			}
			rewind(usu);
			fread(&u,sizeof(usuario),1,usu);
			while(!feof(usu))
			{
				if(strcmp(au,u.usu)==0)
				{
					printf("\nUsuario existente, ingrese otro\n");
					gets(au);
					f1=false;
					fread(&u,sizeof(usuario),1,usu);
				}
				else
				{
					f1=true;
					fread(&u,sizeof(usuario),1,usu);
				}
			}	
			
			printf("\nIngrese la contrasenia para el usuario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contrasenia: ");
			_flushall();
			gets(u.contrasenia);
			aceptar = false;
			while(aceptar==false)
			{
				if(strstr(u.contrasenia,"Q")==NULL && strstr(u.contrasenia,"W")==NULL && strstr(u.contrasenia,"E")==NULL && strstr(u.contrasenia,"R")==NULL && strstr(u.contrasenia,"T")==NULL && strstr(u.contrasenia,"Y")==NULL && strstr(u.contrasenia,"U")==NULL && strstr(u.contrasenia,"I")==NULL && strstr(u.contrasenia,"O")==NULL && strstr(u.contrasenia,"P")==NULL && strstr(u.contrasenia,"A")==NULL && strstr(u.contrasenia,"S")==NULL && strstr(u.contrasenia,"D")==NULL && strstr(u.contrasenia,"F")==NULL && strstr(u.contrasenia,"G")==NULL && strstr(u.contrasenia,"H")==NULL && strstr(u.contrasenia,"J")==NULL && strstr(u.contrasenia,"K")==NULL && strstr(u.contrasenia,"L")==NULL && strstr(u.contrasenia,"�")==NULL && strstr(u.contrasenia,"Z")==NULL && strstr(u.contrasenia,"X")==NULL && strstr(u.contrasenia,"C")==NULL && strstr(u.contrasenia,"V")==NULL && strstr(u.contrasenia,"B")==NULL && strstr(u.contrasenia,"N")==NULL && strstr(u.contrasenia,"M")==NULL)
				{
					printf("La contrasenia no posee mayuscula, ingrese de nuevo la contrasenia");
					_flushall;
					gets(u.contrasenia);
				}
				else
				{
					if(strstr(u.contrasenia,"q")==NULL && strstr(u.contrasenia,"w")==NULL && strstr(u.contrasenia,"e")==NULL && strstr(u.contrasenia,"r")==NULL && strstr(u.contrasenia,"t")==NULL && strstr(u.contrasenia,"y")==NULL && strstr(u.contrasenia,"u")==NULL && strstr(u.contrasenia,"i")==NULL && strstr(u.contrasenia,"o")==NULL && strstr(u.contrasenia,"p")==NULL && strstr(u.contrasenia,"a")==NULL && strstr(u.contrasenia,"s")==NULL && strstr(u.contrasenia,"d")==NULL && strstr(u.contrasenia,"f")==NULL && strstr(u.contrasenia,"g")==NULL && strstr(u.contrasenia,"h")==NULL && strstr(u.contrasenia,"j")==NULL && strstr(u.contrasenia,"k")==NULL && strstr(u.contrasenia,"l")==NULL && strstr(u.contrasenia,"�")==NULL && strstr(u.contrasenia,"z")==NULL && strstr(u.contrasenia,"x")==NULL && strstr(u.contrasenia,"c")==NULL && strstr(u.contrasenia,"v")==NULL && strstr(u.contrasenia,"b")==NULL && strstr(u.contrasenia,"n")==NULL && strstr(u.contrasenia,"m")==NULL)
					{
						printf("La contrasenia no posee minuscula, ingrese de nuevo la contrasenia");
						_flushall;
						gets(u.contrasenia);
					}
					else
					{
						if(strstr(u.contrasenia,"0")==NULL && strstr(u.contrasenia,"1")==NULL && strstr(u.contrasenia,"2")==NULL && strstr(u.contrasenia,"3")==NULL && strstr(u.contrasenia,"4")==NULL && strstr(u.contrasenia,"5")==NULL && strstr(u.contrasenia,"6")==NULL && strstr(u.contrasenia,"7")==NULL && strstr(u.contrasenia,"8")==NULL && strstr(u.contrasenia,"9")==NULL)
						{
							printf("La contrasenia no posee numeros, ingrese de nuevo la contrasenia");
							_flushall;
							gets(u.contrasenia);
						}
						else
						{
							if(strstr(u.contrasenia,",")!=NULL && strstr(u.contrasenia,".")!=NULL && strstr(u.contrasenia,"-")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,",")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL && strstr(u.contrasenia,"�")!=NULL)
							{
								printf("La contrasenia posee signos de puntuacion, ingrese de nuevo la contrasenia");
								_flushall;
								gets(u.contrasenia);
							}
							else
							{
								if(strlen(u.contrasenia)<6)
								{
									printf("La contrasenia es muy corta, ingrese de nuevo la contrasenia");
									_flushall;
									gets(u.contrasenia);
								}
								else
								{
									if(strlen(u.contrasenia)>32)
									{
										printf("La contrasenia es muy larga, ingrese de nuevo la contrasenia");
										_flushall;
										gets(u.contrasenia);
									}
									else
									{
										for(int i=0;i<strlen(u.contrasenia);i++)
										{
											if((u.contrasenia[i+2]==u.contrasenia[i+1]+1) && (u.contrasenia[i+1]==u.contrasenia[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese de nuevo la contrasenia: ");
												_flushall();
												gets(u.contrasenia);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("Contrasenia aceptada");
											
										}
									}
								}
							}
						}
					}
				}
			}	
		}
	strcpy(u.usu,au);
    fwrite(&u,sizeof(usuario),1,usu);
    printf("\nEl usuario asistente fue guardado correctamente\n");
    system("pause");
    system("cls");
}
void ate(usuario u,turnos t,veterinario v,FILE *tur,FILE *vet);

void ate(usuario u,turnos t, veterinario v,FILE *tur,FILE *vet)
{
	char auvet[80];
	int i=0;
	vet=fopen("Veterinarios.dat","r+b");
	tur=fopen("turnos.dat","r+b");
						
	printf("\nATENCIONES POR VETERINARIOS\n");
	_flushall();
	printf("Veterinario: ");
	gets(auvet);
						
	fread(&v,sizeof(veterinario),1,vet);
	fread(&t,sizeof(turnos),1,tur);
	while(!feof(vet)&& !feof(tur))
	{
		if(strcmp(auvet,v.apynom)==0)
		{
								
			if(t.mat==v.matricula)
			{
				printf("Turno %d: \n",i);
				i++;
				printf("\nFecha:");
				printf("\nDia: %d", t.fn.dia);
				printf("\nMes: %d", t.fn.mes);
				printf("\nAnio: %d", t.fn.anio);
				printf("\nDNI del due�o: %d", t.dni);
				fread(&v,sizeof(veterinario),1,vet);
				fread(&t,sizeof(turnos),1,tur);
										
			}
			else
			{
				fread(&v,sizeof(veterinario),1,vet);
				fread(&t,sizeof(turnos),1,tur);
	
										
			}	
		}
		else
		{
			fread(&v,sizeof(veterinario),1,vet);
			fread(&t,sizeof(turnos),1,tur);
								
		}				
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void rank(usuario u,FILE *usu);

void rank(usuario u,FILE *usu)
{

	char umayor[70];
	int mayor,op;
	rewind(usu);
						
	fread(&u,sizeof(usuario),1,usu);
	while(!feof(usu))
	{
		if(u.cp>mayor)
		{
			mayor=u.cp;
			strcpy(u.apynom,umayor);
		}
		fread(&u,sizeof(usuario),1,usu);
	}
						
	printf("El veterinario que registro mas mascotas es: %s con %d mascotas", umayor, mayor);					
					
}
//FUNCIONES DEL MODULO ASISTENCIA
void VerifInicioSesion (FILE *usu , usuario u);
void VerifInicioSesion (FILE *usu , usuario u)
{
	
	char iniu[10], inic[10];
	bool b1, b2;
	
	usu=fopen("Usuarios.dat","r+b");
	
	
	printf("\nINICIO DE SESION");
	printf("\nUsuario: ");
	_flushall();
	gets(iniu);	
	b1=false; b2=false;
	while(b1==false)
	{
		rewind(usu);
		fread(&u,sizeof(usuario),1,usu);
		while(!feof(usu))
		{
			if(strcmp(iniu,u.usu)==0)
			{
				b1=true;
			}
			else
			{
				b1=false;
			}
			fread(&u,sizeof(usuario),1,usu);
		}
		
		if(b1==false)
		{
			printf("\nEl nombre de usuario ingresado no esta registrado, por favor digite otro: ");
			gets(iniu);
		}
		
	}
	
	printf("Contrase%ca:",164);
	_flushall();
	gets(inic);
	
	
	
	while(b2==false)
	{
		if(strcmp(inic,u.contrasenia)==0)
		{
			b2=true;
			printf("\nContrase%ca aceptada", 164);
		}
		else
		{
			b2=false;
		}
		
		if(b2==false)
		{
			printf("\nLa contrase%ca ingresada es incorrecta, por favor intente de nuevo: ");
			gets(inic);
			b2=false;
		}
	}
	
	if(b1==true && b2==true)
	{
		printf("\n\nIniciaste sesi%cn correctamente, Bienvendido %s\n",162, iniu);
	}
	



}

void RegMascota(FILE *mas , mascota m);
void RegMascota(FILE *mas , mascota m)
{

	
	mas=fopen("Mascotas.dat","a+b");
	
	printf("\nREGISTRACION DE MASCOTAS\n");
	printf("Apellido y nombre: ");
	_flushall();
    gets(m.apynom);
   
    printf("Domicilio: ");
    gets(m.domicilio);
    
	printf("DNI del due%co: ",164);
    scanf("%d",&m.dni);

    printf("Localidad: ");
    _flushall();
    gets(m.localidad);
    
    printf("Fecha de nacimiento:");
    	printf("\nDia: ");
    	scanf("%d",&m.fec.dia);
		printf("\nMes: ");
    	scanf("%d",&m.fec.mes);
		printf("\nA%co: ",164);
    	scanf("%d",&m.fec.anio);
   
    printf("Peso (kg): ");
    scanf("%f",&m.peso);
    
    printf("Ingrese el numero de telefono: ");
    _flushall();
	gets(m.tel);
	
    fwrite(&m,-sizeof(mascota),1,mas);
    
	printf("\n-------->La mascota fue guardado correctamente<--------");
	
	fclose(mas);	
	
}

void RegTurno(FILE *tur , turnos t);
void RegTurno(FILE *tur , turnos t)
{

	tur=fopen("turnos.dat","a+b");
					
	printf("\nREGISTRACION DE TURNO\n");
	
	printf("Matricula del veterinario: ");
	scanf("%d",&t.mat);

	printf("Fecha:\n");
	printf("\nDia: ");
	scanf("%d", &t.fn.dia);
	printf("\nMes: ");
	scanf("%d", &t.fn.mes);
	printf("\nA%co: ",164);
	scanf("%d", &t.fn.anio);
		
	printf("\nDNI del due%co: ",164);
	scanf("%d",&t.dni);
	

	fwrite(&t,sizeof(turnos),1,tur);	
	
	printf("\nEl turno fue guardado correctamente");
	fclose(tur);

}

void ListadoAtenciones(FILE *vet , FILE *tur , FILE *mas , veterinario v , turnos t , mascota m);
void ListadoAtenciones(FILE *vet , FILE *tur , FILE *mas , veterinario v , turnos t , mascota m)
{

	char auvet[40];
	
	vet=fopen("Veterinarios.dat","r+b");
	tur=fopen("turnos.dat","r+b");
	mas=fopen("Mascotas.dat","r+b");
	
	printf("LISTADO DE ATENCIONES POR VETERINARIOS Y FECHA\n");
	printf("Veterinario: ");
	_flushall();
	gets(auvet);
	
	fread(&v,sizeof(veterinario),1,vet);
	fread(&t,sizeof(turnos),1,tur);
	fread(&m,sizeof(mascota),1,mas);
	
	while(!feof(vet)&&!feof(tur)&&!feof(mas))
	{
		if(strcmp(auvet,v.apynom)==0)
		{
			
				if(t.mat==v.matricula)
				{
					printf("\nNombre de la mascota: %s",m.apynom);
					printf("\nFecha de turno:");
					printf("\nDia: %d", t.fn.dia);
					printf("\nMes: %d", t.fn.mes);
					printf("\nA%co: %d",164, t.fn.anio);
					printf("\nNombre del veterinario: %s",v.apynom);
					printf("\nMatricula: %d",v.matricula);
					fread(&v,sizeof(veterinario),1,vet);
					fread(&t,sizeof(turnos),1,tur);
					fread(&m,sizeof(mascota),1,mas);
				}
				else
				{
					fread(&v,sizeof(veterinario),1,vet);
					fread(&t,sizeof(turnos),1,tur);
					fread(&m,sizeof(mascota),1,mas);
				}	
		}
		else
		{
			fread(&v,sizeof(veterinario),1,vet);
			fread(&t,sizeof(turnos),1,tur);
			fread(&m,sizeof(mascota),1,mas);
		}
	}

}

main ()
{
	system("color 0a");
	printf("\t\t\t\t\t\tBIENVENIDO\n\n\n\n\n\n\n");
	system("pause");
	system("cls");
	
	int op=-1, opcon = -1, opasis=-1, opad = -1, mm=0;
	char auvet[80];	
	char pass [10];	
	FILE *mas,*tur,*vet,*usu;
	bool inisec = false;
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
				//MODULO CONSULTA
				opcon = menuconsult();
				system ("cls");
				switch(opcon)
				{
					case 1:
					{
						printf ("\nIniciar sesion\n");
						mm=Datosvet (vet, v, auvet);						
						system("pause");
						break;
					}
					case 2: 
					{
						printf("\nVisualizar Lista de Espera de Turnos\n");
						Turnomasc (tur, vet, mas, v, t, m,mm);
						system("pause");
						break;
					}
					case 3:
					{
						printf("\nRegistrar Evoluci�n de la Mascota\n");
						regeva (tur, t);
						system("pause");
						break;
					}
					case 4:
					{
						printf("\nEl programa finalizo\n");
						system("pause");
						
						break;
						
					}
					default :
					{
						printf("Opcion seleccionada incorrecta");
						system("pause");
						system("cls");
						break;
					}
				
				}
	
			}while(opcon !=4);
			
			break;
		}
		//MODULO ASISTENCIA
		case 2:
		{
			do
			{
				
				opasis = menuasistente();
				system("cls");
				switch (opasis)
				{
				
				case 1:
				{
					printf("\nIniciar Sesi�n\n");
					VerifInicioSesion(usu , u);
					bool inisec = false;
					system("pause");
					break;
					
				}	
				case 2:
				{
					printf("\nRegistrar Mascota\n");
					RegMascota(mas , m);
					system("pause");
					break;
				}
				case 3:
				{
					printf("\nRegistrar Turno\n");
					RegTurno(tur ,t);
					system("pause");
					break;
				}
				case 4:
				{
					printf("\nListado de Atenciones por Veterinario y Fecha\n");
					ListadoAtenciones(vet , tur , mas , v , t , m);
					system("pause");
					break;
				}

				case 5:
				{
					printf("\nEl programa finalizo\n");
					system("pause");
					system("cls");
					break;
				}
				default :
				{
					printf("Opcion seleccionada incorrecta");
					system("pause");
					system("cls");
					break;
				}
				
			}
			
			
				
			}while(opasis !=5);
			break;
		}
		//MODULO ADMINISTRACION
		case 3:
		{
			do
			{
				
				opad = menuadmin();
				system ("cls");
				switch(opad)
				{
					case 1:
					{
						printf("\nRegistrar Veterinario\n"); 
						reg(v,vet);
						system("pause");
						break;
					}
					case 2:
					{
						printf("\nRegistrar Usuario Asistente\n");
						usur(usu,u);
						system("pause");
						break;
					}
					case 3:
					{
						printf("\nAtenciones por Veterinarios\n");
						ate(u,t, v,tur,vet);
						system("pause");
						break;
					}
					case 4:
					{
						printf("\nRanking de Veterinarios por Atenciones\n");
						rank(u,usu);
						system("pause");
						break;
					}
					case 5:
					{
						printf("\nEl programa finalizo\n");
						system("pause");
						system("cls");
						break;
					}					
					default :
					{
						printf("Opcion seleccionada incorrecta");
						system("pause");
						system("cls");
						break;
					}
				}
				
			}while(opad !=5);
			
			break;
		}
		case 4:
		{
			printf("\nEl programa se cerro");
			system("pause");
			system("cls");
			break;
		} 
		default :
		{
			printf("Opcion seleccionada incorrecta");
			system("pause");
			system("cls");
			break;
		}	
		}
	 
	
	
	}while(op != 4);
}



