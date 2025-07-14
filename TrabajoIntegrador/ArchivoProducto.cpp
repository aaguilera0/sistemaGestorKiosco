#include <iostream>
#include <cstring>
using namespace std;

#include "Producto.h"
#include "ArchivoProducto.h"

ArchivoProducto::ArchivoProducto(){
    _nombreArchivo = "productos.dat";
}
ArchivoProducto::ArchivoProducto(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
bool ArchivoProducto::guardar(Producto registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    resultado = fwrite(&registro, sizeof(Producto),1,pFile);

    fclose(pFile);

    return resultado;
}
bool ArchivoProducto::guardar(Producto registro, int posicion){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(),"rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, posicion * sizeof(Producto), SEEK_SET);

    resultado = fwrite(&registro,sizeof(Producto),1,pFile);

    fclose(pFile);

    return resultado;
}
int ArchivoProducto::CantidadRegistros(){
    FILE *pFile;
    int cantidad, total;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile,0,SEEK_END);

    total = ftell(pFile);

    cantidad = total / sizeof(Producto);

    fclose(pFile);

    return cantidad;
}
Producto ArchivoProducto::leer(int pos){
    FILE *pFile;
    Producto reg;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile==nullptr){
        return reg;
    }

    fseek(pFile,sizeof(Producto)*pos,SEEK_SET);
    fread(&reg,sizeof(Producto),1,pFile);

    fclose(pFile);

    return reg;
}
int ArchivoProducto::buscarPorID(int idBuscado) {
    Producto prod;
    int cantidad = CantidadRegistros();
    for(int i = 0; i < cantidad; i++) {
        prod = leer(i);
        if(prod.getIdProducto() == idBuscado ) {
            return i;
        }
    }
    return -1;
}
int ArchivoProducto::ObtenerUltimoId() {
    int cantidad = CantidadRegistros();
    if (cantidad == 0) return 0;

    Producto ultimoProducto = leer(cantidad - 1);
    return ultimoProducto.getIdProducto();
}
