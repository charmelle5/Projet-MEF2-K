#ifndef VARIANTE_H
    #define VARIANTE_H
    #include"Creation_chenil.h"
    
        // Structure pour stocker les temps de nettoyage
        typedef struct {
        int temps_quotidien;
        int temps_hebdomadaire;
        } TempsNettoyage;

    //Protocoles pour les variantes
    TempsNettoyage temps_nettoyage();
    TempsNettoyage temps_nettoyage(Type espece);
    void affiche_temps_nettoyage(Animal* chenil, int taille);
    void afficher_inventaire_chenil(Animal* chenil, int taille);

#endif
