#include <iostream>
#include <iomanip>
#include <string>
#include "Entidades/Sucursal.h"
#include "Listas/Lista.h"
using namespace std;

ResultadoComparacion compararMonto(PtrDato ptrDato1, PtrDato ptrDato2) {
//hacer un metodo como la gente y no un hardcodeo

 if (getMonto(*(Sucursal*)ptrDato1) < getMonto(*(Sucursal*)ptrDato2))
        return MAYOR;

}

int main()
{
    cout<< "leyendo archivo"<<endl;
    Lista lista;
    crearLista(lista,compararMonto);
    cargarSucursal( lista);

    reordenar(lista);

    return 0;
}
