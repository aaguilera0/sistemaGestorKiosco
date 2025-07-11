#ifndef PROVEEDORPRODUCTOMANAGER_H_INCLUDED
#define PROVEEDORPRODUCTOMANAGER_H_INCLUDED

class ProveedorProductoManager{
    public:
        void cargarNuevaRelacion(string cuitProveedor, int idProducto);
        void modificarRelacion();
        void eliminarRelacion();
        void listar();
        void mostrarCantidadRegistros();
        void buscarRelacionPorCuit();
};

#endif // PROVEEDORPRODUCTOMANAGER_H_INCLUDED
