#include <iostream>
#include <cstring>
using namespace std;

#include "Producto.h"
#include "ArchivoProducto.h"


ArchivoProducto :: ArchivoProducto(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoProducto :: Guardar(Producto producto){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&producto, sizeof(Producto), 1, pArchivo);
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

int ArchivoProducto :: Buscar(int IDProducto){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Producto producto;
    int i = 0;
    while(fread(&producto, sizeof(Producto), 1, pArchivo)){
        if(producto.getIDProducto() == IDProducto){
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

int ArchivoProducto :: CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Producto);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProducto :: Leer(int cantidadRegistros, Producto *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Producto), 1, pArchivo);
    }
    fclose(pArchivo);
}
int ArchivoProducto :: agregarRegistro(Producto prod){

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo==nullptr){
        return -1;
    }
    int escribio = fwrite(&prod, sizeof(Producto),1,pArchivo);
    fclose(pArchivo);
    return escribio;
}
bool ArchivoProducto :: listarRegistros(){
    Producto obj;
    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo.c_str() , "rb");

    if(pAlumno == nullptr){
        return false;
    }

    while(fread(&obj, sizeof(Producto),1,pAlumno)==1){
        if(obj.getEstado()==true){
        obj.mostrar();
        cout << endl;
        }
    }

    fclose(pAlumno);
    return true;
}
Producto ArchivoProducto :: leerRegistro(int posicion){
    Producto obj;
    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo.c_str(),"rb");

    if(pAlumno==nullptr){
        return obj;
    }
    fseek(pAlumno,posicion*sizeof(Producto),0);
    fread(&obj, sizeof(Producto),1,pAlumno);

    fclose(pAlumno);
    return obj;
}
int ArchivoProducto :: modificarRegistro(Producto prod, int pos){

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo==nullptr){
        return -1;
    }
    fseek(pArchivo,pos*sizeof(Producto),0);
    int escribio = fwrite(&prod, sizeof(Producto),1,pArchivo);
    fclose(pArchivo);
    return escribio;
}
