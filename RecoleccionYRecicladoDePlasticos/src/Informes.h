/*
 * Informes.h
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Cliente.h"
#include "Pedidos.h"

void MostrarTodosLosClientes(eCliente lista[], int largo);
void MostrarUnCliente(eCliente unCliente);
void MostrarTodosLosPedidos(ePedidosRecoleccion lista[], int largo);
void MostrarPedidosPorId(ePedidosRecoleccion elPedido);
void ImprimirListaClienteConPendiente(eCliente lista[],ePedidosRecoleccion listado[],int largo,int largoPlastico);
void MostrarClientePorPendiente(eCliente elPedido);


#endif /* INFORMES_H_ */
