#include <iostream>
#include <cstring>
using namespace std;

#include "Categoria.h"

int Categoria :: getIdCategoria(){
    return _idCategoria;
}
string Categoria :: getNombreCategoria(){
    return _nombreCategoria;
}

void Categoria :: setIDCategoria(int idCategoria){
    _idCategoria = idCategoria;
}
void Categoria :: setNombreCategoria(const char* nombreCategoria ){
    strcpy(_nombreCategoria, nombreCategoria);
}
