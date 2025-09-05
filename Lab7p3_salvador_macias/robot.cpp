#include "robot.h"
#include <stdexcept>


Robot::Robot(const string nombre, int bateria, int procesadores)
    : nombre_(nombre),
      bateria_(clamp(bateria, 1, 10)),
      procesadores_(clamp(procesadores, 1, 10)),
      capacidadTotal_(0) {
    actualizarCapacidadTotal();
}

Robot::~Robot() = default;

void Robot::actualizarCapacidadTotal() {
    capacidadTotal_ = bateria_ * procesadores_;
}
