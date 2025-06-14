#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H

class DetalleCompra {
private:
    int _idDetalle;
    int _idCompra;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;

public:
    DetalleCompra(int idDetalle=0, int IdCompra=0, int IdProducto=0, int cantidad=0, float precioUnitario=0);
    // Getters
    int getIdDetalle();
    int getIdCompra();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    // Setters
    void setIdDetalle(int idDetalle);
    void setIdCompra(int idCompra);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precio);
};

#endif
