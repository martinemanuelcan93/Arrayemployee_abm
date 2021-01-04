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
int servicioporId(float* precio,Servicio* service,int tamanio,int idbuscado)
{
    int retorno=1;
    for(int i=0; i<tamanio; i++)
    {
	if(idbuscado==service[i].idServicio)
	{
	    *precio = service[i].precio;
	}
    }
    return retorno;
}
int recaudacionxfecha(Reparacion* repa,int tamanio,Servicio* service)
{
    int retorno=1;
    int anio,mes,dia;
    int opcion,rta;
    float precio,acumulador=0;
    Fecha aux;
    if(repa!=NULL&& tamanio >0)
    {
	do
	{
	    getNro(&opcion, "Buscar recaudacion por \n1)Anio\n2)Mes\n3)dia \n","Error",1, 3, 2);

	    switch(opcion)
	    case 1:
	    {
		getNro(&anio, "ingrese anio", "error", 1945, 2021, 2);
		for(int i=0;i<tamanio;i++)
		{
		    if(anio==repa[i].fechaReparacion.year)
		    {
			servicioporId(&precio, service, tamanio, repa[i].id_del_Servicio);
			acumulador+=precio;
		    }
		}
		printf("Total recaudacion anio %d : $%.2f",anio,acumulador);
		break;
	    case 2:
		getNro(&mes, "ingrese mes", "error", 1,12, 2);
		for(int i=0;i<tamanio;i++)
		{
		    if(mes==repa[i].fechaReparacion.month)
		    {
			servicioporId(&precio, service, tamanio, repa[i].id_del_Servicio);
			acumulador+=precio;
		    }
		}
		printf("Total recaudacion mes %d : $%.2f",mes,acumulador);
		acumulador=0;
		break;
	    case 3:
		getNro(&dia, "ingrese dia", "error", 1, 31, 2);
		for(int i=0;i<tamanio;i++)
		{
		    if(dia==repa[i].fechaReparacion.day)
		    {
			servicioporId(&precio, service, tamanio, repa[i].id_del_Servicio);
			acumulador+=precio;
		    }
		}
		printf("Total recaudacion dia %d : $%.2f",dia,acumulador);
		acumulador=0;
		break;
	    case 4:
		getNro(&dia, "ingrese fecha", "error", 1, 31, 2);
		for(int i=0;i<tamanio;i++)
		{
		    if(dia==repa[i].fechaReparacion.day)
		    {
			servicioporId(&precio, service, tamanio, repa[i].id_del_Servicio);
			acumulador+=precio;
		    }
		}
		printf("Total recaudacion dia %d : $%.2f",dia,acumulador);
		acumulador=0;
	    }
	getNro(&rta, "\nDesea ver mas recaudaciones? 1)SI 2)NO", "error", 1, 2, 2);
	}while(rta==1);
    }
    return retorno;
}
int serviciomaspedido(Servicio* service,int tamanio,Reparacion* repa,int tamaniorepa)
{
    int total=0;
    int arrayService[tamanio];
    int a=0,b=0,c=0,d=0;

    for(int i=0; i<tamanio; i++)
    {
	arrayService[i] = service[i].idServicio;
    }
    for(int j=0; j<tamaniorepa ; j++)
    {
	if(repa[j].id_del_Servicio==arrayService[0])
	    a++; //3
	else if(repa[j].id_del_Servicio==arrayService[1])
	    b++; //4
	else if(repa[j].id_del_Servicio==arrayService[2])
	    c++; //1
	else if(repa[j].id_del_Servicio==arrayService[3])
	    d++; //7
    }
    if(a>b && a>c && a>d)
	total=arrayService[0];
    else if(b > a && b>c && b>d)
	total=arrayService[1];
    else if(c>a && c > b && c> d)
	total=arrayService[2];
    else
    {
	total=arrayService[3];
    }
	return total;
    }
int preciototalelec(Electrodomestico* elec,Reparacion* reparacioness,Servicio* servicio,Cliente* cliente)
{
	int aux_id_elec;
	int indice;
	float acumulador=0;
	float total=0;
	printElectrodomesticos(elec,tam_ele);

	if(getNro(&aux_id_elec,"\nIngrese ID de Electrodomestico :","ERROR Ingrese un ID valido",100,106,3)==0
	&& isValid_elec(elec, tam_ele, aux_id_elec)==0)
	{
	    for(indice=0; indice<tam_rep; indice++)
	    {
		if(reparacioness[indice].serieReparacion == aux_id_elec)
		{
		    printUnitReparacion(reparacioness,servicio,indice,elec,cliente);
		    servicioporId(&acumulador, servicio, tam_ser, reparacioness[indice].id_del_Servicio);
		    total+=acumulador;
		}
	    }
	    printf("\n Precio total : $%.2f",total);
	}
	return 0;
}
int elecSinReparacion(Electrodomestico* elec,Reparacion* reparacioness,int tam_elec,int repara,Marca* marca,int tamanio_mar){

	int indice,j;
	//int array[10];
// podria agregar un flag a la estruct de electrodomestico osino ...
	for(indice=0; indice<tam_elec; indice++)
	{
	  for(j=0;  j<tam_rep ; j++)
	  {
	     if(elec[indice].idElec==reparacioness[j].serieReparacion)
	     {
		 break;
	     }
	     else if(j==tam_rep-1)
	     {
		 cartelUnitElec("sin reparar");
		 printUnitElec(elec, indice, marca, tamanio_mar);
	     }
	  }
	}
	return 0;
}
int reparacionporelec(Electrodomestico* elec,Reparacion* reparacioness,Servicio* servicio,Cliente* cliente,Marca* marca){
	int aux_id_elec;
	int indice;

	printElectrodomesticos(elec,tam_ele);

	if(getNro(&aux_id_elec,"\nIngrese ID de Electrodomestico :","ERROR Ingrese un ID valido",100,106,3)==0
	&& isValid_elec(elec, tam_ele, aux_id_elec)==0)
	{
	    for(indice=0; indice<tam_rep; indice++)
	    {
		if(reparacioness[indice].serieReparacion == aux_id_elec)
		    printUnitReparacion(reparacioness,servicio,indice,elec,cliente);

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

	do{
	    getNro(&submenu,
	    "\nINFORMES \n"
	    "1)Electrodomesticos a�o 2020\n"
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
	    "13)SALIR\t",
	    "Ingrese opcion valida",1,13,3);
	    switch(submenu)
	    {
		case 1:
		    printelec2020(elec,tam_ele,marca,tam_mar);
		    break;
		case 2:
		    printpormarca(marca, elec, tam_ele,tam_mar);
		    break;
		case 3:
		    reparacionporelec(elec, reparaciones, servicio, cliente,marca);
		    break;
		case 4:
		    elecSinReparacion(elec, reparaciones, 4,tam_rep, marca, tam_mar);
		    break;
		case 5:
		    preciototalelec(elec, reparaciones, servicio, cliente);
		    break;
		case 6:
		    puts("El servicio mas demandado es :\n");
		    printServicioporID(serviciomaspedido(servicio, tam_ser, reparaciones, tam_rep), servicio, tam_ser);
		    break;
		case 7:
		    recaudacionxfecha(reparaciones, tam_rep, servicio);
		    break;
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
