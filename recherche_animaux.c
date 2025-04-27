void rechercher_animal(Animal* chenil, int taille) {

	if (chenil == NULL || taille <= 0) {
        	printf("Aucun animal dans le chenil.\n");
        	return;
    	}
	
	int choix;
	int espece;
	int age;
	int type_age;
	int annee_actuelle = 2025;
	char nom_recherche[MAXCHAR];
	
	printf("\n=== CRITERES DE RECHERCHE ===\n");
	printf("1. Par nom\n");
	printf("2. Par espece\n");
	printf("3. Par age (jeune <2 ans, senior >10 ans)\n");
	printf("Votre choix : ");
	if (scanf("%d", &choix) != 1 || choix < 1 || choix > 3) {
        	printf("Choix invalide.\nVeuillez refaire votre choix\n");
		printf("1. Par nom\n");
		printf("2. Par espece\n");
		printf("3. Par age (jeune <2 ans, senior >10 ans)\n");
		printf("Votre choix : ");
		scanf("%d", &choix);
   	}	
	getchar();

	printf("\n=== RESULTATS DE LA RECHERCHE ===\n");
	int trouve = 0;
	int resultats[MAX_ANIMAUX];
	int nb_resultats = 0;
	
	// Demande à l'utilisateur les critères de recherche pour la comparaison
	switch(choix) {
        case 1:
            printf("Entrez le nom a rechercher : ");
            fgets(nom_recherche, MAXCHAR, stdin);
            nom_recherche[strcspn(nom_recherche, "\n")] = '\0';
            break;
        case 2:
            printf("Entrez le numero de l'espece (1:Chien, 2:Chat, 3:Hamster, 4:Autruche, 5:Lapin, 6:Poisson): ");
            scanf("%d", &espece);
            getchar();
            break;
        case 3:
            printf("Rechercher :\n1. Jeune (<2 ans)\n2. Senior (>10 ans)\nVotre choix : ");
            scanf("%d", &type_age);
            getchar();
            break;
        default:
            printf("Choix invalide.\n");
            return;
    }
    
    // Recherche des animaux correspondants aux critère rechercher
	for (int i = 0; i < taille; i++) {
		Animal a = chenil[i];
		int match = 0;

		switch(choix) {
		case 1:
			if (strstr(a.nom, nom_recherche)) {
                    match = 1;
                }
			break;
		case 2:
			if (a.espece == espece) {
                    match = 1;
                }
			break;
		case 3:
			age = annee_actuelle - a.annee;
                if ((type_age == 1 && age < 2) || (type_age == 2 && age > 10)) {
                    match = 1;
                }
			break;
		}

		if (match) {
			resultats[nb_resultats++] = i; // Stocke les indices des animaux trouvés
		}
	}
	
    
	if (nb_resultats>0) {
	    	// Afficher tous les animaux correspondants aux critère rechercher
		printf("\n=== %d ANIMAUX TROUVES ===\n", nb_resultats);
		for (int r = 0; r < nb_resultats; r++) {
			printf("\n--- Animal %d/%d ---\n", r+1, nb_resultats);
			afficher_animal(chenil[resultats[r]]);
		}
		
		// Selectionner l'animal voulu
        	if (nb_resultats > 1) {
         		int selection;
          		printf("\nEntrez le numero de l'animal a selectionner (0 pour annuler) : ");
      	        	scanf("%d", &selection);
                   	getchar();
            
            	   	if (selection > 0 && selection <= nb_resultats) {
                		printf("\n=== ANIMAL RECHERCHE ===\n");
                		afficher_animal(chenil[resultats[selection-1]]);
            	     	}
        	}
        }
	else {
	  	printf("Aucun animal ne correspond aux criteres de recherche.\n");
	}


}


