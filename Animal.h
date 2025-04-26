typedef enum{
  CHIEN=1, CHAT, HAMSTER, AUTRUCHE, LAPIN
}Type;

typedef struct{
  int num;
  char nom[MAXCHAR];
  Type espece;
  float poids;
  int annee;
  char commentaire[MAXCOM];
}Animal;

void 
