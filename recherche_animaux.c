void Rechercher_animal(Animal* chenil1, int SIZE){
   if(chenil == NULL){
    printf("Erreur !");
    exit(1);
  }
char* nom; 
int espece;
printf("Taper le nom de l'animal :" \n)
scanf("%s",&nom);
printf("Taper l'espèce de l'animal : 1:Chien\n 2:Chat\n 3:Hamster\n 4:Autruche\n 5:Lapin\n 6:Poisson\n");
scanf("%d",&espece);
if(espece<1 || espece>6){
   printf("Erreur");
   printf("Saisir une numéro : 1:Chien\n 2:Chat\n 3:Hamster\n 4:Autruche\n 5:Lapin\n 6:Poisson\n");
   scanf("%d",&espece);
}
printf("Taper l'age de l'animal :" \n)
scanf("%d",nom);
for(int i=0; i<SIZE;i++){
   if( strcmp(nom)!=strcmp(chenil1[i].nom && espece != chenil1[i].espece ){
      
   }


