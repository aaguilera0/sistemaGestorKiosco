#include "ArchivoProveedorProducto.h"
#include <cstdio>

ArchivoProveedorProducto::ArchivoProveedorProducto(string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoProveedorProducto::Guardar(RelacionProveedorProducto relacionProveedorProducto) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&relacionProveedorProducto, sizeof(RelacionProveedorProducto), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

bool ArchivoProveedorProducto::Guardar(RelacionProveedorProducto relacionProveedorProducto, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(RelacionProveedorProducto) * posicion, SEEK_SET);
    bool ok = fwrite(&relacionProveedorProducto, sizeof(RelacionProveedorProducto), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

RelacionProveedorProducto ArchivoProveedorProducto::Leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return RelacionProveedorProducto(); // constructor por defecto
    }
    RelacionProveedorProducto relacion1;
    fseek(pArchivo, sizeof(RelacionProveedorProducto) * posicion, SEEK_SET);
    fread(&relacion1, sizeof(RelacionProveedorProducto), 1, pArchivo);
    fclose(pArchivo);
    return relacion1;
}

int ArchivoProveedorProducto::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(RelacionProveedorProducto);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProveedorProducto::Leer(int cantidadRegistros, RelacionProveedorProducto *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    for (int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(RelacionProveedorProducto), 1, pArchivo);
    }
    fclose(pArchivo);
}

bool ArchivoProveedorProducto::Buscar(int IdProveedorProducto, RelacionProveedorProducto& relacionEncontrada) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    RelacionProveedorProducto relacion1;
    while (fread(&relacion1, sizeof(RelacionProveedorProducto), 1, pArchivo)) {
        if (relacion1.getIdProveedorProducto() == IdProveedorProducto) {
            fclose(pArchivo);
            relacionEncontrada = relacion1;  // corregido variable
            return true;
        }
    }
    fclose(pArchivo);
    return false;
}

bool ArchivoProveedorProducto::BuscarPorCuit(int cantidadRegistros,  RelacionProveedorProducto *vector,  string cuit) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    RelacionProveedorProducto relacion1;
    int aux = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (fread(&relacion1, sizeof(RelacionProveedorProducto), 1, pArchivo) == 1) {
            if (relacion1.getCuitProveedor() == cuit) {
                vector[aux] = relacion1;
                aux++;
            }
        }
    }

    fclose(pArchivo);
    return (aux > 0);
}
int ArchivoProveedorProducto::ObtenerUltimoId() {
    int cantidad = CantidadRegistros();
    if (cantidad == 0) return 0;

    RelacionProveedorProducto ultimo = Leer(cantidad - 1);
    return ultimo.getIdProveedorProducto();
}
