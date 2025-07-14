#ifndef ARCHIVOCATEGORIA_H_INCLUDED
#define ARCHIVOCATEGORIA_H_INCLUDED
//#include "c"
#include "Categoria.h"


class ArchivoCategoria{
private:
    string _nombreArchivo;
public:
        ArchivoCategoria();
        ArchivoCategoria(std::string nombreArchivo);
        bool guardar(Categoria registro);
        bool guardar(Categoria registro, int posicion);
        int CantidadRegistros();
        Categoria leer(int pos);
        int buscarPorID(int id);
        int obtenerUltimoId();
};

#endif // ARCHIVOCATEGORIA_H_INCLUDED
