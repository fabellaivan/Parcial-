/*
 * InPut.h
 *
 *  Created on: 12 oct 2021
 *      Author: Ivan Fabella
 */

#ifndef INPUT_H_
#define INPUT_H_

int myGets(char* cadena, int longitud);
int getInt(int* pResultado);
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int reintentos);
int esNumerica(char* cadena);
int IngresarAlfanumerico(char cadena[], char* mensaje, int tam);
float IngresarFlotante(char mensaje[]);
char IngresarChar(char mensaje[]);
int RecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam);
char IngresarChar(char mensaje[]);



#endif /* INPUT_H_ */
