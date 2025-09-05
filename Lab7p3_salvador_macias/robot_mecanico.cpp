#include "robot_mecanico.h"
#include <random>
#include <iostream>
#include <algorithm>

static inline int clampM(int v, int lo, int hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

RobotMecanico::RobotMecanico(const std::string& nombre,
                             int bateria,
                             int procesadores,
                             int potenciaInicial)
    : Robot(nombre, bateria, procesadores),
      potenciaHerramientas_(clampM(potenciaInicial, 0, 100)) {}

void RobotMecanico::agregarHerramienta(const std::string& h) {
    herramientas_.push_back(h);
}

bool RobotMecanico::suerteFallo10() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.10);
    return d(gen);
}

int RobotMecanico::randomEnRango(int lo, int hi) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(lo, hi);
    return dist(gen);
}

void RobotMecanico::optimizar() {

    long double nueva = static_cast<long double>(potenciaHerramientas_) * 1.10L;
    potenciaHerramientas_ = clampM(static_cast<int>(std::lround(nueva)), 0, 100);

    if (herramientas_.size() < 5) {
        herramientas_.push_back("Herramienta_" + std::to_string(herramientas_.size() + 1));
    }

    if (suerteFallo10() && !herramientas_.empty()) {
        int idx = randomEnRango(0, static_cast<int>(herramientas_.size()) - 1);
        std::cout << "[FALLO] " << nombre_ << " perdio la herramienta: "
                  << herramientas_[static_cast<size_t>(idx)] << "\n";
        herramientas_.erase(herramientas_.begin() + idx);
    }
}

/*double RobotMecanico::promedioLongitudesHerramientas() const {
    std::vector<int> lens;
    lens.reserve(herramientas_.size());
    for (const auto& h : herramientas_) lens.push_back(static_cast<int>(h.size()));
    return calcularPromedio<int>(lens);
}*/

void RobotMecanico::mostrarEspecificaciones() const {
    std::cout << "=== Robot Mecanico: " << nombre_ << " ===\n";
    std::cout << "Bateria: " << bateria_ << "  Procesadores: " << procesadores_
              << "  CapacidadTotal: " << capacidadTotal_ << "\n";
    std::cout << "Potencia herramientas: " << potenciaHerramientas_ << "\n";
    std::cout << "Herramientas (" << herramientas_.size() << "):\n";
    for (size_t i = 0; i < herramientas_.size(); ++i) {
        std::cout << "  - [" << i << "] " << herramientas_[i] << "\n";
    }
    std::cout << "Longitud promedio de nombres de herramientas: "
              << promedioLongitudesHerramientas() << "\n";
}

bool RobotMecanico::sobrecargado() const {

    return (potenciaHerramientas_ > 90) && (herramientas_.size() > 3);
}
