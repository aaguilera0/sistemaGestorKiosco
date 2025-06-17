#ifndef ARCHIVOCOMPRA_H_INCLUDED
#define ARCHIVOCOMPRA_H_INCLUDED

#include <string>
#include "Compra.h"
#include "Fecha.h"

class ArchivoCompra {
private:
    std::string _nombreArchivo;

public:
    ArchivoCompra(std::string nombreArchivo);
    bool Guardar(Compra compraNueva);
    bool Guardar(Compra compraNuevo, int posicion);
    int Buscar(int IDCompra);
    bool Buscar(int IdCompra, Compra& compraEncontrada);
    bool Buscar(std::string cuitProveedor, Fecha fechaCompra, Compra& compraEncontrada);
    bool Buscar(std::string cuitProveedor, Compra& compraEncontrada);
    Compra Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Compra* vector);
};

#endif // ARCHIVOCOMPRA_H_INCLUDED
