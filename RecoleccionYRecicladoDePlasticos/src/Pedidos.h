/*
 * Pedidos.h
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

typedef struct
{
	int idTipoPlastico;
	char descripcion[50];
	int kgPorTipo;
}eTiposDePlasticos;
typedef struct
{
	int idPedido;
	int idCliente;
	int idTipoPlastico;
	int cantidadKilos;
	int estadoActual;
	int isEmpty;
	eTiposDePlasticos tiposDePlastico;
}ePedidosRecoleccion;

int CargaKilosParaRecolectar(ePedidosRecoleccion lista[],int idCliente,int* espacioId,int largo);
void InicializarVectorPedidos(ePedidosRecoleccion lista[], int largo);
int BuscarPrimerEspacioLibrePedidos(ePedidosRecoleccion lista[], int tam,int* espacioLibre);
ePedidosRecoleccion IngresarCantidadKilos(ePedidosRecoleccion lista,int idCliente);
ePedidosRecoleccion IngresarTipoDePlastico(eTiposDePlasticos listados);
ePedidosRecoleccion AltaIdPedidos(ePedidosRecoleccion lista,char mensaje[],int* numeroAlta,int contadorId,int tam);
int BuscarPedidoPorId(ePedidosRecoleccion lista[], int tam, int id);
#endif /* PEDIDOS_H_ */
