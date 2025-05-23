#include "Creation_chenil.h"

// Déclaration des variables statiques pour la gestion des numéros
static int numeros_utilises[MAX_ANIMAUX]; 
static int nb_numeros = 0;

void vider_buffer(){
    while(getchar() != '\n'){
    }
}

// Fonction de vérification des doublons
int numero_existe_deja(int num) {
    for (int i = 0; i < nb_numeros; i++) {
        if (numeros_utilises[i] == num) {
		return 1;
	}
    }
    return 0;
}

Animal creation_animal(){
  Animal a;
  char temp_comment[MAXCOM];
  
   // Génération d'un numéro unique
    do {
        a.num = rand() % 9000 + 1000; // 1000-9999
    } while(numero_existe_deja(a.num));
    
     // Ajoute le nouveau numéro dans le tableau de num d'id
    numeros_utilises[nb_numeros++] = a.num;


    do {
        printf("Saisir le nom de l'animal : ");
        if (fgets(a.nom, MAXCHAR, stdin) == NULL) {
            printf("Erreur de saisie.\n");
            exit(EXIT_FAILURE);
        }
        a.nom[strcspn(a.nom, "\n")] = '\0';
    } while(strlen(a.nom) == 0);
	
    do {
        printf("1:Chien\n2:Chat\n3:Hamster\n4:Autruche\n5:Lapin\n6:Poisson\nChoisissez l'espece: ");
        if (scanf("%d", (int*)&a.espece) != 1) {
            printf("Saisie invalide.\n");
            vider_buffer();
            continue;
        }
    } while(a.espece < CHIEN || a.espece > POISSON);
    vider_buffer();

    do {
        printf("Saisir l'année de naissance (2000-2025) : ");
        if (scanf("%d", &a.annee) != 1) {
            printf("Saisie invalide.\n");
            vider_buffer();
            continue;
        }
    } while (a.annee < 2000 || a.annee > 2025 );
    vider_buffer();
    


    do {
        printf("Saisir le poids de l'animal: ");
        if (scanf("%f", &a.poids) != 1) {
            printf("Saisie invalide.\n");
            vider_buffer();
            continue;
        }
    } while(a.poids <= 0 || a.poids >=100);
    vider_buffer();
    
    
	
    printf("Saisir un commentaire (optionnel):\n");
    if (fgets(temp_comment, MAXCOM, stdin) == NULL) {
        temp_comment[0] = '\0';
    } 
    else {
        temp_comment[strcspn(temp_comment, "\n")] = '\0'; // Supprimer le saut de ligne
    }

    strncpy(a.commentaire, temp_comment, MAXCOM-1);
    a.commentaire[MAXCOM-1] = '\0';
	
  return a;
}


void afficher_animal(Animal a) {
    const char* especes[] = {"", "Chien", "Chat", "Hamster", "Autruche", "Lapin", "Poisson"};
    printf("\n N°%d ---\n", a.num);
    printf("Nom: %s\n", a.nom);
    printf("Espece: %s\n", especes[a.espece]);
    printf("Annee naissance: %d\n", a.annee);
    printf("Poids: %.2f kg\n", a.poids);
    if (strlen(a.commentaire)){
      printf("Commentaire: %s\n", a.commentaire);
    }
}

void charger_chenil(Animal** chenil, int* taille) {

    // Actualisation du tableau chenil en lisant le ficher
    FILE* fichier = fopen("Animaux_Chenil.dat", "rb");
    if (fichier == NULL) {
        *taille = 0; // Initialise à 0 si fichier inexistant
        nb_numeros = 0;
        return; // Fichier inexistant (normal au premier lancement)
    }
    
    // Lit le nombre d'animaux et gestion erreur
    if (fread(taille, sizeof(int), 1, fichier) != 1) {
        printf("Erreur de lecture du nombre d'animaux.\n");
        fclose(fichier);
        *taille = 0;
        return;
    }
    
     if (*taille < 0 || *taille > MAX_ANIMAUX) {
        printf("Données corrompues: nombre d'animaux invalide.\n");
        fclose(fichier);
        *taille = 0;
        return;
    }


    
    *chenil = malloc(*taille * sizeof(Animal)); // Allocation mémoire pour le tableau chenil
    if (*chenil == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        fclose(fichier);
        *taille = 0;
        return;
    }
	
    // Remplit le tableau chenil avec les données binaires du fichier.
    if (fread(*chenil, sizeof(Animal), *taille, fichier) != (size_t)*taille) {
        printf("Erreur de lecture des animaux.\n");
        free(*chenil);
        *chenil = NULL;
        *taille = 0;
        fclose(fichier);
        return;
    } 
	
    // Copie les num du chenil dans le tableau d'id
    nb_numeros = 0;
    for (int i = 0; i < *taille; i++) {
        numeros_utilises[nb_numeros++] = (*chenil)[i].num;
    }
	
    fclose(fichier);
}

int sauvegarder_chenil(Animal* chenil, int taille){

  if (chenil == NULL || taille <= 0) {
        printf("Erreur: donnees invalides pour sauvegarde.\n");
        return 0;
    }
  
  // Sauvegarde dans un fichier binaire les animaux à la fin du programme
  FILE* fichier = fopen("Animaux_Chenil.dat", "wb");
  if (fichier == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return 0;
  }
  
  // Écrit le nombre d'animaux
  if (fwrite(&taille, sizeof(int), 1, fichier) != 1) {
        printf("Erreur d'ecriture du nombre d'animaux.\n");
        fclose(fichier);
        return 0;
    }  
	
  // Écrit tous les animaux du tableau chenil
  if (fwrite(chenil, sizeof(Animal), taille, fichier) != (size_t)taille) {
        printf("Erreur d'ecriture des animaux.\n");
        fclose(fichier);
        return 0;
    } 
    
    
  fclose(fichier);
  return 1;
  
}
