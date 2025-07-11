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
bool Categoria :: getEstado(){
    return _estado;
}

void Categoria :: setEstado(bool estado){
    _estado = estado;
}
void Categoria :: setIDCategoria(int idCategoria){
    _idCategoria = idCategoria;
}
void Categoria :: setNombreCategoria(std::string nombreCategoria ){
    strcpy(_nombreCategoria, nombreCategoria.c_str());
}

std::string Categoria :: toCSV(){
        return "ID CATEGORIA : " + std::to_string(_idCategoria) + " || " + "NOMBRE CATEGORIA : " + std::string(_nombreCategoria);
    }
