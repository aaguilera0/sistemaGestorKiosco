#include <iostream>
#include <cctype>
#include "Menu.h"
#include "Funciones.h"
#include "Fecha.h"
#include "CompraManager.h"
#include "DetalleCompraManager.h"
#include <limits>
#include <cstdlib>
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
        cout << "[5] Sistema e informes" << endl;
        cout << "[0] Salir" << endl;
        cout << "-------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1:{
                cout << "Registrar nueva compra..." << endl;
                compraManager.cargarNuevaCompra();
                break;}
            case 2:{
                int opcion=0, opcion2=0;
                cout << "Listado de compras" << endl;
                cout << "1-listar todas las compras" << endl;
                cout << "2-listar todas las compras de hoy" << endl;
                cout << "3-listar de una fecha en especifico" << endl;
                cout << "0-Salir" << endl;
                cin >> opcion;
                while(opcion!=0){
                    if(opcion==1){
                        system("cls");
                        cout << "----------------------------------------------" << endl;
                        DetalleCompraManager detalleManager;
                        compraManager.listarCompras();
                        cout << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "desea ver un detalle en especifico?1-si.0-no." << endl;
                        cin >> opcion2;
                        if(opcion2==1){
                            detalleManager.listarDetallesDeCompra();
                            cout << "presione enter para continuar" << endl;
                            cin.ignore();
                            cin.get();
                            system("cls");
                        }
                    }
                    else if(opcion==2){
                        system("cls");
                        DetalleCompraManager detalleManager;
                        Fecha fecha;
                        fecha.FechaActual();
                        if(compraManager.listarComprasPorFecha(fecha.toString())){
                            cout << "desea ver un detalle en especifico?1-si.0-no." << endl;
                            cin >> opcion2;
                            if(opcion2==1){
                                detalleManager.listarDetallesDeCompra();
                                cout << "presione enter para continuar" << endl;
                                cin.ignore();
                                cin.get();
                                system("cls");}
                        }else{
                            cout << "no se encontraron compras en la fecha ingresada" << endl;
                        }
                    }
                    else if(opcion==3){
                            system("cls");
                            DetalleCompraManager detalleManager;
                            cout << "ingrese la fecha a buscar(D/M/A)" << endl;
                            string fecha;
                            cin >> fecha;
                            if(compraManager.listarComprasPorFecha(fecha)){
                                cout << "desea ver un detalle en especifico?1-si.0-no." << endl;
                                cin >> opcion2;
                                if(opcion2==1){
                                    detalleManager.listarDetallesDeCompra();
                                    cout << "presione enter para continuar" << endl;
                                    cin.ignore();
                                    cin.get();
                                    system("cls");}
                            }
                            else{
                                cout << "no se encontraron compras en la fecha ingresada" << endl;
                                cout << "presione enter para continuar" << endl;
                                cin.ignore();
                                cin.get();
                                system("cls");
                            }
                    }
                    else if(opcion==0){
                            break;
                    }else{
                            cout << "opcion no disponible" << endl;
                        }
                    cout << "Listado de compras" << endl;
                    cout << "1-listar todas las compras" << endl;
                    cout << "2-listar todas las compras de hoy" << endl;
                    cout << "3-listar de una fecha en especifico" << endl;
                    cout << "0-Salir" << endl;
                    cin >> opcion;
                    system("cls");
                }

                break;}
            case 3:{
                menuProveedores();
                cout << "Gestion de proveedores y sus productos..." << endl;
                break;}
            case 4:{
                menuProducto();
                cout << "Gestion de productos y categorias..." << endl;

                break;}
            case 5:{
                menuSistemaEInformes();
                cout << "Sistema e informes..." << endl;
                break;}
            case 0:{
                cout << "Saliendo del sistema..." << endl;
                break;}
            default:{
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;}
        }

        if (opcion != 0) {
            cout << "\nPresione una tecla para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (opcion != 0);
}

