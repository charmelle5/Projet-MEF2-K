#include<stdio.h>
#include<stdlib.h>
#include"Creation_chenil.h"

void ajouter_animal(Animal** chenil, int* taille){
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
}

void adopter_animal(Animal** chenil, int* taille){
    if (chenil == NULL || *taille <= 0) {
        printf("Aucun animal dans le chenil.\n");
        return;
    }

    int num;
    printf("\n=== ADOPTION D'UN ANIMAL ===\n");
    printf("Entrez le numero d'identification : ");
    if (scanf("%d", &num) != 1) {
        exit(3);
    }

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


}


void rechercher_animal(Animal* chenil, int taille) {

	if (taille == 0) {
		printf("Aucun animal dans le chenil.\n");
		return;
	}
	int choix =  0;
	int espece = 0;
	int type_age = 0;
	int annee_actuelle = 2025;
	char nom_recherche[MAXCHAR];

	printf("\n=== CRITERES DE RECHERCHE ===\n");
	printf("1. Par nom\n");
	printf("2. Par espece\n");
	printf("3. Par age (jeune <2 ans, senior >10 ans)\n");
	printf("Votre choix : ");
	scanf("%d", &choix);
	getchar();

	printf("\n=== RESULTATS DE LA RECHERCHE ===\n");
	int trouve = 0;
	int resultats[MAX_ANIMAUX]; // Stocke les indices des animaux trouvC)s
	int nb_resultats = 0;
	
	// Préparation des critères de recherche pour la comparaison
	switch(choix) {
        case 1:
            printf("Entrez le nom a rechercher : ");
            fgets(nom_recherche, MAXCHAR, stdin);
            nom_recherche[strcspn(nom_recherche, "\n")] = '\0';
            break;
        case 2:
            printf("Entrez le numero de l'espece (1:Chien, 2:Chat, 3:Hamster, 4:Autruche, 5:Lapin, 6:Poisson): ");
            scanf("%d", &espece);
            getchar();
            break;
        case 3:
            printf("Rechercher :\n1. Jeune (<2 ans)\n2. Senior (>10 ans)\nVotre choix : ");
            scanf("%d", &type_age);
            getchar();
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
                if ((type_age == 1 && age < 2) || (type_age == 2 && age > 10)) {
                    match = 1;
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
            int selection;
            printf("\nEntrez le numero de l'animal a selectionner (0 pour annuler) : ");
            scanf("%d", &selection);
            getchar();
            
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
