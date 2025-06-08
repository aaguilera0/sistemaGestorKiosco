#include <iostream>
#include <cstring>
using namespace std;

#include "Categoria.h"
#include "ArchivoCategoria.h"
#include "Compra.h"

ArchivoCategoria::ArchivoCategoria(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCategoria::Guardar(Categoria categoria){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

/*bool ArchivoCategoria::Guardar(Categoria categoria, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Categoria) * posicion, SEEK_SET);
    bool ok = fwrite(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}*/

int ArchivoCategoria::Buscar(int IDCategoria){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Categoria categoria;
    int i = 0;
    while(fread(&categoria, sizeof(Categoria), 1, pArchivo)){
        if(categoria.getIdCategoria() == IDCategoria){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/*Compra ArchivoCategoria::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Categoria();
    }
    Categoria categoria;
    fseek(pArchivo, sizeof(Categoria) * posicion, SEEK_SET);
    fread(&categoria, sizeof(Categoria), 1, pArchivo);
    fclose(pArchivo);
    return categoria;
}*/

int ArchivoCategoria::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Categoria);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoCategoria::Leer(int cantidadRegistros, Categoria *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Categoria), 1, pArchivo);
    }
    fclose(pArchivo);
}
