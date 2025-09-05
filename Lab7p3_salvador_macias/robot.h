#pragma once
#include <string>
#include <iostream>

using namespace std;

class Robot {
protected:
    string nombre_;
    int bateria_;
    int procesadores_;
    int capacidadTotal_;

    void actualizarCapacidadTotal();

public:
    Robot(const string nombre, int bateria, int procesadores);
    virtual ~Robot();

   
    const string getNombre() const { return nombre_; }
    int getBateria() const { return bateria_; }
    int getProcesadores() const { return procesadores_; }
    int getCapacidadTotal() const { return capacidadTotal_; }
    
    

 
    Robot(const Robot&) = delete;
    Robot& operator=(const Robot&) = delete;

    Robot(Robot&&) noexcept = default;
    Robot& operator=(Robot&&) noexcept = default;

    virtual void optimizar() = 0;
    virtual void mostrarEspecificaciones() const = 0;

    virtual bool necesitaMantenimiento() const { return false; }
    virtual bool sobrecargado() const { return false; }
};
