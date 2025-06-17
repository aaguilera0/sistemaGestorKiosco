#include "ArchivoCompra.h"
#include <cstdio>

ArchivoCompra::ArchivoCompra(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCompra::Guardar(Compra compraNueva) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&compraNueva, sizeof(Compra), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

bool ArchivoCompra::Guardar(Compra compraNuevo, int posicion) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Compra) * posicion, SEEK_SET);
    bool ok = fwrite(&compraNuevo, sizeof(Compra), 1, pArchivo) == 1;
    fclose(pArchivo);
    return ok;
}

Compra ArchivoCompra::Leer(int posicion) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return Compra();
    }
    Compra compra1;
    fseek(pArchivo, sizeof(Compra) * posicion, SEEK_SET);
    fread(&compra1, sizeof(Compra), 1, pArchivo);
    fclose(pArchivo);
    return compra1;
}

int ArchivoCompra::CantidadRegistros() {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Compra);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoCompra::Leer(int cantidadRegistros, Compra* vector) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    for (int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(Compra), 1, pArchivo);
    }
    fclose(pArchivo);
}

int ArchivoCompra::Buscar(int IdCompra) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }
    Compra compra1;
    int i = 0;
    while (fread(&compra1, sizeof(Compra), 1, pArchivo)) {
        if (compra1.getIdCompra() == IdCompra) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

bool ArchivoCompra::Buscar(int IdCompra, Compra& compraEncontrada) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    Compra compra1;
    while (fread(&compra1, sizeof(Compra), 1, pArchivo)) {
        if (compra1.getIdCompra() == IdCompra) {
            fclose(pArchivo);
            compraEncontrada = compra1;
            return true;
        }
    }
    fclose(pArchivo);
    return false;
}

bool ArchivoCompra::Buscar(std::string cuitProveedor, Fecha fechaCompra, Compra& compraEncontrada) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    Compra compra1;
    while (fread(&compra1, sizeof(Compra), 1, pArchivo)) {
        if (compra1.getCuitProveedor() == cuitProveedor && compra1.getFechaCompra().toString() == fechaCompra.toString()) {
            fclose(pArchivo);
            compraEncontrada = compra1;
            return true;
        }
    }
    fclose(pArchivo);
    return false;
}

bool ArchivoCompra::Buscar(std::string cuitProveedor, Compra& compraEncontrada) {
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return false;
    }

    Compra compra1;
    while (fread(&compra1, sizeof(Compra), 1, pArchivo)) {
        if (compra1.getCuitProveedor() == cuitProveedor) {
            fclose(pArchivo);
            compraEncontrada = compra1;
            return true;
        }
    }
    fclose(pArchivo);
    return false;
}
int ArchivoCompra::ObtenerUltimoId() {
    int cantidad = CantidadRegistros();
    if (cantidad == 0) return 0;

    Compra ultimaCompra = Leer(cantidad - 1);
    return ultimaCompra.getIdCompra();
}
