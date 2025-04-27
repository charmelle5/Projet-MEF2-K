void adopter_animal(Animal** chenil, int* taille){
    if (*taille == 0) {
        printf("Aucun animal dans le chenil.\n");
        return;
    }

    int num;
    printf("\n=== ADOPTION D'UN ANIMAL ===\n");
    printf("Entrez le numero d'identification : ");
    scanf("%d", &num);

    int index = 0;
    for (int i = 0; i < *taille; i++) {
        if ((*chenil)[i].num == num) {
            index = i;
            break; // arrêt de la boucle 
        }
    }

    if (index == 0) {
        printf("Animal non trouve.\n");
        return;
    }

    // Afficher l'animal à adopter
    printf("Vous allez adopter cet animal :\n");
    afficher_animal((*chenil)[index]);

    // Supression de l'animal et déplacement des animaux suivent
    for (int i = index; i < *taille - 1; i++) {
        (*chenil)[i] = (*chenil)[i+1];
    }
        
    (*taille)--;
    Animal* temp = realloc(*chenil, *taille * sizeof(Animal));
    if (*taille > 0 && temp == NULL) {
        printf("Erreur de reallocation.\n");
        return;
    }
    *chenil = temp;
        
    printf("Animal adopte avec succes !\n");


}
