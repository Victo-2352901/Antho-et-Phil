#include <iostream>
#include "RessourceLoader.h"

using namespace std;

int main() {
    try {
        // Charger les données depuis un fichier CSV
        ResourceLoader loader("data.csv");
        loader.afficherDonnees(); // Afficher les données chargées
    }
    catch (const exception& e) {
        // Capture et affichage des erreurs en cas de problème avec le fichier
        cerr << "Erreur: " << e.what() << "\n";
    }

    return 0;
}