#ifndef PRODUCTOMANAGER_H_INCLUDED
#define PRODUCTOMANAGER_H_INCLUDED
#include "Producto.h"
class ProductoManager{
public:
    int cargarNuevoProducto();
    void modificarProducto();
    void mostrarCantidadRegistros();
    void listarProductos();
    void eliminarProducto();
    void activarProducto();
    bool BuscarProductoPorId(int idProducto, Producto& productoEncontrado);

};

#endif // PRODUCTOMANAGER_H_INCLUDED
