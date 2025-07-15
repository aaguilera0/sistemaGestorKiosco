#ifndef PROVEEDORPRODUCTOMANAGER_H_INCLUDED
#define PROVEEDORPRODUCTOMANAGER_H_INCLUDED

class ProveedorProductoManager{
    public:
        void cargarNuevaRelacion(std::string cuitProveedor, int idProducto);
        void modificarRelacion();
        void eliminarRelacion();
        void listar();
        void mostrarCantidadRegistros();
        void buscarRelacionesPorCuit(std::string cuit);
};

#endif // PROVEEDORPRODUCTOMANAGER_H_INCLUDED
