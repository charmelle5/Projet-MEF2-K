#include<stdio.h>
#include<stdlib.h>

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
