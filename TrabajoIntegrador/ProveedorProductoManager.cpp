#include <iostream>
#include "RelacionProveedorProducto.h"
#include "ArchivoProveedorProducto.h"
#include "ProveedorProductoManager.h"
#include <string>

using namespace std;

void ProveedorProductoManager::cargarNuevaRelacion(string cuitProveedor, int idProducto) {
    ArchivoProveedorProducto pArchivo("ArchivoProveedorProducto.dat");

    int nuevoId = pArchivo.ObtenerUltimoId();
    RelacionProveedorProducto relacion(nuevoId, cuitProveedor, idProducto);

    if (pArchivo.Guardar(relacion)) {
        cout << "SE GUARDO CORRECTAMENTE." << endl;
    } else {
        cout << "HUBO UN ERROR AL GUARDAR." << endl;
    }
}

void ProveedorProductoManager::modificarRelacion() {
    ArchivoProveedorProducto pArchivo("ArchivoProveedorProducto.dat");
    RelacionProveedorProducto relacion;
    int cantidad = pArchivo.CantidadRegistros();
    bool encontrado = false;
    int idProveedorProducto = 0;

    cout << "INGRESE EL IdProveedorProducto DE la relacion A MODIFICAR: ";
    cin >> idProveedorProducto;
    cin.ignore(); // limpia el buffer antes de usar getline

    for (int i = 0; i < cantidad; i++) {
        relacion = pArchivo.Leer(i);

        if (relacion.getIdProveedorProducto() == idProveedorProducto) {
            encontrado = true;
            cout << "ENCONTRADO: " << endl;
            cout << relacion.toCSV() << endl;

            string cuitNuevo;
            int idProducto;

            cout << "INGRESE CUIT proveedor: ";
            getline(cin, cuitNuevo);

            cout << "INGRESE idProducto: ";
            cin >> idProducto;

            relacion.setCuitProveedor(cuitNuevo);
            relacion.setIdProducto(idProducto);

            if (pArchivo.Guardar(relacion, i)) {
                cout << "RELACION MODIFICADA CON EXITO." << endl;
            } else {
                cout << "ERROR AL MODIFICAR." << endl;
            }

            break;
        }
    }

    if (!encontrado) {
        cout << "NO SE ENCONTRO NINGUNA RELACION CON ESE ID." << endl;
    }
}

void ProveedorProductoManager::mostrarCantidadRegistros() {
    ArchivoProveedorProducto pArchivo("ArchivoProveedorProducto.dat");

    int cantidadRegistros = pArchivo.CantidadRegistros();

    cout << "LA CANTIDAD DE REGISTROS ES: " << cantidadRegistros << endl;
}

void ProveedorProductoManager::listar() {
    ArchivoProveedorProducto pArchivo("ArchivoProveedorProducto.dat");
    RelacionProveedorProducto registro;
    int cantidadRegistros = pArchivo.CantidadRegistros();

    for (int i = 0; i < cantidadRegistros; i++) {
        registro = pArchivo.Leer(i);
        cout << registro.toCSV() << endl;
    }
}
void ProveedorProductoManager::buscarRelacionPorCuit() {
    ArchivoProveedorProducto pArchivo("ArchivoProveedorProducto.dat");
    int cantidad = pArchivo.CantidadRegistros();

    RelacionProveedorProducto* coincidencias = new RelacionProveedorProducto[cantidad];

    string cuitStr;
    cout << "Ingrese el CUIT del proveedor: ";
    cin >> cuitStr;

    if (pArchivo.BuscarPorCuit(cantidad, coincidencias, cuitStr)) {
        cout << "Coincidencias encontradas. Relaciones:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "ID Relación: " << coincidencias[i].getIdProveedorProducto() << endl;
            cout << "CUIT: " << coincidencias[i].getCuitProveedor() << endl;
            cout << "ID Producto: " << coincidencias[i].getIdProducto() << endl;
            cout << "-------------------------------" << endl;
        }
    } else {
        cout << "Coincidencias no encontradas.\n";
    }

    delete[] coincidencias;
}
