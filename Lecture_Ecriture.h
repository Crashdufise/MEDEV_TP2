#include <iostream>
#include <string>
#include <fstream>
#pragma once

using namespace std;
class image {
private:
	string nomImage;
    string entete = "P2";
    string commentaire;
    int maxVal = 255;
    int hauteur;
    int largeur;
    vector<vector<int>> contenu;// creer tableau de valeurs ici

public:
    void ecriture();
    vector<vector<int>> getContenu();
    void setValeurXY(int x, int y, int _valeur);
	void histogramme();
	image(string nomFichier);
	image(string nomImage, string commentaire, int hauteur, int largeur, vector<vector<int>> contenu);
};
