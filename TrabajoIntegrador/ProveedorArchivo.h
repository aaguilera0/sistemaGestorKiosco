#pragma once
#include <string>
#include "Proveedor.h"

class ProveedorArchivo{
    private:
        std::string _nombreArchivo;
    public:
        ProveedorArchivo();
        ProveedorArchivo(std::string nombreArchivo);

        bool guardar(Proveedor registro);
        bool guardar(Proveedor registro, int posicion);
        int getCantidadRegistros();
        Proveedor leer(int pos);
};
