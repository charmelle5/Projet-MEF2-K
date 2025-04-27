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
