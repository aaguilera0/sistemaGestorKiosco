#include <iostream>
#include "Producto.h"
#include "ArchivoProducto.h"
#include "ProductoManager.h"
#include <string>

using namespace std;

int ProductoManager :: cargarNuevoProducto()
{
    Producto producto;
    ArchivoProducto pArchivo;

    int idProducto;
    int idCategoria;
    int stock;
    float precioUnitario;
    std::string nombreProducto;


    cout << "ID PRODUCTO : " ;
    int cantidad = pArchivo.getCantidadRegistros();
    idProducto = cantidad + 1;
    cout << idProducto << endl;


    int pos = pArchivo.buscarPorID(idProducto);
    if(pos >= 0) { // Ya existe un producto con ese ID
        cout << "ERROR: Ya existe un producto con ese ID." << endl;
        return -1; // No continúa el guardado
    }

    cout << "NOMBRE DE PRODUCTO :" ;
    cin >> nombreProducto;
    cout << "ID CATEGORIA | 1 - COMIDA | 2 - BEBIDA | 3 - VARIOS ";
    cin >> idCategoria;
    cout << "STOCK : " ;
    cin >> stock;
    cout << "PRECIO UNITARIO : ";
    cin >> precioUnitario;

    producto.setEstado(true);
    producto.setIdProducto(idProducto);
    producto.setIdCategoria(idCategoria);
    producto.setStock(stock);
    producto.setPrecioUnitario(precioUnitario);
    producto.setNombre(nombreProducto);

    if(pArchivo.guardar(producto)){
        cout << "SE GUARDO CORRECTAMENTE." << endl;
    }
    else{
        cout << "HUBO UN ERROR AL GUARDAR." << endl;
    }

}

void ProductoManager::mostrarCantidadRegistros(){
    ArchivoProducto pArchivo;

    int cantidadRegistros = pArchivo.getCantidadRegistros();

    cout << "LA CANTIDAD DE REGISTROS SON: " << cantidadRegistros << endl;
}

void ProductoManager::listarProductos(){
    ArchivoProducto pArchivo;
    Producto registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0;i<cantidadRegistros;i++){
        registro = pArchivo.leer(i);
        if(registro.getEstado()==true){
            cout << registro.toCSV() << endl;
        }

    }
}
void ProductoManager::modificarProducto(){
    ArchivoProducto pArchivo;
    int idProducto;
    Producto producto;
    int cantidad = pArchivo.getCantidadRegistros();
    bool encontrado = false;

    cout << "INGRESE EL ID DEL PRODUCTO A MODIFICAR: ";
    cin >> idProducto;

    for(int i = 0; i < cantidad; i++){
        producto = pArchivo.leer(i);

        if(producto.getIdProducto() == idProducto){
            encontrado = true;
            cout << "PRODUCTO ENCONTRADO: " << endl;
            cout << producto.toCSV() << endl;


            int idCategoria;
            int stock;
            float precioUnitario;
            string nombreProducto;

            cout << "INGRESE ID: ";
            cin >> idProducto;

            cout << "INGRESE EL NOMBRE: ";
            cin >> nombreProducto;

            cout << "INGRESE ID CATEGORIA: ";
            cin >> idCategoria;

            cout << "INGRESE STOCK: ";
            cin >> stock;

            cout << "INGRESE PRECIO UNITARIO: ";
            cin >> precioUnitario;

            producto.setIdProducto(idProducto);
            producto.setIdCategoria(idCategoria);
            producto.setStock(stock);
            producto.setPrecioUnitario(precioUnitario);
            producto.setEstado(true);
            producto.setNombre(nombreProducto);

            if(pArchivo.guardar(producto, i)){
                cout << "PRODUCTO MODIFICADO CON EXITO." << endl;
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
void ProductoManager :: eliminarProducto(){
    ArchivoProducto pArchivo;
    int idProducto;
    Producto producto;
    int cantidad = pArchivo.getCantidadRegistros();
    bool encontrado = false;

    cout << "INGRESE EL ID DEL PRODUCTO A ELIMINAR: ";
    cin >> idProducto;

    for(int i = 0; i < cantidad; i++){
        producto = pArchivo.leer(i);

        if(producto.getIdProducto() == idProducto){
            encontrado = true;
            cout << "PRODUCTO ENCONTRADO: " << endl;
            cout << producto.toCSV() << endl;

            producto.setEstado(false);

            if(pArchivo.guardar(producto, i)){
                cout << "PRODUCTO ELIMINADO CON EXITO." << endl;
            } else {
                cout << "ERROR AL MODIFICAR." << endl;
            }

            break;
        }
    }

    if(!encontrado){
        cout << "NO SE ENCONTRO NINGUN PRODUCTO CON ESE ID." << endl;
    }

}
