#include "DetalleCompra.h"
DetalleCompra::DetalleCompra(int idDetalle=0, int IdCompra=0, int IdProducto=0, int cantidad=0, float precioUnitario=0){
setIdDetalle(idDetalle);
setIdCompra(IdCompra);
setIdProducto(IdProducto);
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

float DetalleCompra::getPrecioUnitario() {
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

void DetalleCompra::setPrecioUnitario(float precio) {
    _precioUnitario = precio;
}
