#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include "Lecture_Ecriture.h"

void image::ecriture() {
    ofstream outfile (nomImage);
    outfile << "P2" << endl << commentaire << endl << hauteur +" "+ largeur << endl;
    for(int i = 0; i < hauteur; i++) {
        for(int j = 0; j< largeur; j++) {
            outfile << contenu[i][j] + " ";
        }
        outfile << endl;
    }
}

image::image(string nomFichier) {
    ifstream fichier(nomFichier, ios::in);

    if(fichier) { // n'entre que si l'ouverture a réussi

        string ligne;

        nomImage = nomFichier;

        getline(fichier, ligne);
        entete = ligne;
        // on a rentré le "P2" normalement

        getline(fichier, ligne);
        commentaire = ligne;
        // on a rentré le commentaire normalement

        getline(fichier, ligne, ' ');
        hauteur = stoi (ligne);
        getline(fichier, ligne);
        largeur = stoi (ligne);

        for(int i = 0; i < hauteur; i++) {
            getline(fichier, ligne);
            for(int j = 0; j < largeur; j++) {
                contenu[i][j] = ligne[j*2];
            }
        }
        // euh... ça marche ça ?
    }
}

vector<vector<int>> getContenu() {
    return contenu;
}

void image::setValeurXY(int x, int y, int _valeur) {
    contenu[y][x]=_valeur;
}

image image::histogramme() {
	string nomImageHist = "Histogramme " + this.nomImage;
	string commentaireHist = "Histogramme de l'image " + this.nomImage;
	int hauteurHist = 100;
	int largeurHist = 256;
	vector<vector<int>> contenuHistogramme;
	for (int i=0; i<hauteurHist, i++) {
		vector<int> ligne;
		for (int j=0; j<largeurHist, j++) {
			ligne.push_back(255);
		}
		contenuHistogramme.push_back(ligne);
	}
	for (int k=0, k<largeurHist, k++) {
		int e;
	}
}
