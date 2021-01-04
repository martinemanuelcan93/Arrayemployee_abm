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
/*
 * 1- Mostrar Electrodomésticos del año(nodelo) 2020 -
2- Mostrar Electrodomésticos de una marca seleccionada -
3- Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado -
4- Listar los Electrodomésticos que no tuvieron reparaciones -
5- Informar importe total de las reparaciones realizadas a un Electrodoméstico
seleccionado
6- Mostrar el servicio más pedido
7- Mostrar la recaudación en una fecha en particular
8- Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha
9- Trabajos realizados a Electrodomésticos del año(modelo) 2018
10- Facturación total por los mantenimientos
11- Informar la marca de Electrodomésticos que efectuaron más refacciones
12- Listar los Electrodomésticos que recibieron reparación en un fecha determinada
 * */

int main(void) {
	setbuf(stdin,NULL);
	int opcion;
	int rta_ordenamiento;
	int rta;
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
	altaforzadaVariosElec(elec,tam_ele,&IdElectrodomestico);
	initReparaciones(reparaciones,tam_rep);
	altaforzadaReparacion(reparaciones,fecha,service,elec,&IdReparacion,tam_rep);


	do{
	    getNro(&opcion,
			    "\nIngrese una opcion del menu\n"
			    "1)Alta Electrodomestico\n"
			    "2)Modificar Electrodomestico\n"
			    "3)Baja Electrodomestico\n"
			    "4)Mostrar Electrodomestico\n"
			    "5)Mostrar marcas\n"
			    "6)Mostrar servicios\n"
			    "7)Alta reparacion\n"
			    "8)Listar Reparaciones\n"
			    "9)INFORMES\n:",
			    "Ingrese opcion valida",1,9,3);
	    switch(opcion){
	    case 1:
		    do
		    {
			electrodomesticos_cargados(elec,tam_ele);
			addElectrodomestico(elec,fecha,marca,tam_ele,&IdElectrodomestico);
			getNro(&rta,"\nDesea cargar electrodomestico?\n"
				"Si(1)/ No(2): ","Ingrese una respuesta valida",1,2,3);
		    }while(rta==1);
		    break;
	    case 2:
		    modifyElectrodomestico(elec,marca,tam_ele);
		    break;
	    case 3:
		    while(removeElectrodomestico(elec,tam_ele,marca)==1)
		    {
			removeElectrodomestico(elec,tam_ele,marca);
		    }
		    break;
	    case 4:
		    if(getNro(&rta_ordenamiento,
		    "\t -Ordenamiento por Modelo-\n "
		    "Mayor a Menor ingrese[ 1 ]  Menor a mayor [ 2 ] :",
		    "Seleccione un valor de los mencionados", 1, 2, 3)==0)
		    {
			sortElectrodomestico(elec,tam_ele,rta_ordenamiento);
			printElectrodomesticos(elec,tam_ele);
		    }
		    break;
	    case 5:
		    printMarcas(marca,tam_mar);
		    break;
	    case 6:
		    printServicios(service,tam_ser);
		    break;
	    case 7:
		    addReparacion(reparaciones,fecha,service,elec,cliente,tam_rep,&IdReparacion,marca);
		    break;
	    case 8:
		    printReparaciones(reparaciones,cliente,service,tam_rep);
		    break;
	    case 9:
		    nuevosInformes(reparaciones,cliente,service,elec,marca,tam_mar);
		    break;
	    default:
		    puts("Ingrese una opcion valida");
		    break;
	    }
	}
	while(opcion!=10);

	return  0;
}
