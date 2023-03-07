#include "vehicule.hpp"



//constructeur
Vehicule::Vehicule(int ligne,int colonne,int longueur,bool direction){

    this->ligne = ligne;
    this->colonne = colonne;
    this->longueur = longueur;
    this->direction = direction;
}

//getters

int Vehicule::getLigne() const{
    return ligne;
}

int Vehicule::getColonne() const{
    return colonne;
}

int Vehicule::getLongueur() const{
    return longueur;
}

bool Vehicule::Horizantale() const{
    return direction;
}