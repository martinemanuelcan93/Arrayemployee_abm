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
#define tam_mar 5
#define tam_rep 10

int reparacionporelec(Electrodomestico* elec,Reparacion* repa,Servicio* servicio,Cliente* cliente){
	int aux;
	printElectrodomesticos(elec,tam_ele);
	getNro(&aux,"\nIngrese ID de cliente :","ERROR Ingrese un ID valido",1,20,3);
	for(int i=0; i<tam_rep  ;i++){
		if(aux == repa[i].id_cliente){
			printUnitReparacion(repa,servicio,i);
			//printReparaciones(repa,cliente,servicio,tam_rep);
		}
	}

	return 0;
}
int printpormarca(Marca* marca,Electrodomestico* elec, int cantidad){
	char buffermarca[20];
	int retorno =1;
	int reintentos=3;

	printMarcas(marca,5);
	do{
	if(getChar(buffermarca,20,"\nIngrese nombre de marca :","ingrese marca valida",3)==0)
	{
		for (int i=0;  i<tam_ele ;i++){

		if(strcmp(buffermarca,marca[i].descripcion)==0){
			retorno=0;

			printUnitElec(elec,tam_ele,i);
			break;
			}
		else if (i==3){
			reintentos--;
			printf("\nError.\nCantidad de reintentos --%d \nUsted ingreso -%s- revise minusculas y mayusculas ",reintentos,buffermarca);
			}
		}

	}
	}while( retorno!=0 && reintentos>0);
	return retorno;
}
int printElec2020(Electrodomestico* elec, int tamanio){
	int retorno=-1;
	int anio=2020;
		if(elec!=NULL && tamanio >0){
			printf("Electrodomestico\n|Id |Serie  |Modelo\n");
			for(int posicion=0; posicion<tamanio ;posicion++){
				if(anio==elec[posicion].modelo.year){

				printf(" %d   %d     %d \n",
						elec[posicion].idElec,
						elec[posicion].serie,
						elec[posicion].modelo.year);

			}
		}
		retorno=0;

		}
		return retorno;
}
int nuevosInformes(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio,Electrodomestico* elec,Marca* marca){
	int submenu;
	do{
		getNro(&submenu,
		"\nINFORMES \n1)Electrodomesticos año 2020\n2)Electrodomestico segun marca\n3)Reparac de Electrodomestico\n4)Electrodomestico sin reparar\n5)Precio total de 1 Electr.\n6)Servicio mas pedido\n7)Recaudacion segun fecha\n8)Elec segun Garantiayfecha\n9)Rep en 2018\n10)facturacion total\n11)Marca con mas arreglos\n12)Elect reparados segun fecha",
		"Ingrese opcion valida",1,12,3);
		switch(submenu){
		case 1:
			printElec2020(elec,tam_ele);
			break;
		case 2:
			printpormarca(marca,elec,5);
			break;
		case 3:

			break;
		case 4:
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


