#include <iostream>
#include <cctype>
#include "Menu.h"
#include "Funciones.h"
#include "CompraManager.h"
#include <limits>
using namespace std;
CompraManager compraManager;
void Menu::mostrarMenuPrincipal()
{
    int opcion;

    do {
        cout << "===============================" << endl;
        cout << "     SISTEMA DE COMPRAS        " << endl;
        cout << "===============================" << endl;
        cout << "[1] Registrar nueva compra" << endl;
        cout << "[2] Ver compras realizadas" << endl;
        cout << "[3] Gestion de proveedores y sus productos" << endl;
        cout << "[4] Gestion de productos y categorias" << endl;
        cout << "[5] Configuraciones e informes" << endl;
        cout << "[0] Salir" << endl;
        cout << "-------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls"); // o "clear" en Linux/Mac

        switch (opcion) {
            case 1:
                // registrarNuevaCompra();
                cout << "Registrar nueva compra..." << endl;
                compraManager.cargarNuevaCompra();
                break;
            case 2:
                // verComprasRealizadas();

                cout << "Ver compras realizadas..." << endl;
                compraManager.listarCompras();
                break;
            case 3:
                // gestionProveedores();
                cout << "Gestion de proveedores y sus productos..." << endl;
                break;
            case 4:
                menuProducto();
                cout << "Gestion de productos y categorias..." << endl;
                break;
            case 5:
                // configuracionesEInformes();
                cout << "Configuraciones e informes..." << endl;
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }

        if (opcion != 0) {
            cout << "\nPresione una tecla para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (opcion != 0);
}

