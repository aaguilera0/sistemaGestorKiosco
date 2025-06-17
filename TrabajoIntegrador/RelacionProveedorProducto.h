#pragma once
#include <string>

class RelacionProveedorProducto{
    private:
        char _cuitProveedor[20];
        int _idProducto;
    public:
        RelacionProveedorProducto();
        RelacionProveedorProducto(std::string cuitProveedor, int idProducto);

        std::string getCuitProveedor();
        int getIdProducto();

        void setCuitProveedor(std::string cuitProveedor);
        void setIdProducto(int idProducto);

        std::string toCSV();
};
