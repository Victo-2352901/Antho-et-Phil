#include "RessourceLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Charger les données depuis un fichier CSV
vector<Donnee> chargerDonnees(const string& fichier) {
    vector<Donnee> donnees;
    ifstream file(fichier);

    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir le fichier " << fichier << endl;
        return donnees;
    }

    string ligne;
    while (getline(file, ligne)) {
        Donnee instance;
        stringstream ss(ligne);
        string valeur;

        if (getline(ss, valeur, ',')) instance.aciditeFixe = stod(valeur);
        if (getline(ss, valeur, ',')) instance.aciditeVolatile = stod(valeur);
        if (getline(ss, valeur, ',')) instance.aciditeCitrique = stod(valeur);
        if (getline(ss, valeur, ',')) instance.sucreResiduel = stod(valeur);
        if (getline(ss, valeur, ',')) instance.chlorure = stod(valeur);
        if (getline(ss, valeur, ',')) instance.dioxydeSoufreLibre = stod(valeur);
        if (getline(ss, valeur, ',')) instance.dioxydeSoufreTotal = stod(valeur);
        if (getline(ss, valeur, ',')) instance.densite = stod(valeur);
        if (getline(ss, valeur, ',')) instance.pH = stod(valeur);
        if (getline(ss, valeur, ',')) instance.sulfate = stod(valeur);
        if (getline(ss, valeur, ',')) instance.alcool = stod(valeur);

        donnees.push_back(instance);
    }

    file.close();
    return donnees;
}

// Retourne k % des données pour l'entraînement
vector<Donnee> getTrainData(const vector<Donnee>& donnees, double k) {
    vector<Donnee> trainData;
    int trainSize = donnees.size() * k;

    for (int i = 0; i < trainSize; i++) {
        trainData.push_back(donnees[i]);
    }

    return trainData;
}

// Retourne (1 - k) % des données pour le test
vector<Donnee> getTestData(const vector<Donnee>& donnees, double k) {
    vector<Donnee> testData;
    int trainSize = donnees.size() * k;

    for (int i = trainSize; i < donnees.size(); i++) {
        testData.push_back(donnees[i]);
    }

    return testData;
}

// Affiche les données
void afficherDonnees(const vector<Donnee>& donnees) {
    for (int i = 0; i < donnees.size(); i++) {
        cout << "Acidité Fixe: " << donnees[i].aciditeFixe << ", "
            << "Acidité Volatile: " << donnees[i].aciditeVolatile << ", "
            << "Alcool: " << donnees[i].alcool << endl;
    }
}
