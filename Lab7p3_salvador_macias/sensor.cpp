#include "sensor.h"

static inline int clampS(int v, int lo, int hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

Sensor::Sensor(const std::string& tipo, int sensibilidad)
    : tipo_(tipo), sensibilidad_(clampS(sensibilidad, 0, 100)) {}

Sensor::~Sensor() = default;

void Sensor::setSensibilidad(int val) {
    sensibilidad_ = clampS(val, 0, 100);
}
