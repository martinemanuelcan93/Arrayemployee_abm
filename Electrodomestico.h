#include "Serv&Marc.h"
#ifndef ARRAYELECTRODOMESTICO_H_
#define ARRAYELECTRODOMESTICO_H_
typedef struct{
	int day;
	int month;
	int year;
}Fecha;

typedef struct
{
    	int idElec;
    	int serie;
    	int idmarca;
    	int isEmpty;
    	int id_cliente;
    	Fecha modelo;
}Electrodomestico;

int buscarElectrodomesticoLibre(Electrodomestico* elec,int tamanio,int* posicion);
int initElectrodomestico(Electrodomestico* elec,int cantidad);
int addElectrodomestico(Electrodomestico* elec,Fecha* fecha,Marca *marca, int L,int* idElectrodomestico);
int printElectrodomesticos(Electrodomestico* elec, int tamanio);
/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int isValid_elec(Electrodomestico* elec, int tam,int idBuscado);
int sortElectrodomestico(Electrodomestico* elec, int tamanio, int order);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int removeElectrodomestico(Electrodomestico* elec, int tamanio,Marca* marca);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int modifyElectrodomestico(Electrodomestico* elec,Marca* marca, int tamanio);
int electrodomesticobyID(Electrodomestico* elec,int tamanio,int* posicion);
int printUnitElec(Electrodomestico* data,int posicion,Marca* marca,int tamanio_mar);
void cartelUnitElec(char* msj_electrodomestico);
int altaforzadaUnidadElec(Electrodomestico* elec,int tamanio,int i,int* id,int marca,int serie,int modelo,int anio);
float promedio(Electrodomestico* elec,float* promedy,int tamanio);
void altaforzadaVariosElec(Electrodomestico* elec,int tamanio,int *id_elec);
void electrodomesticos_cargados(Electrodomestico* elec,int tamanio);
char* elecporIdReparacion(Electrodomestico* elec,int tamanio,int idBuscado);
#include "Electrodomestico.h"
#endif
