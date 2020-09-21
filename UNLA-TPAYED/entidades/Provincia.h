#ifndef PROVINCIA_H_INCLUDED
#define PROVINCIA_H_INCLUDED
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "../Listas/Lista.h"

typedef struct {
    int id;
    std::string provArch;
}SProvincia;

void crearSProvincia(SProvincia &sprovincia, int id, std::string provArch);
void borrarSProvincia(SProvincia *sprovincia);
int getId(SProvincia &sprovincia);
void setId(SProvincia &sprovinciam, int id);
std::string getProvArch(SProvincia &sprovincia);
void setProvArch(SProvincia &sprovincia, std::string provArch);
void cargarProvincias(Lista &lista);
void leerLineaProvincia(std::string *destino, FILE* fProvincias);
std::string toStringProvincia(SProvincia &sprovincia);

#endif // PROVINCIA_H_INCLUDED
