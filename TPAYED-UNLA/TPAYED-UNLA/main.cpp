#include <iostream>
#include <iomanip>
#include <string>
#include "entidades/Sucursal.h"
#include "entidades/Provincia.h"
#include "Listas/Lista.h"
#include "entidades/Nucleo.h"
using namespace std;

int opc;
void consulta(), menu(),facturacion(),ventas(), rendimiento(), volver();



void consulta(){
system("cls");
cout <<"###############################################"<< endl;
    cout << "#\tSistema de control se sucursal.       #" << endl;
    cout <<"###############################################"<< endl;
    cout << "\n\n1. Sucursal con mayor facturacion" << endl;
    cout << "\n2. Sucursal con mayor Venta de Articulos" << endl;
    cout << "\n3. Sucursal con mayor rendimiento" << endl;
    cout << "\n4. Salir del programa" << endl;

    cout << "\n\nIngrese la opcion deseada: "; cin>>opc;
    system("cls");
    switch(opc){
    case 1: facturacion(); break;
    case 2: ventas(); break;
    case 3: rendimiento(); volver(); break;
    case 4: break;

    default : consulta();
    }
    }
void facturacion(){
system("cls");

    cout <<"###############################################"<< endl;
    cout << "#\tSistema de control se sucursal.       #" << endl;
    cout <<"###############################################"<< endl;
     cout << "\n\n\tSucursal con mayor facturacion." << endl;
    cout << "\n\n1. A nivel nacional" << endl;
    cout << "\n2. A nivel provincial" << endl;
    cout << "\n3. Volver" << endl;
    cout << "\n\nIngrese la opcion deseada: "; cin>>opc;
    system("cls");
    switch(opc){
    case 1: lstNacionalPorMonto(); volver(); break;
    case 2: lstProvincialPorMonto(); volver(); break;
    case 3: consulta(); break;
    default : facturacion();
    }
}
void ventas(){
system("cls");

    cout <<"###############################################"<< endl;
    cout << "#\tSistema de control se sucursal.       #" << endl;
    cout <<"###############################################"<< endl;
     cout << "\n\n\tSucursal con mayor Venta de Articulos" << endl;
    cout << "\n\n1. A nivel nacional" << endl;
    cout << "\n2. A nivel provincial" << endl;
    cout << "\n3. Volver" << endl;
    cout << "\n\nIngrese la opcion deseada: "; cin>>opc;
    system("cls");
    switch(opc){
    case 1: lstNacionalPorArticulo(); volver(); break;
    case 2: lstProvincialPorArticulo(); volver(); break;
    case 3: consulta(); break;
    default : ventas();
    }

    }
void rendimiento(){
system("cls");
lstRendimiento();
}
void volver(){
cout << "\n Ingrese 0 para volver o cualquier numero para salir: "; cin>>opc;
    system("cls");
    switch(opc){
    case 0: consulta(); break;
    default : break;
    }
}




int main()
{

    consulta();


    return 0;
}


