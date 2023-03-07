#include "grille.hpp"
#include "vehicule.hpp"
#include <fstream>
#include <iostream>
using namespace std;
Grille::Grille(const std::string& filename) {
    // Ouverture du fichier en lecture
    std::ifstream fichier(filename);
    if (!fichier) {
        // Si l'ouverture du fichier échoue, on affiche une erreur et on quitte le programme
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // Lecture de la taille de la grille
    int sor_lignes, sor_colonnes;
    fichier >> sor_lignes >> sor_colonnes;
    m_sortie = {sor_lignes, sor_colonnes};
    cout << "The pair p2 is: ( " << m_sortie.first << " " << m_sortie.second << " )." << endl;
    
    // std::cout<<sor_lignes<< std ::endl;
    // std::cout<<sor_colonnes<< std ::endl;
    
    // Initialisation de la grille avec des points
    m_grille.resize(6, std::vector<char>(6, '.'));
    // std::cout<<sor_colonnes<< std ::endl;
    // std::cout<<sor_colonnes<< std ::endl;

    // // Lecture et ajout des véhicules à la grille
    int nb_vehicules = 13;
    int i=0;
    // std::cout << nb_vehicules << std::endl;
    while(true){
        int ligne, colonne, longueur;
        bool direction;
        fichier >> ligne >> colonne >> longueur >> direction;
    
        if(fichier.fail()) {
            break ;
        }
        // cout << i << endl;
        // cout<< ligne << endl;
        // cout<< colonne << endl;
        // cout<< longueur << endl;
        // cout<< direction << endl;
        // cout << endl;
        Vehicule v1(ligne, colonne, longueur, direction);
        m_vehicles.push_back({ligne, colonne, longueur, (int)direction});          
        // cout << v1.getLigne() << endl;
        // cout << v1.getColonne() << endl;
        i++;
        
    }

    // for (int i = 0; i < nb_vehicules; i++) {
    //     int ligne, colonne, longueur;
    //     bool direction;
    //     fichier >> ligne >> colonne >> longueur >> direction;
    //     Vehicule vehicule(ligne, colonne, longueur, direction);
    //     if (direction) {
    //         // Si la direction est horizontale, on ajoute le véhicule de gauche à droite
    //         for (int j = colonne; j < colonne + longueur; j++) {
    //             m_grille[ligne][j] = 'H';
    //         }
    //     } else {
    //         // Si la direction est verticale, on ajoute le véhicule de haut en bas
    //         for (int j = ligne; j < ligne + longueur; j++) {
    //             m_grille[j][colonne] = 'V';
    //         }
    //     }
    //     // Ajout du véhicule à la liste des véhicules de la grille
    //     m_vehicles.push_back({ligne, colonne, longueur, (int)direction});
    // }

    // // Lecture de la position de la sortie
    // int sortie_x, sortie_y;
    // fichier >> sortie_x >> sortie_y;
    // m_sortie = {sortie_x, sortie_y};

    // Fermeture du fichier
    fichier.close();
}

void Grille::print() const
{
    for (int i = 0; i < m_grille.size(); i++) {
        for (int j = 0; j < m_grille[i].size(); j++) {
            std::cout << m_grille[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

char Grille::get(int x,int y) const {
    return m_grille[x][y];
}

void Grille::set(int x,int y,char c){
    m_grille[x][y];
}

std::pair<int, int> Grille::getSortie() const{
    return m_sortie;
}

//On utilise un vecteur de vecteurs car chaque véhicule est représenté par un vecteur d'entiers, et la liste de tous les véhicules est elle-même représentée par un vecteur de ces vecteurs
std::vector<std::vector<int>> Grille::getVehicles() const
{
    return m_vehicles;
}