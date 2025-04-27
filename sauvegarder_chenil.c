void sauvegarder_chenil(Animal* chenil, int taille){

  if (chenil == NULL || taille < 0) {
        printf("Erreur: donnees invalides pour sauvegarde.\n");
        return;
    }
  
  // Sauvegarde dans un fichier binaire les animaux à la fin du programme //
  FILE* fichier = fopen("Animaux_Chenil.dat", "wb");
  if (fichier == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
  }
  
  // Écrit le nombre d'animaux
  if (fwrite(&taille, sizeof(int), 1, fichier) != 1) {
        printf("Erreur d'ecriture du nombre d'animaux.\n");
        fclose(fichier);
        return;
    }  
  // Verification a faire !!!
  fwrite(chenil, sizeof(Animal), taille, fichier);  // Écrit tous les animaux du tableau chenil
  fclose(fichier);
}
