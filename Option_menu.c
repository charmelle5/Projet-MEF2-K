#include<stdio.h>
#include<stdlib.h>
#include"Creation_chenil.h"

void ajouter_animal(Animal** chenil, int* taille){

  if (chenil == NULL || *taille <= 0) {
        printf("Erreur dans les parametres pour l'ajout.\n");
        return;
    }
	
  if (*taille >= MAX_ANIMAUX) {
        printf("Le chenil est plein (capacité max: %d).\n", MAX_ANIMAUX);
        return;
  }

  Animal nouvel_animal = creation_animal();

  // Réallocation mémoire pour agrandir le tableau
  Animal* Newchenil = realloc(*chenil, (*taille + 1) * sizeof(Animal));
  if (Newchenil == NULL) {
        printf("Erreur mémoire !\n");
        return;
  }
  *chenil = Newchenil;
  // Ajout de l'animal
  (*chenil)[*taille] = nouvel_animal;
  (*taille)++;

  printf("\n✅ Animal ajouté !\n");

  if (sauvegarder_chenil(*chenil, *taille)) {
        printf("Sauvegarde automatique réussie.\n");
  } 
  else {
        printf("Erreur lors de la sauvegarde !\n");
  }
	
}

void adopter_animal(Animal** chenil, int* taille){
    if (chenil == NULL || *taille <= 0) {
        printf("Erreur dans les parametres pour l'adoption.\n");
        return;
    }

    int num = 0;
    printf("\n=== ADOPTION D'UN ANIMAL ===\n");
    
    do {
	    printf("Entrez le numero d'identification : ");
	    if (scanf("%d", &num) != 1) {
        	printf("Numero invalide.\n");
        	vider_buffer();
        	continue;
    	     }
    }while(num<1000 || num>9000);
    vider_buffer();

    int index = 0;
    for (int i = 0; i < *taille; i++) {
        if ((*chenil)[i].num == num) {
            index = i;
            break; // arrêt de la boucle lorsque le numéro d'idenfication trouvé
        }
    }

    if (index == 0) {
        printf("Animal non trouvé.\n");
        return;
    }

    // Afficher l'animal à adopter
    printf("Vous allez adopter cet animal :\n");
    afficher_animal((*chenil)[index]);

    // Supression de l'animal et déplacement des animaux suivent
    for (int i = index; i < *taille - 1; i++) {
        (*chenil)[i] = (*chenil)[i+1];
    }
        
    (*taille)--;
    Animal* temp = realloc(*chenil, *taille * sizeof(Animal));
    if (*taille > 0 && temp == NULL) {
        printf("Erreur de reallocation.\n");
        return;
    }
    *chenil = temp;
        
    printf("Animal adopté avec succes !\n");
	
    if (sauvegarder_chenil(*chenil, *taille)) {
        printf("Sauvegarde automatique réussie.\n");
    } else {
        printf("Erreur lors de la sauvegarde !\n");
    }

}


void rechercher_animal(Animal* chenil, int taille) {

    	if (chenil == NULL || taille <= 0) {
        	printf("Erreur dans les parametres pour la recherche.\n");
        	return;
    	}
	if (taille == 0) {
		printf("Aucun animal dans le chenil.\n");
		return;
	}
	int choix =  0;
	int espece = 0;
	int type_age = 0;
	int age = 0;
	int annee_actuelle = 2025;
	char nom_recherche[MAXCHAR];

	printf("\n=== CRITERES DE RECHERCHE ===\n");
	printf("1. Par nom\n");
	printf("2. Par espece\n");
	printf("3. Par age (jeune <2 ans, senior >10 ans)\n");
	
	do{
	    printf("Votre choix : ");
	    if (scanf("%d", &choix) != 1 ){
        	  printf("Choix invalide.\n");
        	  vider_buffer();
        	  continue;
    	    }
	}while(choix < 1 || choix > 3);
    	vider_buffer();

	printf("\n=== RESULTATS DE LA RECHERCHE ===\n");
	int trouve = 0;
	int resultats[MAX_ANIMAUX]; // Stocke les indices des animaux trouvés
	int nb_resultats = 0;
	
	// Préparation des critères de recherche pour la comparaison
	switch(choix) {
        case 1:
            do{
                printf("Entrez le nom a rechercher : ");
                if (fgets(nom_recherche, MAXCHAR, stdin) == NULL) {
                    printf("Erreur de saisie.\n");
                    return;
                }
                nom_recherche[strcspn(nom_recherche, "\n")] = '\0';
            }while(strlen(nom_recherche) == 0);
            
            break;
        case 2:
            do{
                printf("Entrez le numero de l'espece (1:Chien, 2:Chat, 3:Hamster, 4:Autruche, 5:Lapin, 6:Poisson): ");
                if (scanf("%d", &espece) != 1 ) {
                    printf("Espece invalide.\n");
                    vider_buffer();
                    continue;
                }
            }while(espece < 1 || espece > 6);
            vider_buffer();
		
            break;
        case 3:
            do{
                printf("Rechercher :\n1. Jeune (<2 ans)\n2. Senior (>10 ans)\nVotre choix : ");
                if (scanf("%d", &type_age) != 1 ) {
                    printf("Choix invalide.\n");
                    vider_buffer();
                    continue;
                }
            }while(type_age != 1 && type_age != 2);
            vider_buffer();
		
            break;
        default:
            printf("Choix invalide.\n");
            return;
    }
    
    // Recherche des animaux correspondants aux critère rechercher
	for (int i = 0; i < taille; i++) {
		Animal a = chenil[i];
		int match = 0;

		switch(choix) {
		case 1:
			
			if (strstr(a.nom, nom_recherche)) {
                    	   match = 1;
                	}
			break;
			
		case 2:
			
			if (a.espece == espece) {
                   	   match = 1;
                	}
			break;
			
		case 3:
			
			int age = annee_actuelle - a.annee;
            		if (type_age == 1 && age <= 2) {
                	   match = 1;  // Jeune
            		} 
            		else if (type_age == 2 && age >= 10) {
                	   match = 1;  // Senior
            		}
			
			break;
		}

		if (match) {
			resultats[nb_resultats++] = i;
		}
	}
	
    
	if (nb_resultats>0) {
	    // Afficher les animaux correspondants aux critère rechercher
		printf("\n=== %d ANIMAUX TROUVES ===\n", nb_resultats);
		for (int r = 0; r < nb_resultats; r++) {
			printf("\n--- Animal %d/%d ---\n", r+1, nb_resultats);
			afficher_animal(chenil[resultats[r]]);
		}
		
	// Selectionner l'animal voulu
        if (nb_resultats > 1) {
            int selection = 0;
            do{
                printf("\nEntrez le numero de l'animal a selectionner (0 pour annuler) : ");
                if (scanf("%d", &selection) != 1) {
                    printf("Saisie invalide.\n");
                    vider_buffer();
                    continue;
                }
            }while(selection<0 || selection>nb_resultats);
            vider_buffer();

            
            if (selection > 0 && selection <= nb_resultats) {
                printf("\n=== ANIMAL SELECTIONNE ===\n");
                afficher_animal(chenil[resultats[selection-1]]);
            }
        }
	}
	else {
		printf("Aucun animal ne correspond aux criteres de recherche.\n");
	}

}


	
  
