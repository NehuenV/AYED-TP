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
ResultadoComparacion compararIdProvincia(PtrDato ptrDato1, PtrDato ptrDato2) {
    if (getId(*(SProvincia*)ptrDato1) < getId(*(SProvincia*)ptrDato2))
        return MAYOR;
    else if (getId(*(SProvincia*)ptrDato1) > getId(*(SProvincia*)ptrDato2))
        return MENOR;
    else
        return IGUAL;
}

int main()
{
    cout<< "leyendo archivo"<<endl;
    Lista listaSuc;
    crearLista(listaSuc,compararMonto);
    cargarSucursal( listaSuc);
    reordenar(listaSuc);
    ImprimirLista(listaSuc);

    Lista listaProvincias;
    crearLista(listaProvincias,compararIdProvincia);
    cargarProvincias(listaProvincias);
    ImprimirListaProvincia(listaProvincias);

    eliminarListaProvincia(listaProvincias);
    eliminarListaSucursal(listaSuc);


    return 0;
}
