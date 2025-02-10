#pragma once
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <string>

//#pragma once : Empêche l’inclusion multiple du fichier (alternative à #ifndef ... #define ...).
// #ifndef RESOURCELOADER_H / #define RESOURCELOADER_H : Définit une protection d’inclusion multiple.
// Structure représentant une ligne de données dans le fichier CSV
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

// Structure pour la liste chaînée
//Structure Node : Un élément d’une liste chaînée qui contient une Donnee et un pointeur vers le prochain élément (next).
//Node(const Donnee& d) : data(d), next(nullptr) {} → Initialise un nœud avec des données et met next à nullptr.

struct Node {
    Donnee data;
    Node* next;
    Node(const Donnee& d) : data(d), next(nullptr) {}
};

class ResourceLoader {
private:
    Node* head;  // Pointeur vers le premier élément de la liste chaînée
                //head: Pointeur vers le premier élément de la liste chaînée.
public:
    // Constructeur prenant un fichier CSV en entrée
    ResourceLoader(const std::string& fichier);

    // Destructeur pour libérer la mémoire
    ~ResourceLoader();

    // Afficher toutes les données chargées
    void afficherDonnees();

    // Retourner l'ensemble des données sous forme chaînée (train data)
    Node* getTrainDataLinked();

    // Retourner un sous-ensemble des données pour les tests
    Node* getTestDataLinked();
};

#endif // RESOURCELOADER_H
