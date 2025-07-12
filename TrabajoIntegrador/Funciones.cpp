#include "Funciones.h"
#include "Menu.h"
#include "ProveedorManager.h"
#include "ProductoManager.h"
#include <iostream>
#include <limits>
using namespace std;

void menuProveedores(){
    int opc;
    ProveedorManager manager;

    system("cls");

    do
    {
        cout << "====================================" << endl;
        cout << "          MAXIKIOSCO LAMINE         " << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << "--------- MENU PROVEEDORES ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR PROVEEDORES" << endl;
        cout << "2- MODIFICAR PROVEEDORES" << endl;
        cout << "3- ELIMINAR PROVEEDORES" << endl;
        cout << "4- LISTAR PROVEEDORES" << endl;
        cout << "5- MOSTRAR CANTIDAD DE REGISTROS" << endl;
        cout << "6- SELECCIONAR UN PROVEEDOR" << endl;
        cout << "0- SALIR" << endl;
        cin >> opc;
        if (cin.fail())
        {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inv lida
            cout << "Error: Solo se permiten n£meros.\n";
            continue;
        }

        switch(opc)
        {

        case 1:
            system("cls");
            manager.cargarNuevoProveedor();
            break;
        case 2:
            system("cls");
            manager.modificarProveedor();
            break;
        case 3:
            system("cls");
            //manager.eliminarProveedor();
            break;
        case 4:
            system("cls");
            manager.listarProveedores();
            break;
        case 5:
            system("cls");
            manager.mostrarCantidadRegistros();
            break;
        case 6:
            system("cls");
            //buscamos el proveedor
            string cuit;
            cout << "ingrese el cuit del proveedor" << endl;
            cin >> cuit;
            if(manager.BuscarProveedorPorCuit(cuit)){

            }else{
                cout << "proveedor no encontrado" << endl;
            }

            break;
        case 0:
            system("cls");
            cout << "GRACIAS POR USAR EL PROGRAMITA. HASTA LUEGO." << endl;
            return;
        default:
            cout << "INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}
void menuProducto(){
    int opc;
    ProductoManager manager;

    system("cls");

    do
    {
        cout << "====================================" << endl;
        cout << "          MAXIKIOSCO LAMINE         " << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << "--------- MENU PRODUCTO ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR PRODUCTO" << endl;
        cout << "2- MODIFICAR PRODUCTO" << endl;
        cout << "3- ELIMINAR PRODUCTO" << endl;
        cout << "4- LISTAR PRODUCTOS" << endl;
        cout << "5- MOSTRAR CANTIDAD DE REGISTROS" << endl;
        cout << "6- GESTION DE CATEGORIAS DE PRODUCTOS" << endl;
        cout << "0- SALIR" << endl;
        cin >> opc;
        if (cin.fail())
        {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inv lida
            cout << "Error: Solo se permiten numeros.\n";
            continue;
        }

        switch(opc)
        {

        case 1:
            system("cls");
           manager.cargarNuevoProducto();
            break;
        case 2:
            system("cls");
           manager.modificarProducto();
            break;
        case 3:
            system("cls");
            manager.eliminarProducto();
            break;
        case 4:
            system("cls");
            manager.listarProductos();
            break;
        case 5:
            system("cls");
            manager.mostrarCantidadRegistros();
            break;
        case 6:
            system("cls");
            menuCategoria();
            break;
        case 0:
            system("cls");
            cout << "GRACIAS POR USAR EL PROGRAMITA. HASTA LUEGO." << endl;
            return;
        default:
            cout << "INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}
void menuCategoria(){
    int opc;
    ProductoManager manager;

    system("cls");

    do
    {
        cout << "====================================" << endl;
        cout << "          MAXIKIOSCO LAMINE         " << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << "--------- MENU CATEGORIA ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR CATEGORIA" << endl;
        cout << "2- MODIFICAR CATEGORIA" << endl;
        cout << "3- ELIMINAR CATEGORIA" << endl;
        cout << "4- LISTAR CATEGORIAS" << endl;
        cout << "0- SALIR" << endl;
        cin >> opc;
        if (cin.fail())
        {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inv lida
            cout << "Error: Solo se permiten numeros.\n";
            continue;
        }

        switch(opc)
        {

        case 1:
            system("cls");
            manager.agregarCategoria();
            break;
        case 2:
            system("cls");
            manager.modificarCategoria();
            break;
        case 3:
            system("cls");
            manager.eliminarCategoria();
            break;
        case 4:
            system("cls");
            manager.listarCategorias();
            break;
        case 0:
            system("cls");
            cout << "GRACIAS POR USAR EL PROGRAMITA. HASTA LUEGO." << endl;
            return;
        default:
            cout << "INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}
