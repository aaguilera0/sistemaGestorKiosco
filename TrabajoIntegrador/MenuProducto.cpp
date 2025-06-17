#include <iostream>
#include <cctype>
#include "MenuProducto.h"
#include "Menu.h"
#include "Producto.h"
#include "ArchivoProducto.h"
#include <limits>
using namespace std;

void MenuProducto::mostrarMenuProducto()
{
    int opc;
    ArchivoProducto arch("productos.dat");

    system("cls");

    do
    {
        cout << "===================================" << endl;
        cout << "          MAXIKIOSCO LAMINE        " << endl;
        cout << "===================================" << endl;
        cout << "1- AGREGAR" << endl;
        cout << "2- MODIFICAR" << endl;
        cout << "3- ELIMINAR" << endl;
        cout << "4- VER TODOS LOS PRODUCTOS" << endl;
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
            if(altaProducto()== true){cout << "REGISTRO AGREGADO"<<endl;}
            else{cout << "NO SE PUDO AGREGAR EL REGISTRO"<<endl;};
            break;
        case 2:
            system("cls");
            modificarProducto();
            break;
        case 3:
            system("cls");
            if(bajaLogica()==true){
                cout << "REGISTRO BORRADO" << endl;
            }else{
                cout << "NO SE PUDO BORRAR" << endl;
            }
            break;
        case 4:
            system("cls");
            if(arch.listarRegistros()==false){
                cout << "NO SE PUDO ABRIR EL ARCHIVO";
            }
            cout << endl;
            break;
        case 0:
            system("cls");
            cout << "GRACIAS POR USAR EL PROGRAMITA. HASTA LUEGO." << endl;
            return;
        default:
            cout << "TE EQUIVOCASTE GIL. INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
    }
    while(true);
}

bool MenuProducto :: altaProducto(){

    Producto prod;
    ArchivoProducto archivo("productos.dat");
    int idProducto;
    cout << "INGRESAR ID DEL PRODUCTO : " ;
    cin >> idProducto;

    int encontro = archivo.Buscar(idProducto);
    if(encontro >= 0){
        cout << "ESTE PRODUCTO YA ESTA INGRESADO."<<endl;
        return false;
    }
    prod.cargar();

    if(archivo.agregarRegistro(prod)==1)return true;
    return false;

}

bool MenuProducto :: bajaLogica(){
    Producto prod;
    ArchivoProducto archivo("productos.dat");
    int idProducto;
    cout << "INGRESAR ID DEL PRODUCTO : " ;
    cin >> idProducto;

    int encontro = archivo.Buscar(idProducto);
    if(encontro < 0){
        cout << "ESTE PRODUCTO NO EXISTE."<<endl;
        return false;
    }
    prod = archivo.leerRegistro(encontro);
    prod.setEstado(false);
    if(archivo.modificarRegistro(prod,encontro)==1)return true;
    return false;

}
bool MenuProducto :: modificarProducto(){
    Producto prod;
    ArchivoProducto archivo("productos.dat");
    int idProducto;

    cout << "Ingresar ID : " << endl;
    cin >> idProducto;

    int encontro = archivo.Buscar(idProducto);
    if(encontro < 0){
        cout << "ESTE PRODUCTO NO EXISTE."<<endl;
        return false;
    }
    prod = archivo.leerRegistro(encontro);

    cout << "Ingrese los nuevos datos..." << endl;
    prod.cargar();

    if(archivo.modificarRegistro(prod,encontro)==true){
        cout << "El archivo se modifico con exito!" << endl;
        return true;
    }else{
        cout << "Error al modificar el archivo " << endl;
        return false;
    }


}
