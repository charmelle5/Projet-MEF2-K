// Fonction indicant le temps de nettoyage pour chaque espèce 
TempsNettoyage temps_nettoyage(Type espece) {
    TempsNettoyage temps;
    switch(espece) {
        case CHIEN:
            temps.temps_quotidien = 5;
            temps.temps_hebdomadaire = 20;
            break;
        case CHAT:
            temps.temps_quotidien = 10;
            temps.temps_hebdomadaire = 20;
            break;
        case HAMSTER:
            temps.temps_quotidien = 10;
            temps.temps_hebdomadaire = 20;
            break;
        case AUTRUCHE:
            temps.temps_quotidien = 20;
            temps.temps_hebdomadaire = 45;
            break;
        case LAPIN:
        case POISSON:
        default:
            temps.temps_quotidien = 2;
            temps.temps_hebdomadaire = 0;
    }
    return temps;
}

// Fonction qui calcule et affiche le temps de nettoyage
void calculer_temps_nettoyage(Animal* chenil, int taille) {
    if (taille == 0) {
        printf("Aucun animal dans le chenil - nettoyage minimal (2 minutes/jour).\n");
        return;
    }

    int total_quotidien = 0;
    int total_hebdomadaire = 0;
    int cages_vides = MAX_ANIMAUX - taille;

    // Ajout temps pour les cages vides
    total_quotidien += cages_vides * 2;

    // Temps pour les animaux
    for (int i = 0; i < taille; i++) {
        TempsNettoyage t = temps_nettoyage(chenil[i].espece);
        total_quotidien += t.temps_quotidien;
        total_hebdomadaire += t.temps_hebdomadaire;
    }

    // Affichage des résultats
    printf("\n=== TEMPS DE NETTOYAGE ===\n");
    printf("Temps quotidien total : %d minutes\n", total_quotidien);
    printf("Temps hebdomadaire supplementaire : %d minutes\n", total_hebdomadaire);
    printf("Total semaine : %d minutes\n", 
           (total_quotidien * 7) + total_hebdomadaire);
}

