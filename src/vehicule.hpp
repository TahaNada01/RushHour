#ifndef LIFAP6_VEHICULE_HPP
#define LIFAP6_VEHICULE_HPP


class Vehicule {
    public:
    /* constructeur , destructeur*/
    Vehicule();
    ~Vehicule();
     
    /*Positioner les véhicule dans la grille*/
    void position(int ligne,int colonne,int longueur,);

    /*Définir la longueur de la case*/
    int longueur;

    /*déterminer la direction du véhicule horizontal (1) ou vertical (0)*/

    enum direction {
        horizantal = 1,
        verticale = 0
    };



     

    private:

};
#endif