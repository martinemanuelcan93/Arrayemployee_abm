#include "Electrodomestico.h"
#include "Cliente.h"
#ifndef REPARACIONES_H_
#define REPARACIONES_H_

typedef struct {
	int idReparacion; // autoincremental

	int serieReparacion;// ID de electrodomestico
	int id_del_Servicio; // hacer un getServicio

	int isEmpty;
	Fecha fechaReparacion;
}Reparacion;

int initReparaciones(Reparacion* reparaciones,int tam_rep);
int altaforzadaReparacion(Reparacion* datarep,Fecha* fecha,Servicio* service,Electrodomestico* data,int* idreparacion,int tam_repa);
int addReparacion(Reparacion* datarep,Fecha* fecha,Servicio* service,Electrodomestico* data,Cliente* cliente,int tam_reparacion,int* Idreparacion);
int buscarReparacionLibre(Reparacion* reparacion,int tam,int* posicion);
int printUnitReparacion(Reparacion* datarep,Servicio* service,int posicion);
int printReparaciones(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio, int L);
int printClienteporID(int ID,Cliente* cliente);
int printServicioporID(int ID,Servicio* service,int tam_ser);
#include "Reparaciones.h"

#endif /* REPARACIONES_H_ */
