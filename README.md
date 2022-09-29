# TicTacToe
Jeu TicTacToe écrit en C++ pour le Labo 1 de PRG1
## Pseudo code vérification des cases   
### Entrées: 
- `grid[3][3]`: grille de jeu représentée par un tableau à 2 dimensions
- `EMPTY = 0`: constante représentant la valeur d'une case vide dans le tableau `grid`
- `PLAYER1 = 1`: constante représentant la valeur d'une case remplie par le joueur 1 dans le tableau `grid` 
- `PLAYER2 = 2`: constante représentant la valeur d'une case remplie par le joueur 2 dans le tableau `grid`
### Algorithme:
On remplit le tableau `grid` avec les valeurs constanstes afin de tester notre algorithme:
2 1 2
0 1 0
0 1 0
Nous avons pensé à définir une fonction `checkLine()` qui prendrait comme arguments `grid` ainsi que 3 positions; Cette fonction retournerait `EMPTY`, `PLAYER1` ou `PLAYER2` si les cases sont identiques dans ces 3 positions en utilisant l'opérateur AND `&`.
Enfin pour trouver la valeur `winner` on éxécute `checkline()` pour toutes les lignes horizontales, verticales et diagonales et on utilise l'opérateur OR `|` pour les résultats retournés de la fonction.
### Sortie:
Si `winner` est égal à `EMPTY` alors il n'y a pas de gagnant sinon il sera `PLAYER1` ou `PLAYER2`
## Pseudo code jouabilité 2 joueurs
### Entrées: 
- `currentPlayer`: joueur actuel
- `playerInput`: saisie de l'utilisateur

### Algorithme:
- Boucle de jeu while qui attend la saisie de l'utilisateur 
- Les cases ont des touches définies pour chacune et l'utilisateur choisit quelle case il veut remplir 
- Après la saisie de la touche on regarde le playerInput 
```sh
    if(case == EMPTY)
    {
        La case sera remplie avec le symbole du joueur selon la variable currentPlayer 
        Aprés on vérifie le résultat de la partie
            if(result == win)
            {
                Fin de la partie et victoire de currentPlayer
            }
            else if(result == draw)
            {
                Fin de la partie sans gagnant
            }
            else
            {
                Joueur suivant en modifiant la variable currentPlayer
            }
    }
    else
    {
        On ne fait rien et on laisse le joueur rechoisir une case
    }
``` 

### Sorties: 
Résultat de la partie si terminée par victoire ou égalité ou continuation de celle-ci
