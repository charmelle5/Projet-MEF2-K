void creation_animaux(){
  Animal a;
  char temp_comment[MAXCOM];
  
  printf("Saisir le numero d'identification :\n");
  scanf("%d",&a.num);
  
  printf("Saisir le nom de l'animal :\n");
  scanf("%49s",a.nom); // Limité à 49 caractères pour éviter le débordement
  
  printf("Saisir l'espece de l'animal :\n");
  printf("Saisir une numéro : 1:Chien\n 2:Chat\n 3:Hamster\n 4:Autruche\n 5:Lapin\n 6:Poisson\n");
  scanf("%d",(int*)&a.espece); 
  while(a.espece < CHIEN || a.espece > POISSON) {
        printf("Erreur : choix invalide. Veuillez ressaisir :\n");
        printf("1:Chien\n2:Chat\n3:Hamster\n4:Autruche\n5:Lapin\n6:Poisson\n");
        scanf("%d", (int*)&a.espece);
  }
  
  printf("Saisir l'annee de naissance :\n");
  scanf("%d",&a.annee);
  
  printf("Saisir le poids de l'animal :\n");
  scanf("%f", &a.poids);
  
  printf("Saisir un commentaire (optionnel) :\n");
  getchar(); // Pour consommer le '\n' restant
  fgets(temp_comment, MAXCOM, stdin);
  temp_comment[strcspn(temp_comment, "\n")] = '\0'; // Supprimer le saut de ligne
    
  if(strlen(temp_comment) > 0) {
      strncpy(a.commentaire, temp_comment, MAXCOM-1);
      a.commentaire[MAXCOM-1] = '\0'; // Assurance null-terminated
  } else {
      a.commentaire[0] = '\0'; // Commentaire vide si non fourni
  }
}
