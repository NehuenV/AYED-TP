#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Sucursal.h"
#include "../Listas/Lista.h"
#include <stdlib.h>
using namespace std;


void crearSucursal(Sucursal &sucursal ,int codSucursal,string provincia, int cantArticulo, float monto, float cm2,int casaMatriz ){
    sucursal.codSucursal = codSucursal;
    sucursal.provincia = provincia;
    sucursal.cantArticulo= cantArticulo;
    sucursal.monto = monto;
    sucursal.cm2 = cm2;
    sucursal.casaMatriz = casaMatriz;
}

void borrarSucursal(Sucursal *sucursal)
{
    delete sucursal;
}

int getCodSucursal(Sucursal &sucursal){
    return sucursal.codSucursal;
}
void setCodSucursal(Sucursal &sucursal, int codSucursal){
    sucursal.codSucursal = codSucursal;
}

//char

string getProvincia(Sucursal &sucursal)
{
    return sucursal.provincia;
}
void setProvincia(Sucursal &sucursal, string provincia)
{
   sucursal.provincia = provincia;
}

int getCantArticulo(Sucursal &sucursal)
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

float getCm2(Sucursal &sucursal)
{
    return sucursal.cm2;
}

void setCm2(Sucursal &sucursal, float cm2)
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

void cargarSucursal(Lista &lista)
{
    FILE* fSucursal;
    string lectura="";
    int pos=0;
    //fSucursal = fopen("C:\\Users\\Equipo\\Documents\\AYED-TP\\archivo.txt","r");
    fSucursal = fopen("C:\\Users\\Nehuen\\Documents\\AYED-TP\\AYED-TP\\archivos.txt","r");

    while(!feof(fSucursal))
    {
        //leemos la linea
        leerLineaSucursal(&lectura, fSucursal);
        //cout<< lectura<< endl;
       //se obtiene el largo de la linea
        int largo = lectura.size();
        //encontramos el primer guion
        pos = lectura.find('-');
        //cortamos y casteamos desde el inicio de la linea hasta el guion
        int idSuc = atoi(lectura.substr(0,pos).c_str());
        //conservamos el resto de la linea a partir del primer guion hasta el final
        lectura= lectura.substr(pos+1,largo).c_str();

        /*se repite el proceso anterior
            recorte de provincia
        */
        pos = lectura.find('-');
        string prov = lectura.substr(0,pos);
        lectura= lectura.substr(pos+1,largo).c_str();

        /*recorte de cant articulo*/
        pos = lectura.find('-');
        int cant = atoi(lectura.substr(0,pos).c_str());
        lectura= lectura.substr(pos+1,largo).c_str();

         /*recorte de monto*/
        pos = lectura.find('-');
        float mont = atof(lectura.substr(0,pos).c_str());
        lectura= lectura.substr(pos+1,largo).c_str();

        /*centimetros cuadrados*/
        pos = lectura.find('-');
        float cm = atof(lectura.substr(0,pos).c_str());
        lectura= lectura.substr(pos+1,largo).c_str();

        /*casa matriz*/
        pos = lectura.find('-');
        int casa = atoi(lectura.substr(0,pos).c_str());
        lectura= lectura.substr(pos+1,largo).c_str();

      //  cout<< idSuc<<  prov<<  cant<<  mont<< cm<< casa<<endl;


        Sucursal *sucursal = new Sucursal;
        crearSucursal(*sucursal,idSuc,prov,cant,mont,cm,casa);
       // cout <<toString(*sucursal)<<endl;
        adicionarPrincipio(lista,sucursal);
    lectura="";
    }
    fclose(fSucursal);
}

void leerLineaSucursal(string *destino, FILE* fSucursal)
{
    char buffer=0;
    int i;
    i=0;
    while (buffer!=10 && fread(&buffer,1,1,fSucursal)==1)
    {
        if(buffer!=10)
        {
           // cout<< buffer<< endl;
            *destino += buffer;

        }
        i++;
    }

}

string toString(Sucursal &sucursal) {
    string dato="NULL\n";
       dato = "IdSuc: "+  std::to_string(getCodSucursal(sucursal)) +
               " - Provincia: " + getProvincia(sucursal)+
               " - CantArticulo: "+ std::to_string(getCantArticulo(sucursal))+
               " - Monto: "+ std::to_string(getMonto(sucursal))+
               " - Cm2: "+ std::to_string(getCm2(sucursal))+
                " - CasaMatriz: " + std::to_string(getCasaMatriz(sucursal));
    return dato;
}
