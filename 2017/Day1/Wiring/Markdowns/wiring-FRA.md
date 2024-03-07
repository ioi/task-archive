# Câblage (Wiring)

Maryam est ingénieure électricienne.
Elle conçoit les câblages d'une tour de communication.
La tour est dotée de points de connexion, disposés à différentes hauteurs.
Un câble peut être utilisé pour connecter n'importe quelle paire  de points de connexion. 
Chaque point de connexion peut être connecté à un nombre quelconque de câbles.
Il y a deux types de points de connexion&nbsp;: des rouges et des bleus.

Dans le cadre de ce problème, la tour peut être vue comme une ligne et les points de connexion
comme des points bleus et rouges placés à des coordonnées entières positives sur cette ligne.
La longueur d'un câble est la distance entre les deux points de connexion qu'il connecte.

Votre but est d'aider Maryam à trouver le plan de câblage tel que&nbsp;:
1. Chaque point de connexion est câblé à au moins un point de connexion d'une autre couleur.
1. La longueur totale de câble est minimisée.

## Détails d'implémentation

Vous devez implémenter les fonctions suivantes:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$&nbsp;: tableau de taille $n$ contenant les positions des points de connexion rouges, par ordre croissant.
* $b$&nbsp;: tableau de taille $m$ contenant les positions des points de connexion bleus, par ordre croissant.
* Cette fonction doit renvoyer la longueur totale minimale de câbles parmi toutes les configurations possibles.
* Notez que le type de retour de cette fonction est `int64`.

## Exemple

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Le schéma suivant illustre cet exemple.
![Wiring](wiring.png)

* La tour est schématisée horizontalement.
* Dans la solution imprimée en noir et blanc de l'énoncé, les points de connexion rouges sont foncés, les bleus sont clairs.
* Il y a $4$ points de connexion rouges, situés aux positions $1, 2, 3$ et $7$.
* Il y a $5$ points de connexion bleus, situés aux positions $0, 4, 5, 9$ et $10$.
* Le schéma ci-dessus montre une solution optimale.
* Dans cette solution, la longueur totale des câbles est de $1 + 2 + 2 + 2 + 3 = 10$, ce qui est optimal.
La fonction doit donc retourner $10$.
* Notez que deux câbles sont connectés au point de connexion à la position $7$.

## Contraintes

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (pour tout $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (pour tout $0 \leq i \leq m-1$),
* Les tableaux $r$ et $b$ sont triés par ordre croissant.
* Les $n+m$ valeurs dans les tablaux $r$ et $b$ sont distinctes.

## Sous-tâches

1. (7 points) $n, m \leq 200$,
1. (13 points) Tous les points de connexion rouges ont des positions inférieures à tous les points de connexion bleus.
1. (10 points) Il y a au moins un point de connexion rouge et un point de connexion bleu parmi tout ensemble de $7$ points de connexion consécutifs.
1. (25 points) Tous les points de connexions sont dans l'intervalle $[1, n+m]$ avec des positions distinctes.
1. (45 points) Aucune contrainte supplémentaire.

## Évaluateur d'exemple

L'évaluateur d'exemple lit l'entrée dans le format suivant&nbsp;:
* ligne $1$&nbsp;: $\;\; n \;\; m$
* ligne $2$&nbsp;: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* ligne $3$&nbsp;: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

L'évaluateur d'exemple affiche une seule ligne contenant la valeur de retour de `min_total_length`.