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
            temps.temps_quotidien = 10;
            temps.temps_hebdomadaire = 30;
        case POISSON:
            temps.temps_quotidien = 5;
            temps.temps_hebdomadaire = 15;
        default:
            temps.temps_quotidien = 2;
            temps.temps_hebdomadaire = 0;
    }
    return temps;
}

// Fonction qui affiche le temps de nettoyage pour chaque espèce
void affiche_temps_nettoyage(Animal* chenil, int taille) {
    if (taille == 0) {
        printf("Aucun animal dans le chenil - nettoyage minimal (2 minutes/jour).\n");
        return;
    }
    printf("\n=== TEMPS DE NETTOYAGE ===\n");
    for (int i = 0; i < taille; i++) {
        TempsNettoyage t = temps_nettoyage(chenil[i].espece);
        printf("\n---Temps de nettoyage de %s---\n",chenil[i].nom);
        printf("Temps quotidien : %d min\n", t.temps_quotidien);
        printf("Temps hebdomadaire supplementaire : %d min\n", t.temps_hebdomadaire);
        printf("Temps hebdomadaire de nettoyage : %d min\n",(t.temps_quotidien*7) + t.temps_hebdomadaire);
    }
}


