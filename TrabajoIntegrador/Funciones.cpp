#include "Funciones.h"
#include "Menu.h"
#include "ProveedorManager.h"
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
            //manager.modificarProveedor();
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
        case 0:
            system("cls");
            cout << "GRACIAS POR USAR EL PROGRAMITA. HASTA LUEGO." << endl;
            return;
        default:
            cout << "TE EQUIVOCASTE GIL. INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}
