#include <iostream>
#include <string>
#include <fstream>
#include "Lecture_Ecriture.h"

void image::ecriture(string nomFichier) {

}

image::image(string nomFichier) {
    ifstream fichier(nomFichier, ios::in);

    if(fichier) { // n'entre que si l'ouverture a réussi

        string ligne;

        nomImage = nomFichier;

        //compter les lignes
        int nb_lignes = 0;

        getline(fichier, ligne);
        entete = ligne;
        // on a rentré le "P2" normalement

        getline(fichier, ligne);
        commentaire = ligne;
        // on a rentré le commentaire normalement

        getline(fichier, ligne, ' ');
        hauteur = ligne;
        getline(fichier, ligne);
        largeur = ligne;

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

void image::histogramme() {

}
