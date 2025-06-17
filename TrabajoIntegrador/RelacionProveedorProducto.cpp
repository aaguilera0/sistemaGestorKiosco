#include "RelacionProveedorProducto.h"
#include <cstring>
using namespace std;

RelacionProveedorProducto::RelacionProveedorProducto(){
    strcpy(_cuitProveedor,"");
    _idProducto = 0;
}
RelacionProveedorProducto::RelacionProveedorProducto(std::string cuitProveedor, int idProducto){
    setCuitProveedor(cuitProveedor);
    setIdProducto(idProducto);
}
std::string RelacionProveedorProducto::getCuitProveedor(){
    return _cuitProveedor;
}
int RelacionProveedorProducto::getIdProducto(){
    return _idProducto;
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

