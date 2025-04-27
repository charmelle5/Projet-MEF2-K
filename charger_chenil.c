void charger_chenil(Animal** chenil, int* taille) {
    // Actualisation du tableau chenil en lisant le ficher
    FILE* fichier = fopen("Animaux_Chenil.dat", "rb");
    if (fichier == NULL) {
        return; // Fichier inexistant (normal au premier lancement)
    }

    fread(taille, sizeof(int), 1, fichier);
    *chenil = malloc(*taille * sizeof(Animal));
    fread(*chenil, sizeof(Animal), *taille, fichier);
    fclose(fichier);
}
