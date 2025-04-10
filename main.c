#include<stdio.h>
#include<stdlib.h>
#include<Animal.h>
#define MAXCHAR 50

int main() {
  int n;
  while(n>50 || n<0){
    printf("Saisir le nombre d'animaux dans le chenil :\n");
    scanf("%d",&n);
  }

  Animal* chenil = malloc(n*sizeof(Animal));

  for (int i=0; i<n; i++){
    creation_animaux();
  }
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
