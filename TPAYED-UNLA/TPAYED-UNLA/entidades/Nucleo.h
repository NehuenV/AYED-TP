#ifndef NUCLEO_H_INCLUDED
#define NUCLEO_H_INCLUDED
#include "../entidades/Sucursal.h"
#include "../entidades/Provincia.h"
#include "../Listas/Lista.h"

ResultadoComparacion compararArticulo(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararMonto(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararMontoProv(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararArticuloProv(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararIdProvincia(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararMt2Fact(PtrDato ptrDato1, PtrDato ptrDato2);
void lstNacionalPorMonto();
void lstProvincialPorMonto();
void lstNacionalPorArticulo();
void lstProvincialPorArticulo();
void lstRendimiento();
void ImprimirLista(Lista &lista);
void ResultadoRendimiento(Lista &lista);
void eliminarListaSucursal(Lista &lista);
void calculoRendimiento (Lista &listaSuc, Lista &listaCasMat);

#endif // NUCLEO_H_INCLUDED
