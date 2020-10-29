#ifndef SUCURSAL_H_INCLUDED
#define SUCURSAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../Listas/Lista.h"
/**
  Definicion de tipo de estructura Sucursal
*/

typedef struct {
    int codSucursal;
    std::string provincia;
    int cantArticulo;
    float monto;
    float cm2;
    int casaMatriz;
}Sucursal;

/* pre: Se recibe una instancia de sucursal
 post: Devuelve la instancia con toda la informacion de ella */
void crearSucursal(Sucursal &sucursal,int codSucursal,char provincia, int cantArticulo, float monto, int cm2,int casaMatriz );

/* pre: Debe haber una sucursal creada
 post: elimina una sucursal existente */
void borrarSucursal(Sucursal *sucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: DEVUELVE CODIGO DE SUCURSAL */
int getCodSucursal(Sucursal &sucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: ASIGNA EL VALOR A CODSUCURSAL A LA INSTANCIA DE SUCURSAL */
void setCodSucursal(Sucursal &sucursal, int codSucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: DEVUELVE LA PROVINCIA */
std::string getProvincia(Sucursal &sucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: ASIGNA EL VALOR A PROVINCIA A LA INSTANCIA DE SUCURSAL*/
void setProvincia(Sucursal &sucursal, std::string provincia);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: DEVUELVE CANTIDAD DE ARTICULO */

int getCantArticulo(Sucursal &sucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: ASIGNA EL VALOR A CANT ARTICULO A LA INSTANCIA DE SUCURSAL */

void setCantArtciulo(Sucursal &sucursal, int cantArticulo);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: DEVUELVE MONTO */
float getMonto(Sucursal &sucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: ASIGNA EL VALOR A MONTO A LA INSTANCIA DE SUCURSAL */
void setMonto(Sucursal &sucursal, float monto);


/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: DEVUELVE cm2 */

float getCm2(Sucursal &sucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post:  ASIGNA EL VALOR A CM2 A LA INSTANCIA DE SUCURSAL */

void setCm2(Sucursal &sucursal, float cm2);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: DEVUELVE Casa Matriz */

int getCasaMatriz(Sucursal &sucursal);

/* pre: LA INSTANCIA DE TDA SUCURSAL DEBE HABERSE CREADO PERO NO DEBE ESTAR DESTRUIDA.
 post: ASIGNA EL VALOR A CASA MATRIZ A LA INSTANCIA DE SUCURSAL */
void setCasaMatriz(Sucursal &sucursal, int casaMatriz);

/* pre: DEBE EXISTIR UN ARCHIVO DE LECTURA DE SUCURSALES Y UNA LISTA DE SUCURSALES VACIA
 post: LEER EL ARCHIVO, DEVOLVER UNA LISTA DE SUCURSALES CARGADA CON TODA LA INFORMACION*/
void cargarSucursal(Lista &lista);

/* pre: TIENE QUE ESTAR ABIERTO EL ARCHIVO EN MODO LECTURA Y TENER UN STRING DONDE RECIBIR EL CONTENIDO
 post: DEVUELVE UNA LINEA DE LECTURA DEL ARCHIVO*/
void leerLineaSucursal(std::string *destino, FILE* fSucursal);

/* pre: EXISTIR UNA SUCURSAL CREADA Y CON DATOS
 post: DEVUELVE STRING CON TODOS LOS DATOS DE LA SUCURSAL*/

std::string toString(Sucursal &sucursal);

#endif // SUCURSAL_H_INCLUDED
