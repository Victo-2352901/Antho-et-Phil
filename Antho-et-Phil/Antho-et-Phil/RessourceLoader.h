#pragma once
#include <vector>
#include <string>

// Structure représentant une ligne de données
struct Donnee {
    double aciditeFixe;
    double aciditeVolatile;
    double aciditeCitrique;
    double sucreResiduel;
    double chlorure;
    double dioxydeSoufreLibre;
    double dioxydeSoufreTotal;
    double densite;
    double pH;
    double sulfate;
    double alcool;
};

// Fonction pour charger les données depuis un fichier CSV
std::vector<Donnee> chargerDonnees(const std::string& fichier);

// Fonction pour récupérer k % des données pour l'entraînement
std::vector<Donnee> getTrainData(const std::vector<Donnee>& donnees, double k);

// Fonction pour récupérer (1 - k) % des données pour le test
std::vector<Donnee> getTestData(const std::vector<Donnee>& donnees, double k);

// Fonction pour afficher les données
void afficherDonnees(const std::vector<Donnee>& donnees);
