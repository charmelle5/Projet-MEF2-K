#include<stdio.h>
#include<stdlib.h>
#include<Animal.h>

int n;
printf("Saisir le nombre d'animaux dans le chenil :\n");
scanf("%d",&n);

Animal* chenil = malloc(n*sizeof(Animal));

for (int i=0; i<n; i++){
  creation_animaux();
}
