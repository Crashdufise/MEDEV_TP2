#include <iostream>
#include <string>
#include <fstream>
#pragma once

using namespace std;
class image {
private:
    string entete = "P2";
    string commentaire;
    int maxVal = 255;
    int hauteur;
    int largeur;
    vector<vector<int>> contenu;// creer tableau de valeurs ici
public:
    void lecture(string nomFichier);
    void ecriture(string nomFichier);
    vector<vector<int>> getContenu();
    void setValeurXY(int x, int y, int _valeur)
};
