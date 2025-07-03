#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <string>
using namespace std;

    class Producto{
private:
    int _idProducto;
    int _idCategoria;
    int _stock;
    float _precioUnitario;
    bool _estado;
    char _nombre[30];
public:
    Producto();
    Producto(int idProducto, int idCategoria, int stock, float precioUnitario, bool estado);

    int getIdProducto();
    int getIdCategoria();
    int getStock();
    float getPrecioUnitario();
    bool getEstado();
    std::string getNombre();

    void setIdProducto(int idProducto);
    void setIdCategoria(int idCategoria);
    void setStock(int stock);
    void setPrecioUnitario(int precioUnitario);
    void setEstado(bool estado);
    void setNombre(std::string nombre);

    string toCSV();

    void cargar(int id=0);
    void mostrar();
};

#endif // PRODUCTO_H_INCLUDED
