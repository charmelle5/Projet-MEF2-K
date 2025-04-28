#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<Animal.h>

#define MAXCHAR 50
#define MAXCOM 200
#define MAX_ANIMAUX 50

int main() {
   
 Animal* chenil = NULL;
 int taille = 0;
 int choix=0
 
  // Charger les animaux existants
  charger_chenil(&chenil, &taille);
    
  do{
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Rechercher un/des animaux\n");
    printf("2. Ajouter un animal\n");
    printf("3. Adopter un animal\n");
    printf("4. Calculer le temps de nettoyage\n");
    printf("5. Quitter\n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide. Veuillez entrer un nombre.\n");
            exit(1);
    }
    getchar(); // Pour consommer le '\n'

    switch(choix) {
          case 1:
              rechercher_animal(chenil, taille);
              break;
          case 2:
              ajouter_animal(&chenil, &taille);
              break;
          case 3:
              adopter_animal(&chenil, &taille);
              break;
          case 4:
              affiche_temps_nettoyage(chenil, taille);
              break;
          case 5:
            printf("Au revoir !\n");
               break;
          default:
              printf("Choix invalide. Veuillez réessayer.\n");
    }
  } while(choix != 5);

  // Sauvegarder avant de quitter //
  sauvegarder_chenil(chenil, taille);
    
  // Libérer la mémoire //
  free(chenil);
  
  return 0;
}
