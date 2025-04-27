typedef enum{
  CHIEN=1, CHAT, HAMSTER, AUTRUCHE, LAPIN, POISSON
}Type;

typedef struct{
  int num;
  char nom[MAXCHAR];
  Type espece;
  float poids;
  int annee;
  char commentaire[MAXCOM];
}Animal;

// Structure pour stocker les temps de nettoyage
typedef struct {
    int temps_quotidien;
    int temps_hebdomadaire;
} TempsNettoyage;

// Prototypes
Animal creation_animal();
void ajouter_animal(Animal** chenil, int* taille);
void rechercher_animal(Animal* chenil, int taille);
void afficher_animal(Animal a);
void sauvegarder_chenil(Animal* chenil, int taille);
void charger_chenil(Animal** chenil, int* taille);
void calculer_temps_nettoyage(Animal* chenil, int taille);
TempsNettoyage get_temps_nettoyage(Type espece);
