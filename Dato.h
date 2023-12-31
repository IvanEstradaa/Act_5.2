#ifndef DATO_H
#define DATO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

// Struct para guardar cada octeto del ip  y el puerto con la menor cantidad de bits posibles
struct IP
{
int oct1;
int oct2;
int oct3;
int oct4;
int port;

    void FILL_IP(std::string ip)
    {
        std::stringstream ss(ip);
        char dot, colon;

        // Extraer valores y meterlos al struct de IP
        ss >> this->oct1 >> dot >> this->oct2 >> dot >> this->oct3 >> dot >> this->oct4 >> colon >> this->port;
    }
};

struct Hora
{
int Hora;
int Minuto;
int Segundo;

    void FILL_HORA(std::string hora)
    {
        std::stringstream ss(hora);
        char colon;

        // Extraer valores y meterlos al struct de IP
        ss >> this->Hora >> colon >> this->Minuto >> colon >> this->Segundo;
    }
};

class Dato
{
private:
    string mes,
        hora,
        ip,
        fallo,
        stringIp;

    int dia;
    IP IP_VALUE;
    Hora HORA_VALUE;

public:
    // Constructor
    Dato(string line);

    // Getters
    string getIp();
    string getIpNoPort();
    int getOcteto(int index);
    string getMes() const;
    int getDia();
    string getFullDate();
    const string &getHora() const;

    // Operator overload
    friend ostream &operator<<(ostream &os, Dato &d){
        os << d.mes << " " << d.dia << "" << d.hora << " " << d.ip << " " << d.fallo<<endl;
        return os;
    }
};

#endif // ACT2_3_DATO_H
