#include "reparaciones.h"
#include <stdio.h>
#include <stdlib.h>
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
int initReparaciones(Reparacion* reparaciones,int tamanio_rep){
	int retorno = -1;
	if(reparaciones!=NULL && tamanio_rep >0){

		for(int i=0;  i< tamanio_rep  ;i++){
			reparaciones[i].isEmpty=TRUE;
			//printf("\nValor de i :%d",i);
				retorno = 0;
			}
	}
	return retorno;
}
int printUnitReparacion(Reparacion* reparacion,Servicio* service,int posicion){
	int retorno=-1;
			if(reparacion!=NULL ){
				printf("Reparacion\nNro Rep.   |Serie   |Idcliente    |Fecha\n");
				printf(" %d         %d        %d          %d/%d/%d \n",
						reparacion[posicion].idReparacion,
						reparacion[posicion].serieReparacion,
						reparacion[posicion].id_cliente,

						reparacion[posicion].fechaReparacion.day,
						reparacion[posicion].fechaReparacion.month,
						reparacion[posicion].fechaReparacion.year); //todo lo q pidioen alta
				retorno=0;
			}
			return retorno;
}
int printReparaciones(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio, int tamanio){
	int retorno=-1;
	if(reparaciones!=NULL && tamanio > 0)
	    {
		printf("-Reparaciones-\nNro    |FechaRep      |Cliente             |Servicio      |Precio   ");
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

				printClienteporID(reparaciones[i].id_cliente,cliente);
				printServicioporID(reparaciones[i].id_del_Servicio,servicio,tam_ser);
				printf("nValor i = %d",i);
			}
		    }
		retorno=0;
	    }
		return retorno;
}
int printClienteporID(int ID,Cliente* cliente){

	for(int i=0;i<tam_cli;i++){
		if(cliente[i].idcliente==ID){
			printf("%s %s ",cliente[i].apellido,cliente[i].nombre);
		}
	}
	return 0;
}
int printServicioporID(int ID,Servicio* service,int tam_servicio){

	for(int i=0 ;  i<tam_servicio ;i++){
			if(ID == service[i].idServicio){
				printf("   %s   ",service[i].descripcion);
				printf("$%.2f",service[i].precio);
				break;
			}
		}

		return 0;
}
int altaforzadaReparacion(Reparacion* reparacion,Fecha* fecha,Servicio* service,Electrodomestico* elec,Cliente* cliente,int* idreparacion,int tam_repa)
{
	Reparacion aux[]={
			{10,20,20000,1000,4,FALSE,{2,12,1993}},	//1
			{11,23,20002,1000,2,FALSE,{2,12,1999}},	//2
			{12,29,20000,1004,6,FALSE,{2,12,2020}},	//3
			{13,24,20001,1003,8,FALSE,{9,10,2009}},	//4
			{14,90,20003,1004,6,FALSE,{2,12,2010}}, //5
			{15,40,20001,1003,8,FALSE,{9,10,2007}},	//6
			{16,24,20001,1003,8,FALSE,{9,10,2005}}	//7
	};
	int cantidad_hardcodeada = 7;
	*idreparacion=*idreparacion+cantidad_hardcodeada;

	for(int i=0; i<cantidad_hardcodeada  ;i++){
		reparacion[i]=aux[i];
		}

	return 0;
}
int addReparacion(Reparacion* reparacion,Fecha* fecha,Servicio* service,Electrodomestico* elec,Cliente* cliente,int tam_reparacion,int* Idreparacion)
{
	int retorno=-1,posicion;
	Reparacion buffer;

	if (reparacion!=NULL  &&  tam_reparacion >=0
	    && buscarReparacionLibre(reparacion,tam_reparacion,&posicion)==0)
	{
		printf("Nro factura generado:%d\n",*Idreparacion);
		printElectrodomesticos(elec,tam_ele);
	    if (getNro(&buffer.serieReparacion,"\nIngrese ID de electrodomestico a reparar [1-1000]:","ERROR Ingrese id valido",0,1000,3)==0
		&&printServicios(service,tam_ser)==0
		&&getNro(&buffer.id_del_Servicio,"\nIngrese ID del servicio :","Ingrese id valido",20000,20055,3)==0
		&&printCliente(cliente,tam_cli)==0
		&&getNro(&buffer.id_cliente,"\nIngrese ID del cliente :","Ingrese idcliente valido",2,10,3)==0
		&&getNro(&buffer.fechaReparacion.day,"\nFecha\nDia :","Ingrese dia valido",1,31,3)==0
		&&getNro(&buffer.fechaReparacion.month,"Mes :","Ingrese dia valido",1,12,3)==0
		&&getNro(&buffer.fechaReparacion.year,"A�o :","Ingrese dia valido",1,3000,3)==0)
		{
		    buffer.isEmpty=FALSE;
		    buffer.idReparacion=*Idreparacion;
		    reparacion[posicion]=buffer;
		    *Idreparacion=*Idreparacion+1;
		    printUnitReparacion(reparacion,service,posicion);
		    retorno=0;
		}
	}
	else
	{
	    puts("\nNo hay reparaciones! ");
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
int getService(Reparacion* reparacion,Servicio* service, int cantidad){
	int bufferservice;
	int retorno =1,i=0;
	int reintentos=3;
	printServicios(service,5);
	do{
	if(getNro(&bufferservice,"\nIngrese ID servicio :","ingrese servicio valida",1,3000,3)==0)
	{
		for (int i=0;  i<5 ;i++)
		{
		if(bufferservice==reparacion[i].id_del_Servicio){
			retorno=0;

			puts("id servicio cargado exitosamente");
			break;
			}
		}
	}
	else{
		reintentos--;
		printf("\nError. Cantidad de reintentos :%d char ingresado %d",reintentos,bufferservice);
		i++;
	}
	}while( retorno!=0 && reintentos>0);
	return retorno;
}
int getCliente(Reparacion* reparacion,Cliente* cliente, int cantidad){
	int buffercliente;
	int retorno =1,i=0;
	int reintentos=3;
	printCliente(cliente,5);
	do{
	if(getNro(&buffercliente,"\nIngrese ID Cliente :","Ingrese cliente valido",1,3000,3)==0)
	{
		for (int i=0;  i<5 ;i++){
		if(buffercliente==reparacion[i].id_cliente){
			retorno=0;
			puts("Id cliente cargado exitosamente");
			break;
			}
		}
	}
	else{
		reintentos--;
		printf("\nError. \nCantidad de reintentos :%d \nusted ingreso %d",reintentos,buffercliente);
		i++;
	}
	}while( retorno!=0 && reintentos>0);
	return retorno;
}


