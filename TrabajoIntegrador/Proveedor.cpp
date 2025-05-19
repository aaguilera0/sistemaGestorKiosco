#include "Proveedor.h"
#include <cstring>
using namespace std;

Proveedor::Proveedor(){
    strcpy(_cuit,"");
    strcpy(_nombre,"");
    strcpy(_apellido,"");
    _numTelefono = 0;
    strcpy(_mail,"");
    strcpy(_direccion,"");
    _estado = false;
}
Proveedor::Proveedor(std::string cuit, std::string nombre, std::string apellido, int numTelefono, std::string mail, std::string direccion, bool estado){
    setCuit(cuit);
    setNombre(nombre);
    setApellido(apellido);
    setNumeroTelefono(numTelefono);
    setMail(mail);
    setDireccion(direccion);
    setEstado(estado);
}
std::string Proveedor::getCuit(){
    return _cuit;
}
std::string Proveedor::getNombre(){
    return _nombre;
}
std::string Proveedor::getApellido(){
    return _apellido;
}
int Proveedor::getNumTelefono(){
    return _numTelefono;
}
std::string Proveedor::getMail(){
    return _mail;
}
std::string Proveedor::getDireccion(){
    return _direccion;
}
bool Proveedor::getEstado(){
    return _estado;
}

//TENGO QUE AGREGAR VALIDACIONES EN LOS SETTERS.

void Proveedor::setCuit(std::string cuit){
    _cuit = cuit;
}
void Proveedor::setNombre(std::string nombre){
    strcpy(_nombre,nombre.c_str());
}
void Proveedor::setApellido(std::string apellido){
    strcpy(_apellido,apellido.c_str());
}
void Proveedor::setNumeroTelefono(int numTelefono){
    _numTelefono = numTelefono;
}
void Proveedor::setMail(std::string mail){
    strcpy(_mail,mail.c_str());
}
void Proveedor::setDireccion(std::string direccion){
    strcpy(_direccion,direccion.c_str());
}
void Proveedor::setEstado(bool estado){
    _estado = estado;
}

std::string Proveedor::toCSV(){
    string str = "";

    str = string(_cuit)+",";
    str += string(_nombre)+",";
    str += string(_apellido)+",";
    str += to_string(_numTelefono)+",";
    str += string(_mail)+",";
    str += string(_direccion)+",";
    str += to_string(_estado);

    return str;
}
