#ifndef LIFAP6_GRILLE_HPP
#define LIFAP6_GRILLE_HPP

#include "vehicule.hpp"
#include <vector>
#include <string>


/*
  Le fichier Grille va gérer la grille de jeu, qui est représentée par une matrice de caractères (m_grille). Cette grille contient les informations sur l'emplacement de tous les véhicules ainsi que la sortie .

La classe Grille va offrir des méthodes pour initialiser la grille à partir des informations de jeu fournies dans le fichier d'entrée, pour mettre à jour la grille après chaque déplacement de véhicule et pour récupérer les informations sur la grille (par exemple, la position de la sortie, l'emplacement de tous les véhicules, etc.) pour pouvoir créer et explorer le graphe de jeu.

En somme, la classe Grid sera au centre du traitement de la grille de jeu pour la résolution du problème Rush Hour.
*/
class Grille {

    private:
      /*
      La variable m_grille est une matrice de caractères représentant la grille du jeu. Elle est déclarée sous la forme d'un vecteur de vecteurs, où chaque vecteur représente une ligne de la grille.
      Les caractères sont utilisés pour représenter les cases de la grille et les véhicules.
      Par exemple, le caractère '.' peut représenter une case vide, 'H' peut représenter un véhicule horizontal et 'V' peut représenter un véhicule vertical.
      */
      std::vector<std::vector<char>> m_grille;// Grille sous forme d'un vecteur de vecteurs de caractères.
      std::vector<std::vector<int>> m_vehicles;// Vecteur des véhicules sous forme de vecteurs d'entiers.
      std::pair<int, int> m_sortie;// Coordonnées de la sortie de la grille sous forme d'une paire d'entiers.


    public:
      // Constructeur de la grille prenant un nom de fichier en paramètre.
      Grille(const std::string& filename);

      // Fonction pour afficher la grille.
      void print() const;

      // Fonction pour obtenir le contenu de la case de coordonnées (x,y) de la grille.
      char get(int x, int y) const;

      // Fonction pour modifier le contenu de la case de coordonnées (x,y) de la grille.
      void set(int x, int y, char c);

      // Fonction pour obtenir les coordonnées de la sortie de la grille.
      std::pair<int, int> getSortie() const;

      // Fonction pour obtenir les informations sur les véhicules de la grille.
      std::vector<std::vector<int>> getVehicles() const;

      // Fonction pour obtenir les grilles voisines de la grille courante.
      std::vector<Grille> getNeighbors() const;




};
#endif