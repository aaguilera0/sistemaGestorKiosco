#include <iostream>

#include "Categoria.h"
#include "ArchivoCategoria.h"
#include "CategoriaManager.h"

#include <string>
/// CATEGORIA

int CategoriaManager :: agregarCategoria(){

    Categoria categoria;
    ArchivoCategoria pArchivo;

    int idCategoria;
    std::string nombreCategoria;


    cout << "ID CATEGORIA : " ;
    int cantidad = pArchivo.getCantidadRegistros();
    idCategoria = cantidad + 1;
    cout << idCategoria << endl;


    int pos = pArchivo.buscarPorID(idCategoria);
    if(pos >= 0) { // Ya existe una categoria con ese ID
        cout << "ERROR: Ya existe una CATEGORIA con ese ID." << endl;
        return -1; // No continua el guardado
    }

    cout << "NOMBRE DE CATEGORIA :" ;
    cin >> nombreCategoria;

    categoria.setEstado(true);
    categoria.setIDCategoria(idCategoria);
    categoria.setNombreCategoria(nombreCategoria);

    if(pArchivo.guardar(categoria)){
        cout << "SE GUARDO CORRECTAMENTE." << endl;
    }
    else{
        cout << "HUBO UN ERROR AL GUARDAR." << endl;
    }
}

void CategoriaManager :: modificarCategoria(){

    ArchivoCategoria pArchivo;
    int idCategoria;
    Categoria categoria;
    int cantidad = pArchivo.getCantidadRegistros();
    bool encontrado = false;

    cout << "INGRESE EL ID DE LA CATEGORIA A MODIFICAR: ";
    cin >> idCategoria;

    for(int i = 0; i < cantidad; i++){
        categoria = pArchivo.leer(i);

        if(categoria.getIdCategoria() == idCategoria){
            encontrado = true;
            cout << "CATEGORIA ENCONTRADA: " << endl;
            cout << categoria.toCSV() << endl;


            int idCategoria;
            string nombreCategoria;

            cout << "INGRESE EL NUEVO NOMBRE: ";
            cin >> nombreCategoria;

            categoria.setNombreCategoria(nombreCategoria);

            if(pArchivo.guardar(categoria, i)){
                cout << "CATEGORIA MODIFICADA CON EXITO." << endl;
            } else {
                cout << "ERROR AL MODIFICAR." << endl;
            }

            break;
        }}}

void CategoriaManager :: eliminarCategoria(){

    ArchivoCategoria pArchivo;
    int idCategoria;
    Categoria categoria;
    int cantidad = pArchivo.getCantidadRegistros();
    bool encontrado = false;

    cout << "INGRESE EL ID DE LA CATEGORIA A ELIMINAR: ";
    cin >> idCategoria;

    for(int i = 0; i < cantidad; i++){
        categoria = pArchivo.leer(i);

        if(categoria.getIdCategoria() == idCategoria){
            encontrado = true;
            cout << "CATEGORIA ENCONTRADA: " << endl;
            cout << categoria.toCSV() << endl;

            categoria.setEstado(false);

            if(pArchivo.guardar(categoria, i)){
                cout << "CATEGORIA ELIMINADA CON EXITO." << endl;
            } else {
                cout << "ERROR AL ELIMINAR." << endl;
            }

            break;
        }
    }

    if(!encontrado){
        cout << "NO SE ENCONTRO NINGUNA CATEGORIA CON ESE ID." << endl;
    }
}

void CategoriaManager :: listarCategorias(){
    ArchivoCategoria pArchivo;
    Categoria registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0;i<cantidadRegistros;i++){
        registro = pArchivo.leer(i);
        if(registro.getEstado()==true){
            cout << registro.toCSV() << endl;
        }

    }
}
void CategoriaManager :: activarCategoria(){
    Categoria registro;
    ArchivoCategoria pArchivo;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    int idCategoria;
    bool encontrado = false;

    cout << "CATEGORIAS ELIMINADAS ||" << endl;

    for(int i=0; i<cantidadRegistros; i++)
    {
        registro = pArchivo.leer(i);
        if(registro.getEstado()==false)
        {
            cout << registro.toCSV() << endl;
        }
    }
    cout << endl;
    cout << "INGRESAR EL ID DE LA CATEGORIA PARA ACTIVAR" << endl;
    cin >> idCategoria;


    for(int i =0; i < cantidadRegistros; i++)
    {
        registro = pArchivo.leer(i);
        if(registro.getIdCategoria()== idCategoria)
        {
            encontrado = true;

            cout << "CATEGORIA ENCONTRADO!" << endl;
            cout << registro.toCSV() << endl;

            registro.setEstado(true);

            if(pArchivo.guardar(registro,i))
            {
                cout << "CATEGORIA ACTIVADA!" << endl;
            }
            else
            {
                cout << "NO SE PUDO ACTIVAR LA CATEGORIA CON EXITO!" << endl;
            }
            break;
        }

    }
    if(!encontrado)
    {
        cout << "NO SE ENCONTRO NINGUNA CATEGORIA CON ESE ID." << endl;
    }

}
