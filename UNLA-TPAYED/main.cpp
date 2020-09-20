#include <iostream>
#include <iomanip>
#include <string>
#include "Entidades/Sucursal.h"
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

int main()
{
    cout<< "leyendo archivo"<<endl;
    Lista lista;
    crearLista(lista,compararMonto);
    cargarSucursal( lista);
    reordenar(lista);
    ImprimirLista(lista);
    eliminarListaSucursal(lista);


    return 0;
}
