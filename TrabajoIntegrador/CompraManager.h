#ifndef COMPRAMANAGER_H_INCLUDED
#define COMPRAMANAGER_H_INCLUDED

class CompraManager {
public:
    void cargarNuevaCompra();              // Ingresar una nueva compra
    void modificarCompra();                // Modificar datos de una compra existente
    void eliminarCompra();                 // Marcar una compra como eliminada (o borrado físico)
    void listarCompras();                  // Mostrar todas las compras
    void mostrarCantidadRegistros();
    bool listarComprasPorFecha(std::string fecha);
};

#endif // COMPRAMANAGER_H_INCLUDED

