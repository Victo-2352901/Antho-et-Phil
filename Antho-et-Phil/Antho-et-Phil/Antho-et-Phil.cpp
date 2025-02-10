#include "RessourceLoader.h"
#include <iostream>

using namespace std;

int main() {
    string fichier = "binary-winequality-white.csv";  // Nom du fichier CSV
    vector<Donnee> donnees = chargerDonnees(fichier);

    if (donnees.size() == 0) {
        cout << "Aucune donnée chargée." << endl;
    }
    else {
        cout << "Toutes les données :" << endl;
        afficherDonnees(donnees);

        double k = 0.7;  // 70% pour l'entraînement, 30% pour le test
        vector<Donnee> trainData = getTrainData(donnees, k);
        vector<Donnee> testData = getTestData(donnees, k);

        cout << "\nDonnées d'entraînement :" << endl;
        afficherDonnees(trainData);

        cout << "\nDonnées de test :" << endl;
        afficherDonnees(testData);
    }

    return 0;
}
