#include <iostream>
#include "CompraManager.h"
#include "ProveedorProductoManager.h"
#include "ProveedorManager.h"
#include "ProductoManager.h"
#include "DetalleCompra.h"
#include "ArchivoDetalleCompra.h"
#include "Compra.h"
#include "ArchivoCompra.h"
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

void CompraManager::cargarNuevaCompra() {
    ArchivoCompra archivo("compras.dat");
    archivoDetalleCompra archDetalle("Detalles.DAT");
    Compra nuevaCompra;
    ProductoManager prodManager;
    ProveedorProductoManager ProvProdManager;
    ProveedorManager proveedorManager;
    DetalleCompra* detallesCompra;
    Fecha fechaActual;
    string cuit;
    int acuPrecio=0;
    int acuStock=0;
    int cantProducto=0;
    int nuevoId = archivo.ObtenerUltimoId() + 1;
    nuevaCompra.setIdCompra(nuevoId);

    cout << "ingrese CUIT del proveedor: ";
    cin >> cuit;
    if(proveedorManager.BuscarProveedorPorCuit(cuit)){
        system("cls");
        nuevaCompra.setCuitProveedor(cuit);
        fechaActual.FechaActual();
        nuevaCompra.setFechaCompra(fechaActual.getDia(), fechaActual.getMes(), fechaActual.getAnio());

        cout << "PRODUCTOS CARGADOS DEL PROVEEDOR CON CUIT: " << cuit << endl;
        cout << endl;
        ProvProdManager.buscarRelacionesPorCuit(cuit);
        cout << endl;
        cout << "Ingrese la cantidad total de Productos diferentes que desea comprar" << endl;
        cin >> cantProducto;

        detallesCompra = new DetalleCompra[cantProducto];
        for(int i=0; i<cantProducto; i++){
            DetalleCompra detalle;
            int idProducto, cantidad;
            cout << "cargando " << (i+1) << " de " << cantProducto << " productos" << endl;
            cout << "ingrese el id producto" << endl;
            cin >> idProducto;
            cout << "ingrese la cantidad del producto a comprar" << endl;
            cin >> cantidad;
            acuStock+=cantidad;
            detalle.setIdDetalle(archDetalle.ObtenerUltimoId()+(i+1));
            detalle.setIdCompra(nuevaCompra.getIdCompra());
            detalle.setIdProducto(idProducto);
            detalle.setPrecioUnitario(prodManager.obtenerPrecio(idProducto));
            detalle.setCantidad(cantidad);
            detallesCompra[i]=detalle;
            acuPrecio+=(prodManager.obtenerPrecio(idProducto)*cantidad);
        }
        system("cls");
        cout << "RESUMEN" << endl;
        cout << "Fecha: " << fechaActual.toString() << endl;
        cout << "CUIT PROVEEDOR: " << cuit << endl;
        cout << "CANTIDAD DE PRESENTACIONES: " << cantProducto << endl;
        cout << "CANTIDAD TOTAL DE INGRESO AL STOCK: " << acuStock << endl;
        cout << "IMPORTE FINAL: $" << acuPrecio << endl;
        cout << "presione 1 para finalizar compra. CERO para borrar." << endl;
        //system("cls");
        nuevaCompra.setImporte(acuPrecio);
        int opcion=0;
        cin >> opcion;
        if(opcion==1){
            if (archivo.Guardar(nuevaCompra)) {
            for(int i=0;i<cantProducto; i++){
                archDetalle.Guardar(detallesCompra[i]);
            }
            cout << "Compra guardada exitosamente con ID: " << nuevoId << endl;
            } else {
                cout << "Error al guardar la compra." << endl;
            }
        }
        else{
            cout << "compra borrada" << endl;
        }
    }else{
        cout << "Proveedor no encontrado" << endl;
    }
}

void CompraManager::modificarCompra() {
    ArchivoCompra archivo("compras.dat");
    int id;
    cout << "Ingrese ID de la compra a modificar: ";
    cin >> id;

    Compra compra;
    if (archivo.Buscar(id, compra)) {
        cout << "Compra encontrada. Ingrese nuevo CUIT: ";
        string nuevoCuit;
        cin >> nuevoCuit;
        compra.setCuitProveedor(nuevoCuit);

        cout << "Nueva fecha (dd mm aaaa): ";
        int d, m, a;
        cin >> d >> m >> a;
        compra.setFechaCompra(d, m, a);

        int pos = archivo.Buscar(id);
        if (archivo.Guardar(compra, pos)) {
            cout << "Compra modificada correctamente." << endl;
        } else {
            cout << "Error al modificar la compra." << endl;
        }
    } else {
        cout << "Compra no encontrada." << endl;
    }
}

void CompraManager::eliminarCompra() {
    ArchivoCompra archivo("compras.dat");
    int id;
    cout << "Ingrese ID de la compra a eliminar: ";
    cin >> id;

    Compra compra;
    if (archivo.Buscar(id, compra)) {
        // Simular baja lógica con un CUIT especial
        compra.setCuitProveedor("ELIMINADO");
        int pos = archivo.Buscar(id);
        if (archivo.Guardar(compra, pos)) {
            cout << "Compra eliminada lógicamente." << endl;
        } else {
            cout << "No se pudo eliminar la compra." << endl;
        }
    } else {
        cout << "Compra no encontrada." << endl;
    }
}

void CompraManager::listarCompras() {
    ArchivoCompra archivo("compras.dat");
    int total = archivo.CantidadRegistros();

    for (int i = 0; i < total; i++) {
        Compra compra = archivo.Leer(i);
            cout << "ID: " << compra.getIdCompra()
                 << " | CUIT: " << compra.getCuitProveedor()
                 << " | Fecha: " << compra.getFechaCompra().toString() << endl;
    }
}
bool CompraManager::listarComprasPorFecha(std::string fecha) {
    ArchivoCompra archivo("compras.dat");
    int total = archivo.CantidadRegistros();
    bool flag=false;
    for (int i = 0; i < total; i++) {
        Compra compra = archivo.Leer(i);
        if(compra.getFechaCompra().toString()==fecha){
                flag=true;
            cout << "ID: " << compra.getIdCompra()
                 << " | CUIT: " << compra.getCuitProveedor()
                 << " | Fecha: " << compra.getFechaCompra().toString() << endl;
        }
    }
    if(flag){return true;}
    else{return false;}
}

void CompraManager::mostrarCantidadRegistros() {
    ArchivoCompra archivo("compras.dat");
    cout << "Total de registros (incluye eliminados): " << archivo.CantidadRegistros() << endl;
}
