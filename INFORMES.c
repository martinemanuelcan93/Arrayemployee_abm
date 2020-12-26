#include "reparaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca2020.h"
#include "Electrodomestico.h"
#include <string.h>
#define TRUE 1
#define FALSE 0
#define tam_ele 6
#define tam_cli 5
#define tam_ser 4
#define tam_rep 10

int reparacionporelec(Electrodomestico* elec,Reparacion* repa,Servicio* servicio,Cliente* cliente){
	int aux_id_elec;
	printElectrodomesticos(elec,tam_ele);
	getNro(&aux_id_elec,"\nIngrese ID de Electrodomestico :","ERROR Ingrese un ID valido",100,106,3);
	for(int i=0; i<tam_rep  ;i++)
	{
	    if(aux_id_elec == repa[i].serieReparacion)
	    {
		printUnitReparacion(repa,servicio,i);
	    }
	}
	return 0;
}
int printpormarca(Marca* marca,Electrodomestico* elec, int cantidad,int tam_mar){

	int retorno =1;
	int auxiliar_marca,cont=0;
	int array_de_posiciones[tam_ele],j=0;

	if(marca!=NULL&&elec!=NULL&&cantidad>0)
	{
	    getMarca(marca, tam_mar, &auxiliar_marca);
	    for (int i=0;  i<tam_ele ;i++)
	    {
		if(auxiliar_marca == elec[i].idmarca)
		{
		    *(array_de_posiciones+j) = i;
		    j++;
		    cont++;
		}
	    }
	    if(cont==1)
	    {
		printf("Se encontro %d electrodomestico en total, de la marca ingresada.\n",cont);
		printf("Electrodomestico cargado:\n|Id  |Serie  |Modelo | Id Marca\n");
		printUnitElec(elec,*array_de_posiciones,marca,tam_mar);
	    }
	    else if(cont==0)
		puts("No se encontro ningun electrodomestico de la marca ingresada.\n");
	    else
	    {
		printf("Se encontraron %d electrodomesticos en total, de la marca ingresada.\n",cont);
		printf("Electrodomesticos cargados:\n|Id  |Serie  |Modelo | Id Marca\n");
		for(int k=0; k<cont; k++)
		    printUnitElec(elec,array_de_posiciones[k],marca, tam_mar);
	    }
	    retorno=0;
	}
	return retorno;
}
int printelec2020(Electrodomestico* elec, int tamanio,Marca* marca,int tam_mar){
	int retorno=-1;
	int cont=0,j=0;
	int array_de_elec2020[tamanio];

	if(elec!=NULL && tamanio >0)
	{
	    for(int posicion=0; posicion<tamanio ;posicion++)
	    {
		if(2020==elec[posicion].modelo.year)
		{
		    *(array_de_elec2020+j)=posicion;
		    j++;
		    cont++;
		}
	    }
	    if(cont==0)
		puts("No se encontro ningun electrodomestico del anio 2020");
	    else if(cont==1)
	    {
		printf("Se encontro %d electrodomestico del anio 2020",cont);
		printUnitElec(elec, *(array_de_elec2020),marca,tam_mar);
	    }
	    else
	    {
		printf("Se encontraron %d electrodomesticos del anio 2020.\n",cont);
		printf("Electrodomesticos cargados:\n|Id  |Serie  |Modelo | Id Marca\n");
		for(int k=0; k<cont; k++)
		    printUnitElec(elec,array_de_elec2020[k],marca,tam_mar);
	    }
	    retorno=0;
	}
	return retorno;
}
int nuevosInformes(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio,Electrodomestico* elec,Marca* marca,int tam_mar){
	int submenu;
	int bufferelec;
	do{
	    getNro(&submenu,
	    "\nINFORMES \n"
	    "1)Electrodomesticos año 2020\n"
	    "2)Electrodomestico segun marca\n"
	    "3)Reparac de Electrodomestico seleccionado\n"
	    "4)Electrodomestico sin reparar\n"
	    "5)Precio total de 1 Electr.\n"
	    "6)Servicio mas pedido\n"
	    "7)Recaudacion segun fecha\n"
	    "8)Elec segun Garantiayfecha\n"
	    "9)Rep en 2018\n"
	    "10)facturacion total\n"
	    "11)Marca con mas arreglos\n"
	    "12)Elect reparados segun fecha\n"
	    "13)SALIR",
	    "Ingrese opcion valida",1,12,3);
	    switch(submenu)
	    {
		case 1:
			printelec2020(elec,tam_ele,marca,tam_mar);
			break;
		case 2:
			printpormarca(marca, elec, tam_ele,tam_mar);
			break;
		case 3:
			reparacionporelec(elec, reparaciones, servicio, cliente);
			break;
		case 4:
			getNro(&bufferelec,"\nIngrese id electrodomestico :","ingrese electrodomestico valido",100,106,3);
			if(isValid_elec(elec, tam_ele, bufferelec)==0)
			{
			    for(int k=0;k<tam_rep;k++)
			    {
				if(reparaciones[k].serieReparacion==bufferelec)
				 printUnitReparacion(reparaciones, servicio, k);
			    }
			}
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		default:
			break;

	    }
	}while(submenu!=13);
	return 0;
}
