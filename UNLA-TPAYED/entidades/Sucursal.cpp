#include <iostream>
#include <sstream>
#include "Sucursal.h"

void crearSucursal(Sucursal &sucursal,int codSucursal,char provincia[20], int cantArticulo, float monto, int cm2,int casaMatriz ){
    sucursal.codSucursal = codSucursal;
//    sucursal.provincia = provincia;
    sucursal.cantArticulo = cantArticulo;
    sucursal.monto = monto;
    sucursal.cm2= cm2;
    sucursal.casaMatriz = casaMatriz;

}

void borrarSucursal(Sucursal &sucursal)
{
}

int getCodSucursal(Sucursal &sucursal){
    return sucursal.codSucursal;
}
void setCodSucursal(Sucursal &sucursal, int codSucursal){
    sucursal.codSucursal = codSucursal;
}

//char
char * getProvincia(Sucursal &sucursal)
{
    return sucursal.provincia;
}
void setProvincia(Sucursal &sucursal, char * provincia)
{
   for( int i=0;  i<20 ;i++){
        sucursal.provincia[i]=provincia[i];
    }
}

int getCantArticulo(Sucursal &sucursal, int cantArticulo)
{
    return sucursal.cantArticulo;
}
void setCantArtciulo(Sucursal &sucursal, int cantArticulo)
{
    sucursal.cantArticulo = cantArticulo;
}

float getMonto(Sucursal &sucursal)
{
    return sucursal.monto;
}
void setMonto(Sucursal &sucursal, float monto)
{
    sucursal.monto = monto;
}

int getCm2(Sucursal &sucursal)
{
    return sucursal.cm2;
}

void setCm2(Sucursal &sucursal, int cm2)
{
    sucursal.cm2 = cm2;
}

int getCasaMatriz(Sucursal &sucursal)
{
    return sucursal.casaMatriz;
}
void setCasaMatriz(Sucursal &sucursal, int casaMatriz)
{
    sucursal.casaMatriz = casaMatriz;
}
