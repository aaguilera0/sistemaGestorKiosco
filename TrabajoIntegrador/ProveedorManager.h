#ifndef PROVEEDORMANAGER_H_INCLUDED
#define PROVEEDORMANAGER_H_INCLUDED
#include <cstring>
#include <string>
class ProveedorManager{
    public:
        void cargarNuevoProveedor();
        void modificarProveedor();
        void eliminarProveedor();
        void listarProveedores();
        void mostrarCantidadRegistros();
        bool BuscarProveedorPorCuit();
        bool BuscarProveedorPorCuit(std::string cuit);
        void verProductosAsociados();
        void desactivarProveedor();
};
#endif // PROVEEDORANAGER_H_INCLUDED
