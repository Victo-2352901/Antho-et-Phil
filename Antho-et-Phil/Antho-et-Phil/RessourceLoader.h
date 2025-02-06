#pragma once
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <string>

// Structure repr�sentant une ligne de donn�es dans le fichier CSV
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

// Structure pour la liste cha�n�e
struct Node {
    Donnee data;
    Node* next;
    Node(const Donnee& d) : data(d), next(nullptr) {}
};

class ResourceLoader {
private:
    Node* head;  // Pointeur vers le premier �l�ment de la liste cha�n�e

public:
    // Constructeur prenant un fichier CSV en entr�e
    ResourceLoader(const std::string& fichier);

    // Destructeur pour lib�rer la m�moire
    ~ResourceLoader();

    // Afficher toutes les donn�es charg�es
    void afficherDonnees();

    // Retourner l'ensemble des donn�es sous forme cha�n�e (train data)
    Node* getTrainDataLinked();

    // Retourner un sous-ensemble des donn�es pour les tests
    Node* getTestDataLinked();
};

#endif // RESOURCELOADER_H
