#include "Electrodomestico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca2020.h"
#include "Serv&Marc.h"
#define TRUE 1
#define FALSE 0
#define tam_ele 6
#define tam_cli 5
#define tam_ser 4
#define tam_mar 5
#define tam_rep 10
/*  Recibe el puntero de tipo struct con su tamaño
 *  e inicializa todas las posiciones de la estructura del campo "isEmpty" en 1 (TRUE)
 *  retorna 0 si esta todo bien y -1 si los parametros no son correctos
 * */
int initElectrodomestico(Electrodomestico* elec,int tam){
	int retorno=-1;
	if(elec!=NULL && tam >0){

		for(int i=0;  i<tam  ;i++){

				elec[i].idmarca=0;
				elec[i].idElec=0;
				elec[i].serie=0;
				elec[i].isEmpty=TRUE;
				retorno=0;
			}
	}
	return retorno;
}
/* Recibe la direccion de memoria de tipo struct y su tamaño,
 * busca una posicion dentro del array que este libre
 * retorna 0 si la funcion encontro un espacio libre
 * y escribe en la direccion de memoria de posicion, la posicion encontrada
 * */
int buscarElectrodomesticoLibre(Electrodomestico* elec,int tam,int* posicion){
	int retorno = -1;
	int i;
	if(elec!=NULL && posicion!=NULL  && tam>0){
		for(i=0; i<tam ;i++){
			if (elec[i].isEmpty==TRUE){
				*posicion=*posicion+i; //retorna 0 y ademas la posicion libre encontrada
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int buscaridElectrodomestico(Electrodomestico* elec, int tam, int idBuscado, int* posicion){
    int retorno=-1;
    int i;
    if(elec!= NULL && tam>=0)
    {
        for(i=0;i<tam ;i++)
        {
            if(elec[i].isEmpty==TRUE)  //si esta vacia la posicion sigo buscando
                continue;
            else if(idBuscado == elec[i].idElec)
            {
                retorno=0;
                *posicion=i; //Devuelve la posicion del id Elec buscado !
                break;
            }
        }
    }
    return retorno;
}
int findElectrodomesticoById(Electrodomestico* elec, int tamanio_ele,int idbuscado){
	int retorno=-1;
	if(elec!=NULL && 0<tamanio_ele && 0<=idbuscado)
	{
	    for(int i=0; i<tamanio_ele ; i++)
	    {
		if(elec[i].isEmpty==TRUE) //si esta vacia la posicion sigo buscando*importante*
		continue;

		else if(elec[i].idElec==idbuscado)
		{
			retorno = i;
			break;
		}
	    }
	}
	else
	{
	    printf("\nNo se encontro Id ingresado! (%d) ",idbuscado);
	    retorno=1;
	}
		return retorno;
}
int addElectrodomestico(Electrodomestico* elec,Fecha* fecha,Marca *marca, int tam,int* idElectrodomestico){
	int retorno=-1,posicion=0;
	Electrodomestico aux_elec;

	if (elec==NULL  ||  tam<=0 || buscarElectrodomesticoLibre(elec,tam,&posicion) == -1)
	{
	    puts("\nError !!");
	}
	else if (printf("Identificacion Nro >> % d",*idElectrodomestico)>0
		&&getNro(&aux_elec.serie,"\n\tNuevo Electrodomestico\nIngrese SERIE de electrodomestico [1-200]:","ERROR Ingrese un nombre valido",1,200,3)==0
		&&getMarca(marca,tam_mar,&aux_elec.idmarca)==0
		&&getNro(&aux_elec.modelo.year,"\nModelo ? [1940-2020] :","Ingrese año valido",1940,2020,3)==0)
	{
		aux_elec.idElec=*idElectrodomestico;
		aux_elec.isEmpty=FALSE;
		elec[posicion]=aux_elec;
		(*idElectrodomestico)++;
		printUnitElec(elec,tam,posicion);
		posicion++;
		retorno=0;
	}
	return retorno;
}
/* Retorna la posicion en la que se encuentra el electrodomestico
 * que fue elegido a travez de su ID
 * */
int validarElectrodomestico(Electrodomestico* elec,int tam,int* posicion){
	int bufferelec;
	int retorno =1;
	int reintentos=3;
	if(elec!=NULL&&posicion!=NULL&& tam>0)
	{
	    retorno=2;
	    printElectrodomesticos(elec,tam); // muestro lista
	    do{
		getNro(&bufferelec,"\nIngrese id electrodomestico :","ingrese electrodomestico valido",100,106,3);
		for (int i=0;  i<tam_ele ;i++)/// BUSCO
		{
		    if(bufferelec==elec[i].idElec)
		    {
			*posicion=i;
			retorno=0;
			break;
		    }
		    else if (i==tam_ele)
		    {
			printf("\nNo se encontro electrodomestico ingresado.\nCantidad de reintentos --%d \n ",reintentos);
			reintentos--;
			break;
		    }
		}

	      }while( retorno!=0 && reintentos>0);
	}
	return retorno;
}
int altaforzadaUnidadElec(Electrodomestico* elec,int tam,int i,int* id,int marca,int serie,int modelo,int dia,int mes,int anio){

		int retorno =1;
		Electrodomestico buffer;

		if(elec!=NULL && tam>0){
		buffer.serie=serie;
		buffer.modelo.day=dia;
		buffer.modelo.month=mes;
		buffer.modelo.year=anio;
		buffer.idElec=*id;
		buffer.isEmpty=FALSE;
		retorno=0;
		elec[i]=buffer;
		(*id)++;
		}
	return retorno;
}
int altaforzadaVariosElec(Electrodomestico* elec,int tam){
	Electrodomestico buffermarca[]={
			{100,20,1000,0,{2,2,2006}},
			{101,20,1002,0,{2,2,2020}},
			{102,20,1002,0,{2,2,2020}},
			{103,23,1004,0,{2,2,2001}},
			{104,200,1004,0,{2,2,2002}},
			{105,19,1004,0,{2,2,1999}}
	};
	for(int i=0;i<tam;i++){
		elec[i]=buffermarca[i];
	}
return 0;
}
int removeElectrodomestico(Electrodomestico* elec, int tam){
	int retorno=-1;
	int i=0;
	printElectrodomesticos(elec,tam);

	if(validarElectrodomestico(elec,tam,&i)==0
	    &&elec[i].isEmpty==FALSE)
	{
	    printUnitElec(elec,tam,i);
	    elec[i].isEmpty=TRUE;
	    puts("\n - Electrodomestico removido exitosamente -");
	    retorno = 0;
	}
	else
	{
	    puts(" ID Ya fue removido !\n");
	}
	return retorno;
}
int modifyElectrodomestico(Electrodomestico* elec,Marca* marca, int tam){
	int retorno= -1;
	int i;
	int opcionSubMenu;
	if(elec!=NULL && marca!=NULL && tam>0)
	{
	    if(validarElectrodomestico(elec,tam,&i)==0)  //valido que exista ID
	    {
		printUnitElec(elec,tam,i);// muestra elec elegido - VALIDADO 100%
		do{
		    getNro(&opcionSubMenu,"\nModificar:\n1)Serie\n2)Marca\n3)Modelo\n4)Salir: ","Ingrese una opcion valida",1,5,3);
		    switch(opcionSubMenu)
		    {
			case 1:
				getNro(&elec[i].serie,"\nIngrese nueva serie de electrodomestico [1-200]:","ERROR Ingrese un nombre valido",1,200,3);
				break;
			case 2:
				getMarca(marca,tam_mar,&elec[i].idmarca);
				break;
			case 3:
				getNro(&elec[i].modelo.year,"\nModelo ? [1940-2020] :","Ingrese año valido",1940,2020,3);
				break;
			case 4:
				puts("Modificacion finalizada.-");
				break;
		    }
		}
		while(opcionSubMenu<4);
		retorno = 0;
	    }
	    else{
			    puts("no existe ID ingresado");
	    }
	}

	return retorno;
}
int sortElectrodomestico(Electrodomestico* elec, int tam, int order){
	int retorno=-1,i,j;
	Electrodomestico auxiliar,auxiliarserie;
	if(elec != NULL && tam>0)
	    {
	    for(i=0; i<tam-1;  i++)
		{
		for(j=i+1; j<tam; j++)
		    {
		    if( order==1 && (elec[i].modelo.year < elec[j].modelo.year ))
			{
			    auxiliar = elec[i];
			    elec[i]  = elec[j];
			    elec[j]  = auxiliar;
			}
		    else if(elec[i].modelo.year == elec[j].modelo.year
			    && elec[i].serie < elec[j].serie)
			{
			    auxiliarserie = elec[i];
			    elec[i]  = elec[j];
			    elec[j]  = auxiliarserie;
			    retorno =0;
			}
		    else if(order==2 && (elec[i].modelo.year > elec[j].modelo.year ))
			{
			    auxiliar = elec[i];
			    elec[i]  = elec[j];
			    elec[j]  = auxiliar;
			    retorno =0;
			}
		     }
		 }
	    }
	return retorno;
}
int printElectrodomesticos(Electrodomestico* elec, int tam){
	int retorno=-1,i;
	int contadorisempty=0;
	if(elec!=NULL && tam >0)
	{
	    printf("     - Electrodomesticos -\n|Id    |Id Marca |Serie   |Modelo \n");
	    for(i=0;  i<tam  ;i++)
	    {
		    if(elec[i].isEmpty==TRUE)
		    {
			    contadorisempty++;
			    continue;
		    }
		    else
		    {
			printf(" %-d     %-d      %03d      %-d  \n",
					elec[i].idElec,
					elec[i].idmarca,
					elec[i].serie,
					elec[i].modelo.year
					);
		     }
	     }
	    if(contadorisempty==tam)
	    {
		    puts("No hay electrodomesticos ingresados");
	    }
	    retorno=0;
	}
	return retorno;
}
int printUnitElec(Electrodomestico* data, int tam,int posicion){
	int retorno=-1;
	if(data!=NULL && tam >0)
	{
	    printf("Electrodomestico cargado:\n|Id  |Serie  |Modelo | Id Marca\n");
	    printf(" %d   %d     %d    %d\n",
		    data[posicion].idElec,
		    data[posicion].serie,
		    data[posicion].modelo.year,
		    data[posicion].idmarca);
	    retorno=0;
	}
	return retorno;
}
/*
float promedio(Electrodomestico* data,float* promedy,int L){
	float total=0;
	int contador=0;

	for(int i=0;i<L;i++){
		total=  data[i].salary + total ;
		contador++;
	}
	*promedy=total/contador;

	return 0;
}*/
