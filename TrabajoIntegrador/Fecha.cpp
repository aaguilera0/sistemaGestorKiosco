#include "Fecha.h"
#include <ctime>
Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}
void Fecha::FechaActual(){
    time_t now = time(0);                 // tiempo actual en segundos desde Epoch
    tm* localTime = localtime(&now);      // convertir a tiempo local

    int dia = localTime->tm_mday;         // día del mes [1, 31]
    int mes = localTime->tm_mon + 1;      // mes [0, 11] → sumamos 1
    int anio = localTime->tm_year + 1900; // años desde 1900
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}
