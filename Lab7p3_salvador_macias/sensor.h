#pragma once
#include <string>

class Sensor {
    std::string tipo_;
    int sensibilidad_;
public:
    Sensor(const std::string& tipo, int sensibilidad);
    ~Sensor();

    const std::string& getTipo() const { return tipo_; }
    int getSensibilidad() const { return sensibilidad_; }
    void setTipo(const std::string& tipo) { tipo_ = tipo; }
    void setSensibilidad(int val); 
};

