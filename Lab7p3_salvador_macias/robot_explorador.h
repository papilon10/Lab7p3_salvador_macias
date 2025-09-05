#pragma once
#include "robot.h"
#include "sensor.h"
//#include "Promedios.h"
#include <vector>
#include <memory>

class RobotExplorador : public Robot {
    int alcanceTerrenoKm_;
    std::vector<Sensor*> sensores_;

    static bool suerteFallo10();
    static int  randomEnRango(int lo, int hi);

public:
    RobotExplorador(const std::string& nombre,
                    int bateria,
                    int procesadores,
                    int alcanceTerrenoKm);

    ~RobotExplorador() override;

    void agregarSensor(Sensor* s);  
    size_t cantidadSensores() const { return sensores_.size(); }

    int getAlcanceTerreno() const { return alcanceTerrenoKm_; }

    void optimizar() override;
    void mostrarEspecificaciones() const override;
    bool necesitaMantenimiento() const override;

private:
    double promedioSensibilidad() const;
    std::string sensorMasComun() const;
};

