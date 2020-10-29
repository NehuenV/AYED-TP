#ifndef NUCLEO_H_INCLUDED
#define NUCLEO_H_INCLUDED
#include "../entidades/Sucursal.h"
#include "../entidades/Provincia.h"
#include "../Listas/Lista.h"
/* Axiomas resultadoComparacion:
pre: Tener dos punteros de Datos
post: Devuelve un menor mayor o igual de la comparacion
    */
ResultadoComparacion compararArticulo(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararMonto(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararMontoProv(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararArticuloProv(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararIdProvincia(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararMt2Fact(PtrDato ptrDato1, PtrDato ptrDato2);


/* Axiomas :
pre: Tener el programa ejecutandose
post: Muestra la salida de datos

    */
void lstNacionalPorMonto();
void lstProvincialPorMonto();
void lstNacionalPorArticulo();
void lstProvincialPorArticulo();
void lstRendimiento();



/* Axiomas :
pre: La lista debe existir y tener contenido
post: Imprime por consola la lista

    */
void ImprimirListaNacional(Lista &lista);
void ImprimirListaProvincialMonto(Lista &lista);
void ImprimirListaProvincialArticulo(Lista &lista);
void ResultadoRendimiento(Lista &lista);
/*
pre: Debe existir una lista de Sucursales
post: Elimina la lista de sucursales

    */
void eliminarListaSucursal(Lista &lista);

/*
pre: Debe existir una lista de sucursales (llena de datos) y una lista de casas matrices (vacia)
post: Una lista de casas matrices con la suma de la facturacion y de los cm2 de todas las sucursales

    */
void calculoRendimiento (Lista &listaSuc, Lista &listaCasMat);

#endif // NUCLEO_H_INCLUDED
