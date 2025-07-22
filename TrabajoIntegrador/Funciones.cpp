#include "Funciones.h"
#include "Menu.h"
#include "ProveedorManager.h"
#include "ProveedorProductoManager.h"
#include "ProductoManager.h"
#include "CategoriaManager.h"
#include "CompraManager.h"
#include "ArchivoProducto.h"
#include "ArchivoCompra.h"
#include "ArchivoDetalleCompra.h"
#include <iostream>
#include <limits>
using namespace std;

void menuProveedores(){
    int opc;
    ProveedorManager manager;

    system("cls");

    do
    {
        cout << "--------- MENU PROVEEDORES ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR PROVEEDORES" << endl;
        cout << "2- MODIFICAR PROVEEDORES" << endl;
        cout << "3- DESACTIVAR PROVEEDORES" << endl;
        cout << "4- LISTAR PROVEEDORES" << endl;
        cout << "5- MOSTRAR CANTIDAD DE REGISTROS" << endl;
        cout << "6- VER PRODUCTOS DE UN PROVEEDOR" << endl;
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

        case 1:{
            system("cls");
            manager.cargarNuevoProveedor();
            break;}
        case 2:{
            system("cls");
            manager.modificarProveedor();
            break;}
        case 3:{
            system("cls");
            manager.desactivarProveedor();
            break;}
        case 4:{
            system("cls");
            manager.listarProveedores();
            break;}
        case 5:{
            system("cls");
            manager.mostrarCantidadRegistros();
            break;}
        case 6:{
            system("cls");
            ProveedorProductoManager ProvProdManager;
            string cuit;
            cout << "ingrese el cuit del proveedor" << endl;
            cin >> cuit;
            if(manager.BuscarProveedorPorCuit(cuit)){
                    cout << "PRODUCTOS DEL PROVEEDOR CON CUIT: " << cuit << endl;
                    cout << endl;
                    ProvProdManager.buscarRelacionesPorCuit(cuit);
                    cout << endl;
            }else{
                cout << "proveedor no encontrado" << endl;
            }

            break;}
        case 0:{
            system("cls");
            return;}
        default:{
            cout << "INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;}
        }
}while(true);
}
void menuProducto(){
    int opc;
    ProductoManager manager;

    system("cls");

    do
    {
        cout << "--------- MENU PRODUCTO ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR PRODUCTO" << endl;
        cout << "2- MODIFICAR PRODUCTO" << endl;
        cout << "3- ELIMINAR PRODUCTO" << endl;
        cout << "4- LISTAR PRODUCTOS" << endl;
        cout << "5- MOSTRAR CANTIDAD DE REGISTROS" << endl;
        cout << "6- GESTION DE CATEGORIAS DE PRODUCTOS" << endl;
        cout << "7- ACTIVAR PRODUCTO" << endl;
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
        case 7:
            system("cls");
            manager.activarProducto();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "INTENTA NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}
void menuCategoria(){
    int opc;
    CategoriaManager manager;

    system("cls");

    do
    {
        cout << "--------- MENU CATEGORIA ---------" << endl;
        cout << endl;
        cout << "1- AGREGAR CATEGORIA" << endl;
        cout << "2- MODIFICAR CATEGORIA" << endl;
        cout << "3- ELIMINAR CATEGORIA" << endl;
        cout << "4- LISTAR CATEGORIAS" << endl;
        cout << "5- ACTIVAR CATEGORIA" << endl;
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
        case 5:
            system("cls");
            manager.activarCategoria();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "INTENTE NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}
void menuSistemaEInformes(){
    int opc;

    system("cls");

    do
    {
        cout << "--------- MENU DE SISTEMA E INFORMES ---------" << endl;
        cout << endl;
        cout << "1- INFORMACION DEL SISTEMA" << endl;
        cout << "2- INFORMES" << endl;
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
            menuSistema();
            break;
        case 2:
            system("cls");
            menuInformes();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "INTENTE NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);

}

void menuSistema(){
    int opc, cantidad;
    ProductoManager managerPROD;
    ProveedorManager managerPROV;
    CompraManager managerCOMP;

    ArchivoProducto archivoP;
    Producto producto;

    system("cls");

    do
    {
        cout << "--------- MENU SISTEMA ---------" << endl;
        cout << endl;
        cout << "1- VERSION DEL SOFTWARE" << endl;
        cout << "2- CANTIDAD TOTAL DE REGISTROS EN ARCHIVOS" << endl;
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
            cout << "VERSION DEL SOFTWARE: V 0.2.9" << endl;
            cout << endl << endl;
            cout << "ULTIMA ACTUALIZACION: 16/07/2025" << endl;
            break;
        case 2:
            system("cls");
            cout << "------ TOTAL DE REGISTROS ------" << endl;
            cout << endl << endl;
            cout << "--PRODUCTOS--" << endl;
            managerPROD.mostrarCantidadRegistros();
            cout << endl;
            cout << "--PROVEEDORES--" << endl;
            managerPROV.mostrarCantidadRegistros();
            cout << endl;
            cout << "--CANTIDAD DE COMPRAS--" << endl;
            managerCOMP.mostrarCantidadRegistros();
            cout << endl << endl;
            cout << "--STOCK DE ARTICULOS--" << endl;

            cantidad = archivoP.CantidadRegistros();

            for(int i = 0; i < cantidad; i++){
            producto = archivoP.leer(i);

            if(producto.getEstado()){
                cout << producto.getNombre() << " - Stock: " << producto.getStock() << endl;
            }
        }
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "INTENTE NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}

void menuInformes(){
    int opc;

    system("cls");

    do
    {
        cout << "--------- MENU INFORMES ---------" << endl;
        cout << endl;
        cout << "1- PROVEEDORES MAS FRECUENTES" << endl;
        cout << "2- PRODUCTOS MAS COMPRADOS" << endl;
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
            informeProveedoresFrecuentes();
            break;
        case 2:
            system("cls");
            informeProductosMasComprados();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "INTENTE NUEVAMENTE, POR FAVOR." << endl;
            return;
        }
}while(true);
}

void informeProveedoresFrecuentes(){
    ArchivoCompra archivoC("compras.dat");
    Compra compra;

    const int PROV = 50;
    int total = 0, cantidad = archivoC.CantidadRegistros();
    int contador[PROV]={};
    string cuitProveedor[PROV]={};

    if (archivoC.CantidadRegistros() == 0) {
        cout << "No hay compras registradas." << endl;
        return;
    }

    for(int i=0;i<cantidad;i++){
        bool existe = false;
        compra = archivoC.Leer(i);
        string cuit = compra.getCuitProveedor();

        for(int z=0;z<total;z++){
            if(cuitProveedor[z] == cuit){
                contador[z]++;
                existe = true;
                break;
            }
        }

        if(!existe && total < PROV){
            cuitProveedor[total] = cuit;
            contador[total] = 1;
            total++;
        }
    }

    cout << " ---  PROVEEDORES MAS FRECUENTES  --- " << endl;
    cout << endl << endl;
    for(int i = 0; i < total; i++){
        cout << "CUIT: " << cuitProveedor[i] << " - COMPRAS: " << contador[i] << endl;
    }
}

void informeProductosMasComprados() {
    archivoDetalleCompra archivoDetalle("detallecompras.dat");
    DetalleCompra detalle;

    const int PROD = 100;
    int total = 0, cantidad = archivoDetalle.CantidadRegistros();
    int idProducto[PROD]={};
    int cantidadComprada[PROD]={};

    if (archivoDetalle.CantidadRegistros() == 0) {
    cout << "No hay compras registradas." << endl;
    return;
    }

    for (int i=0;i<cantidad;i++) {
        bool existe = false;
        detalle = archivoDetalle.Leer(i);
        int idProd = detalle.getIdProducto();

        for (int z=0;z<total;z++) {
            if (idProducto[z]==idProd) {
                cantidadComprada[z]+= detalle.getCantidad();
                existe = true;
                break;
            }
        }

        if (!existe && total < PROD) {
            idProducto[total] = idProd;
            cantidadComprada[total] = detalle.getCantidad();
            total++;
        }
    }

    cout << " ---  PRODUCTOS MAS COMPRADOS A PROVEEDORES  --- " << endl;
    cout << endl << endl;
    for (int i = 0; i < total; i++) {
        cout << "ID PRODUCTO: " << idProducto[i] << " - CANTIDAD TOTAL COMPRADA: " << cantidadComprada[i] << endl;
    }
}
