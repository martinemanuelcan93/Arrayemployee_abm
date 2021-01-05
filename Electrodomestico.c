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
int initElectrodomestico(Electrodomestico* elec,int tam)
{
	int retorno=-1;
	if(elec!=NULL && tam >0)
	{
	    for(int i=0;  i<tam  ;i++)
	    {
		elec[i].isEmpty=TRUE;
		retorno=0;
	    }
	}
	return retorno;
}
/* Busca una posicion dentro del array que este libre
 * retorna 0 si la funcion encontro un espacio libre
 * y escribe la posicion encontrada en una direccion de memoria de una posicion,
 * */
int buscarElectrodomesticoLibre(Electrodomestico* elec,int tam,int* posicion){
	int retorno = -1;
	int i;
	if(elec!=NULL && posicion!=NULL  && tam>0)
	{
	    for(i=0; i<tam ;i++)
	    {
		if (elec[i].isEmpty==TRUE)
		{
		    *posicion+=i; //retorna la posicion libre del array encontrada
		    retorno=0;
		    break;
		}
	    }
	}
	return retorno;
}
int isValid_elec(Electrodomestico* elec, int tam,int idBuscado)
{
    int retorno=-1;
    int i;
    if(elec!= NULL && tam>=0)
    {
        for(i=0;i<tam ;i++)
        {
            if(idBuscado == elec[i].idElec && elec[i].isEmpty==FALSE)
	    {
        	retorno=0;
		break;
	    }
        }
    }
    return retorno;
}
int addElectrodomestico(Electrodomestico* elec,Fecha* fecha,Marca *marca, int tam,int* idElectrodomestico){
	int retorno=-1,posicion=0;
	Electrodomestico buffer_elec;

	if (elec==NULL  ||  tam<=0 || buscarElectrodomesticoLibre(elec,tam,&posicion) == -1)
	{
	    puts("\nError !!");
	}
	else if (printf("\tNuevo Electrodomestico\nIdentificacion Nro >> % d",*idElectrodomestico)>0
	&&getNro(&buffer_elec.serie,"\n\nIngrese SERIE de electrodomestico [1-200]:","ERROR Ingrese un nombre valido",1,200,3)==0
	&&getMarca(marca,tam_mar,&buffer_elec.idmarca)==0
	&&getNro(&buffer_elec.modelo.year,"\nModelo ? [1940-2020] :","Ingrese año valido",1940,2020,3)==0)
	{
		buffer_elec.isEmpty=FALSE;
		buffer_elec.idElec=*idElectrodomestico;
		elec[posicion] = buffer_elec;
		(*idElectrodomestico)++;
		cartelUnitElec("cargado");
		printUnitElec(elec,posicion,marca,tam_mar);
		retorno=0;
	}
	return retorno;
}
/* Muestra la lista de electrodomesticos
 * Retorna la posicion en la que se encuentra el electrodomestico
 * que fue elegido a travez de su ID
 */
