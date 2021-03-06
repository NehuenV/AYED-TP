     // #include "entidades/Sucursal.h"
     // #include "entidades/Provincia.h"
    //  #include "Listas/Lista.h"
#include "../entidades/Nucleo.h"
#include <iostream>
#include <iomanip>
using namespace std;


void ResultadoRendimiento(Lista &lista) {

  float resultado=0;

  PtrNodoLista ptrCursor = primero(lista);
  while ( ptrCursor != fin() ) {

        resultado=(getMonto(*(Sucursal*)ptrCursor->ptrDato)/getCm2(*(Sucursal*)ptrCursor->ptrDato));
        std::cout<<  toString(*(Sucursal*)ptrCursor->ptrDato)<< std::endl << "El rendimiento es: " << resultado  << std::endl;
        ptrCursor=ptrCursor->sgte;

  }
}



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

void lstNacionalPorMonto(){

    Lista listaSuc;
    crearLista(listaSuc,compararMonto);
    cargarSucursal( listaSuc);
    reordenar(listaSuc);

    ImprimirListaNacional(listaSuc);
    eliminarListaSucursal(listaSuc);
}
void lstProvincialPorMonto(){
    Lista listaSuc;
    crearLista(listaSuc,compararMontoProv);
    cargarSucursal( listaSuc);
    reordenar(listaSuc);

    ImprimirListaProvincialMonto(listaSuc);
    eliminarListaSucursal(listaSuc);
}

void lstProvincialPorArticulo(){
    Lista listaSuc;
    crearLista(listaSuc,compararArticuloProv);
    cargarSucursal(listaSuc);
    reordenar(listaSuc);

    ImprimirListaProvincialArticulo(listaSuc);
    eliminarListaSucursal(listaSuc);
}
void lstNacionalPorArticulo(){
     Lista listaSuc;
    crearLista(listaSuc,compararArticulo);
    cargarSucursal(listaSuc);
    reordenar(listaSuc);

    ImprimirListaNacional(listaSuc);
    eliminarListaSucursal(listaSuc);
}

void lstRendimiento(){
    Lista listaFact;
    Lista listaSuc;
    crearLista(listaSuc,compararMt2Fact);
    cargarSucursal(listaSuc);
    crearLista(listaFact,compararMt2Fact);
    calculoRendimiento(listaSuc,listaFact);
    reordenar(listaFact);

    ResultadoRendimiento(listaFact);
    eliminarListaSucursal(listaFact);

}

void ImprimirListaNacional(Lista &lista) {


  PtrNodoLista ptrCursor = primero(lista);
  while ( ptrCursor != fin() ) {
       std::cout<< toString(*(Sucursal*)ptrCursor->ptrDato)<<std::endl;
       ptrCursor=ptrCursor->sgte;

  }

}

void ImprimirListaProvincialMonto(Lista &lista) {
    PtrNodoLista ptrPrevio = primero(lista);
    PtrNodoLista ptrCursor = primero(lista);
    std::cout <<std::endl <<"Provincia: " << getProvincia(*(Sucursal*)ptrPrevio->ptrDato)<<std::endl;
   float resultado = 0;
   float aux=0;

   int flag = 0;
    while ( ptrCursor != fin() ) {

         resultado+=(getMonto(*(Sucursal*)ptrPrevio->ptrDato));

         if(flag==1) {
            resultado-=(getMonto(*(Sucursal*)ptrPrevio->ptrDato));
         }

        if(getProvincia(*(Sucursal*)ptrPrevio->ptrDato)!=getProvincia(*(Sucursal*)ptrCursor->ptrDato))
       {

           std::cout <<std::endl <<"Total :  $" << resultado <<std::endl;



           std::cout <<std::endl <<"Provincia:  " << getProvincia(*(Sucursal*)ptrCursor->ptrDato)<<std::endl;


         resultado = 0;
       }



        std::cout<< toString(*(Sucursal*)ptrCursor->ptrDato)<<std::endl;

        ptrPrevio=ptrCursor;

        ptrCursor=ptrCursor->sgte;

flag++;
  }
aux=(getMonto(*(Sucursal*)ptrPrevio->ptrDato));
std::cout <<std::endl <<"Total :  $" << resultado+aux <<std::endl;

}

