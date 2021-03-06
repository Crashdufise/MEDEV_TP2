#include <iostream>
#include <string>
#include <fstream>
#pragma once

#include <vector>

using namespace std;
class image {
private:
	string nomImage;
    string entete;
    string commentaire;
    int maxVal;
    int hauteur;
    int largeur;
    vector<vector<int>> contenu;// creer tableau de valeurs ici

public:
    void ecriture();
    vector<vector<int>> getContenu();
	int getHauteur() { return hauteur; }
	int getLargeur() { return largeur; }
	string getNom() { return nomImage; }
	string getCommentaire() { return commentaire; }
	void contenuPushBack(int i, int ajout) { contenu[i].push_back(ajout);	 }
    void setValeurXY(int x, int y, int _valeur);
	image histogramme();
	image(string nomFichier);
	image(string nomImage, string commentaire, int hauteur, int largeur, vector<vector<int>> contenu);
};
