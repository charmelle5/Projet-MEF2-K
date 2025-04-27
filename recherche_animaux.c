void rechercher_animal(Animal* chenil, int taille){

   if (taille == 0) {
        printf("Aucun animal dans le chenil.\n");
        return;
    }
   int choix;
   int espece;
   int type_age;
   int annee_actuelle = 2025;
   char nom_recherche[MAXCHAR];

   printf("\n=== CRITERES DE RECHERCHE ===\n");
   printf("1. Par nom\n");
   printf("2. Par espece\n");
   printf("3. Par age (jeune <2 ans, senior >10 ans)\n");
   printf("Votre choix : ");
   scanf("%d", &choix);
   getchar();

   printf("\n=== RESULTATS DE LA RECHERCHE ===\n");
    int trouve = 0;

    for (int i = 0; i < taille; i++) {
        Animal a = chenil[i];
        int match = 0;

        switch(choix) {
            case 1:
                printf("Entrez le nom a rechercher : ");
                fgets(nom_recherche, MAXCHAR, stdin);
                nom_recherche[strcspn(nom_recherche, "\n")] = '\0';
                if (strstr(a.nom, nom_recherche)) {
                   match = 1;
                }
                break;
            case 2:
                printf("Entrez l'espece (1:Chien, 2:Chat, etc.) : ");
                scanf("%d", &espece);
                if (a.espece == espece){
                   match = 1;
                }
                break;
            case 3:
                printf("Rechercher jeune (1) ou senior (2) : ");
                scanf("%d", &type_age);
                int age = annee_actuelle - a.annee;
                if ((type_age == 1 && age < 2) || (type_age == 2 && age > 10)){
                   match = 1;
                }
                break;
        }
         if (match) {
            afficher_animal(a);
            trouve = 1;
        }
    }
   if (trouve != 1) {
        printf("Aucun animal ne correspond aux criteres de recherche.\n");
    }
}



