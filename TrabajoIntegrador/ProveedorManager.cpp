#include <iostream>
#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include "ProveedorManager.h"
#include <string>

using namespace std;

void ProveedorManager::cargarNuevoProveedor(){
    Proveedor proveedor;
    ProveedorArchivo pArchivo;

    int numTelefono;
    std::string cuit, nombre, apellido, mail, direccion;
    bool estado;

    cin.ignore();

    cout << "INGRESE CUIT: " << endl;
    getline(cin, cuit);

    cout << "INGRESE NOMBRE: " << endl;
    getline(cin, nombre);

    cout << "INGRESE APELLIDO: " << endl;
    getline(cin, apellido);

    cout << "INGRESE NUMERO DE TELEFONO: " << endl;
    cin >> numTelefono;

    cout << "INGRESE MAIL: " << endl;
    cin.ignore();
    getline(cin, mail);

    cout << "INGRESE DIRECCION: " << endl;
    getline(cin, direccion);

    cout << "�SU ESTADO ES ACTIVO? 1- SI 0- NO: " << endl;
    cin >> estado;

    proveedor = Proveedor(cuit, nombre, apellido, numTelefono, mail, direccion, estado);

    if(pArchivo.guardar(proveedor)){
        cout << "SE GUARDO CORRECTAMENTE." << endl;
    }
    else{
        cout << "HUBO UN ERROR AL GUARDAR." << endl;
    }
}
void ProveedorManager::modificarProveedor(){
    ProveedorArchivo pArchivo;
    string cuit;
    Proveedor proveedor;
    int cantidad = pArchivo.getCantidadRegistros();
    bool encontrado = false;

    cin.ignore();
    cout << "INGRESE EL CUIT DEL PROVEEDOR A MODIFICAR: ";
    getline(cin, cuit);

    for(int i = 0; i < cantidad; i++){
        proveedor = pArchivo.leer(i);

        if(proveedor.getCuit() == cuit){
            encontrado = true;
            cout << "PROVEEDOR ENCONTRADO: " << endl;
            cout << proveedor.toCSV() << endl;

            string nuevoNombre, nuevoApellido, nuevoMail, nuevaDireccion;
            int nuevoTelefono;
            bool nuevoEstado;

            cout << "INGRESE NUEVO NOMBRE: ";
            getline(cin, nuevoNombre);

            cout << "INGRESE NUEVO APELLIDO: ";
            getline(cin, nuevoApellido);

            cout << "INGRESE NUEVO TELEFONO: ";
            cin >> nuevoTelefono;
            cin.ignore();

            cout << "INGRESE NUEVO MAIL: ";
            getline(cin, nuevoMail);

            cout << "INGRESE NUEVA DIRECCION: ";
            getline(cin, nuevaDireccion);

            cout << "ESTADO ACTIVO? 1- SI 0- NO: ";
            cin >> nuevoEstado;

            proveedor.setNombre(nuevoNombre);
            proveedor.setApellido(nuevoApellido);
//<<<<<<< HEAD
            proveedor.setNumeroTelefono(nuevoTelefono);
//=======
            proveedor.setNumeroTelefono(nuevoTelefono);
//>>>>>>> 1ebef20bec1b1744a16d72ddb8679f74737cf90c
            proveedor.setMail(nuevoMail);
            proveedor.setDireccion(nuevaDireccion);
            proveedor.setEstado(nuevoEstado);

            if(pArchivo.guardar(proveedor, i)){
                cout << "PROVEEDOR MODIFICADO CON EXITO." << endl;
            } else {
                cout << "ERROR AL MODIFICAR." << endl;
            }

            break;
        }
    }

    if(!encontrado){
        cout << "NO SE ENCONTRO NINGUN PROVEEDOR CON ESE CUIT." << endl;
    }
}
void ProveedorManager::eliminarProveedor(){
    ProveedorArchivo archivo("proveedores.dat");
    int cuit;
    cout << "Ingrese CUIT del proveedor a eliminar: ";
    cin >> cuit;

    Proveedor proveedor;
    if (archivo.Buscar(cuit, proveedor)) {
        // Simulamos eliminacion logica con ID producto -1
        proveedor.setCuit(-1);
        //int pos = archivo.Buscar(id);
        if (archivo.Guardar(proveedor, proveedor.getCuit())) {
            cout << "Proveedor eliminado logicamente." << endl;
        } else {
            cout << "No se pudo eliminar el proveedor." << endl;
        }
    } else {
        cout << "Proveedor no encontrado." << endl;
    }
}
void ProveedorManager::mostrarCantidadRegistros(){
    ProveedorArchivo pArchivo;

    int cantidadRegistros = pArchivo.getCantidadRegistros();

    cout << "LA CANTIDAD DE REGISTROS SON: " << cantidadRegistros << endl;
}
void ProveedorManager::listarProveedores(){
    ProveedorArchivo pArchivo;
    Proveedor registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0;i<cantidadRegistros;i++){
        registro = pArchivo.leer(i);

        cout << registro.toCSV() << endl;
    }
}

