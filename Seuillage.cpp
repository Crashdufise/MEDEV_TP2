// TP2MEDEV.cpp : Définit le point d'entrée pour l'application console.
//

#include <iostream>
#include <vector>
#include "Lecture_Ecriture.h"
using namespace std;


image seuillage(string filepath, int seuil) {

	image imagePGM = lecture(filepath);
	int hauteur = imagePGM.getHauteur();
	int largeur = imagePGM.getLargeur();
	vector<vector<int>> tabPGM = imagePGM.getContenu();
	for (int i = 0; i < hauteur; i++) {
		for (int j = 0; j < largeur; j++) {
			if (tabPGM[i][j] < seuil) {
				imagePGM.setValeurXY(i,j,0);
			}
			else {
				imagePGM.setValeurXY(i,j,255);
			}
		}
	}
}

imag difference(string filepath1, string filepath2) {
	image imagePGM1 = lecture(filepath1);
	image imagePGM2 = lecture(filepath2);
	int hauteur = min(imagePGM1.getHauteur(), imagePGM2.getHauteur());
	int largeur = min(imagePGM1.getLargeur(), imagePGM2.getLargeur());
	std::vector<std::vector<int>> tabPGM = imagePGM.getContenu();
	for (int i = 0; i< hauteur ; i++) {
		for (int j = 0 ; j< largeur ; j++) {
			imagePGM1.setValeurXY(i,j,)
		}
	}

}
