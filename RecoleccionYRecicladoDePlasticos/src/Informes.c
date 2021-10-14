/*
 * Informes.c
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */
#include "Cliente.h"
#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define EMPTY 0
#define FULL 1
#define PENDIENTE 0
#define COMPLETADO 1
void MostrarTodosLosClientes(eCliente lista[], int largo)
{

		for(int i=0;i<largo;i++)
		{
			if(lista[i].isEmpty==FULL)
			{
				printf("\t");
				MostrarUnCliente(lista[i]);
			}
		}
}


void MostrarUnCliente(eCliente unCliente)
{
	printf("%4d %-10s \n",unCliente.idCliente,unCliente.nombreEmpresa);

}
void MostrarTodosLosPedidos(ePedidosRecoleccion lista[], int largo)
{

	for(int i=0;i<largo;i++)
	{
		if(lista[i].isEmpty==FULL)
		{
			printf("\t");
			MostrarPedidosPorId(lista[i]);
		}
	}

}
void MostrarPedidosPorId(ePedidosRecoleccion elPedido)
{
	printf("%4d %4d \n",elPedido.idPedido, elPedido.cantidadKilos);

}
void ImprimirListaClienteConPendiente(eCliente lista[],ePedidosRecoleccion listado[],int largo,int largoPlastico)
{

	for(int i=0;i<largoPlastico;i++)
	{	printf("dentroFor");

		for(int j=0;j<largo;j++)
		{
			if(lista[i].idCliente==listado[j].idCliente)
				{
					printf("DentroIF");
					printf("\t");
					MostrarClientePorPendiente(lista[i]);
				}
		}

	}

}
/*6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
de recolección” que posee en estado “Pendiente”.*/
void MostrarClientePorPendiente(eCliente eCliente)
{
	printf("%4d %-10s %4d",eCliente.idCliente,eCliente.nombreEmpresa,eCliente.pedidosDeRecoleccion.cantidadKilos);
}

