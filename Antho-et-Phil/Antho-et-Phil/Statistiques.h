#pragma once

#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <vector>
using namespace std;

// Classe contenant des fonctions statistiques utiles
class Statistiques {
public:
    // Calcule la moyenne d'un ensemble de valeurs
    static double moyenne(const vector<double>& valeurs);

    // Calcule la médiane d'un ensemble de valeurs
    static double mediane(vector<double> valeurs);

    // Calcule l'écart-type d'un ensemble de valeurs
    static double ecartType(const vector<double>& valeurs);

    // Calcule la distance euclidienne entre deux points
    static double distanceEuclidienne(const vector<double>& point1, const vector<double>& point2);

    // Calcule la distance de Manhattan entre deux points
    static double distanceManhattan(const vector<double>& point1, const vector<double>& point2);
};

#endif // STATISTIQUES_H
