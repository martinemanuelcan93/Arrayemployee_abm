#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca2020.h"
#include "Serv&Marc.h"

int altaforzadaMarca1(Marca* marca,int posicion,int* id,char* descripcion)
{
	int retorno =1;
	Marca buffer;
	if(marca!=NULL && posicion>=0)
	{
	    (*id)++;
	    strcpy(buffer.descripcion,descripcion);
	    buffer.idMarca=*id;
	    marca[posicion]=buffer;
	    retorno=0;
	}
	return retorno;
}
int altaforzadaMarca2(Marca* marca,int tam){
	Marca buffermarca[]=
	{
	    {1000,"Sony"},
	    {1001,"Wirpool"},
	    {1002,"Liliana"},
	    {1003,"Gafa"},
	    {1004,"Philips"},
	};
	for(int i=0;i<tam;i++)
	{
	    marca[i]=buffermarca[i];
	}
	return 0;
}
int printMarcas(Marca* data, int tam)
{
	int retorno=-1;
	if(data!=NULL && tam >0)
	{
	    printf("Marcas : \n");
	    for(int i=0;  i<tam  ;i++)
	    {
		printf("\t-  %s - \n",data[i].descripcion);
	    }
	    retorno=0;
	}
	return retorno;
}
/* 1er parametro "marca",2do su "tamanio", 3 "auxiliar o puntero" a id.marca
 * Valida la marca ingresada de las marcas hardcodeadas previamente
 * contempla 3 intentos en caso que se haya ingresado algo incorrecto
 * devuelve 0 si esta todoo ok
 * */
int getMarca(Marca* marca, int tamanio_marca,int* id_aux_marca){
	int retorno=1;
	char buffer_marca[sizeof((*marca).descripcion)];
	int reintentos=3;
	if(marca!=NULL && tamanio_marca>0)
	{
	    printMarcas(marca, tamanio_marca);
	    do{

		getChar(buffer_marca,sizeof((*marca).descripcion),"\nIngrese nombre de la marca :","Ingrese solo letras",3);
		formatoName(buffer_marca);

		for (int i=0;  i<tamanio_marca ; i++)
		{
		    if(strcmp(buffer_marca, marca[i].descripcion)==0)
		    {
			*id_aux_marca = marca[i].idMarca; // escribe id de marca en puntero a id
			puts("Ok...");
			retorno=0;
			break;
		    }
		    else if(i==tamanio_marca-1) // cuando se recorrio todoo el array de  marcas
						// y no hay coincidencias:
		    {
			puts("# No se encontro marca  # \n");
			printf("Intentos restantes %d\n",reintentos);
			reintentos--;
		    }
		}
	     }while(reintentos>0 && retorno!=0);
	}
	return retorno;
}
void strcpyMarcaporID(char* buffer,int idmarca_buscada,Marca* marca,int tamanio_marca)
{
    if(buffer!=NULL && idmarca_buscada>0 && marca!=NULL && tamanio_marca >0)
    {
	for(int i=0;  i<tamanio_marca ;i++)
	{
	    if(idmarca_buscada== marca[i].idMarca)
	    {
		strcpy(buffer,marca[i].descripcion);
	    }
	}
    }
}
int altaforzadaServicio(Servicio* servicio,int tam){
	if(servicio!=NULL && 0<tam ){
	Servicio bufferservicio[]={
				{20000,"Garantia     ",250},     //0
				{20001,"Mantenimiento",500},	 //1
				{20002,"Repuestos    ",400},	 //2
				{20003,"Refaccion    ",600}		 //3
		};
		for(int i=0;i<tam;i++){
			servicio[i]=bufferservicio[i];
		}
	}

	return 0;
}
int printServicios(Servicio* servicio, int tam){
	int retorno=-1;
	if(servicio!=NULL && tam >0){
		printf("|Id       |Servicio        |Precio \n");

		for(int i=0;  i<tam  ;i++){
		printf("%d  %15s      %6.2f\n",
				servicio[i].idServicio,
				servicio[i].descripcion,
				servicio[i].precio);

		}
		retorno=0;
	}
		return retorno;
}
