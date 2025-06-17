#include "Funciones.h"
#include "Menu.h"
#include "ProductoManager.h"
#include "ProveedorManager.h"
#include "CompraManager.h"
#include <iostream>
#include <limits>
using namespace std;

void menuProductos(){
    int opc;
    ProductoManager manager;

    system("cls");

    do{
        cout << "====================================" << endl;
        cout << "          MAXIKIOSCO LAMINE         " << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << "--------- MENU PRODUCTOS ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR PRODUCTO" << endl;
        cout << "2- MODIFICAR PRODUCTO" << endl;
        cout << "3- ELIMINAR PRODUCTO" << endl;
        cout << "4- LISTAR PRODUCTOS" << endl;
        cout << "5- MOSTRAR CANTIDAD DE REGISTROS" << endl;
        cout << "0- VOLVER" << endl;
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
            //manager.cargarNuevoProducto();
            break;
        case 2:
            system("cls");
            //manager.modificarProducto();
            break;
        case 3:
            system("cls");
            //manager.eliminarProducto();
            break;
        case 4:
            system("cls");
            //manager.listarProductos();
            break;
        case 5:
            system("cls");
            //manager.mostrarCantidadRegistros();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "TE EQUIVOCASTE. INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
    }while(true);
}

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
        cout << "0- VOLVER" << endl;
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
            manager.eliminarProveedor();
            break;
        case 4:
            system("cls");
           manager.listarProveedores();
            break;
        case 5:
            system("cls");

            manager.mostrarCantidadRegistros();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "TE EQUIVOCASTE. INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}

void menuCompras(){
    int opc;
    CompraManager manager;

    system("cls");

    do
    {
        cout << "====================================" << endl;
        cout << "          MAXIKIOSCO LAMINE         " << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << "--------- MENU COMPRAS ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR COMPRA" << endl;
        cout << "2- MODIFICAR COMPRA" << endl;
        cout << "3- ELIMINAR COMPRA" << endl;
        cout << "4- LISTAR COMPRAS" << endl;
        cout << "5- MOSTRAR CANTIDAD DE REGISTROS" << endl;
        cout << "0- VOLVER" << endl;
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
            manager.cargarNuevaCompra();
            break;
        case 2:
            system("cls");
            manager.modificarCompra();
            break;
        case 3:
            system("cls");
            manager.eliminarCompra();
            break;
        case 4:
            system("cls");
            manager.listarCompras();
            break;
        case 5:
            system("cls");
            manager.mostrarCantidadRegistros();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "TE EQUIVOCASTE. INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}
