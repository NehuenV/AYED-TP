#include <iostream>
#include <iomanip>
#include <string>
#include "entidades/Sucursal.h"
#include "entidades/Provincia.h"
#include "Listas/Lista.h"
using namespace std;

ResultadoComparacion compararArticulo(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getCantArticulo(*(Sucursal*)ptrDato1) >getCantArticulo(*(Sucursal*)ptrDato2))
        return MAYOR;
    else if (getCantArticulo(*(Sucursal*)ptrDato1) < getCantArticulo(*(Sucursal*)ptrDato2))
        return MENOR;
    else
        return IGUAL;
}
ResultadoComparacion compararMonto(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getMonto(*(Sucursal*)ptrDato1) >getMonto(*(Sucursal*)ptrDato2))
        return MAYOR;
    else if (getMonto(*(Sucursal*)ptrDato1) < getMonto(*(Sucursal*)ptrDato2))
        return MENOR;
    else
        return IGUAL;
}
ResultadoComparacion compararMontoProv(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getProvincia(*(Sucursal*)ptrDato1)>getProvincia(*(Sucursal*)ptrDato2))
    {
        return MAYOR;
    }else
    if (getProvincia(*(Sucursal*)ptrDato1)<getProvincia(*(Sucursal*)ptrDato2))
    {
        return MENOR;
    }
    else
        compararMonto(ptrDato1,ptrDato2);
}

ResultadoComparacion compararArticuloProv(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getProvincia(*(Sucursal*)ptrDato1)>getProvincia(*(Sucursal*)ptrDato2))
    {
        return MAYOR;
    }else
    if (getProvincia(*(Sucursal*)ptrDato1)<getProvincia(*(Sucursal*)ptrDato2))
    {
        return MENOR;
    }
    else
        compararArticulo(ptrDato1,ptrDato2);
}

ResultadoComparacion compararIdProvincia(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getId(*(SProvincia*)ptrDato1) > getId(*(SProvincia*)ptrDato2))
        return MAYOR;
    else if (getId(*(SProvincia*)ptrDato1) < getId(*(SProvincia*)ptrDato2))
        return MENOR;
    else
        return IGUAL;
}


ResultadoComparacion compararMt2Fact(PtrDato ptrDato1, PtrDato ptrDato2) {
    float cos1=getCm2(*(Sucursal*)ptrDato1)/ getMonto(*(Sucursal*)ptrDato1);
    float cos2=getCm2(*(Sucursal*)ptrDato2)/ getMonto(*(Sucursal*)ptrDato2);
    if (cos1 > cos2)
        return MAYOR;
    else if (cos1<cos2)
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
    crearLista(listaSuc,compararMonto);
    cargarSucursal( listaSuc);
    //    ImprimirLista(listaSuc);
    reordenar(listaSuc);
    cout<< ""<<endl;
    cout<< "Ranking nacional por monto"<<endl;
    cout<< ""<<endl;
    ImprimirLista(listaSuc);
    cout<< ""<<endl;
    cout<< "Ranking provincial por monto"<<endl;
    cout<< ""<<endl;
    setCompare(listaSuc,compararMontoProv);
    reordenar(listaSuc);
    ImprimirLista(listaSuc);

    cout<< ""<<endl;
    cout<< "Ranking nacional por articulos"<<endl;
    cout<< ""<<endl;
    setCompare(listaSuc,compararArticulo);
    reordenar(listaSuc);
    ImprimirLista(listaSuc);
    cout<< ""<<endl;
    cout<< "Ranking provincial por articulo"<<endl;
    cout<< ""<<endl;
    setCompare(listaSuc,compararArticuloProv);
    reordenar(listaSuc);
    ImprimirLista(listaSuc);

    cout<< ""<<endl;
    cout<< "Ranking asdasldjalsd mt2"<<endl;
    cout<< ""<<endl;
    setCompare(listaSuc,compararMt2Fact);
    reordenar(listaSuc);
    ImprimirLista(listaSuc);


   // eliminarListaProvincia(listaProvincias);
    eliminarListaSucursal(listaSuc);


    return 0;
}


