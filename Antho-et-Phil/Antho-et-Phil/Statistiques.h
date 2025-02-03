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
	double Moyenne(double[]);
	double Mediane(double[]);
	double EcartType(double[]);

	double DistanceEucli(double[]);
	double DistanceMan(double[]);
};	


