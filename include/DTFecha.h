#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>
#include <iostream>

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha(int dia, int mes, int anio);
    DTFecha(DTFecha* fecha);
    
    bool operator>=(DTFecha* fecha);
    bool operator<(DTFecha* fecha);
    bool operator==(DTFecha* fecha);
    std::string toString();
};

std::ostream& operator<<(std::ostream& os, DTFecha* fecha);

#endif
