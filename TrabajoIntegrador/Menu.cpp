#include <iostream>
#include <cctype>
#include "Menu.h"
//Updated upstream
#include "Funciones.h"

#include "MenuProducto.h"
// Stashed changes
#include <limits>
using namespace std;

void Menu::mostrarMenuPrincipal()
{
    int opc;

    system("cls");

    do
    {
        cout << "===================================" << endl;
        cout << "          MAXIKIOSCO LAMINE        " << endl;
        cout << "===================================" << endl;
        cout << "1- PRODUCTOS" << endl;
        cout << "2- PROVEEDORES" << endl;
        cout << "3- COMPRAS" << endl;
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
// Updated upstream
            menuProductos();

            MenuProducto menu;
            menu.mostrarMenuProducto();
//Stashed changes
            break;
        case 2:
            system("cls");
            menuProveedores();
            break;
        case 3:
            system("cls");
            menuCompras();
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
