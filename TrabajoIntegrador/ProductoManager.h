#ifndef PRODUCTOMANAGER_H_INCLUDED
#define PRODUCTOMANAGER_H_INCLUDED

class ProductoManager{
public:
    int cargarNuevoProducto();
    void modificarProducto();
    void mostrarCantidadRegistros();
    void listarProductos();
    void eliminarProducto();
    //void activarProducto();

    /// CATEGORIA

    int agregarCategoria();
    void modificarCategoria();
    void eliminarCategoria();
    void listarCategorias();
};

#endif // PRODUCTOMANAGER_H_INCLUDED
