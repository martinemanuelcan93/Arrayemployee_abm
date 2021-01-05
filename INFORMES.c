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

int electrodomesticoxidhard(Electrodomestico* elec, int tam,int idbuscado)
{
	int posicion=0;
	for(int i =0 ; i< tam; i++)
	{
	    if(elec[i].idElec==idbuscado)
		posicion=i;
	}
	return posicion;
}
int marcaconmasarreglos(Reparacion* repa,int tamrepa,Marca* marca,int tamarca,Electrodomestico* elec,int tamele)
{
	int retorno=1,flag=0,max=0,i;
	int indice;
	int arraydeMax[tamarca];
	char auxmarca[40];

	for(int c=0; c<tamrepa ; c++)
	{
	    arraydeMax[c]=0;// inicializo array en 0
	}

	for( i=0; i<tamrepa ;i++) // recorro reparaciones
	{
	    if(repa[i].isEmpty!=TRUE)
	    {
		indice=electrodomesticoxidhard(elec, tamele,repa[i].serieReparacion); //obtengo posicion de elec
	    }
	    else
		break;

	    for(int j=0; j<tamarca ;j++) // recorro marcas
	    {
		if(marca[j].idMarca == elec[indice].idmarca) // marca 1 coincide con elec 3
		{ 							//printf("arraydeMax[%d] %d\n",j,arraydeMax[j]);
		    arraydeMax[j]++;
		}
	    }
	}
	int posicionMAX;
	for(int k=0; k<tamarca ; k++)
	{
	    if(flag==0 || arraydeMax[k]>max )
	    {
		flag=1;
		max = arraydeMax[k];
		posicionMAX=k;
	    }
	}
	strcpyMarcaporID(auxmarca,marca[posicionMAX].idMarca , marca, tamarca);
	puts(auxmarca);
	printf("\nLa marca que tuvo mas reparaciones fue %s",auxmarca);

	return retorno;
}
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
int facturaciontotal(Reparacion* repa,int tamrepa,Servicio* servicio)
{
    int retorno=1;
    float total,acumulador;
    for(int i=0;i<tamrepa;i++)
    {
	if(repa[i].isEmpty==FALSE)
	{
	    servicioporId(&acumulador, servicio, tam_ser, repa[i].id_del_Servicio);
	    total+=acumulador;
	}
    }
    printf("Facturacion total $%f",total);
    return retorno;
}
int reparaciones2018(Reparacion* repa,int tamrepa,Electrodomestico* elec,Servicio* service,Cliente* cliente)
{
	int i;
	for(i=0; i<tam_rep; i++)
	{
	    if(repa[i].fechaReparacion.year == 2018)
	    printUnitReparacion(repa, service, i, elec, cliente);
	}
	return 0;
}
int elecxgarantiayfecha(Reparacion* repa,int tamanio,Servicio* service,int tamanioser,Electrodomestico* elec,int tamelec,Marca* marca,int tamarca)
{
	int retorno=0,flag=0;
	Fecha aux;
	puts("\nElectrodomestico por Garantia y fecha \nIngrese fecha exacta");
	getNro(&aux.day, " Dia : ", "error",1, 31,2);
	getNro(&aux.month, "Mes : ", "error",1,12,2);
	getNro(&aux.year, "Anio : ", "error", 1945,2021,2);

	for(int i=0;i<tamanio;i++)
	{
	    if(serviciopordescripcion("Garantia", service, tamanio)==repa[i].id_del_Servicio//1ero descarto por "garantia"
		&& aux.day  ==repa[i].fechaReparacion.day
		&& aux.month==repa[i].fechaReparacion.month
		&& aux.year ==repa[i].fechaReparacion.year)
	    {
		if(flag==0)cartelUnitElec("por garantia y fecha");

		printUnitElec(elec,/*Obtengo posicion de id buscado
		                  */electrodomesticoxidhard(elec,tamelec, repa[i].serieReparacion), marca, tamarca);
	    flag=1;
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
	    getNro(&opcion, "Buscar recaudacion por \n1)Anio\n2)Mes\n3)dia\n4)Fecha exacta\n","Error",1, 4, 2);

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
		puts("\nIngrese fecha exacta");
		getNro(&aux.day, "Dia : ", "error",1, 31,2);
		getNro(&aux.month, "Mes : ", "error",1,12,2);
		getNro(&aux.year, "Anio : ", "error", 1945,2021,2);
		for(int i=0;i<tamanio;i++)
		{
		    if(aux.day==repa[i].fechaReparacion.day
		    && aux.month==repa[i].fechaReparacion.month
		    && aux.year==repa[i].fechaReparacion.year)
		    {
			servicioporId(&precio, service, tamanio, repa[i].id_del_Servicio);
			acumulador+=precio;
		    }
		}
		printf("Total recaudacion fecha %d/%d/%d : $%.2f",aux.day,aux.month,aux.year,acumulador);
		acumulador=0;
		break;
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
/*
12- Listar los Electrodomésticos que recibieron reparación en un fecha determinada
 * */
int elecreparadosxfecha(Electrodomestico* elec,int tamelec,Reparacion* repa,int tamrepa,Marca* marca,int tamarca)
{
	int retorno=1,indice;
	Fecha aux;
	aux.day=2;
	aux.month=12;
	aux.year=1993;
	/*puts("\nElectrodomesticos reparados por fecha \nIngrese fecha exacta");
	getNro(&aux.day, " Dia : ", "error",1, 31,2);
	getNro(&aux.month, "Mes : ", "error",1,12,2);
	getNro(&aux.year, "Anio : ", "error", 1945,2021,2);
	 */
	for(int i=0;i<tamrepa;i++)
	{
	    printf("(%d)",i);
	    if( repa[i].isEmpty==FALSE
		&& aux.month==repa[i].fechaReparacion.month
		&& aux.year ==repa[i].fechaReparacion.year
		&& aux.day==repa[i].fechaReparacion.day)
	    {
		cartelUnitElec("reparado");
		indice=electrodomesticoxidhard(elec,tamelec,repa[i].serieReparacion);
		printUnitElec(elec,indice,marca,tamarca);

	      //imprimo electrodomesticos usando el id que esta dentro de la reparacion
	    }

	}
	return retorno;
}
int nuevosInformes(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio,Electrodomestico* elec,Marca* marca,int tam_mar){
	int submenu;
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
	    "8)Elec segun Garantia y fecha\n"
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
		    elecxgarantiayfecha(reparaciones, tam_rep, servicio,tam_ser,elec,tam_ele, marca,tam_mar);
		    break;
		case 9:
		    reparaciones2018(reparaciones, tam_rep, elec, servicio, cliente);
		    break;
		case 10:
		    facturaciontotal(reparaciones, tam_rep, servicio);
		    break;
		case 11:
		    marcaconmasarreglos(reparaciones, tam_rep, marca, tam_mar, elec, tam_ele);
		    break;
		case 12:
		    elecreparadosxfecha(elec, tam_ele, reparaciones,tam_rep, marca, tam_mar);
		    break;
		default:
		    puts("Bye");
			break;

	    }
	}while(submenu!=13);
	return 0;
}


