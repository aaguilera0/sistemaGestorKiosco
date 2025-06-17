#include "archivoDetalleCompra.h"
#include <cstdio> // para FILE*, fopen, fwrite, fread, fclose

archivoDetalleCompra::archivoDetalleCompra(string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool archivoDetalleCompra::Guardar(DetalleCompra detalleCompra) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&detalleCompra, sizeof(DetalleCompra), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

bool archivoDetalleCompra::Guardar(DetalleCompra detalleCompra, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(DetalleCompra) * posicion, SEEK_SET);
    bool ok = fwrite(&detalleCompra, sizeof(DetalleCompra), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

DetalleCompra archivoDetalleCompra::Leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return DetalleCompra(); // constructor por defecto
    }
    DetalleCompra detalleCompra1;
    fseek(pArchivo, sizeof(DetalleCompra) * posicion, SEEK_SET);
    fread(&detalleCompra1, sizeof(DetalleCompra), 1, pArchivo);
    fclose(pArchivo);
    return detalleCompra1;
}

int archivoDetalleCompra::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(DetalleCompra);
    fclose(pArchivo);
    return cantidadRegistros;
}

void archivoDetalleCompra::Leer(int cantidadRegistros, DetalleCompra *vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    for (int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(DetalleCompra), 1, pArchivo);
    }
    fclose(pArchivo);
}

bool archivoDetalleCompra::Buscar(int IdDetalle, DetalleCompra& detalleCompraEncontrada) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    DetalleCompra detalleCompra1;
    while (fread(&detalleCompra1, sizeof(DetalleCompra), 1, pArchivo)) {
        if (detalleCompra1.getIdDetalle() == IdDetalle) {
            fclose(pArchivo);
            detalleCompraEncontrada = detalleCompra1;  // corregido variable
            return true;
        }
    }
    fclose(pArchivo);
    return false;
}

bool archivoDetalleCompra::BuscarPorIdCompra(int cantidadRegistros, DetalleCompra *vector, int IdCompra) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    DetalleCompra detalleCompra1;
    int aux = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        if (fread(&detalleCompra1, sizeof(DetalleCompra), 1, pArchivo) == 1) {
            if (detalleCompra1.getIdCompra() == IdCompra) {
                vector[aux] = detalleCompra1;
                aux++;
            }
        }
    }

    fclose(pArchivo);
    return (aux > 0);
}
int archivoDetalleCompra::ObtenerUltimoId() {
    int cantidad = CantidadRegistros();
    if (cantidad == 0) return 0;

    DetalleCompra ultimoDetalle = Leer(cantidad - 1);
    return ultimoDetalle.getIdDetalle();
}
