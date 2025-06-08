#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class Categoria{
    private:
        int _idCategoria;
        char _nombreCategoria[50];


    public:
    int getIdCategoria();
    string getNombreCategoria();

    void setIDCategoria(int idCategoria);
    void setNombreCategoria(const char* nombreCategoria );




};

#endif // CATEGORIA_H_INCLUDED
