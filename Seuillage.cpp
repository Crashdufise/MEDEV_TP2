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
	image resultat = image(imagePGM.getNom() + "seuillée", "Image" + imagePGM.getNom() + "seuillée", hauteur, largeur, tabPGM);
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
			tabPGM[i].push_back(tabPGM1[i][j]-tabPGM2[i][j]));
		}
	}
	image resultat = image("Difference", "Différence entre les images suivantes : " + imagePGM1.getNom() + "\t" + imagePGM2.getNom(), hauteur, largeur, tabPGM);
	resultat.ecriture();
}


void aggrandir(string filepath) {

	image imagePGM = image(filepath);
	int hauteur = 2*imagePGM.getHauteur();
	int largeur = 2 * imagePGM.getLargeur();
	std::vector<std::vector<int>> tabPGM = imagePGM.getContenu();
	std::vector<std::vector<int>> newtab;
	newtab.resize(hauteur);


	image imageAggrandie = image(imagePGM.getNom()+" x2", "Image Aggrandie :"+imagePGM.getCommentaire(), hauteur, largeur, newtab);
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			imageAggrandie.contenuPushBack(i, tabPGM[i/2][j/2]);
		}
	}
	imageAggrandie.ecriture();
}

void reduction(string filepath) {
	image imagePGM = image(filepath);
	int hauteur = imagePGM.getHauteur()/2;
	int largeur = imagePGM.getLargeur()/2;
	std::vector<std::vector<int> > tabPGM = imagePGM.getContenu();
	image imageRetrecie = image(imagePGM.getNom()+" /2", "Image Retrecie :"+imagePGM.getCommentaire(), hauteur, largeur, tabPGM);
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			imageRetrecie.setValeurXY(i, j, tabPGM[i*2][j*2]);
		}
	}
	imageRetrecie.ecriture();
}
