/*
 * Cliente.h
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Pedidos.h"

typedef struct
{
	int idCliente;
	int idPedido;
	char nombreEmpresa[50];
	char localidad[50];
	char direccion[50];
	int cuit;
	int isEmpty;
	ePedidosRecoleccion pedidosDeRecoleccion;

} eCliente;

void InicializarVectorCliente(eCliente lista[], int largo);
int AgregarCliente(eCliente lista[],int* espacioId,int largo);
int BuscarPrimerEspacioLibreCliente(eCliente lista[], int tam,int* espacioLibre);
eCliente IngresarUnCliente(eCliente lista);
eCliente AltaId(eCliente lista,char mensaje[],int* numeroAlta,int contadorId,int tam);
int BuscarClienteParaModificar(eCliente lista[], int tam, char mensajeBusqueda[]);
int ConfirmacionDeModificarCliente(eCliente lista,char mensajeCualAModificar[], char mensajeParaConfirmar[]);
int BuscarClientePorId(eCliente lista[], int tam, int id);
eCliente ModificarCliente(eCliente elCliente,char mensaje[],int* refVerificacion);


#endif /* CLIENTE_H_ */
