#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "RessourceLoader.h"

using namespace std;

// Constructeur de ResourceLoader qui charge les donn�es depuis un fichier CSV
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

        // Lecture et conversion des valeurs s�par�es par des virgules
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

        // Ajout de l'instance au vecteur de donn�es
        data.push_back(instance);
    }
    file.close();
}

// Fonction pour afficher les donn�es charg�es dans la console
void ResourceLoader::afficherDonnees()  {
    for (const auto& instance : data) {
        cout << "Acidit� Fixe: " << instance.aciditeFixe << ", "
            << "Acidit� Volatile: " << instance.aciditeVolatile << ", "
            << "Acidit� Citrique: " << instance.aciditeCitrique << ", "
            << "Sucre R�siduel: " << instance.sucreResiduel << ", "
            << "Chlorure: " << instance.chlorure << ", "
            << "Dioxyde de Soufre Libre: " << instance.dioxydeSoufreLibre << ", "
            << "Dioxyde de Soufre Total: " << instance.dioxydeSoufreTotal << ", "
            << "Densit�: " << instance.densite << ", "
            << "pH: " << instance.pH << ", "
            << "Sulfate: " << instance.sulfate << ", "
            << "Alcool: " << instance.alcool << "\n";
    }
}