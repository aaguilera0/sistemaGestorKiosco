#pragma once
#include <string>

class RelacionProveedorProducto{
    private:
        int _idProveedorProducto;
        char _cuitProveedor[20];
        int _idProducto;
    public:
        RelacionProveedorProducto();
        RelacionProveedorProducto(int idProveedorProducto, std::string cuitProveedor, int idProducto);

        int getIdProveedorProducto();
        std::string getCuitProveedor();
        int getIdProducto();

        void setIdProveedorProducto(int id);
        void setCuitProveedor(std::string cuitProveedor);
        void setIdProducto(int idProducto);

        std::string toCSV();
};
