void Ajouter_animal(Animal* chenil, int taille){
  if(chenil == NULL|| taille<0){
    printf("Erreur !");
    exit(1);
  }
  if(taille==50){
    printf("Le chenil est plein, nous ne pouvons pas acceuillir un nouvel animal ");
  }
  else{
    Animal* Newchenil = malloc((taille+1)*sizeof(Animal));
    for (int i = 0; i < taille; i++)
    {
        Newchenil[i] = chenil[i];
    }
    Newchenil[taille+1] = creation_animaux();
    Newchenil[taille+1].num = rand()%100;
