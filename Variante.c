#include"Variante.h"

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
            break;
        case POISSON:
            temps.temps_quotidien = 5;
            temps.temps_hebdomadaire = 15;
            break;
        default:
            temps.temps_quotidien = 2;
            temps.temps_hebdomadaire = 0;
    }
    return temps;
}

void affiche_temps_nettoyage(Animal* chenil, int taille) {
    if (chenil == NULL || taille < 0) {
        printf("Erreur dans les parametres de l'affichage du nettoyage.\n");
        exit(1);
    }

    if (taille == 0) {
        printf("Chenil vide - 2 min/jour par cage.\n");
        return;
    }

    int total_quotidien = 0;
    int total_hebdomadaire = 0;
    int cages_vides = MAX_ANIMAUX - taille;

    // Temps nettoyage pour les cages vides
    total_quotidien += cages_vides * 2;

    // Calcule et affiche le temps de nettoyage de chaques animaux
    printf("\n=== TEMPS DE NETTOYAGE ===\n");
    for (int i = 0; i < taille; i++) {
        TempsNettoyage t = temps_nettoyage(chenil[i].espece);
        printf("\n---Temps de nettoyage N°%d : %s  ---\n", chenil[i].num, chenil[i].nom);
        printf("Temps quotidien : %d min\n", t.temps_quotidien);
        printf("Temps hebdomadaire supplementaire : %d min\n", t.temps_hebdomadaire);
        printf("Temps hebdomadaire de nettoyage : %d min\n",(t.temps_quotidien*7) + t.temps_hebdomadaire);
        total_quotidien += t.temps_quotidien;
        total_hebdomadaire += t.temps_hebdomadaire;
    }

    if (total_quotidien <= 0 || total_hebdomadaire < 0) {
        printf("Erreur dans le calcul des temps.\n");
        return;
    }

    // Affiche le temps total de nettoyage pour le chenil 
    printf("\n---Temps de nettoyage total---\n");
    printf("Temps quotidien total : %d minutes\n", total_quotidien);
    printf("Temps hebdomadaire supplementaire : %d minutes\n", total_hebdomadaire);
    printf("Total semaine : %d minutes\n", (total_quotidien * 7) + total_hebdomadaire);

}



void afficher_inventaire_chenil(Animal* chenil, int taille) {
    
    if (chenil == NULL || taille <= 0) {
        printf("Aucun animal dans le chenil.\n");
        return;
    }
    
    

    // Tableau des noms d'espèces
    const char* noms_especes[] = {"Chien", "Chat", "Hamster", "Autruche", "Lapin", "Poisson"};
    
    // Tableau des compteurs (initialisés à 0)
    int compteurs[6] = {0};

    // Compter les animaux
    for (int i = 0; i < taille; i++) {
        if (chenil[i].espece >= CHIEN && chenil[i].espece <= POISSON) {
            compteurs[chenil[i].espece - 1]++; //
        }
    }
    
    // Tri à bulles par ordre décroissant
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (compteurs[j] < compteurs[j+1]) {
                // Échanger compteurs
                int temp = compteurs[j];
                compteurs[j] = compteurs[j+1];
                compteurs[j+1] = temp;
            
               // Échanger noms
                const char* temp_nom = noms_especes[j];
                noms_especes[j] = noms_especes[j+1];
                noms_especes[j+1] = temp_nom;
            }
        }
    }
    


    // Afficher les résultats
    printf("\n=== INVENTAIRE DU CHENIL ===\n");
    printf("Nombre total d'animaux : %d\n\n", taille);
    printf("Répartition par espèce :\n");

    //Affiche les animaux triés
    for (int i = 0; i < 6; i++) {
        if (compteurs[i] > 0) {
            printf("%s: %d \n", noms_especes[i], compteurs[i]);
        }
    }
}
