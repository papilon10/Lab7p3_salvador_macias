#pragma once
#include <vector>
#include <type_traits>
#include <numeric>

using namespace std;

template <typename T>
inline double calcularPromedio(const std::vector<T>& datos) {
    static_assert(std::is_arithmetic<T>::value, "calcularPromedio requiere tipo numerico");
    if (datos.empty()) return 0.0;
    long double suma = std::accumulate(datos.begin(), datos.end(), static_cast<long double>(0));
    return static_cast<double>(suma / datos.size());
}
