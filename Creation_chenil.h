#ifndef CREATION_CHENIL_H
    #define CREATION_CHENIL_H

        #include<stdio.h>
        #include <stdlib.h>
        #include <string.h>

        #define MAXCHAR 50
        #define MAXCOM 200
        #define MAX_ANIMAUX 50


        typedef enum{
        CHIEN=1, CHAT, HAMSTER, AUTRUCHE, LAPIN, POISSON
        }Type;

        typedef struct{
        int num;
        char nom[MAXCHAR];
        Type espece;
        float poids;
        int annee;
        char commentaire[MAXCOM];
        }Animal;

        // Prototypes
        void vider_buffer();
        int numero_existe_deja(int num);
        Animal creation_animal();
        void afficher_animal(Animal a);
        int sauvegarder_chenil(Animal* chenil, int taille);
        void charger_chenil(Animal** chenil, int* taille);
        
#endif


