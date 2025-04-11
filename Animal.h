typedef enum{
  CHIEN=1, CHAT, HAMSTER, AUTRUCHE, LAPIN, POISSON
}Type;

typedef struct{
  int num;
  char nom[MAXCHAR];
  Type espece;
  float poids;
  int annee;
  char* commentaire[MAXCOM];
}Animal;
