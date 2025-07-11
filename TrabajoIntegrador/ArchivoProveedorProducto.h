#ifndef ARCHIVOPROVEEDORPRODUCTO_H_INCLUDED
#define ARCHIVOPROVEEDORPRODUCTO_H_INCLUDED

#include <string>
#include "RelacionProveedorProducto.h"
using namespace std;

class ArchivoProveedorProducto {
private:
    string _nombreArchivo;

public:
    ArchivoProveedorProducto(string nombreArchivo);
    bool Guardar(RelacionProveedorProducto relacionProveedorProducto);
    bool Guardar(RelacionProveedorProducto relacionProveedorProducto, int posicion);
    RelacionProveedorProducto Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, RelacionProveedorProducto *vector);
    bool Buscar(int IdProveedorProducto, RelacionProveedorProducto& relacionEncontrada);
    bool BuscarPorCuit(int cantidadRegistros,  RelacionProveedorProducto *vector,  string cuit);
    int ObtenerUltimoId();
};

#endif // ARCHIVOPROVEEDORPRODUCTO_H_INCLUDED
