#include<stdio.h>
#include<stdlib.h>
#include<Animal.h>
#define MAXCHAR 50
#define SIZE 50

int main() {
  int n;
  while(n>50 || n<0){
    printf("Saisir le nombre d'animaux dans le chenil :\n");
    scanf("%d",&n);
  }

  Animal* chenil = malloc(SIZE*sizeof(Animal));
  FILE* fichier = NULL;
  fichier = fopen(" Animaux_Chenil.txt", "r+");
  if (fichier == NULL){
    printf("Ouverture du fichier impossible\n"); 
    exit(1);
  char* nom= " Cacahuete ";
  fputs(nom,fichier);
  fclose(fichier);

FILE *fichier = fopen("fichier.txt", "w");  // "w" = écriture (crée/écrase)
    
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 1;
    }

    // Écrire dans le fichier
    fprintf(fichier, "Bonjour GitHub !\n");
    fprintf(fichier, "Ligne 2.\n");

    fclose(fichier);  // Fermer le fichier
    printf("Écriture terminée.\n");

    
  
  int choix;
    do{
      printf("\n=== MENU PRINCIPAL ===\n");
      printf("1. Rechercher un/des animaux\n");
      printf("2. Ajouter un animal\n");
      printf("3. Adopter un animal\n");
      printf("4. Quitter\n");
      printf("Votre choix : ");
      scanf("%d",&choix);
      getchar(); // Pour consommer le '\n'

      switch(choix) {
            case 1:
                rechercher_animaux();
                break;
            case 2:
                ajouter_animal();
                break;
            case 3:
                adopter_animal();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while(choix != 4);
  

  switch (numero)
    {
    case 1:
        return recherche_animaux();
    case 2:
        return Ajouter_animal();
    case 3:
        return Adoption_animal();
    default:
        return 
          printf("Quelle action voulez-vous réaliser ? 1.Rechercher un/des animaux\n 2.Ajouter un animal qui vous a été confié \n3.Adoption d’un animal");
          scanf("%d",&numero);
    }
  
}
