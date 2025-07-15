#include <iostream>
#include <cstring>
using namespace std;

#include "Producto.h"

    Producto::Producto() {
        _idProducto = 0;
        _idCategoria = 0;
        _stock = 0;
        _precioUnitario = 0.0f;
        _estado = true;
    }
    Producto::Producto(int idProducto, int idCategoria, int stock, float precioUnitario, bool estado, std::string nombre){
        setIdProducto(idProducto);
        setIdCategoria(idCategoria);
        setStock(stock);
        setPrecioUnitario(precioUnitario);
        setEstado(estado);
        setNombre(nombre);
    }
    int Producto :: getIdProducto(){
        return _idProducto;
    }
    int Producto :: getIdCategoria(){
        return _idCategoria;
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
    string Producto::getNombre(){
        return string(_nombre);
    }
    void Producto :: setIdProducto(int idProducto){
        _idProducto = idProducto;
    }
    void Producto :: setIdCategoria(int idCategoria){
        _idCategoria = idCategoria;
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
    void Producto::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}
    std::string Producto :: toCSV(){
        return "ID PRODUCTO : " + std::to_string(_idProducto) + " || " + "NOMBRE PRODUCTO : " + std::string(_nombre) + " || " +
         "ID CATEGORIA : " + std::to_string(_idCategoria) + " || " +
        "STOCK : " + std::to_string(_stock) + " || " + "PRECIO : " + std::to_string(_precioUnitario);
    }

    void Producto :: cargar(int id){
        int idProducto;
        int idCategoria;
        int stock;
        float precioUnitario;

        if(id ==0){
            cout << "ID PRODUCTO : ";
            cin >> idProducto;
        }else{
            _idProducto = id;
        }
        cout << "ID PRODUCTO : " ;
        cin >> idProducto;
        cout << "ID CATEGORIA : ";
        cin >> idCategoria;
        cout << "STOCK : " ;
        cin >> stock;
        cout << "PRECIO UNITARIO : ";
        cin >> precioUnitario;

        _estado = true;
        setIdProducto(idProducto);
        setIdCategoria(idCategoria);
        setStock(stock);
        setPrecioUnitario(precioUnitario);
    }
    void Producto :: mostrar(){
        cout << "ID PRODUCTO : " << _idProducto << endl;
        cout << "ID CATEGORIA : " << _idCategoria << endl;
        cout << "STOCK : " << _stock << endl;
        cout << "PRECIO UNITARIO : " << _precioUnitario << endl;
    }
