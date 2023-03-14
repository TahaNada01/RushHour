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
    
    // Lecture de la position de la sortie
    int sor_lignes, sor_colonnes;
    fichier >> sor_lignes >> sor_colonnes;
    m_sortie = {sor_lignes, sor_colonnes};
    cout << "The pair m_sortie is: ( " << m_sortie.first << " " << m_sortie.second << " )." << endl;
  
    // Initialisation de la grille avec des points
    m_grille.resize(6, std::vector<char>(6, '.'));

    // // Lecture et ajout des véhicules à la grille
    //int nb_vehicules = 13;
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
        //std::cout << std::endl;         
        // cout << v1.getLigne() << endl;
        // cout << v1.getColonne() << endl;
        i++;
        
    }

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

/*
  auto : permet au compilateur de déterminer automatiquement
  le type de la variable 'vehicle' ici c'est de type std::vector<int>
  & est utilisé pour déclarer une référence à un objet existant
  const :  l'objet pointé ne peut pas être modifié par cette référence.
*/
std::pair<int, int> Grille::getVehicleBleu() const {
    for (int i = 0; i < m_vehicles.size(); ++i) {
        //Récupérer une référence constante vers l'élément i du vecteur m_vehicles, ce qui permet ensuite d'accéder aux valeurs de cet élément en utilisant la variable vehicle.
        const auto& vehicle = m_vehicles[i];
        if (vehicle[2] == 1 && vehicle[3] == 2) {
            // Le véhicule est horizontal et a une longueur de 2.
            std::cout << "Position du véhicule bleu : (" << vehicle[0] << ", " << vehicle[1] << ")" << std::endl;
            return {vehicle[0], vehicle[1]};
        }
    }
    // Si le véhicule rouge n'a pas été trouvé, on retourne un pair (-1, -1).
    return {-1, -1};
}

std::vector<Grille> Grille::getNeighbors() const{
    std::vector<Grille> voisins;

    for(int i=0;i< m_vehicles.size();++i){
        const auto& vehicle = m_vehicles[i];
        /*int ligne = vehicle[0];
        int colonne = vehicle[1];
        int longueur = vehicle[2];
        bool direction = vehicle[3];*/

        //création de la nouvelle grille
        Grille voisins (*this);
        
        //deplacer le véhicule horizantalement a gauche ou à droite 
        if(Horizantale == 0){
            if(colonne > 0 && voisins.m_grille[ligne][colonne - 1] = '.'){

            }
            if(colonne > 0 && voisins.m_grille[ligne][colonne + 1] = '.'){

            }

        }

    }

    

    



};


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