#include "RessourceLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructeur de ResourceLoader
//Initialise head à nullptr (la liste chaînée est vide au début).
ResourceLoader::ResourceLoader(const string& fichier) : head(nullptr) {
    ifstream file(fichier);
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier " + fichier);
    }

    string ligne;
    Node* last = nullptr; // Pointeur vers le dernier élément inséré

    //stringstream ss(ligne); → Permet de découper la ligne en valeurs séparées par ,.
  //  getline(ss, valeur, ',') → Récupère chaque valeur et la convertit(stod()) en double.
    
    while (getline(file, ligne)) {
        Donnee instance;
        stringstream ss(ligne);
        string valeur;

        // Lire chaque valeur séparée par une virgule
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

        // Création du nouveau nœud
        Node* newNode = new Node(instance);

        // Insertion en fin de liste chaînée
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

// Destructeur pour libérer la mémoire allouée dynamiquement
ResourceLoader::~ResourceLoader() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Affichage des données de la liste chaînée
void ResourceLoader::afficherDonnees() {
    Node* current = head;
    while (current) {
        cout << "Acidité Fixe: " << current->data.aciditeFixe << ", "
            << "Acidité Volatile: " << current->data.aciditeVolatile << ", "
            << "Alcool: " << current->data.alcool << "\n";
        current = current->next;
    }
}

// Retourne l'ensemble des données sous forme chaînée
Node* ResourceLoader::getTrainDataLinked() {
    return head;
}

// Retourne un sous-ensemble des données comme test (moitié des données)
Node* ResourceLoader::getTestDataLinked() {
    if (!head) return nullptr;
}