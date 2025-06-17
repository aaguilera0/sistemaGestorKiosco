#include "DetalleCompra.h"

// Constructor por defecto
DetalleCompra::DetalleCompra() {
    _idDetalle = 0;
    _idCompra = 0;
    _idProducto = 0;
    _cantidad = 0;
    _precioUnitario = 0.0f;
}

// Constructor con parámetros
DetalleCompra::DetalleCompra(int idDetalle, int idCompra, int idProducto, int cantidad, float precioUnitario){
    setIdDetalle(idDetalle);
    setIdCompra(idCompra);
    setIdProducto(idProducto);
    setCantidad(cantidad);
    setPrecioUnitario(precioUnitario);
}

// Getters
int DetalleCompra::getIdDetalle() {
    return _idDetalle;
}

int DetalleCompra::getIdCompra() {
    return _idCompra;
}

int DetalleCompra::getIdProducto() {
    return _idProducto;
}

int DetalleCompra::getCantidad() {
    return _cantidad;
}

float DetalleCompra::getPrecio() {
    return _precioUnitario;
}

// Setters
void DetalleCompra::setIdDetalle(int idDetalle) {
    _idDetalle = idDetalle;
}

void DetalleCompra::setIdCompra(int idCompra) {
    _idCompra = idCompra;
}

void DetalleCompra::setIdProducto(int idProducto) {
    _idProducto = idProducto;
}

void DetalleCompra::setCantidad(int cantidad) {
    _cantidad = cantidad;
}

void DetalleCompra::setPrecioUnitario(float precioUnitario) {
    _precioUnitario = precioUnitario;
}
