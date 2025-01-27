#include "ResourceLoader.h"
#include <iostream>

using namespace std;

int main() {
    try {
        // Charger les données depuis un fichier CSV
        ResourceLoader loader("data.csv");
        loader.afficherDonnees();

    }
    catch (const exception& e) {
        cerr << "Erreur: " << e.what() << "\n";
    }

    return 0;
}
