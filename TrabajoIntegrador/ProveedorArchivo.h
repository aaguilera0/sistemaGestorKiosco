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
        int cantidadRegistros();
        Proveedor leer(int pos);
};
