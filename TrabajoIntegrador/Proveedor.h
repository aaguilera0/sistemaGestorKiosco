#pragma once
#include <string>

class Proveedor{
    private:
        char _cuit[20];
        char _nombre[30];
        char _apellido[30];
        int _numTelefono;
        char _mail[30];
        char _direccion[30];
        bool _estado;
    public:
        Proveedor();
        Proveedor(std::string cuit, std::string nombre, std::string apellido, int numTelefono, std::string mail, std::string direccion, bool estado);

        std::string getCuit();
        std::string getNombre();
        std::string getApellido();
        int getNumTelefono();
        std::string getMail();
        std::string getDireccion();
        bool getEstado();

        void setCuit(std::string cuit);
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setNumeroTelefono(int numTelefono);
        void setMail(std::string mail);
        void setDireccion(std::string direccion);
        void setEstado(bool estado);

        std::string toCSV();
};
