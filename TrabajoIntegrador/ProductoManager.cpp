#include <iostream>
#include "Producto.h"
#include "Categoria.h"
#include "ArchivoCategoria.h"
#include "ArchivoProducto.h"
#include "ProductoManager.h"
#include "ProveedorProductoManager.h"
#include "ProveedorManager.h"
#include "CategoriaManager.h"
#include <string>


using namespace std;

void ProductoManager :: activarProducto()
{
    Producto registro;
    ArchivoProducto pArchivo;
    int cantidadRegistros = pArchivo.CantidadRegistros();
    int idProducto;
    bool encontrado = false;

    cout << "PRODUCTOS ELIMINADOS ||" << endl;

    for(int i=0; i<cantidadRegistros; i++)
    {
        registro = pArchivo.leer(i);
        if(registro.getEstado()==false)
        {
            cout << registro.toCSV() << endl;
        }
    }
    cout << "INGRESAR EL ID DEL PRODUCTO PARA ACTIVAR" << endl;
    cin >> idProducto;


    for(int i =0; i < cantidadRegistros; i++)
    {
        registro = pArchivo.leer(i);
        if(registro.getIdProducto()== idProducto)
        {
            encontrado = true;

            cout << "PRODUCTO ENCONTRADO!" << endl;
            cout << registro.toCSV() << endl;

            registro.setEstado(true);

            if(pArchivo.guardar(registro,i))
            {
                cout << "PRODUCTO ACTIVADO!" << endl;
            }
            else
            {
                cout << "NO SE PUDO ACTIVAR EL PRODUCTO CON EXITO!" << endl;
            }
            break;
        }

    }
    if(!encontrado)
    {
        cout << "NO SE ENCONTRO NINGUN PRODUCTO CON ESE ID." << endl;
    }

}

int ProductoManager :: cargarNuevoProducto()
{
    CategoriaManager catManager;
    ProveedorProductoManager relacionManager;
    ProveedorManager proveedorManager;
    Producto producto;
    ArchivoProducto pArchivo;
    Categoria categoria;

    int idProducto;
    int idCategoria;
    int stock;
    float precioUnitario;
    std::string nombreProducto;
    std::string cuit;

    cout << "ingrese el cuit del proveedor a vincular con el producto:" << endl;
    cin >> cuit;
    if(proveedorManager.BuscarProveedorPorCuit(cuit)){
        idProducto = pArchivo.ObtenerUltimoId() + 1;
        cout << "ID PRODUCTO : " ;
        cout << idProducto << endl;

        cout << "NOMBRE DE PRODUCTO :" ;
        cin.ignore();
        getline(cin, nombreProducto);
        cout << endl;

        catManager.listarCategorias();
        cout << endl;
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

        if(pArchivo.guardar(producto))
        {
            cout << "SE GUARDO CORRECTAMENTE." << endl;
        }
        else
        {
            cout << "HUBO UN ERROR AL GUARDAR." << endl;
        }
    }else{
        cout << "proveedor no encontrado" << endl;
    }

    return 0;

}

void ProductoManager::mostrarCantidadRegistros()
{
    ArchivoProducto pArchivo;

    int cantidadRegistros = pArchivo.CantidadRegistros();

    cout << "LA CANTIDAD DE REGISTROS SON: " << cantidadRegistros << endl;
}

void ProductoManager::listarProductos()
{
    ArchivoProducto pArchivo;
    Producto registro;
    int cantidadRegistros = pArchivo.CantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        registro = pArchivo.leer(i);
        if(registro.getEstado()==true)
        {
            cout << registro.toCSV() << endl;
        }

    }
}
void ProductoManager::modificarProducto()
{
    ArchivoProducto pArchivo;
    int idProducto;
    Producto producto;
    Categoria categoria;
    CategoriaManager catManager;
    bool encontrado = false;

    cout << "INGRESE EL ID DEL PRODUCTO A MODIFICAR: ";
    cin >> idProducto;

    for(int i = 0; i < pArchivo.CantidadRegistros(); i++)
    {
        producto = pArchivo.leer(i);

        if(producto.getIdProducto() == idProducto)
        {
            encontrado = true;
            cout << "PRODUCTO ENCONTRADO: " << endl;
            cout << producto.toCSV() << endl;


            int idCategoria;
            int stock;
            float precioUnitario;
            string nombreProducto;


            cout << "INGRESE EL NUEVO NOMBRE: ";
            cin.ignore();
            getline(cin, nombreProducto);
            cout << endl;

            cout << "CATEGORIAS ||" << endl;
            catManager.listarCategorias();
            cout << endl;

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

            if(pArchivo.guardar(producto, i))
            {
                cout << "PRODUCTO MODIFICADO CON EXITO." << endl;
            }
            else
            {
                cout << "ERROR AL MODIFICAR." << endl;
            }

            break;
        }
    }

    if(!encontrado)
    {
        cout << "NO SE ENCONTRO NINGUN PROVEEDOR CON ESE CUIT." << endl;
    }
}
void ProductoManager :: eliminarProducto()
{
    ArchivoProducto pArchivo;
    int idProducto;
    Producto producto;
    bool encontrado = false;

    cout << "INGRESE EL ID DEL PRODUCTO A ELIMINAR: ";
    cin >> idProducto;

    for(int i = 0; i <  pArchivo.CantidadRegistros(); i++)
    {
        producto = pArchivo.leer(i);

        if(producto.getIdProducto() == idProducto)
        {
            encontrado = true;
            cout << "PRODUCTO ENCONTRADO: " << endl;
            cout << producto.toCSV() << endl;

            producto.setEstado(false);

            if(pArchivo.guardar(producto, i))
            {
                cout << "PRODUCTO ELIMINADO CON EXITO." << endl;
            }
            else
            {
                cout << "ERROR AL MODIFICAR." << endl;
            }

            break;
        }
    }

    if(!encontrado)
    {
        cout << "NO SE ENCONTRO NINGUN PRODUCTO CON ESE ID." << endl;
    }

}
bool ProductoManager::BuscarProductoPorId(int IdProducto, Producto& productoEncontrado){
    ArchivoProducto pArchivo;
    Producto registro;
    if(pArchivo.buscarPorID(IdProducto, registro)){
        productoEncontrado=registro;
        return true;
    }else{
        return false;
    }

}
float ProductoManager::obtenerPrecio(int idProducto){
    ArchivoProducto pArchivo;
    Producto registro;
    if(pArchivo.buscarPorID(idProducto, registro)){
        return registro.getPrecioUnitario();
    }else{
        return 0;
    }
}
