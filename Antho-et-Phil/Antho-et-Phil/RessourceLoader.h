#pragma once
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <vector>
#include <string>

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

class ResourceLoader {
private:
    std::vector<Donnee> data;

public:
    ResourceLoader(const std::string& fichier);
    void afficherDonnees() const;
};

#endif // RESOURCELOADER_H


