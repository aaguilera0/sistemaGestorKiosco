#ifndef ARCHIVODETALLECOMPRA_H_INCLUDED
#define ARCHIVODETALLECOMPRA_H_INCLUDED

#include <string>
#include "DetalleCompra.h"
using namespace std;

class archivoDetalleCompra {
private:
    string _nombreArchivo;

public:
    archivoDetalleCompra(string nombreArchivo);
    bool Guardar(DetalleCompra detalleCompra);
    bool Guardar(DetalleCompra detalleCompra, int posicion);
    DetalleCompra Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, DetalleCompra *vector);
    bool Buscar(int IdDetalle, DetalleCompra& detalleCompraEncontrada);
    bool BuscarPorIdCompra(int cantidadRegistros,  DetalleCompra *vector,  int IdCompra);
};

#endif // ARCHIVODETALLECOMPRA_H_INCLUDED
