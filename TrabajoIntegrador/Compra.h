#ifndef COMPRA_H
#define COMPRA_H

#include "Fecha.h"
#include <cstring>
#include <string>
using namespace std;
class Compra {
private:
    int _idCompra;
    char _cuitProveedor[20];
    float _importe;
    Fecha _fechaCompra;

public:
    Compra(int idCompra, string cuitProveedor, float importe, int dia, int mes, int ani);
    // Getters
    int getIdCompra();
    string getCuitProveedor();
    Fecha getFechaCompra();
    float getImporte();
    // Setters
    void setIdCompra(int id);
    void setCuitProveedor(string cuit);
    void setFechaCompra(int dia, int mes, int anio);
    void setImporte(float importe);
};

#endif
