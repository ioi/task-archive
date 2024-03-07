# Nowruz

Bald ist Nowruz, das persische Neujahr, zu dem Opa seine Familie in seinen Garten eingeladen hat.
Unter den Gästen sind $k$ Kinder, die Opa mit einem Versteckspiel unterhalten möchte.

Der Garten kann als $(m \times n)$-Raster von Feldern angesehen werden.
Einige (möglicherweise keine) der Felder sind von Steinen blockiert, die restlichen Felder sind *frei*.
Zwei Felder sind *benachbart*, wenn sie eine gemeinsame Kante haben, d.&#8239;h.
jedes Feld besitzt bis zu vier Nachbarn; zwei horizontale und zwei vertikale.
Opa möchte nun seinen Garten in ein Labyrinth verwandeln.
Dazu kann er einige freie Felder blockieren, indem er in ihnen Büsche pflanzt.
Diese Felder sind danach nicht mehr frei.

Ein Labyrinth muss folgende Eigenschaft erfüllen: Jedes Paar freier Felder $a$ und $b$ im Labyrinth ist mit genau einem *einfachen Pfad* verbunden.
Ein einfacher Pfad zwischen zwei Feldern $a$ und $b$ ist eine Folge von freien Feldern, welche mit $a$ beginnt und $b$ aufhört und deren Felder paarweise verschieden sind; ausserdem müssen aufeinanderfolgenden Felder benachbart sein.

Ein Kind kann sich in einem Feld verstecken, wenn es frei ist und *genau* einen freien Nachbarn besitzt.
In jedem Feld kann sich höchstens ein Kind verstecken. 

Gegeben ist eine Beschreibung des Gartens. Deine Aufgabe ist es, Opa zu helfen, diesen in ein Labyrinth umzuwandeln, in welchem sich viele Kinder verstecken können.

## Implementierungsdetails

Dies ist eine Output-Only-Aufgabe mit Teilpunkten.
Dir werden $10$ Eingabedateien zur Verfügung gestellt, die jeweils Opas Garten beschreiben.
Zu jeder dieser Eingabedateien sollst du eine Ausgabedatei mit der Beschreibung eines Labyrinths einsenden.
Für jede eingesendete Ausgabedatei erhältst du Punkte abhängig von der Anzahl Kinder, die sich in deinem Labyrinth verstecken können.

Beachte, dass du keinen Quellcode einsenden kannst, da dies eine Output-Only-Aufgabe ist.

## Eingabeformat

Jede Eingabedatei beschreibt ein Raster, welches den Garten repräsentiert, und gibt die Anzahl $k$ an Kindern, welche Opa eingeladen hat, in folgendem Format:

* Zeile 1: $\;\; m \;\; n \;\; k$
* Zeile $1+i$ (für $1\leq i\leq m$): Die $i$-te Reihe des Rasters, gegeben als Zeichenkette der Länge $n$, bestehend aus den folgenden Zeichen (ohne Leerzeichen):
  - '`.`': Ein freies Feld
  - '`#`': Ein Stein

## Ausgabeformat

* Zeile $i$ (für $1 \leq i \leq m$): Die $i$-te Reihe des Labyrinths (des Gartens, nachdem die Büsche gepflanzt wurden), repräsentiert als Zeichenkette der Länge $n$, bestehend aus den folgenden Zeichen (ohne Leerzeichen):
  -  '`.`': Ein freies Feld
  -  '`#`': Ein Stein
  -  '`X`': Ein Busch (beachte, dass der Buchstabe X ein Grossbuchstabe ist)
 
## Limits
 
* $1 \leq m, n \leq 1024$

## Bewertung

Deine Ausgabedatei wird als *gültig* angesehen, sofern sie
* der Eingabedatei entspricht, mit der Ausnahme, dass beliebig viele Zeichen '`.`' mit '`X`' ersetzt wurden (diejenigen Felder, welche mit Büschen blockiert sind) und
* die Eigenschaften eines Labyrinths erfüllt, wie in der Aufgabe beschrieben.

Ist deine Ausgabe für einen Testfall nicht gültig, erhält sie $0$ Punkte. Andernfalls ist ihre Punktzahl $\min(10, 10 \cdot l/k)$ Punkte, abgerundet auf 2 Dezimalstellen nach dem Komma.
Hier ist $l$ die Anzahl Kinder, die sich in deinem Labyrinth verstecken können und $k$ die Anzahl gegeben in der Eingabe.
Du erhältst $10$ Punkte für einen Testfall genau dann, wenn deine Ausgabe ein Labyrinth ist, in welchem sich mindestens $k$ Kinder verstecken können.
Es ist garantiert, dass für jeden Testfall eine Lösung existiert, welche $10$ Punkte erzielt.

Beachte, dass gültige Lösungen, welche nach obiger Formel $0$ Punkte erzielen, vom Bewertungssystem als "Wrong Answer" angezeigt werden.

## Beispiel
Für folgende Eingabe:
 ```
4 5 5
....#
.#..#
...#.
....#
```
wäre dies eine mögliche gültige Ausgabe:
 
```
.X.X#
.#..#
...#X
XX..#
```

Es können sich $l=4$ Kinder im Labyrinth verstecken, deshalb würde diese Lösung  $10 \cdot 4 / 5 = 8$ Punkte erhalten. Die Felder, in denen sich Kinder verstecken können, sind unten mit einem  '`O`' markiert:

```
OXOX#
.#.O#
...#X
XX.O#
```

Hingegen sind nachfolgende drei Ausgaben nicht gültig:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

In der linken Ausgabe gibt es keinen einfachen Pfad zwischen dem freien Feld in der oberen linken Ecke und dem freien Feld in der rechten Spalte.
In den beiden anderen Ausgaben gibt es für je zwei verschiedene freie Felder genau zwei unterschiedliche einfache Pfade.

