void sauvegarder_chenil(Animal* chenil, int taille){
  
  // Sauvegarde dans un fichier binaire les animaux à la fin du programme //
  FILE* fichier = fopen("Animaux_Chenil.dat", "wb");
    if (fichier == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }

  fwrite(&taille, sizeof(int), 1, fichier);  // Écrit le nombre d'animaux
  fwrite(chenil, sizeof(Animal), taille, fichier);  // Écrit tous les animaux du tableau chenil
  fclose(fichier);
}
