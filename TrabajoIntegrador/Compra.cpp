#include "Compra.h"
Compra::Compra(int idCompra, string cuitProveedor, float importe, int dia, int mes, int anio){
setIdCompra(idCompra);
setCuitProveedor(cuitProveedor);
setImporte(importe);
setFechaCompra(dia,mes,anio);
}
Compra::Compra(){

}
// Getters
int Compra::getIdCompra() {
    return _idCompra;
}

string Compra::getCuitProveedor() {
    return string(_cuitProveedor);
}

Fecha Compra::getFechaCompra() {
    return _fechaCompra;
}

float Compra::getImporte() {
    return _importe;
}

// Setters
void Compra::setIdCompra(int id) {
    _idCompra = id;
}

void Compra::setCuitProveedor(string cuit) {
    strncpy(_cuitProveedor, cuit.c_str(), sizeof(_cuitProveedor) - 1);
}

void Compra::setFechaCompra(int dia, int mes, int anio) {
    _fechaCompra=Fecha(dia, mes, anio);
}

void Compra::setImporte(float importe) {
    _importe = importe;
}

