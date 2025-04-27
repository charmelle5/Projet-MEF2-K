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

// Prototypes //
void creation_animaux();
void ajouter_animal(Animal** chenil, int* taille);
void rechercher_animal(Animal* chenil, int taille);
void afficher_animal(Animal a);
void sauvegarder_chenil(Animal* chenil, int taille);
void charger_chenil(Animal** chenil, int* taille);
