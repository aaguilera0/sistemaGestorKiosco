#include <iostream>
#include <cstring>
using namespace std;

#include "Producto.h"

    Producto::Producto() {
        _IDproducto = 0;
        _IDCategoria = 0;
        _stock = 0;
        _precioUnitario = 0.0f;
        _estado = true;
    }
    int Producto :: getIDProducto(){
        return _IDproducto;
    }
    int Producto :: getIDCategoria(){
        return _IDCategoria;
    }
    int Producto :: getStock(){
        return _stock;
    }
    float Producto :: getPrecioUnitario(){
        return _precioUnitario;
    }
    bool Producto :: getEstado(){
        return _estado;
    }
    void Producto :: setIDProducto(int IDProducto){
        _IDproducto = IDProducto;
    }
    void Producto :: setIDCategoria(int IDCategoria){
        _IDCategoria = IDCategoria;
    }
    void Producto :: setStock(int stock){
        _stock = stock;
    }
    void Producto :: setPrecioUnitario(int precioUnitario){
        _precioUnitario = precioUnitario;
    }
    void Producto :: setEstado(bool estado){
        _estado = estado;
    }
    std::string Producto :: toCSV(){
        return std::to_string(_IDCategoria) + " - " + std::to_string(_IDCategoria) + " - " +
        std::to_string(_stock) + " - " + std::to_string(_precioUnitario)+ " - " + std::to_string(_estado);
    }

    void Producto :: cargar(){
        int idProducto;
        int idCategoria;
        int stock;
        int precioUnitario;

        cout << "ID PRODUCTO : " ;
        cin >> idProducto;

        cout << "ID CATEGORIA : ";
        cin >> idCategoria;
        cout << "STOCK : " ;
        cin >> stock;
        cout << "PRECIO UNITARIO : ";
        cin >> precioUnitario;

        _estado = true;
        setIDProducto(idProducto);
        setIDCategoria(idCategoria);
        setStock(stock);
        setPrecioUnitario(precioUnitario);

    }
