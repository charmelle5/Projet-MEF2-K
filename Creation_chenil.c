
Animal creation_animal(){
  Animal a;
  char temp_comment[MAXCOM];
  
  a.num = rand() % 9000 + 1000; // Entre 1000 et 9999
  
  printf("Saisir le nom de l'animal :\n");
  scanf("%49s",a.nom); // Limité à 49 caractères pour éviter le débordement
  
  printf("Saisir l'espece de l'animal :\n");
  printf("Saisir une numéro :\n 1:Chien\n 2:Chat\n 3:Hamster\n 4:Autruche\n 5:Lapin\n 6:Poisson\n");
  scanf("%d",(int*)&a.espece); 
  while(a.espece < CHIEN || a.espece > POISSON) {
        printf("Erreur : choix invalide. Veuillez ressaisir :\n");
        printf("1:Chien\n2:Chat\n3:Hamster\n4:Autruche\n5:Lapin\n6:Poisson\n");
        scanf("%d", (int*)&a.espece);
  }
  getchar(); // Nettoyer le buffer
  
  printf("Saisir l'annee de naissance : ");
  scanf("%d",&a.annee);
  
  printf("Saisir le poids de l'animal : ");
  scanf("%f", &a.poids);
  
  printf("Saisir un commentaire (optionnel) :\n");
  getchar(); // Pour consommer le '\n' restant
  fgets(temp_comment, MAXCOM, stdin);
  temp_comment[strcspn(temp_comment, "\n")] = '\0'; // Supprimer le saut de ligne
    
  if(strlen(temp_comment)) {
        strncpy(a.commentaire, temp_comment, MAXCOM-1);
        a.commentaire[MAXCOM-1] = '\0';
    } else {
        a.commentaire[0] = '\0';
    }
  return a;
}


void afficher_animal(Animal a) {
    const char* especes[] = {"", "Chien", "Chat", "Hamster", "Autruche", "Lapin", "Poisson"};
    printf("\n N°%d ---\n", a.num);
    printf("Nom: %s\n", a.nom);
    printf("Espece: %s\n", especes[a.espece]);
    printf("Annee naissance: %d\n", a.annee);
    printf("Poids: %.2f kg\n", a.poids);
    if (strlen(a.commentaire)){
      printf("Commentaire: %s\n", a.commentaire);
    }
}

void charger_chenil(Animal** chenil, int* taille) {
    // Actualisation du tableau chenil en lisant le ficher
    FILE* fichier = fopen("Animaux_Chenil.dat", "rb");
    if (fichier == NULL) {
        return; // Fichier inexistant (normal au premier lancement)
    }

    // Lit le nombre d'animaux et gestion erreur
    if (fread(taille, sizeof(int), 1, fichier) != 1) {
        printf("Erreur de lecture du nombre d'animaux.\n");
        fclose(fichier);
        return;
    }
    if (*taille < 0 || *taille > MAX_ANIMAUX) {
        printf("Donnees corrompues: nombre d'animaux invalide.\n");
        fclose(fichier);
        return;
    }
    *chenil = malloc(*taille * sizeof(Animal)); // Allocation mémoire pour le tableau chenil
    if (*chenil == NULL) {
        printf("Erreur d'allocation memoire.\n");
        fclose(fichier);
        return;
    }
    // Faire la verification !!!!
    fread(*chenil, sizeof(Animal), *taille, fichier); // Remplit le tableau chenil avec les données binaires du fichier.
    fclose(fichier);
}


