#ifndef ARCHIVOCATEGORIA_H_INCLUDED
#define ARCHIVOCATEGORIA_H_INCLUDED
//#include "Compra."

class ArchivoCategoria{
private:
    string _nombreArchivo;
public:
        ArchivoCategoria(std::string nombreArchivo);
        bool Guardar(Categoria categoria);
        //bool Guardar(Servicio servicio, int posicion);
        int Buscar(int IDCategoria);
        //Compra Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Categoria *vector);
};

#endif // ARCHIVOCATEGORIA_H_INCLUDED
