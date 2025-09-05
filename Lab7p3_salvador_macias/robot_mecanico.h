#pragma once
#include "robot.h"
//#include "Promedios.h"
#include <vector>
#include <string>

class RobotMecanico : public Robot {
    int potenciaHerramientas_;
    std::vector<std::string> herramientas_;

    static bool suerteFallo10();
    static int  randomEnRango(int lo, int hi);

public:
    RobotMecanico(const std::string& nombre,
                  int bateria,
                  int procesadores,
                  int potenciaInicial = 0);

    ~RobotMecanico() override = default;

    void agregarHerramienta(const std::string& h);
    size_t cantidadHerramientas() const { return herramientas_.size(); }

    int getPotencia() const { return potenciaHerramientas_; }
    const std::vector<std::string>& getHerramientas() const { return herramientas_; }

    void optimizar() override;
    void mostrarEspecificaciones() const override;
    bool sobrecargado() const override;

private:
    double promedioLongitudesHerramientas() const; 
};

