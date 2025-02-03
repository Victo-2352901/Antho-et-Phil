#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "RessourceLoader.h"

using namespace std;

// Constructeur de ResourceLoader qui charge les données depuis un fichier CSV
ResourceLoader::ResourceLoader(const string& fichier) {
    ifstream file(fichier);
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier " + fichier);
    }

    string ligne;
    while (getline(file, ligne)) {
        Donnee instance;
        stringstream ss(ligne);
        string valeur;

        // Lecture et conversion des valeurs séparées par des virgules
        getline(ss, valeur, ',');
        instance.aciditeFixe = stod(valeur);

        getline(ss, valeur, ',');
        instance.aciditeVolatile = stod(valeur);

        getline(ss, valeur, ',');
        instance.aciditeCitrique = stod(valeur);

        getline(ss, valeur, ',');
        instance.sucreResiduel = stod(valeur);

        getline(ss, valeur, ',');
        instance.chlorure = stod(valeur);

        getline(ss, valeur, ',');
        instance.dioxydeSoufreLibre = stod(valeur);

        getline(ss, valeur, ',');
        instance.dioxydeSoufreTotal = stod(valeur);

        getline(ss, valeur, ',');
        instance.densite = stod(valeur);

        getline(ss, valeur, ',');
        instance.pH = stod(valeur);

        getline(ss, valeur, ',');
        instance.sulfate = stod(valeur);

        getline(ss, valeur, ',');
        instance.alcool = stod(valeur);

        // Ajout de l'instance au vecteur de données
        data.push_back(instance);
    }
    file.close();
}

// Fonction pour afficher les données chargées dans la console
void ResourceLoader::afficherDonnees()  {
    for (const auto& instance : data) {
        cout << "Acidité Fixe: " << instance.aciditeFixe << ", "
            << "Acidité Volatile: " << instance.aciditeVolatile << ", "
            << "Acidité Citrique: " << instance.aciditeCitrique << ", "
            << "Sucre Résiduel: " << instance.sucreResiduel << ", "
            << "Chlorure: " << instance.chlorure << ", "
            << "Dioxyde de Soufre Libre: " << instance.dioxydeSoufreLibre << ", "
            << "Dioxyde de Soufre Total: " << instance.dioxydeSoufreTotal << ", "
            << "Densité: " << instance.densite << ", "
            << "pH: " << instance.pH << ", "
            << "Sulfate: " << instance.sulfate << ", "
            << "Alcool: " << instance.alcool << "\n";
    }
}