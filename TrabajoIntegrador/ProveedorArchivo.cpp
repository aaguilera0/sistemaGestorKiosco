#include "ProveedorArchivo.h"

ProveedorArchivo::ProveedorArchivo(){
    _nombreArchivo = "proveedores.dat";
}
ProveedorArchivo::ProveedorArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
bool ProveedorArchivo::guardar(Proveedor registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    resultado = fwrite(&registro, sizeof(Proveedor),1,pFile);

    fclose(pFile);

    return resultado;
}
bool ProveedorArchivo::guardar(Proveedor registro, int posicion){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(),"rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, posicion * sizeof(Proveedor), SEEK_SET);

    resultado = fwrite(&registro,sizeof(Proveedor),1,pFile);

    fclose(pFile);

    return resultado;
}
int ProveedorArchivo::getCantidadRegistros(){
    FILE *pFile;
    int cantidad, total;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile,0,SEEK_END);

    total = ftell(pFile);

    cantidad = total / sizeof(Proveedor);

    fclose(pFile);

    return cantidad;
}
Proveedor ProveedorArchivo::leer(int pos){
    FILE *pFile;
    Proveedor reg;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile==nullptr){
        return reg;
    }

    fseek(pFile,sizeof(Proveedor)*pos,SEEK_SET);
    fread(&reg,sizeof(Proveedor),1,pFile);

    fclose(pFile);

    return reg;
}
bool ProveedorArchivo::Buscar(std::string cuitProveedor, Proveedor& proveedorEncontrado) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    Proveedor proveedor1;
    while (fread(&proveedor1, sizeof(Proveedor), 1, pArchivo)) {
        if (proveedor1.getCuit() == cuitProveedor) {
            fclose(pArchivo);
            proveedorEncontrado = proveedor1;
            return true;
        }
    }
    fclose(pArchivo);
    return false;
}
