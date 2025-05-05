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
