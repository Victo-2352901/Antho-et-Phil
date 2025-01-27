
#include "Statistiques.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

double Statistiques::moyenne(const std::vector<double>& valeurs) {
    double somme = 0;
    for (double v : valeurs) {
        somme += v;
    }
    return somme / valeurs.size();
}

double Statistiques::mediane(std::vector<double> valeurs) {
    std::sort(valeurs.begin(), valeurs.end());
    size_t taille = valeurs.size();
    if (taille % 2 == 0) {
        return (valeurs[taille / 2 - 1] + valeurs[taille / 2]) / 2.0;
    }
    else {
        return valeurs[taille / 2];
    }
}

double Statistiques::ecartType(const std::vector<double>& valeurs) {
    double moy = moyenne(valeurs);
    double somme = 0;
    for (double v : valeurs) {
        somme += (v - moy) * (v - moy);
    }
    return std::sqrt(somme / valeurs.size());
}

double Statistiques::distanceEuclidienne(const std::vector<double>& point1, const std::vector<double>& point2) {
    if (point1.size() != point2.size()) {
        throw std::invalid_argument("Les points doivent avoir le même nombre de dimensions");
    }
    double somme = 0;
    for (size_t i = 0; i < point1.size(); ++i) {
        somme += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return std::sqrt(somme);
}

double Statistiques::distanceManhattan(const std::vector<double>& point1, const std::vector<double>& point2) {
    if (point1.size() != point2.size()) {
        throw std::invalid_argument("Les points doivent avoir le même nombre de dimensions");
    }
    double somme = 0;
    for (size_t i = 0; i < point1.size(); ++i) {
        somme += std::abs(point1[i] - point2[i]);
    }
    return somme;
}
