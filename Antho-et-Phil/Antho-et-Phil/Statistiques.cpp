#include "Statistiques.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

// Fonction pour calculer la moyenne d'un ensemble de valeurs
double Statistiques::moyenne(const vector<double>& valeurs) {
    double somme = 0;
    for (double v : valeurs) { // Somme de toutes les valeurs
        somme += v;
    }
    return somme / valeurs.size(); // Division par le nombre total d'�l�ments
}
// Fonction pour calculer la m�diane d'un ensemble de valeurs   
double Statistiques::mediane(vector<double> valeurs) {
    std::sort(valeurs.begin(), valeurs.end()); // Tri des valeurs dans l'ordre croissant
    size_t taille = valeurs.size();
    if (taille % 2 == 0) {
        // Si le nombre d'�l�ments est pair, on prend la moyenne des deux valeurs centrales
        return (valeurs[taille / 2 - 1] + valeurs[taille / 2]) / 2.0;
    }
    else {
        // Sinon, on retourne la valeur centrale
        return valeurs[taille / 2];
    }
}

// Fonction pour calculer l'�cart-type d'un ensemble de valeurs
double Statistiques::ecartType(const vector<double>& valeurs) {
    double moy = moyenne(valeurs); // Calcul de la moyenne
    double somme = 0;
    for (double v : valeurs) {
        somme += (v - moy) * (v - moy); // Somme des carr�s des �carts � la moyenne
    }
    return std::sqrt(somme / valeurs.size()); // Racine carr�e de la variance
}

// Fonction pour calculer la distance euclidienne entre deux points
double Statistiques::distanceEuclidienne(const vector<double>& point1, const vector<double>& point2) {
    if (point1.size() != point2.size()) {
        throw std::invalid_argument("Les points doivent avoir le m�me nombre de dimensions");
    }
    double somme = 0;
    for (size_t i = 0; i < point1.size(); i++) {
        somme += (point1[i] - point2[i]) * (point1[i] - point2[i]); // Somme des carr�s des diff�rences
    }
    return std::sqrt(somme); // Racine carr�e de la somme
}

// Fonction pour calculer la distance de Manhattan entre deux points
double Statistiques::distanceManhattan(const vector<double>& point1, const vector<double>& point2) {
    if (point1.size() != point2.size()) {
        throw std::invalid_argument("Les points doivent avoir le m�me nombre de dimensions");
    }
    double somme = 0;
    for (size_t i = 0; i < point1.size(); i++) {
        somme += std::abs(point1[i] - point2[i]); // Somme des valeurs absolues des diff�rences
    }
    return somme;
}