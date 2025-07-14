#include <iostream>
#include <cstring>
#include "Categoria.h"
#include "ArchivoCategoria.h"
#include "Compra.h"
using namespace std;
ArchivoCategoria::ArchivoCategoria(){
    _nombreArchivo = "categorias.dat";
}
ArchivoCategoria::ArchivoCategoria(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCategoria::guardar(Categoria registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    resultado = fwrite(&registro, sizeof(Categoria),1,pFile);

    fclose(pFile);

    return resultado;
}
bool ArchivoCategoria::guardar(Categoria registro, int posicion){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(),"rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, posicion * sizeof(Categoria), SEEK_SET);

    resultado = fwrite(&registro,sizeof(Categoria),1,pFile);

    fclose(pFile);

    return resultado;
}
int ArchivoCategoria::CantidadRegistros(){
    FILE *pFile;
    int cantidad, total;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile,0,SEEK_END);

    total = ftell(pFile);

    cantidad = total / sizeof(Categoria);

    fclose(pFile);

    return cantidad;
}
Categoria ArchivoCategoria::leer(int pos){
    FILE *pFile;
    Categoria reg;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile==nullptr){
        return reg;
    }

    fseek(pFile,sizeof(Categoria)*pos,SEEK_SET);
    fread(&reg,sizeof(Categoria),1,pFile);

    fclose(pFile);

    return reg;
}
int ArchivoCategoria::buscarPorID(int idBuscado) {
    Categoria cat;
    int cantidad = CantidadRegistros();
    for(int i = 0; i < cantidad; i++) {
        cat = leer(i);
        if(cat.getIdCategoria() == idBuscado ) {
            return i;
        }
    }
    return -1;
}
int ArchivoCategoria::obtenerUltimoId() {
    int cantidad = CantidadRegistros();
    if (cantidad == 0) return 0;

    Categoria ultimaCategoria = leer(cantidad - 1);
    return ultimaCategoria.getIdCategoria();
}
