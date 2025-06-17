#ifndef DETALLECOMPRAMANAGER_H_INCLUDED
#define DETALLECOMPRAMANAGER_H_INCLUDED

class DetalleCompraManager {
public:
    void cargarNuevoDetalle();             // Agregar un nuevo detalle de compra
    void modificarDetalle();               // Modificar un detalle existente
    void eliminarDetalle();                // Eliminar un detalle (por ID)
    void listarDetalles();                 // Mostrar todos los detalles
    void listarDetallesDeCompra();         // Mostrar detalles de una compra específica
    void mostrarCantidadRegistros();       // Mostrar cuántos detalles hay guardados
};

#endif // DETALLECOMPRAMANAGER_H_INCLUDED

