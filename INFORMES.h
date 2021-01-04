/*
 * INFORMES.h
 *
 *  Created on: 22 oct. 2020
 *      Author: Usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_
int preciototalelec(Electrodomestico* elec,Reparacion* reparacioness,Servicio* servicio,Cliente* cliente);
int servicioporId(float* precio,Servicio* service,int tamanio,int idbuscado);
int recaudacionxfecha(Reparacion* repa,int tamanio,Servicio* service);
int elecSinReparacion(Electrodomestico* elec,Reparacion* reparacioness,int tam_elec,int repara,Marca* marca,int tamanio_mar);
int reparacionporelec(Electrodomestico* elec,Reparacion* repa,Servicio* servicio,Cliente* cliente,Marca* marca);
int printpormarca(Marca* marca,Electrodomestico* elec, int cantidad,int tam_mar);
int printelec2020(Electrodomestico* elec, int tamanio,Marca* marca,int tam_mar);
int nuevosInformes(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio,Electrodomestico* aElec,Marca* marca,int tam_mar);
#include "INFORMES.h"
#endif