void ImprimirListaProvincialArticulo(Lista &lista) {
    PtrNodoLista ptrPrevio = primero(lista);
    PtrNodoLista ptrCursor = primero(lista);
    std::cout <<std::endl <<"Provincia: " << getProvincia(*(Sucursal*)ptrPrevio->ptrDato)<<std::endl;
   float resultado = 0;
   float aux=0;

   int flag = 0;
    while ( ptrCursor != fin() ) {

         resultado+=(getCantArticulo(*(Sucursal*)ptrPrevio->ptrDato));

         if(flag==1) {
            resultado-=(getCantArticulo(*(Sucursal*)ptrPrevio->ptrDato));
         }

        if(getProvincia(*(Sucursal*)ptrPrevio->ptrDato)!=getProvincia(*(Sucursal*)ptrCursor->ptrDato))
       {

           std::cout <<std::endl <<"Cantidad de Articulos: " << resultado <<std::endl;



           std::cout <<std::endl <<"Provincia:  " << getProvincia(*(Sucursal*)ptrCursor->ptrDato)<<std::endl;


         resultado = 0;
       }



        std::cout<< toString(*(Sucursal*)ptrCursor->ptrDato)<<std::endl;

        ptrPrevio=ptrCursor;

        ptrCursor=ptrCursor->sgte;

flag++;
  }
aux=(getCantArticulo(*(Sucursal*)ptrPrevio->ptrDato));
std::cout <<std::endl <<"Cantidad de Articulos: " << resultado+aux <<std::endl;

}


void eliminarListaSucursal(Lista &lista) {

  /* retira uno a uno los nodos de la lista */
    while (! listaVacia(lista)){
        borrarSucursal((Sucursal*)primero(lista)->ptrDato);
        eliminarNodo(lista,primero(lista));

    }
}

void calculoRendimiento (Lista &listaSuc, Lista &listaCasMat) {
    PtrNodoLista ptrCursor = primero(listaSuc);
    while (ptrCursor != fin()) {
        if (getCasaMatriz(*(Sucursal*)ptrCursor->ptrDato)==0) {
            adicionarPrincipio(listaCasMat,(Sucursal*)ptrCursor->ptrDato);
        }
        ptrCursor=ptrCursor->sgte;
    }
    PtrNodoLista ptrCursorSuc = primero(listaSuc);
    PtrNodoLista ptrCursorCasMat = primero(listaCasMat);
    float facturacion=0;
    float mt2=0;
    while (ptrCursorCasMat != fin()) {
         facturacion=getMonto(*(Sucursal*)ptrCursorCasMat->ptrDato);
         mt2=getCm2(*(Sucursal*)ptrCursorCasMat->ptrDato);
        while(ptrCursorSuc != fin()) {
            if (getCodSucursal(*(Sucursal*)ptrCursorCasMat->ptrDato) == getCasaMatriz(*(Sucursal*)ptrCursorSuc->ptrDato)){
                mt2+=getCm2(*(Sucursal*)ptrCursorSuc->ptrDato);
                facturacion+=getMonto(*(Sucursal*)ptrCursorSuc->ptrDato);
            }
            ptrCursorSuc=ptrCursorSuc->sgte;
        }
        ptrCursorSuc = primero(listaSuc);
        setCm2(*(Sucursal*)ptrCursorCasMat->ptrDato,mt2);
        setMonto(*(Sucursal*)ptrCursorCasMat->ptrDato,facturacion);
        ptrCursorCasMat=ptrCursorCasMat->sgte;
    }
}

