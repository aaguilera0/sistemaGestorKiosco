#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED
#include "Producto.h"

class ArchivoProducto{
private:
    string _nombreArchivo;
public:
        ArchivoProducto(std::string nombreArchivo);
        bool Guardar(Producto producto);
        //bool Guardar(Servicio servicio, int posicion);
        int Buscar(int IDProducto); // busca por ID
        //Compra Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Producto *vector);

        int agregarRegistro(Producto prod);

        /*
        archivoProducto();
        bool Guardar();
        int BuscarporID();
        bool Buscar();
        int CantidadRegistros();
        void Leer();
        */
};

#endif // ARCHIVOPRODUCTO_H_INCLUDED
