#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED
#include "Producto.h"

class ArchivoProducto{
    private:
        string _nombreArchivo;
    public:
        ArchivoProducto();
        ArchivoProducto(std::string nombreArchivo);

        bool guardar(Producto registro);
        bool guardar(Producto registro, int posicion);
        int CantidadRegistros();
        Producto leer(int pos);
        bool buscarPorID(int id, Producto& registro);
        int ObtenerUltimoId();
};

#endif // ARCHIVOPRODUCTO_H_INCLUDED
