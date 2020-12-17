#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca2020.h"
#include "Electrodomestico.h"
#include "Serv&Marc.h"
#include "Reparaciones.h"
#include "INFORMES.h"

#define TRUE 1
#define FALSE 0
#define tam_ele 6
#define tam_cli 5
#define tam_ser 4
#define tam_mar 5
#define tam_rep 10
int prueba;


int main(void) {
	setbuf(stdin,NULL);
	int opcion;
	int rta_ordenamiento;
	int flagInit=0;
	int IdElectrodomestico=100;
	int IdReparacion=10;

	Electrodomestico elec[tam_ele];
	Fecha fecha[tam_ele];
	Marca marca[tam_mar];
	Servicio service[tam_ser];
	Reparacion reparaciones[tam_rep];
	Cliente cliente[tam_cli];
	altaforzadaMarca2(marca,tam_mar);
	altaforzadaServicio(service,tam_ser);
	altaforzadaCliente(cliente,tam_cli);
	initElectrodomestico(elec,tam_ele);
	altaforzadaVariosElec(elec,tam_ele);
	// ELECTRODOMESTICO
	initReparaciones(reparaciones,tam_rep);
	altaforzadaReparacion(reparaciones,fecha,service,elec,cliente,&IdReparacion,tam_rep);
	//sortElectrodomestico(elec,tam_ele,1);
	//printElectrodomesticos(elec,tam_ele);
	//printServicios(servic,tam_ser);
	//printCliente(cliente,tam_cli);
	//printElec2020(elec,tam_ele);
	//printpormarca(marca,elec,5);
	//printReparaciones(reparaciones,cliente,service,tam_rep);//10
        //printf("\nId reparacion disponible -> %d",IdReparacion);

	do{
	    getNro(&opcion,
	    "\nIngrese una opcion del menu \n1)Alta Electrodomestico\n2)Modificar Electrodomestico\n3)Baja Electrodomestico\n4)Mostrar Electrodomestico\n5)Mostrar marcas\n6)Mostrar servicios \n7)Alta reparacion\n8)Listar Reparaciones\n9)INFORMES \n:",
	    "Ingrese opcion valida",1,9,3);
	    switch(opcion){
	    case 1:
		    if(flagInit==0 && initElectrodomestico(elec,tam_ele)==0 )
			{
			    flagInit=1;
			}
		    int rta;
		    do
		    {
			addElectrodomestico(elec,fecha,marca,tam_ele,&IdElectrodomestico);
			getNro(&rta,"\nDesea cargar electrodomestico?\nSi(1)/ No(2): ","Ingrese una respuesta valida",1,2,3);
		    }while(rta==1);

		    break;
	    case 2:
		    modifyElectrodomestico(elec,marca,tam_ele);
		    break;
	    case 3:
		    while(removeElectrodomestico(elec,tam_ele)==1){ // mientrar no encuentre el electr.
			    removeElectrodomestico(elec,tam_ele);// pide elect. nuevamente
		    };
		    break;
	    case 4:
		    getNro(&rta_ordenamiento,
		    "\t -Ordenamiento por Modelo-\n Mayor a Menor ingrese[ 1 ]  Menor a mayor [ 2 ] :",
		    "Seleccione un valor de los mencionados", 1, 2, 3);
		    sortElectrodomestico(elec,tam_ele,rta_ordenamiento);
		    printElectrodomesticos(elec,tam_ele);
		    break;
	    case 5:
		    printMarcas(marca,tam_mar);
		    break;
	    case 6:
		    printServicios(service,tam_ser);
		    break;
	    case 7:
		    addReparacion(reparaciones,fecha,service,elec,cliente,tam_rep,&IdReparacion);
		    break;
	    case 8:
		    printReparaciones(reparaciones,cliente,service,tam_rep);
		    break;
	    case 9:
		    nuevosInformes(reparaciones,cliente,service,elec,marca);
		    break;
	    default:
		    puts("Ingrese una opcion valida");
		    break;
	    }
	}
	while(opcion!=10);

	return  0;
}
