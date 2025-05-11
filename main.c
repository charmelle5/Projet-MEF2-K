#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"Option_menu.h"
#include"Creation_chenil.h"
#include"Variante.h"

// Déclaration des variables statiques pour la gestion des numéros d'id
static int numeros_utilises[MAX_ANIMAUX]; 
static int nb_numeros = 0;


int main() {

srand(time(NULL));
   
 Animal* chenil = NULL;
 int taille = 0;
 int choix = 0;
 
  // Charger les animaux existants
  charger_chenil(&chenil, &taille);
    
  do{
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Rechercher un/des animaux\n");
    printf("2. Ajouter un animal\n");
    printf("3. Adopter un animal\n");
    printf("4. Calculer le temps de nettoyage\n");
    printf("5. Afficher l'inventaire du chenil\n");
    printf("6. Quitter\n");
    printf("Votre choix : ");
    do{
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide.\n");
            vider_buffer();
        	  continue;
    	    }
	}while(choix < 1 || choix > 6);
    vider_buffer();

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
               afficher_inventaire_chenil(chenil, taille);
               break;
          case 6:
            printf("Au revoir !\n");
               break;
          default:
              printf("Choix invalide. Veuillez réessayer.\n");
    }
  } while(choix != 6);

  // Sauvegarder avant de quitter //
  sauvegarder_chenil(chenil, taille);
    
  // Libérer la mémoire //
  free(chenil);
  
  return 0;
}
