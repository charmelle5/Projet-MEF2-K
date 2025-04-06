#include<stdio.h>
#include<Animal.h>

int n;
printf("Saisir le nombre d'animaux dans le chenil :\n");
scanf("%d",&n);

Animal* chenil = malloc(n*sizeof(Animal));
