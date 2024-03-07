# Notes d'implémentation

Chaque tâche a sa propre archive qui est disponible à la fois sur le CMS et sur votre bureau.

* L'archive contient des évaluateurs d'exemple, des implémentations d'exemple, des exemples de données de test et des scripts de compilation.
* Vous devez soumettre un seul fichier et vous pouvez faire jusqu'à 50 soumissions.
* Vos soumissions ne doivent pas lire depuis l'entrée standard, écrire sur la sortie standard ou intéragir avec des fichiers. Cependant elles peuvent écrire sur la sortie d'erreur standard.
* Le nom du fichier que vous devez soumettre est donné dans l'en-tête de l'énoncé de la tâche. 
Il doit implémenter les fonctions décrites dans l'énoncé de la tâche et utiliser les signatures données dans l'implémentation d'exemple.
* Vous êtes libre d'implémenter d'autres fonctions.
* Lorsque vous testez vos programmes avec l'évaluateur d'exemple, votre entrée doit correspondre au format et aux contraintes de l'énoncé, sans quoi le comportement est indéfini.

## Conventions

Les énoncés spécifient les signatures en utilisant les noms génériques `bool`, `integer`, `int64` et `int[]` (tableau).

Pour chacun des langages supportés, les évaluateurs utilisent les types de données suivants&nbsp;:

Langage | `bool` | `integer` | `int64` |  `int[]` | taille du tableau `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limites

Tâche | Limite de temps | Limite de mémoire
--- | --- | ---
prize | 1 sec | 1024 Mo
simurgh | 3 sec | 1024 Mo
books | 2 sec | 1024 Mo