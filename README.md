# TicTacToe

Jeu TicTacToe écrit en c++

## Pseudocode initial



## Pseudocode no. 2

Entrées:
	playerInput: saisie de l'utilisateur

Algorithme:
	- Boucle de jeu while qui attend la saisie de l'utilisateur
	- Les cases ont des touches définies pour chacune et l'utilisateur choisit quelle case il veut remplir
	- Après la saisie de la touche on regarde le playerInput
		Si la case est vide
        {
			• La case sera remplie avec le symbole du joueur selon la variable currentPlayer
			- On vérifie le résultat de la partie
				Si victoire
                {
					• Fin de la partie et victoire du currentPlayer
				}
				Sinon si egalité
                {
					• Fin de la partie sans gagnant
				}
				Sinon
                {
					• On passe au joueur suivant en modifiant la valeur de la variable currentPlayer
				}
		}
		Sinon
		{
			• On ne fait rien car la case est déjà remplie et on laisse le joueur rechoisir une case
		}
		
Sorties:
	Résultat de la partie si terminée par victoire ou égalité ou continuation de celle-ci
	