#include <iostream>
#include "Producto.h"
#include "Categoria.h"
#include "ArchivoCategoria.h"
#include "ArchivoProducto.h"
#include "ProductoManager.h"
#include "ProveedorProductoManager.h"
#include "ProveedorManager.h"
#include <string>

using namespace std;

/// PRODUCTO
/*void ProductoManager :: activarProducto(){
    Producto producto;
    ArchivoProducto pArchivo;
    cout << "PRODUCTOS ELIMINADOS" << endl;

    cout << "INGRESAR EL ID DEL PRODUCTO PARA ACTIVAR" << endl;

}
*/
int ProductoManager :: cargarNuevoProducto()
{
    ProveedorProductoManager relacionManager;
    ProveedorManager proveedorManager;
    Producto producto;
    ArchivoProducto pArchivo;

    int idProducto;
    int idCategoria;
    int stock;
    float precioUnitario;
    std::string nombreProducto;
    std::string cuit;

    cout << "ingrese el cuit del proveedor a vincular con el producto:" << endl;
    cin >> cuit;
    if(proveedorManager.BuscarProveedorPorCuit(cuit)){
        cout << "proveedor encontrado" << endl;

        cout << "ID PRODUCTO : " ;
    int cantidad = pArchivo.getCantidadRegistros();
    idProducto = cantidad + 1;
    cout << idProducto << endl;


    int pos = pArchivo.buscarPorID(idProducto);
    if(pos >= 0) { // Ya existe un producto con ese ID
        cout << "ERROR: Ya existe un producto con ese ID." << endl;
        return -1; // No contin�a el guardado
    }

    cout << "NOMBRE DE PRODUCTO :" ;
    cin.ignore(); // limpiar el buffer si antes usaste cin >>
    getline(cin, nombreProducto);
    cout << "ID CATEGORIA ";
    cin >> idCategoria;
    cout << "STOCK : " ;
    cin >> stock;
    cout << "PRECIO UNITARIO : ";
    cin >> precioUnitario;
    relacionManager.cargarNuevaRelacion(cuit, idProducto);
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
    }else{
        cout << "proveedor no encontrado" << endl;
    }

    return 0;

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


            cout << "INGRESE EL NUEVO NOMBRE: ";
            cin.ignore(); // limpiar el buffer si antes usaste cin >>
            getline(cin, nombreProducto);

            cout << "INGRESE EL NUEVO ID CATEGORIA: ";
            cin >> idCategoria;

            cout << "INGRESE EL NUEVO STOCK: ";
            cin >> stock;

            cout << "INGRESE EL NUEVO PRECIO UNITARIO: ";
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

/// CATEGORIA

int ProductoManager :: agregarCategoria(){

    Categoria categoria;
    ArchivoCategoria pArchivo;

    int idCategoria;
    std::string nombreCategoria;


    cout << "ID CATEGORIA : " ;
    int cantidad = pArchivo.getCantidadRegistros();
    idCategoria = cantidad + 1;
    cout << idCategoria << endl;


    int pos = pArchivo.buscarPorID(idCategoria);
    if(pos >= 0) { // Ya existe una categoria con ese ID
        cout << "ERROR: Ya existe una CATEGORIA con ese ID." << endl;
        return -1; // No continua el guardado
    }

    cout << "NOMBRE DE CATEGORIA :" ;
    cin >> nombreCategoria;

    categoria.setEstado(true);
    categoria.setIDCategoria(idCategoria);
    categoria.setNombreCategoria(nombreCategoria);

    if(pArchivo.guardar(categoria)){
        cout << "SE GUARDO CORRECTAMENTE." << endl;
    }
    else{
        cout << "HUBO UN ERROR AL GUARDAR." << endl;
    }
}

void ProductoManager :: modificarCategoria(){

    ArchivoCategoria pArchivo;
    int idCategoria;
    Categoria categoria;
    int cantidad = pArchivo.getCantidadRegistros();
    bool encontrado = false;

    cout << "INGRESE EL ID DE LA CATEGORIA A MODIFICAR: ";
    cin >> idCategoria;

    for(int i = 0; i < cantidad; i++){
        categoria = pArchivo.leer(i);

        if(categoria.getIdCategoria() == idCategoria){
            encontrado = true;
            cout << "CATEGORIA ENCONTRADA: " << endl;
            cout << categoria.toCSV() << endl;


            int idCategoria;
            string nombreCategoria;

            cout << "INGRESE EL NUEVO NOMBRE: ";
            cin >> nombreCategoria;

            categoria.setNombreCategoria(nombreCategoria);

            if(pArchivo.guardar(categoria, i)){
                cout << "CATEGORIA MODIFICADA CON EXITO." << endl;
            } else {
                cout << "ERROR AL MODIFICAR." << endl;
            }

            break;
        }}}

void ProductoManager :: eliminarCategoria(){

    ArchivoCategoria pArchivo;
    int idCategoria;
    Categoria categoria;
    int cantidad = pArchivo.getCantidadRegistros();
    bool encontrado = false;

    cout << "INGRESE EL ID DE LA CATEGORIA A ELIMINAR: ";
    cin >> idCategoria;

    for(int i = 0; i < cantidad; i++){
        categoria = pArchivo.leer(i);

        if(categoria.getIdCategoria() == idCategoria){
            encontrado = true;
            cout << "CATEGORIA ENCONTRADA: " << endl;
            cout << categoria.toCSV() << endl;

            categoria.setEstado(false);

            if(pArchivo.guardar(categoria, i)){
                cout << "CATEGORIA ELIMINADA CON EXITO." << endl;
            } else {
                cout << "ERROR AL ELIMINAR." << endl;
            }

            break;
        }
    }

    if(!encontrado){
        cout << "NO SE ENCONTRO NINGUNA CATEGORIA CON ESE ID." << endl;
    }
}

void ProductoManager :: listarCategorias(){
    ArchivoCategoria pArchivo;
    Categoria registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0;i<cantidadRegistros;i++){
        registro = pArchivo.leer(i);
        if(registro.getEstado()==true){
            cout << registro.toCSV() << endl;
        }

    }
}
