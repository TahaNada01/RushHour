#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "grille.hpp"
#include "vehicule.hpp"

int main(){
    
    Grille grille("rush-hour-etu/Sujet/puzzle.txt");
    grille.print(); // Affiche la grille
    return 0;

}

// Création d'un véhicule
    /*Vehicule voiture(2, 3, 4, true);

    // Affichage des caractéristiques
    std::cout << "Ligne : " << voiture.getLigne() << std::endl;
    std::cout << "Colonne : " << voiture.getColonne() << std::endl;
    std::cout << "Longueur : " << voiture.getLongueur() << std::endl;
    std::cout << "Orientation horizontale : " << voiture.Horizantale() << std::endl;*/