int electrodomesticobyID(Electrodomestico* elec,int tam,int* posicion){
	int bufferelec;
	int retorno =1;
	int reintentos=3;
	if(elec!=NULL&&posicion!=NULL&& tam>0)
	{
	    retorno=2;
	    printElectrodomesticos(elec,tam);
	    do{
		getNro(&bufferelec,"\nIngrese id electrodomestico :","ingrese electrodomestico valido",100,106,3);
		for (int i=0;  i<tam_ele ;i++)
		{
		    if(bufferelec==elec[i].idElec && elec[i].isEmpty==FALSE) //chequeo el campo isEmpty
		    {
			*posicion=i;
			retorno=0;
			break;
		    }
		    else if (i==tam_ele-1)
		    {
			printf("\nNo se encontro electrodomestico ingresado.\nCantidad de reintentos --%d \n ",reintentos);
			reintentos--;
			retorno = -1;
			break;
		    }
		}

	      }while( reintentos>0 && retorno!=0);
	}
	return retorno;
}
int altaforzadaUnidadElec(Electrodomestico* elec,int tam,int i,int* id,int marca,int serie,int modelo,int anio){

	int retorno =1;
	Electrodomestico buffer;

	    if(elec!=NULL && tam>0)
	    {
		buffer.serie=serie;
		buffer.modelo.year=anio;
		buffer.idElec=*id;
		buffer.isEmpty=FALSE;
		retorno=0;
		elec[i]=buffer;
		(*id)++;
	    }
	return retorno;
}
void altaforzadaVariosElec(Electrodomestico* elec,int tam,int *id_elec){
	int cantidad_hardcodeada=0;
	Electrodomestico bufferelec[]={
			{100,20,1000,0,2,{2,2,2006}},//0
			{101,55,1002,0,4,{2,2,2020}},//1
			{102,60,1002,0,2,{2,2,2020}},//2
			{103,23,1004,0,6,{2,2,2001}},//3
			{104,19,1004,0,8,{2,2,1999}} //4
	};
	for(int j=0; j<tam ; j++)
	{
	    if(bufferelec[j].isEmpty==0)
	    cantidad_hardcodeada++;
	    else
		break; //corto antes de recorrer el array completo
	}
	(*id_elec) += cantidad_hardcodeada;
	for(int i=0; i<cantidad_hardcodeada  ;i++)
	{
	    elec[i] = bufferelec[i];
	}
}
int removeElectrodomestico(Electrodomestico* elec, int tam,Marca* marca){
	int retorno=-1;
	int i=0;

	if(printf("Usted ha seleccionado BAJA de electrodomestico\n")>0 &&
	    electrodomesticobyID(elec,tam,&i)==0)
	{
	    cartelUnitElec("Seleccionado");
	    printUnitElec(elec,i,marca,tam_mar);
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
	int opcionSubMenu=0;
	if(elec!=NULL && marca!=NULL && tam>0)
	{
	    puts("\n\t MODIFICAR");
	    if(electrodomesticobyID(elec,tam,&i)==0)
	    {
		cartelUnitElec("Seleccionado");
		printUnitElec(elec, i, marca,tam_mar);
		do{
		    if(opcionSubMenu!=0 && opcionSubMenu!=4)
		    {
			cartelUnitElec("Modificado");
			printUnitElec(elec, i, marca,tam_mar);
		    }
		    getNro(&opcionSubMenu,"\nModificar :\n"
			    "1)Serie\n"
			    "2)Marca\n"
			    "3)Modelo\n"
			    "4)SALIR: ","Ingrese una opcion valida",1,5,3);

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
	    else
	    {
		puts("no existe ID ingresado");
	    }
	}
	return retorno;
}
int sortElectrodomestico(Electrodomestico* elec, int tam, int order){
	int retorno=-1,i,j;
	Electrodomestico auxiliar;

	if(elec != NULL && tam>0)
	    {
	    for(i=0; i<tam-1;  i++)
		{
		for(j=i+1; j<tam; j++)
		    {
		    if( order==1 && (elec[i].modelo.year < elec[j].modelo.year ))
			{	// mayor a menor por modelo
			    auxiliar = elec[i];
			    elec[i]  = elec[j];
			    elec[j]  = auxiliar;
			    retorno = 0;
			}
		    else if(elec[i].modelo.year == elec[j].modelo.year
			    && elec[i].serie < elec[j].serie)
			{	// si son iguales ordeno por serie de mayor a menor
			    auxiliar = elec[i];
			    elec[i]  = elec[j];
			    elec[j]  = auxiliar;
			    retorno = 0;
			}
		    else if(order==2 && (elec[i].modelo.year > elec[j].modelo.year ))
			{	// menor a mayor por modelo
			    auxiliar = elec[i];
			    elec[i]  = elec[j];
			    elec[j]  = auxiliar;
			    retorno =0;
			}
		    else if(elec[i].modelo.year == elec[j].modelo.year
			    && elec[i].serie > elec[j].serie)
			{	// si son iguales ordeno por serie de mayor a menor
			    auxiliar = elec[i];
			    elec[i]  = elec[j];
			    elec[j]  = auxiliar;
			    retorno = 0;
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
				elec[i].modelo.year);
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
int printUnitElec(Electrodomestico* data,int posicion,Marca* marca,int tamanio_mar)
{
	int retorno=-1;
	if(data!=NULL)
	{
	    char buffer_marca[400];
	    strcpyMarcaporID(buffer_marca,data[posicion].idmarca,marca,tamanio_mar);
	    printf(" %d    %3s       %d      %d\n",
		    data[posicion].idElec,
		    buffer_marca,
		    data[posicion].serie,
		    data[posicion].modelo.year);
	    retorno=0;
	}
	return retorno;
}
void cartelUnitElec(char* msj_electrodomestico)
{
    printf("Electrodomestico %s:\n Id  |  Marca     |Serie  |Modelo \n",msj_electrodomestico);
}
void electrodomesticos_cargados(Electrodomestico* elec,int tamanio)
{
    int cantidad_hardcodeada=0;
	for(int j=0; j<tamanio ; j++)
	{
	    if(elec[j].isEmpty==0)
	    cantidad_hardcodeada++;
	    else
		break; //corto antes de recorrer el array completo
	}
    printf("Electrodomesticos cargados: %d",cantidad_hardcodeada);

}

