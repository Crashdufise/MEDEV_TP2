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
        // on a rentré le "P2" normalement

        getline(fichier, ligne);
        commentaire = ligne;
        // on a rentré le commentaire normalement

        for(int i = 2; i < nb_lignes; i++) {
            getline(fichier, ligne);
        }
    }
}

vector<vector<int>> getContenu() {

}

void image::setValeurXY(int x, int y, int _valeur) {
    contenu[y][2*x]=_valeur;
}
