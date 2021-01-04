#include "reparaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca2020.h"
#include "Electrodomestico.h"
#include "INFORMES.h"
#define TRUE  1
#define FALSE 0
#define tam_ele 6
#define tam_cli 5
#define tam_ser 4
#define tam_mar 5
#define tam_rep 10

int initReparaciones(Reparacion* reparaciones,int tamanio_rep)
    {
	int retorno = -1;
	if(reparaciones!=NULL && tamanio_rep >0)
	{
	    for(int i=0;  i< tamanio_rep  ;i++)
	    {
		reparaciones[i].isEmpty=TRUE;

		retorno = 0;
	    }
	}
	return retorno;
}
int printUnitReparacion(Reparacion* reparacion,Servicio* service,int posicion,Electrodomestico* elec,Cliente* cliente){
	int retorno=-1;
	//char cadena[150];
	if(reparacion!=NULL )
	{
	    printf("Reparacion\nNro Rep.   |id elec     |Fecha\n");
	    printf(" %d         %d        %d/%d/%d ",
			reparacion[posicion].idReparacion,
			reparacion[posicion].serieReparacion,
			reparacion[posicion].fechaReparacion.day,
			reparacion[posicion].fechaReparacion.month,
			reparacion[posicion].fechaReparacion.year);
	    printServicioporID(reparacion[posicion].id_del_Servicio, service, tam_ser);
	    printf("\n");
	    retorno=0;
	}
	return retorno;
}
int printReparaciones(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio, int tamanio){
	int retorno=-1;

	if(reparaciones!=NULL && tamanio > 0)
	{
	    printf("-Reparaciones-\nNro    |FechaRep         |Servicio      |Precio   ");
	    for(int i=0;  i<tamanio ;i++)
	    {
		if(reparaciones[i].isEmpty==TRUE)
		{
		    continue;
		}
		else
		{
		    printf("\n %d     %d/%d/%d     ",
			    reparaciones[i].idReparacion,
			    reparaciones[i].fechaReparacion.day,
			    reparaciones[i].fechaReparacion.month,
			    reparaciones[i].fechaReparacion.year);
		    printServicioporID(reparaciones[i].id_del_Servicio,servicio,tam_ser);
		}
	    }
	    retorno=0;
	}
	return retorno;
}
int printServicioporID(int id_buscado,Servicio* service,int tam_servicio)
{
	int retorno=1;
	for(int i=0 ;  i<tam_servicio ;i++)
	{
	    if(id_buscado == service[i].idServicio)
	    {
		printf("   %s   $%.2f",service[i].descripcion,service[i].precio);
		retorno = 0;
		break;
	    }
	}
	return retorno;
}
int altaforzadaReparacion(Reparacion* reparacion,Fecha* fecha,Servicio* service,Electrodomestico* elec,int* idreparacion,int tam_repa)
{
    /*	{20000,"Garantia     ",250},     //0
	{20001,"Mantenimiento",500},	 //1
	{20002,"Repuestos    ",400},	 //2
	{20003,"Refaccion    ",600}*/
	int cantidad_hardcodeada=0;
	Reparacion buffer_reparacion[]=	{
		    {10,100,20000,FALSE,{2,12,1993}}, //250
		    {11,100,20002,FALSE,{2,12,1993}},//400
		    {12,101,20000,FALSE,{2,12,2020}},//250
		    {13,102,20001,FALSE,{9,10,2020}},
		    {14,104,20003,FALSE,{2,12,2020}},//600
		    {15,104,20001,FALSE,{9,10,2007}},
		    {16,101,20001,FALSE,{9,10,2005}}
	};

	for(int j=0; j<tam_repa ; j++)
	{
	    if(buffer_reparacion[j].isEmpty==FALSE)
	    cantidad_hardcodeada++;
	    else
		break;
	}
	(*idreparacion)+=cantidad_hardcodeada;

	/// cargo del buffer al array hasta llegar a la cantidad contada
	for(int i=0; i<cantidad_hardcodeada && i<tam_repa  ;i++)
	  reparacion[i]=buffer_reparacion[i];

	return 0;
}
int addReparacion(Reparacion* reparacion,Fecha* fecha,Servicio* service,Electrodomestico* elec,Cliente* cliente,int tam_reparacion,int* Idreparacion,Marca* marca)
{
	int retorno=-1,posicion=0;
	Reparacion buffer;

	if (reparacion!=NULL  &&  tam_reparacion >=0
	&& buscarReparacionLibre(reparacion,tam_reparacion,&posicion)==0)
	{
	    printf("Nro factura :%d\n",*Idreparacion);
	    printElectrodomesticos(elec,tam_ele);
	    if (getNro(&buffer.serieReparacion,"\nIngrese ID de electrodomestico a reparar [1-1000]:","ERROR Ingrese id valido",0,1000,3)==0
		&&printServicios(service,tam_ser)==0
		&&getNro(&buffer.id_del_Servicio,"\nIngrese ID del servicio :","Ingrese id valido",20000,20055,3)==0
		&&getNro(&buffer.fechaReparacion.day,"\nFecha\nDia :","Ingrese dia valido",1,31,3)==0
		&&getNro(&buffer.fechaReparacion.month,"Mes :","Ingrese dia valido",1,12,3)==0
		&&getNro(&buffer.fechaReparacion.year,"Año :","Ingrese dia valido",1,3000,3)==0)
	    {
		buffer.isEmpty=FALSE;
		buffer.idReparacion=*Idreparacion;
		reparacion[posicion]=buffer;
		(*Idreparacion)++;
		printUnitReparacion(reparacion,service,posicion,elec,cliente);
		retorno=0;
	    }
	}
	else
	{
	    puts("\nNo hay reparaciones, o hay un error en los parametros del codigo");
	}
	    return retorno;
}
int buscarReparacionLibre(Reparacion* reparacion,int tam,int* posicion)
{
	int retorno = -1;
	int i;
	if(reparacion!=NULL && posicion!=NULL  && tam>0)
	{
	    for(i=0; i<tam ;i++)
	    {
		if (reparacion[i].isEmpty==TRUE)
		{
		    retorno=0;
		    *posicion=i;
		    break;
		}
	    }
	}
	return retorno;
}
int getService(Reparacion* reparacion,Servicio* service, int cantidad)
{
	int bufferservice;
	int retorno =1;
	int reintentos=2;
	if(reparacion!=NULL&&service!=NULL&&cantidad>0)
	{
	    printServicios(service,cantidad);
	    do{
		getNro(&bufferservice,"\nIngrese ID servicio :","ingrese servicio valida",1,3000,3);
		for (int i=0;  i<cantidad ;i++)
		{
		    if(bufferservice==reparacion[i].id_del_Servicio)
		    {
			puts("ok!");
			retorno=0;
			break;
		    }
		    else if(i==cantidad-1)
		    {
			puts("# No se encontro marca # \n");
			printf("\nCantidad de reintentos :%d ",reintentos);
			reintentos--;
		    }
		}
	     }
	     while( reintentos>0 );
	}
	return retorno;
}

