
#ifndef BIBLIOTECA2020_H_
#define BIBLIOTECA2020_H_

int getNro(int* resp,char* mensaje,char* msjError,int minimo,int maximo,int intentos);
int ordenarArrayNrico(int Array[],int i,int L,int condicion);
int ingresoTexto(char* texto[60],char* mensaje,int L);
int mostrarTexto(char texto[][60],char* mensaje,int L);


int getChar(char* string,int longitud,char* mensaje,char* msjError,int intentos);
void formatoName(char* nombreoapellido);
int getint(int* resp);
int getfloat(float* resp,char* mensaje,char* msjError,float min,float max,int intentos);
int esfloat(char* cadena);
int getf(float* resultadof);
int esnumerica(char* cadena,int limite);
int migets(char* cadena,int longitud);
#include "Biblioteca2020.h"
#endif /* BIBLIOTECA2020_H_ */
