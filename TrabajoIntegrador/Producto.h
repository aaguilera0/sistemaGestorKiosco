#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <string>
using namespace std;

    class Producto{
private:
    int _IDproducto;
    int _IDCategoria;
    int _stock;
    float _precioUnitario;
    bool _estado;
public:
    Producto();

    int getIDProducto();
    int getIDCategoria();
    int getStock();
    float getPrecioUnitario();
    bool getEstado();

    void setIDProducto(int IDProducto);
    void setIDCategoria(int IDCategoria);
    void setStock(int stock);
    void setPrecioUnitario(int precioUnitario);
    void setEstado(bool estado);

    string toCSV();

    void cargar();
};

#endif // PRODUCTO_H_INCLUDED
