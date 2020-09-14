#ifndef SUCURSAL_H_INCLUDED
#define SUCURSAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int codSucursal;
    char provincia[20];
    int cantArticulo;
    float monto;
    int cm2;
    int casaMatriz;
}Sucursal;

void crearSucursal(Sucursal &sucursal,int codSucursal,char provincia, int cantArticulo, float monto, int cm2,int casaMatriz );

void borrarSucursal(Sucursal &sucursal);

int getCodSucursal(Sucursal &sucursal);
void setCodSucursal(Sucursal &sucursal, int codSucursal);

//char
char * getProvincia(Sucursal &sucursal);
void setProvincia(Sucursal &sucursal, char * provincia);

int getCantArticulo(Sucursal &sucursal, int cantArticulo);
void setCantArtciulo(Sucursal &sucursal, int cantArticulo);

float getMonto(Sucursal &sucursal);
void setMonto(Sucursal &sucursal, float monto);

int getCm2(Sucursal &sucursal);
void setCm2(Sucursal &sucursal, int cm2);

int getCasaMatriz(Sucursal &sucursal);
void setCasaMatriz(Sucursal &sucursal, int casaMatriz);

void cargarSucursal(Sucursal &sucursal);

void leerLineaSucursal(char* destino, FILE* fSucursal);

#endif // SUCURSAL_H_INCLUDED
