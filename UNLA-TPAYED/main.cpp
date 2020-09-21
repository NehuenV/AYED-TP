#include <iostream>
#include <iomanip>
#include <string>
#include "entidades/Sucursal.h"
#include "entidades/Provincia.h"
#include "Listas/Lista.h"
using namespace std;

ResultadoComparacion compararMonto(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getMonto(*(Sucursal*)ptrDato1) < getMonto(*(Sucursal*)ptrDato2))
        return MAYOR;
    else if (getMonto(*(Sucursal*)ptrDato1) > getMonto(*(Sucursal*)ptrDato2))
        return MENOR;
    else
        return IGUAL;
}
ResultadoComparacion compararMontoProv(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getProvincia(*(Sucursal*)ptrDato1)==getProvincia(*(Sucursal*)ptrDato2) &&getMonto(*(Sucursal*)ptrDato1) > getMonto(*(Sucursal*)ptrDato2))
        return MAYOR;
    else if (getProvincia(*(Sucursal*)ptrDato1)==getProvincia(*(Sucursal*)ptrDato2) && getMonto(*(Sucursal*)ptrDato1) < getMonto(*(Sucursal*)ptrDato2))
        return MENOR;
        if(getProvincia(*(Sucursal*)ptrDato1)==getProvincia(*(Sucursal*)ptrDato2) && getMonto(*(Sucursal*)ptrDato1) == getMonto(*(Sucursal*)ptrDato2)){
            return IGUAL;}
}
ResultadoComparacion compararIdProvincia(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getId(*(SProvincia*)ptrDato1) < getId(*(SProvincia*)ptrDato2))
        return MAYOR;
    else if (getId(*(SProvincia*)ptrDato1) > getId(*(SProvincia*)ptrDato2))
        return MENOR;
    else
        return IGUAL;
}
void listasProvincias(Lista &listaSuc, Lista &listaProv, Lista listaOrdenProvinciasMonto)
{
    PtrNodoLista ptrCursorP = primero(listaProv);
    PtrNodoLista ptrCursorS = primero(listaSuc);
    while ( ptrCursorP != fin() ) {
        while ( ptrCursorS != fin() ) {

           if(getProvArch(*(SProvincia*)ptrCursorP->ptrDato)==getProvincia(*(Sucursal*)ptrCursorS->ptrDato)){
                adicionarPrincipio(listaOrdenProvinciasMonto,(Sucursal*)ptrCursorS);
           }
            ptrCursorS=ptrCursorS->sgte;
        }
    }
}



int main()
{
    cout<< "leyendo archivo"<<endl;
    Lista listaSuc;
    crearLista(listaSuc,compararMontoProv);
    cargarSucursal( listaSuc);
    reordenar(listaSuc);
    reordenar(listaSuc);
    ImprimirLista(listaSuc);
/*
    Lista listaProvincias;
    crearLista(listaProvincias,compararIdProvincia);
    cargarProvincias(listaProvincias);
   // ImprimirListaProvincia(listaProvincias);

    Lista listaOrdenProvinciasMonto;
    crearLista(listaOrdenProvinciasMonto,compararMonto);
*/

   // eliminarListaProvincia(listaProvincias);
    eliminarListaSucursal(listaSuc);


    return 0;
}


