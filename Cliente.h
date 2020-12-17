
#ifndef CLIENTE_H_
#define CLIENTE_H_
typedef struct{
	int idcliente;
	char nombre[50];
	char apellido[50];
}Cliente;
int altaforzadaCliente(Cliente* cliente,int tamanio);
int printCliente(Cliente* cliente, int L);
#include "Cliente.h"
#endif /* CLIENTE_H_ */
