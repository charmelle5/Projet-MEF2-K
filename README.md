
MEF2 groupe K


# PROJET ChenYl-TECH
<img src="./chenyl.png" alt="chenyl" width="400"/>

##  Table des matières

- [Introduction](#Introduction)
- [Pré-requis](#Pré-requis)
- [Guide d'installation](#Guide-d'installation)
- [Guide d'utilisation](#Guide-d'utilisation)
- [Structure du Projet](#Structure-du-projet)
- [Auteurs](#Auteurs)
  
## Introduction 📝

Notre projet consiste à créer un programme en langage C pour aider à gérer le chenil ChenYl-Tech. Le chenil accueille différents types d'animaux et les propose à l’adoption.
Le programme permet d’ajouter, rechercher, modifier et supprimer les fiches des animaux à partir d’une interface texte. Toutes les informations seront enregistrées dans des fichiers pour garder une trace des animaux. Ce projet a pour objectif de rendre la gestion du chenil plus fluide et plus rapide.

## Pré-requis

- GCC
- Make

## Guide d'installation 📔 


```bash
### Clonez le dépôt
git clone https://github.com/celiast05/CY-BER_Path.git 

### Accédez au répertoire du projet
cd CY-BER_Path

### Compilez le projet
make
```

## Guide d'utilisation 📋

### Exécuter le programme
./CY-BER_Path

### Exemple d'utilisation
Notre procédure pour placer les cibles aléatoirement.

```bash
void placeTarget (Grid gridGame, Coordinate coord){
    int createTarget = 0;
    while (createTarget < 18){
        coord = createCoordinate(rand() % gridGame.width, rand() % gridGame.height);
        if (validePlacementTarget(gridGame, coord)){
           gridGame.cases[coord.y][coord.x].type = TARGET;
           gridGame.cases[coord.y][coord.x].id = 1 + createTarget;
           createTarget++;
        }
    }
}
```

## Structure du projet 
La structure de notre projet est la suivante :

CY-BER_Path/                           

| main.c                                   # Code source

| game.c                                   # Exemple de module

   └── gcc –c createGrid.c -o createGrid.o  # Fichier d'en-tête
  
   └── gcc –c test_grid.c -o test_grid.o
  
   └── gcc –c game.c -o game.o
  
| gcc createGrid.o test_grid.o game.c -o   # Exécution 

| game.h                                   # Header commun

| Makefile                                 # Compilation

| README.md                                # Ce fichier


## Auteurs 👤  

👤 ASTIER Célia

👤 BIDI SINDA Grace

👤 NJANKOU NANA Charmelle
