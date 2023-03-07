#ifndef LIFAP6_VEHICULE_HPP
#define LIFAP6_VEHICULE_HPP

#include <string>

class Vehicule {

    private:
     int ligne;
     int colonne;
     int longueur;
     bool direction;

    public:
      //constructeur ,destructeur
       Vehicule(int ligne,int colonne,int longueur,bool direction);
       //~Vehicule();

     //Getters
       int getLigne() const;
       int getColonne() const;
       int getLongueur() const;
       bool Horizantale() const;

};
#endif

