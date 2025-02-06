#include "RessourceLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructeur de ResourceLoader
ResourceLoader::ResourceLoader(const string& fichier) : head(nullptr) {
    ifstream file(fichier);
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier " + fichier);
    }

    string ligne;
    Node* last = nullptr; // Pointeur vers le dernier �l�ment ins�r�

    while (getline(file, ligne)) {
        Donnee instance;
        stringstream ss(ligne);
        string valeur;

        // Lire chaque valeur s�par�e par une virgule
        getline(ss, valeur, ','); instance.aciditeFixe = stod(valeur);
        getline(ss, valeur, ','); instance.aciditeVolatile = stod(valeur);
        getline(ss, valeur, ','); instance.aciditeCitrique = stod(valeur);
        getline(ss, valeur, ','); instance.sucreResiduel = stod(valeur);
        getline(ss, valeur, ','); instance.chlorure = stod(valeur);
        getline(ss, valeur, ','); instance.dioxydeSoufreLibre = stod(valeur);
        getline(ss, valeur, ','); instance.dioxydeSoufreTotal = stod(valeur);
        getline(ss, valeur, ','); instance.densite = stod(valeur);
        getline(ss, valeur, ','); instance.pH = stod(valeur);
        getline(ss, valeur, ','); instance.sulfate = stod(valeur);
        getline(ss, valeur, ','); instance.alcool = stod(valeur);

        // Cr�ation du nouveau n�ud
        Node* newNode = new Node(instance);

        // Insertion en fin de liste cha�n�e
        if (!head) {
            head = newNode;
        }
        else {
            last->next = newNode;
        }
        last = newNode;
    }

    file.close();
}

// Destructeur pour lib�rer la m�moire allou�e dynamiquement
ResourceLoader::~ResourceLoader() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Affichage des donn�es de la liste cha�n�e
void ResourceLoader::afficherDonnees() {
    Node* current = head;
    while (current) {
        cout << "Acidit� Fixe: " << current->data.aciditeFixe << ", "
            << "Acidit� Volatile: " << current->data.aciditeVolatile << ", "
            << "Alcool: " << current->data.alcool << "\n";
        current = current->next;
    }
}

// Retourne l'ensemble des donn�es sous forme cha�n�e
Node* ResourceLoader::getTrainDataLinked() {
    return head;
}

// Retourne un sous-ensemble des donn�es comme test (moiti� des donn�es)
Node* ResourceLoader::getTestDataLinked() {
    if (!head) return nullptr;
}