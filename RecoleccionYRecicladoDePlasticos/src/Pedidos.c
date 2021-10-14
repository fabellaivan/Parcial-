/*
 * Pedidos.c
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */
#include "InPut.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define EMPTY 0
#define FULL 1
#define REINTENTOS 3
#define PENDIENTE 0
#define COMPLETADO 1
void InicializarVectorPedidos(ePedidosRecoleccion lista[], int largo)
{
    for(int i = 0;i < largo; i++)
    {
        lista[i].isEmpty = EMPTY;
    }
}
int CargaKilosParaRecolectar(ePedidosRecoleccion lista[],int idCliente,int* espacioId,int largo)
{
	int espacioLibre;
	int index = BuscarPrimerEspacioLibrePedidos(lista, largo,&espacioLibre);

	if(index==1)
	{
		lista[espacioLibre] = IngresarCantidadKilos(lista[espacioLibre],idCliente);
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
ePedidosRecoleccion IngresarCantidadKilos(ePedidosRecoleccion lista, int idCliente)
{
	ePedidosRecoleccion dato;
	int validar=0;
	int cantidadKilos;

	validar=getNumero(&cantidadKilos, "Ingrese la cantidad de Kilos ", "Error", REINTENTOS);
	if(validar!=0)
	{
		dato.cantidadKilos=cantidadKilos;
		dato.idCliente=idCliente;
		dato.estadoActual=PENDIENTE;//pendiente
		dato.isEmpty=FULL;
	}
	else
	{
		dato.isEmpty=EMPTY;
	}

	return dato;
}
ePedidosRecoleccion AltaIdPedidos(ePedidosRecoleccion lista,char mensaje[],int* numeroAlta,int contadorId,int tam)
{

		lista.idPedido=contadorId;

		printf("%s %d",mensaje,contadorId++);
		*numeroAlta=contadorId++;
		return lista;
}

int BuscarPrimerEspacioLibrePedidos(ePedidosRecoleccion lista[], int tam,int* espacioLibre)
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
int BuscarPedidoPorId(ePedidosRecoleccion lista[], int tam, int id)
{
	int i;
	int index;

	index = -1;
	for(i = 0; i<tam; i++){
		if(lista[i].isEmpty==FULL && lista[i].idPedido == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

ePedidosRecoleccion IngresarTipoDePlastico(eTiposDePlasticos listados )
{
	ePedidosRecoleccion dato;
	int validar;
	char opcionSeguir;

	do{
		validar=getNumero(&dato.tiposDePlastico.idTipoPlastico, "Ingrese el tipo de plastico", "Error", 3);

		if(validar==0)
		{
			break;
		}
		validar=getNumero(&dato.tiposDePlastico.kgPorTipo, "Ingrese los Kilso del tipo seleccionado", "Error", 3);
		if(validar==0)
		{
				break;
		}
		opcionSeguir=IngresarChar("Ingrese S para continuar N para finalizar");


	}while(opcionSeguir!='n');

	if(validar==1)
	{
		dato.estadoActual=COMPLETADO;

	}
	else
	{
		dato.estadoActual=PENDIENTE;
	}
	return dato;
}
















