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
  
  int numero;
  printf("Quelle action voulez-vous réaliser ? 1.Rechercher un/des animaux\n 2.Ajouter un animal qui vous a été confié \n3.Adoption d’un animal");
  scanf("%d",&numero);

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
