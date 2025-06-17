#include <iostream>
#include "CompraManager.h"
#include "Compra.h"
#include "ArchivoCompra.h"

using namespace std;

void CompraManager::cargarNuevaCompra() {
    Compra nuevaCompra;
    ArchivoCompra archivo("compras.dat");

    int nuevoId = archivo.ObtenerUltimoId() + 1;
    nuevaCompra.setIdCompra(nuevoId);

    cout << "CUIT del proveedor: ";
    string cuit;
    cin >> cuit;
    nuevaCompra.setCuitProveedor(cuit);

    cout << "Fecha de la compra (dd mm aaaa): ";
    int dia, mes, anio;
    cin >> dia >> mes >> anio;
    nuevaCompra.setFechaCompra(dia, mes, anio);

    if (archivo.Guardar(nuevaCompra)) {
        cout << "Compra guardada exitosamente con ID: " << nuevoId << endl;
    } else {
        cout << "Error al guardar la compra." << endl;
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
        if (compra.getCuitProveedor() != "ELIMINADO") {
            cout << "ID: " << compra.getIdCompra()
                 << " | CUIT: " << compra.getCuitProveedor()
                 << " | Fecha: " << compra.getFechaCompra().toString() << endl;
        }
    }
}

void CompraManager::mostrarCantidadRegistros() {
    ArchivoCompra archivo("compras.dat");
    cout << "Total de registros (incluye eliminados): " << archivo.CantidadRegistros() << endl;
}
