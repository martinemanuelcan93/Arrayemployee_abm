#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca2020.h"
#include "Serv&Marc.h"
#include "Cliente.h"

int altaforzadaCliente(Cliente* cliente,int tamanio){
	Cliente buffermarca[]={
			{2,"Martin","Maldonado "},
			{4,"Carlos","Milner    "},
			{6,"Romina","Zeta      "},
			{8,"Homero","Rodriguez "},
			{10,"Ernesto","Martinez"},
	};
	for(int i=0;i<tamanio;i++){
		cliente[i]=buffermarca[i];
	}
return 0;
}
int printCliente(Cliente* cliente, int L){
	int retorno=-1;
	if(cliente!=NULL && L >0){
		printf("|Id Cliente  |Nombre    | Apellido \n");

		for(int i=0;  i<L  ;i++){

		printf("    %d          %s    %s \n",
				cliente[i].idcliente,
				cliente[i].nombre,
				cliente[i].apellido);
		}
		retorno=0;
	}
		return retorno;
}
