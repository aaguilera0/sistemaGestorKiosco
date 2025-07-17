#include <iostream>
#include "DetalleCompraManager.h"
#include "DetalleCompra.h"
#include "archivoDetalleCompra.h"

using namespace std;

void DetalleCompraManager::cargarNuevoDetalle() {
    DetalleCompra nuevoDetalle;
    archivoDetalleCompra archivo("detalles.dat");

    int nuevoId = archivo.ObtenerUltimoId() + 1;
    nuevoDetalle.setIdDetalle(nuevoId);

    int idCompra, idProducto, cantidad;
    float precio;

    cout << "ID de la compra asociada: ";
    cin >> idCompra;
    nuevoDetalle.setIdCompra(idCompra);

    cout << "ID del producto: ";
    cin >> idProducto;
    nuevoDetalle.setIdProducto(idProducto);

    cout << "Cantidad: ";
    cin >> cantidad;
    nuevoDetalle.setCantidad(cantidad);

    cout << "Precio unitario: ";
    cin >> precio;
    nuevoDetalle.setPrecioUnitario(precio);

    if (archivo.Guardar(nuevoDetalle)) {
        cout << "Detalle guardado exitosamente con ID: " << nuevoId << endl;
    } else {
        cout << "Error al guardar el detalle." << endl;
    }
}

void DetalleCompraManager::modificarDetalle() {
    archivoDetalleCompra archivo("detalles.dat");
    int id;
    cout << "Ingrese ID del detalle a modificar: ";
    cin >> id;

    DetalleCompra detalle;
    if (archivo.Buscar(id, detalle)) {
        cout << "Detalle encontrado. Ingrese nueva cantidad: ";
        int nuevaCantidad;
        cin >> nuevaCantidad;
        detalle.setCantidad(nuevaCantidad);

        cout << "Nuevo precio unitario: ";
        float nuevoPrecio;
        cin >> nuevoPrecio;
        detalle.setPrecioUnitario(nuevoPrecio);

        //int pos = archivo.Buscar(id);
        if (archivo.Guardar(detalle, detalle.getIdDetalle())) {
            cout << "Detalle modificado correctamente." << endl;
        } else {
            cout << "Error al modificar el detalle." << endl;
        }
    } else {
        cout << "Detalle no encontrado." << endl;
    }
}

void DetalleCompraManager::eliminarDetalle() {
    archivoDetalleCompra archivo("detalles.dat");
    int id;
    cout << "Ingrese ID del detalle a eliminar: ";
    cin >> id;

    DetalleCompra detalle;
    if (archivo.Buscar(id, detalle)) {
        // Simulamos eliminación lógica con ID producto -1
        detalle.setIdProducto(-1);
        //int pos = archivo.Buscar(id);
        if (archivo.Guardar(detalle, detalle.getIdDetalle())) {
            cout << "Detalle eliminado lógicamente." << endl;
        } else {
            cout << "No se pudo eliminar el detalle." << endl;
        }
    } else {
        cout << "Detalle no encontrado." << endl;
    }
}

void DetalleCompraManager::listarDetalles() {
    archivoDetalleCompra archivo("detalles.dat");
    int total = archivo.CantidadRegistros();

    for (int i = 0; i < total; i++) {
        DetalleCompra det = archivo.Leer(i);
        if (det.getIdProducto() != -1) {
            cout << "----------------------------------------------" << endl;
            cout << endl;
            cout << "ID Detalle: " << det.getIdDetalle()
                 << " | ID Compra: " << det.getIdCompra()
                 << " | ID Producto: " << det.getIdProducto()
                 << " | Cantidad: " << det.getCantidad()
                 << " | Precio: $" << det.getPrecio() << endl;
        }
    }
}

void DetalleCompraManager::listarDetallesDeCompra() {
    archivoDetalleCompra archivo("detalles.dat");
    int idCompra;
    cout << "Ingrese ID de la compra: ";
    cin >> idCompra;

    int total = archivo.CantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < total; i++) {
        DetalleCompra det = archivo.Leer(i);
        if (det.getIdCompra() == idCompra && det.getIdProducto() != -1) {
            cout << "----------------------------------------------" << endl;
            cout << "ID Detalle: " << det.getIdDetalle()
                 << " | ID Producto: " << det.getIdProducto()
                 << " | Cantidad: " << det.getCantidad()
                 << " | Precio: $" << det.getPrecio() << endl;
            cout << "----------------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron detalles para la compra con ID " << idCompra << endl;
    }
}

void DetalleCompraManager::mostrarCantidadRegistros() {
    archivoDetalleCompra archivo("detalles.dat");
    cout << "Total de registros (incluye eliminados): " << archivo.CantidadRegistros() << endl;
}
