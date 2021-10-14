/*
 * Cliente.c
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */
#include "Cliente.h"
#include "Informes.h"
#include "InPut.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//#include "Input.h"
#define EMPTY 0
#define FULL 1
#define REINTENTOS 3


void InicializarVectorCliente(eCliente lista[], int largo)
{
    for(int i = 0;i < largo; i++)
    {
        lista[i].isEmpty = EMPTY;
    }
}
int AgregarCliente(eCliente lista[],int* espacioId,int largo)
{
	int espacioLibre;
	int index = BuscarPrimerEspacioLibreCliente(lista, largo,&espacioLibre);

	if(index==1)
	{
		lista[espacioLibre] = IngresarUnCliente(lista[espacioLibre]);
		if(lista[espacioLibre].isEmpty==EMPTY)
		{
			index=-1;
		}
		else
		{
			*espacioId=espacioLibre;
		}

	}
return index;

}
eCliente EliminarCliente(eCliente lista)
{

	lista.isEmpty=EMPTY;

	return lista;
}
int BuscarPrimerEspacioLibreCliente(eCliente lista[], int tam,int* espacioLibre)
{
	int i;
	for(i = 0; i<tam; i++)
	{
		if(lista[i].isEmpty == EMPTY)
		{
			*espacioLibre = i;
			return 1;
			break;
		}
	}
	return 0;
}
eCliente IngresarUnCliente(eCliente lista)
{
	eCliente dato;
	int validar=0;
	int validacionWhile=0;
	do
	{
		validar=RecibeCadenaSoloCaracteres(dato.nombreEmpresa, "\nIngrese el nombre de la empresa: \n",REINTENTOS, 18);
		if(validar==0)
		{
			break;
		}

		validar=RecibeCadenaSoloCaracteres(dato.localidad, "\nIngrese localidad: \n",REINTENTOS, 50);
		if(validar==0)
		{
			break;
		}
		validar=IngresarAlfanumerico(dato.direccion, "\nIngrese direccion: \n", 50);
		if(validar==0)
		{
			break;
		}

		validar=IngresarAlfanumerico(dato.cuit, "\nIngrese Cuit: \n", 50);
		if(validar==0)
		{
			break;
		}
	}while(validacionWhile!=0);


	if(validar==1)
	{
		dato.isEmpty=FULL;

	}
	else
	{
		dato.isEmpty=EMPTY;
	}
	return dato;
}
eCliente AltaId(eCliente lista,char mensaje[],int* numeroAlta,int contadorId,int tam)
{

		lista.idCliente=contadorId;

		printf("%s %d",mensaje,contadorId++);
		*numeroAlta=contadorId++;
		return lista;

}
int BuscarClienteParaModificar(eCliente lista[], int tam, char mensajeBusqueda[])
{
	int id;
	int idAux;
	int retorno=0;
	int testers;

	testers=getNumero(&idAux,mensajeBusqueda,"Vuelva a intentar con solo numeros\n", 3);
	if(testers==1)
	{
		id=BuscarClientePorId(lista,tam,idAux);
	}

	if(!(id==-1)&&(testers==1))
	{
		testers=ConfirmacionDeModificarCliente(lista[id],"El cliente a modificar es :\n", "Desea continuar con la modificacion S o N  ?\n");
		if(testers==1)
		{
			retorno=1;
		}

	}
	return retorno;
}
int ConfirmacionDeModificarCliente(eCliente lista,char mensajeCualAModificar[], char mensajeParaConfirmar[])
{
	char opcion;
	int validacionModificado;
	int retorno=0;
	printf(mensajeCualAModificar);
	MostrarUnCliente(lista);
	opcion=IngresarChar(mensajeParaConfirmar);

	if(opcion=='s')
	{
		lista=ModificarCliente(lista,"\n1-Modificar direccion\n2-Modificar Localidad  \n",&validacionModificado);

		if(validacionModificado==1)
		{
			MostrarUnCliente(lista);
			retorno=1;
		}
		else
		{
			retorno=-1;
		}
	}
	return retorno;

}
eCliente ModificarCliente(eCliente elCliente,char mensaje[],int* refVerificacion)
{
	setbuf(stdout, NULL);
	char opcionSeguir;
	int opcionModificarParte;
	int testers;

	do{
		testers=getNumero(&opcionModificarParte, mensaje, "Vuelva a intentar con solo numeros",REINTENTOS);
		if(testers==1)
		{
			switch(opcionModificarParte)
			{
			case 1:
				IngresarAlfanumerico(elCliente.direccion, "\nIngrese nueva direccion: \n", 50);
			break;
			case 2:
				RecibeCadenaSoloCaracteres(elCliente.localidad, "\nIngrese nueva localidad: \n",REINTENTOS, 50);
			break;

			default:
				puts("Opcion Invalida");
				//*refVerificacion=0;
			break;
			}

			opcionSeguir=IngresarChar("Desea continuar con la modificacion  ?\n");

		}
	}while(opcionSeguir=='s');

	*refVerificacion=1;

	return elCliente;
}

int BuscarClientePorId(eCliente lista[], int tam, int id)
{
	int i;
	int index;

	index = -1;
	for(i = 0; i<tam; i++){
		if(lista[i].isEmpty==FULL && lista[i].idCliente == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
