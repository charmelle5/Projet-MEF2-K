void charger_chenil(Animal** chenil, int* taille) {
    // Actualisation du tableau chenil en lisant le ficher
    FILE* fichier = fopen("Animaux_Chenil.dat", "rb");
    if (fichier == NULL) {
        return; // Fichier inexistant (normal au premier lancement)
    }

    fread(taille, sizeof(int), 1, fichier); // Lit le nombre d'animaux
    *chenil = malloc(*taille * sizeof(Animal)); // Allocation mémoire pour le tableau chenil
    fread(*chenil, sizeof(Animal), *taille, fichier); // Remplit le tableau chenil avec les données binaires du fichier.
    fclose(fichier);
}
