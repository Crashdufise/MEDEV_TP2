#include <iostream>
#include <string>
#include <fstream>
#include "Lecture_Ecriture.h"

void image::ecriture(string nomFichier) {

}

image::image(string nomFichier) {
    ifstream fichier(nomFichier, ios::in);

    if(fichier) { // n'entre que si l'ouverture a r�ussi

        string ligne;

        nomImage = nomFichier;

        //compter les lignes
        int nb_lignes = 0;
        while(!fichier.eof()){
            getline(fichier,ligne);
            nb_lignes++;
            fichier.close();
        }
        ifstream fichier(nomFichier, ios::in);

        getline(fichier, ligne);
        entete = ligne;
        // on a rentr� le "P2" normalement

        getline(fichier, ligne);
        commentaire = ligne;
        // on a rentr� le commentaire normalement

        hauteur = nb_lignes - 2;
        largeur = (strlen(ligne) + 1)/2;

        for(int i = 2; i < hauteur + 2; i++) {
            getline(fichier, ligne);
            for(int j = 0; j < largeur; j++) {
                contenu[i][j] = ligne[j*2];
            }
        }
        // euh... �a marche �a ?
    }
}

vector<vector<int>> getContenu() {

}

void image::setValeurXY(int x, int y, int _valeur) {
    contenu[y][2*x]=_valeur;
}

void image::histogramme() {

}