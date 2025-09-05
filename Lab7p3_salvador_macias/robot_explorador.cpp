#include "robot_explorador.h"
#include <random>
#include <algorithm>
#include <unordered_map>
#include <iostream>

static inline int clampE(int v, int lo, int hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

RobotExplorador::RobotExplorador(const std::string& nombre,
                                 int bateria,
                                 int procesadores,
                                 int alcanceTerrenoKm)
    : Robot(nombre, bateria, procesadores),
      alcanceTerrenoKm_(std::max(0, alcanceTerrenoKm)) {}

RobotExplorador::~RobotExplorador() {
    for (Sensor* s : sensores_) delete s;
    sensores_.clear();
}

void RobotExplorador::agregarSensor(Sensor* s) {
    if (s) sensores_.push_back(s);
}

bool RobotExplorador::suerteFallo10() {
     std::random_device rd;
     std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.10);
    return d(gen);
}

int RobotExplorador::randomEnRango(int lo, int hi) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(lo, hi);
    return dist(gen);
}

void RobotExplorador::optimizar() {
    // Alcance aumenta [0..30]
    int deltaReach = randomEnRango(0, 30);
    alcanceTerrenoKm_ = std::max(0, alcanceTerrenoKm_ + deltaReach);

    // Sensibilidad de cada sensor +[5..20], clamp 100
    for (Sensor* s : sensores_) {
        if (!s) continue;
        int inc = randomEnRango(5, 20);
        s->setSensibilidad(std::min(100, s->getSensibilidad() + inc));
    }

    // Fallo 10%: pierde un sensor si hay más de 1
    if (suerteFallo10() && sensores_.size() > 1) {
        // eliminamos el último (o aleatorio si prefieres)
        size_t idx = static_cast<size_t>(randomEnRango(0, static_cast<int>(sensores_.size()) - 1));
        delete sensores_[idx];
        sensores_.erase(sensores_.begin() + static_cast<std::ptrdiff_t>(idx));
        std::cout << "[FALLO] " << nombre_ << " perdió un sensor durante la optimización.\n";
    }
}

/*double RobotExplorador::promedioSensibilidad() const {
    std::vector<int> vals;
    vals.reserve(sensores_.size());
    for (const Sensor* s : sensores_) if (s) vals.push_back(s->getSensibilidad());
    return calcularPromedio<int>(vals);
}*/

std::string RobotExplorador::sensorMasComun() const {
    if (sensores_.empty()) return "(sin sensores)";
    std::unordered_map<std::string, int> freq;
    for (const Sensor* s : sensores_) if (s) ++freq[s->getTipo()];
    // elegir el de mayor frecuencia (break ties por orden de inserción no garantizado)
    std::string best; int bestCount = -1;
    for (const auto& kv : freq) {
        if (kv.second > bestCount) {
            best = kv.first; bestCount = kv.second;
        }
    }
    return best;
}

void RobotExplorador::mostrarEspecificaciones() const {
    std::cout << "=== Robot Explorador: " << nombre_ << " ===\n";
    std::cout << "Bateria: " << bateria_ << "  Procesadores: " << procesadores_
              << "  CapacidadTotal: " << capacidadTotal_ << "\n";
    std::cout << "Alcance Terreno: " << alcanceTerrenoKm_ << " km\n";
    std::cout << "Sensores (" << sensores_.size() << "):\n";
    for (size_t i = 0; i < sensores_.size(); ++i) {
        const Sensor* s = sensores_[i];
        if (!s) continue;
        std::cout << "  - [" << i << "] Tipo: " << s->getTipo()
                  << " | Sensibilidad: " << s->getSensibilidad() << "\n";
    }
    std::cout << "Promedio sensibilidad: " << promedioSensibilidad() << "\n";
    std::cout << "Sensor mas comun: " << sensorMasComun() << "\n";
}

bool RobotExplorador::necesitaMantenimiento() const {
    // True si al menos 2 sensores con sensibilidad < 30
    int bajos = 0;
    for (const Sensor* s : sensores_) if (s && s->getSensibilidad() < 30) ++bajos;
    return bajos >= 2;
}
