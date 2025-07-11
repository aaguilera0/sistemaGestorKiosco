#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class Categoria{
    private:
        int _idCategoria;
        char _nombreCategoria[50];
        bool _estado;


    public:
    int getIdCategoria();
    string getNombreCategoria();
    bool getEstado();

    void setEstado(bool estado);
    void setIDCategoria(int idCategoria);
    void setNombreCategoria(std::string nombreCategoria );

    string toCSV();
};

#endif // CATEGORIA_H_INCLUDED
