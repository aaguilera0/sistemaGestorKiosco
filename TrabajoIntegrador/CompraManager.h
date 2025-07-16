#ifndef COMPRAMANAGER_H_INCLUDED
#define COMPRAMANAGER_H_INCLUDED

class CompraManager {
public:
    void cargarNuevaCompra();              // Ingresar una nueva compra
    void modificarCompra();                // Modificar datos de una compra existente
    void eliminarCompra();                 // Marcar una compra como eliminada (o borrado fisico)
    void listarCompras();                  // Mostrar todas las compras
    void mostrarCantidadRegistros();       // Mostrar cuántas compras hay guardadas
};

#endif // COMPRAMANAGER_H_INCLUDED

