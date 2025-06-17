#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H

#include <string>
using namespace std;

class DetalleCompra {
private:
    int _idDetalle;
    int _idCompra;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;

public:
    DetalleCompra(); // Constructor por defecto
    DetalleCompra(int idDetalle, int idCompra, int idProducto, int cantidad, float precioUnitario);

    // Getters
    int getIdDetalle();
    int getIdCompra();
    int getIdProducto();
    int getCantidad();
    float getPrecio();

    // Setters
    void setIdDetalle(int idDetalle);
    void setIdCompra(int idCompra);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
};

#endif // DETALLECOMPRA_H
