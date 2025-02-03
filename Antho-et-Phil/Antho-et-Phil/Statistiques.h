#pragma once

#ifndef STATISTIQUES_H
#define STATISTIQUES_H


#include <vector>

class Statistiques {
public:
    static double moyenne(const std::vector<double>& valeurs);
    static double mediane(std::vector<double> valeurs);
    static double ecartType(const std::vector<double>& valeurs);
    static double distanceEuclidienne(const std::vector<double>& point1, const std::vector<double>& point2);
    static double distanceManhattan(const std::vector<double>& point1, const std::vector<double>& point2);
};

#endif // STATISTIQUES_H

using namespace std;
class Statistiques
{
private:
	
public:
	double moyenne(double[]);
	double mediane(double[]);
	double ecartType(double[]);

	double distanceEucli(double[]);
	double distanceMan(double[]);
};	


