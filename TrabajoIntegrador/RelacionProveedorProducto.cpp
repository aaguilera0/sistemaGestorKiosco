#include "RelacionProveedorProducto.h"
#include <cstring>
using namespace std;

RelacionProveedorProducto::RelacionProveedorProducto(){
    _idProveedorProducto=0;
    strcpy(_cuitProveedor,"");
    _idProducto = 0;
}
RelacionProveedorProducto::RelacionProveedorProducto(int id, std::string cuitProveedor, int idProducto){
    setIdProveedorProducto(id);
    setCuitProveedor(cuitProveedor);
    setIdProducto(idProducto);
}
int RelacionProveedorProducto::getIdProveedorProducto(){
    return _idProveedorProducto;
}
std::string RelacionProveedorProducto::getCuitProveedor(){
    return _cuitProveedor;
}
int RelacionProveedorProducto::getIdProducto(){
    return _idProducto;
}
void RelacionProveedorProducto::setIdProveedorProducto(int id){
    _idProveedorProducto=id;
}
void RelacionProveedorProducto::setCuitProveedor(std::string cuitProveedor){
    strcpy(_cuitProveedor, cuitProveedor.c_str());
}
void RelacionProveedorProducto::setIdProducto(int idProducto){
    _idProducto = idProducto;
}
std::string RelacionProveedorProducto::toCSV(){
    string str = "";

    str = string(_cuitProveedor)+",";
    str += to_string(_idProducto);

    return str;
}

