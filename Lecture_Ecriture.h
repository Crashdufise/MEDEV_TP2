#include <iostream>
#include <string>
#include <fstream>
#pragma once

using namespace std;
class image {
private:
    string entete;
    string commentaire;
    int maxVal;
    int longueur;
    int largeur;
    // creer tableau de valeurs ici
public:
    void lecture(string Nom_Fichier);

};
