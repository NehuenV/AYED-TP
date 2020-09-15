#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "Sucursal.h"
#include <stdlib.h>



void crearSucursal(Sucursal sucursal){
    sucursal = new SucursalStruct;
}

void borrarSucursal(Sucursal sucursal)
{
    delete sucursal;
}

int getCodSucursal(Sucursal sucursal){
    return sucursal->codSucursal;
}
void setCodSucursal(Sucursal sucursal, int codSucursal){
    sucursal->codSucursal = codSucursal;
}

//char

char * getProvincia(Sucursal sucursal)
{
    return sucursal->provincia;
}
void setProvincia(Sucursal sucursal, char * provincia)
{
   for( int i=0;  i<20 ;i++){
        sucursal->provincia[i]=provincia[i];
    }
}

int getCantArticulo(Sucursal sucursal, int cantArticulo)
{
    return sucursal->cantArticulo;
}
void setCantArtciulo(Sucursal sucursal, int cantArticulo)
{
    sucursal->cantArticulo = cantArticulo;
}

float getMonto(Sucursal sucursal)
{
    return sucursal->monto;
}
void setMonto(Sucursal sucursal, float monto)
{
    sucursal->monto = monto;
}

int getCm2(Sucursal sucursal)
{
    return sucursal->cm2;
}

void setCm2(Sucursal sucursal, int cm2)
{
    sucursal->cm2 = cm2;
}

int getCasaMatriz(Sucursal sucursal)
{
    return sucursal->casaMatriz;
}
void setCasaMatriz(Sucursal sucursal, int casaMatriz)
{
    sucursal->casaMatriz = casaMatriz;
}

void cargarSucursal(Sucursal &sucursal)
{
    FILE* fSucursal;
    char lectura[80];
    int i;

    fSucursal = fopen("archivo.txt","r");
    while(!feof(fSucursal))
    {
        for (i=0;i<80;i++) lectura[i]=0;
        leerLineaSucursal(lectura, fSucursal);
        //splitear linea
    }
    fclose(fSucursal);
}

void leerLineaSucursal(char* destino, FILE* fSucursal)
{
    char buffer;
    int i;

    i=0;
    buffer=0;
    while (buffer!=10 && fread(&buffer,1,1,fSucursal)==1)
    {
        if(buffer!=10) destino[i] = buffer;
        i++;
    }
}
