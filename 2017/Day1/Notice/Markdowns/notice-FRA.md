# Notes d'implémentation

Chaque tâche a sa propre archive qui est disponible à la fois sur le CMS et sur votre bureau.

Pour les tâches "output-only"&nbsp;:
* L'archive contient les entrées de chaque test et des données d'exemple. 
Chaque test est une sous-tâche distincte.
* Vous pouvez soumettre plusieurs fichiers de sortie sous la forme d'un fichier zip. Pour cela, vos fichiers de sortie doivent être nommé `??.out`, où `??` est le numéro du test (e.g., `03.out`). Vous pouvez zipper plusieurs fichiers en utilisant la commande suivante: `zip output.zip *.out`
* Vous pouvez faire jusqu'à 100 soumissions pour les tâches "output-only". Dans chaque soumission, vous pouvez inclure les fichiers de sorties des sous-ensembles de tests que vous désirez.

Pour les autres tâches&nbsp;:
* L'archive contient des évaluateurs d'exemple, des implémentations d'exemple, des exemples de données de test et des scripts de compilation.
* Vous devez soumettre un seul fichier et vous pouvez faire jusqu'à 50 soumissions.
* Vos soumissions ne doivent pas lire depuis l'entrée standard, écrire sur la sortie standard ou intéragir avec des fichiers. Cependant elles peuvent écrire sur la sortie d'erreur standard.
* Le nom du fichier que vous devez soumettre est donné dans l'en-tête de l'énoncé de la tâche. 
Il doit implémenter les fonctions décrites dans l'énoncé de la tâche et utiliser les signatures données dans l'implémentation d'exemple.
* Vous êtes libre d'implémenter d'autres fonctions.
* Lorsque vous testez vos programmes avec l'évaluateur d'exemple, votre entrée doit correspondre au format et aux contraintes de l'énoncé, sans quoi le comportement est indéfini.

## Conventions

Les énoncés spécifient les signatures en utilisant les noms génériques `bool`, `integer`, `int64` et `int[]` (tableau).

Pour chacun des langages supportés, les évaluateurs utilisent les types de données appropriés suivants&nbsp;:

Langage | `bool` | `integer` | `int64` |  `int[]` | taille du tableau `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limites

Tâche | Limite de temps | Limite de mémoire
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 Mo
train | 2 sec | 256 Mo