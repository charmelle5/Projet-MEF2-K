typedef enum{
  CHIEN, CHAT, HAMSTER, AUTRUCHE, LAPIN, POISSON
}Type;

typedef struct{
  int num;
  char nom[50];
  Type espece;
  float poids;
  int annee;
}Animal;
