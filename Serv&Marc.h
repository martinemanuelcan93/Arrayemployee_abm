#ifndef SERVICIOS_MARCAS_H_
#define SERVICIOS_MARCAS_H_
typedef struct{
	int idMarca;
	char descripcion[20];
}Marca;
typedef struct {
	int  idServicio;
	char descripcion[50];
	float precio;
}Servicio;

int altaforzadaMarca1(Marca* marca,int posicion,int* id,char* descripcion);
int altaforzadaMarca2(Marca* marca,int tam);
int printMarcas(Marca* marca, int tam);
void strcpyMarcaporID(char* buffer,int idmarca_buscada,Marca* marca,int tamanio_marca);
int getMarca(Marca* marca, int tamanio_marca,int* id_aux_marca);
int altaforzadaServicio(Servicio* servicio,int tam);
int printServicios(Servicio* servicio, int tam);
#include "Serv&Marc.h"
#endif /* SERVICIOS_MARCAS_H_ */
