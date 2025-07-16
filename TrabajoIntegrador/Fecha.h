#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <string>

class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        int getDia();
        int getMes();
        int getAnio();

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void FechaActual();
        std::string toString();
};


#endif // FECHA_H_INCLUDED
