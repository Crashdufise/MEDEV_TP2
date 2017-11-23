// TP2MEDEV.cpp : Définit le point d'entrée pour l'application console.
//

#include <iostream>
#include <vector>


using namespace std;

class image;

image seuillage(string filepath, int seuil) {

	image imagePGM = lecture(filepath);
	int hauteur = imagePGM.getHauteur();
	int largeur = imagePGM.getLargeur();
	vector<vector<int>> tabPGM = imagePGM.getVect();
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			if (tabPGM[i][j] < seuil) {
				tabPGM[i][j] = 0;
			}
			else {
				tabPGM[i][j] = 255;
			}
		}
	}

}
