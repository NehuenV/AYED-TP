#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Provincia.h"
#include "../Listas/Lista.h"
#include <stdlib.h>
using namespace std;

void crearSProvincia(SProvincia &sprovincia, int id, std::string provArch)
{
    sprovincia.id = id;
    sprovincia.provArch = provArch;
}
void borrarSProvincia(SProvincia *sprovincia)
{
    delete sprovincia;
}
int getId(SProvincia &sprovincia)
{
    return sprovincia.id;
}
void setId(SProvincia &sprovincia, int id)
{
    sprovincia.id=id;
}
string getProvArch(SProvincia &sprovincia)
{
    return sprovincia.provArch;
}
void setProvArch(SProvincia &sprovincia, string provArch)
{
    sprovincia.provArch=provArch;
}


void cargarProvincias(Lista &lista)
{
    FILE* fProvincias;
    string lectura="";
    //fSucursal = fopen("C:\\Users\\Equipo\\Documents\\AYED-TP\\archivo.txt","r");
    fProvincias = fopen("C:\\Users\\Nehuen\\Documents\\AYED-TP\\AYED-TP\\provincias.txt","r");
    int i = 0;
    while(!feof(fProvincias))
    {
        leerLineaProvincia(&lectura, fProvincias);
        //cout<<lectura<<endl;
        SProvincia *prov = new SProvincia;
        crearSProvincia(*prov,i,lectura);
        adicionarPrincipio(lista,prov);
        i++;
        lectura="";
    }
    fclose(fProvincias);
}
void leerLineaProvincia(string *destino, FILE* fProvincias)
{
    char buffer=0;
    int i;
    i=0;
    while (buffer!=10 && fread(&buffer,1,1,fProvincias)==1)
    {
        if(buffer!=10)
        {
           // cout<< buffer<< endl;
            *destino += buffer;

        }
        i++;
    }
}

string toStringProvincia(SProvincia &sprovincia) {
    string dato="NULL\n";
       dato = "Id: "+  std::to_string(getId(sprovincia)) +
               " - Provincia: " + getProvArch(sprovincia);
    return dato;
}
