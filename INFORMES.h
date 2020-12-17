/*
 * INFORMES.h
 *
 *  Created on: 22 oct. 2020
 *      Author: Usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_
int reparacionporelec(Electrodomestico* elec,Reparacion* repa,Servicio* servicio,Cliente* cliente);
int printpormarca(Marca* marca,Electrodomestico* elec, int cantidad);
int printElec2020(Electrodomestico* elec, int tamanio);
int nuevosInformes(Reparacion* reparaciones,Cliente* cliente,Servicio* servicio,Electrodomestico* aElec,Marca* marca);
#include "INFORMES.h"
#endif
