// TP2MEDEV.cpp : Définit le point d'entrée pour l'application console.
//

#include <iostream>
#include <vector>
#include "Lecture_Ecriture.h"
using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}

void seuillage(string filepath, int seuil) {

	image imagePGM = image(filepath);
	int hauteur = imagePGM.getHauteur();
	int largeur = imagePGM.getLargeur();
	vector<vector<int>> tabPGM = imagePGM.getContenu();
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			if (tabPGM[i][j] < seuil) {
				tabPGM[i][j] = 0 ;
			}
			else {
				tabPGM[i][j] = 255 ;
			}
		}
	}
	// Faudrait un accesseur pour le nom de l'image plz
	image resultat = image(imagePGM.getNom(), "Image" + imagePGM.getNom() + "seuillée", hauteur, largeur, tabPGM);
	resultat.ecriture();
}

void difference(string filepath1, string filepath2) {
	image imagePGM1 = image(filepath1);
	image imagePGM2 = image(filepath2);
	int hauteur = min(imagePGM1.getHauteur(), imagePGM2.getHauteur());
	int largeur = min(imagePGM1.getLargeur(), imagePGM2.getLargeur());
	std::vector<std::vector<int>> tabPGM;
	std::vector<std::vector<int>> tabPGM1 = imagePGM1.getContenu();
	std::vector<std::vector<int>> tabPGM2 = imagePGM2.getContenu();
	for (int i = 0; i< hauteur ; i++) {
		for (int j = 0 ; j< largeur ; j++) {
			tabPGM[i][j].push_back(tabPGM1[i][j]-tabPGM2[i][j]));
		}
	}
}


void aggrandir(string filepath) {

	image imagePGM = image(filepath);
	int hauteur = 2*imagePGM.getHauteur();
	int largeur = 2 * imagePGM.getLargeur();
	std::vector<std::vector<int>> tabAggrandiPGM = imagePGM.getContenu();

	image imageAggrandie = image(imagePGM.getNom()+" x2", "Image Aggrandie :"+imagePGM.getCommentaire(), imagePGM.getHauteur(), imagePGM.getLargeur(), tabAggrandiPGM);
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			imagePGM.setValeurXY(i, j, tabAggrandiPGM[i/2][j/2]);
		}
	}
}