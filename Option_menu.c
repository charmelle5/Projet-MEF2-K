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
