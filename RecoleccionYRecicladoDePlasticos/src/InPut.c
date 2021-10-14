/*
 * InPut.c
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"

float IngresarFlotante(char mensaje[])
{
    float numero;

    printf("%s",mensaje);
	scanf("%f",&numero );

	return numero;
}
int RecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam)
{
	setbuf(stdout,NULL);
	char auxiliarString[1000];
	int valido=0;
	int retorno;
	int largo;

	if (cadena != NULL && mensaje != NULL)
	{
		do
		{
			if(reintentos==0)
			{
				retorno=0;
				break;
			}
			printf(mensaje);
			fflush(stdin);
			fgets(auxiliarString,21,stdin);
			largo=strlen(auxiliarString);

			valido=0;

			if( largo > tam )
			{
				reintentos--;
				valido=1;
				printf("Ingreso demaciados caracteres. Quedan %d intentos\n",reintentos);
			}
			if(valido==1|| auxiliarString[0]==' '||auxiliarString[0]=='\n')
			{
				reintentos--;
				valido=1;
				printf("Por favor, no ingrese espacios o enter en primer lugar. Quedan %d intentos\n",reintentos);
			}
			if(valido==0)
			{
				for(int i=0;i<largo-1;i++)
				{
					if((auxiliarString[i]<'a'||auxiliarString[i]>'z')&&(auxiliarString[i]<'A'||auxiliarString[i]>'Z')&&!(auxiliarString[i]==' '))
					{
						valido=1;
						reintentos--;
						printf("Por favor, ingrese solo letras. Quedan %d intentos\n",reintentos);
						break;
					}
				}
			}

		}while(valido!=0);

		if(valido==0)
		{
			auxiliarString[largo-1]='\0';
			strcpy(cadena, auxiliarString);
			retorno=1;
		}

	}
	return retorno;
}
int IngresarAlfanumerico(char cadena[], char mensaje[], int tam)
{
	setbuf(stdout,NULL);
	char auxiliarString[1000];
	char reintentar='n';
	int valido=0;
	int retorno=0;
	int largo;

	if(cadena != NULL && mensaje != NULL)
	{
		do
		{
			printf(mensaje);
			fflush(stdin);
			fgets(auxiliarString,21,stdin);
			largo=strlen(auxiliarString);

			if(largo>tam)
			{
				valido=1;
				puts("Ingreso demaciados caracteres\n");
				reintentar=IngresarChar("Desea volver a intentar? Oprima la tecla 's' si es asi. Sino saldra");

			}
			if(valido==0)
			{
				auxiliarString[largo-1]='\0';
				strcpy(cadena, auxiliarString);
				retorno=1;
			}

		}while(reintentar=='s');

	}

	return retorno;
}
char IngresarChar(char mensaje[])
{
	char opcion;
	fflush(stdin);
	printf("%s",mensaje);
	scanf("%c",&opcion);
	opcion=tolower(opcion);


	return opcion;

}
int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}

int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[1000];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

int getNumero(int* pResultado, char* mensaje, char* mensajeError,  int reintentos)
{
	int retorno=0;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)

		do
		{

			printf("%s",mensaje);
			if(getInt(&buffer)==0)
			{
				*pResultado=buffer;
				retorno= 1;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);


		}while(reintentos>=0);

	return retorno;
}
int esNumerica(char* cadena)
{
	int retorno=1;
	int i=0;
	if(cadena[0]=='-')
	{
		i=1;
	}

	for(;cadena[i] != '\0';i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
			break;
		}
	}


	return retorno;
}
