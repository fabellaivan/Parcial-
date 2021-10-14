/*
 ============================================================================
 Name        : RecoleccionYRecicladoDePlasticos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pedidos.h"
#include "Cliente.h"
#include "Informes.h"
#include "InPut.h"
#define TAM 5
#define TAMPUESTOS 3

int main(void) {

		setbuf(stdout, NULL);
		eCliente listaClientes[TAM];
		InicializarVectorCliente(listaClientes, TAM);
		ePedidosRecoleccion listaPedidos[TAM];
		InicializarVectorPedidos(listaPedidos, TAM);
		eCliente datoId;
		//ePedidosRecoleccion datoIdPedido;
		eTiposDePlasticos tiposDePlastico[3]=
		{
				{1,"HDPE",0},
				{2,"LDPE",0},
				{3,"PP",0}
		};
		int opcion;
		char opcionBorrar;
		int idParaBorrar;
		int idCliente;
		int idPedido;
		int testers;
		int valdacionNumero;
		int contadorId;
		int contadorIdPedidos;
		int idAux;
		//float promedio;
		int espacioLibreParaId;
		contadorId=1;
		contadorIdPedidos=1;

		do
		{
			printf("\n1. Altas de cliente"
					"\n2. Modificar datos de cliente"
					"\n3. Baja de cliente"
					"\n4. Crear pedido de recolección: "
					"\n5. Procesar residuos"
					"\n6. Imprimir Clientes: "
					"\n10. Salir\n");
			valdacionNumero=getNumero(&opcion,"Ingrese una opcion: \n","Error al ingresar opcion. \n", 3);
			if(valdacionNumero==0)
			{
				opcion=10;
				puts("Cierre de programa por intentos fallidos");
			}

			switch(opcion)
			{
			case 1:
				testers=AgregarCliente(listaClientes,&espacioLibreParaId,TAM);
				if(testers==1)
				{
				   puts("El cliente fue dado de alta exitosamente\n");
				   listaClientes[espacioLibreParaId]=AltaId(listaClientes[espacioLibreParaId],"Su numero de Id es: ", &datoId.idCliente , contadorId, TAM);
				   contadorId++;
				}
				else
				{
					puts("El cliente no pudo cargarse\n");
				}

				break;

			case 2:
				testers=BuscarClienteParaModificar(listaClientes, TAM,"Ingrse ID a modificar: \n");

				switch(testers)
				{
				case 0:
					puts("No se encontro El id a modificar, vuelva a intentarlo\n");
				break;
				case -1:
					puts("Se ha canceado la funcion de modificar\n");
				break;
				case 1:
					puts("Se ha modificado el empleado");
				break;
				}//Switch mensajes

			break;
			case 3:
				testers=getNumero(&idParaBorrar, "Ingrse ID a eliminar: \n", "Error al ingresar id a borrar.\n", 3);
				printf("%d",idParaBorrar);
				if(testers!=0)
				{
					testers=BuscarClientePorId(listaClientes,TAM,idParaBorrar);
					if(testers!=-1)
					{
						puts("El empleado a eliminar es :\n");

						MostrarUnCliente(listaClientes[idParaBorrar-1]);

						opcionBorrar=IngresarChar("Seguro desea eliminar ? \n");
						if(opcionBorrar=='s')
						{
							//listaClientes[idParaBorrar]=(listaClientes[idParaBorrar]);
							puts("Se ha eliminado correctamente. \n");
						}
						else
						{
							puts("Se cancelo la eliminacion");
						}
					}
				}

			break;

			case 4:
				MostrarTodosLosClientes(listaClientes, TAM);
				testers=getNumero(&idAux,"Ingrese el ID al que desea cargarle la cantidad de Kilos a recolectar","Vuelva a intentar con solo numeros\n", 3);
				if(testers==1)
				{
					idCliente=BuscarClientePorId(listaClientes,TAM,idAux);
					if(idCliente==-1)
					{
						puts("No se encontro el ID\n");
					}
					else
					{
						testers=CargaKilosParaRecolectar(listaPedidos,idCliente,&espacioLibreParaId,TAM);
						listaPedidos[espacioLibreParaId]=AltaIdPedidos(listaPedidos[espacioLibreParaId],"El numero del ID del pedido es: ", &datoId.idPedido , contadorId, TAM);
						contadorIdPedidos++;
					}
				}
			break;
			case 5:
				MostrarTodosLosPedidos(listaPedidos, TAM);
				testers=getNumero(&idAux,"Seleccione el ID que corresponda al siguiente proceso ","\n", 3);
				if(testers==1)
				{
					idPedido=BuscarPedidoPorId(listaPedidos,TAM,idAux);
					if(idPedido==1)
					{
						puts("No se encontro el ID\n");
					}
					else
					{
						listaPedidos[idPedido]=IngresarTipoDePlastico(tiposDePlastico[3]);
					}
				}

			break;
			case 6:
				ImprimirListaClienteConPendiente(listaClientes,listaPedidos,TAM,TAMPUESTOS);
			break;

			case 10:
				MostrarTodosLosClientes(listaClientes, TAM);
			break;

			}
		}while (opcion != 10);





return EXIT_SUCCESS;
}
