void creation_animaux(){
  Animal a;
  printf("Saisir le numero d'identification :\n");
  scanf("%d",&a.num);
  printf("Saisir le nom de l'animal :\n");
  scanf("%s",a.nom);
  printf("Saisir l'espece de l'animal :\n");
  printf("Saisir une numéro : 1:Chien\n 2:Chat\n 3:Hamster\n 4:Autruche\n 5:Lapin\n 6:Poisson\n");
  scanf("%d",&a.espece); 
  if(a.espece<1 || a.espece>6){
    printf("Erreur");
    printf("Saisir une numéro : 1:Chien\n 2:Chat\n 3:Hamster\n 4:Autruche\n 5:Lapin\n 6:Poisson\n");
    scanf("%d",&a.espece);
  }
  printf("Saisir l'annee de naissance :\n");
  scanf("%d",&a.annee);
  printf("Saisir le poids de l'animal :\n");
  scanf("%f", &a.poids);
  //commentaire ???//
}
