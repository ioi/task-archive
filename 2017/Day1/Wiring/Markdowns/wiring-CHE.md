# Verkabelung

Maryam ist Elektroingenieurin. Sie entwirft die Verkabelung an einem Fernmeldeturm. Auf dem Turm befinden sich einige Anschlusspunkte, welche an verschiedenen Höhen angebracht sind. Ein Kabel kann benutzt werden, um zwei beliebige Anschlusspunkte zu verbinden. Jeder Anschlusspunkt kann mit einer beliebigen Anzahl an Kabeln verbunden werden. Es gibt zwei Arten von Anschlusspunkten: rot und blau.

In dieser Aufgabe sollte der Turm als eine Linie, und die Anschlusspunkte als blaue und rote Punkte, die nichtnegative ganzzahlige Koordinaten auf dieser Linie sind, dargestellt werden. Die Länge eines Kabels ist die Distanz zwischen den zwei Anschlusspunkten, die es verbindet.

Hilf Maryam ein Verkabelungsschema zu finden, so dass:
1. Jeder Anschlusspunkt über mindestens ein Kabel mit einem Anschlusspunkt der anderen Farbe verbunden ist.
1. Die Gesamtlänge der Kabel minimiert ist.

## Implementierung

Du sollst folgende Funktion implementieren:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: Ein Array der Länge $n$. Enthält die Positionen der roten Anschlusspunkte in aufsteigender Reihenfolge.
* $b$: Ein Array der Länge $m$. Enthält die Positionen der blauen Anschlusspunkte in aufsteigender Reihenfolge.
* Diese Funktion sollte aus allen gültigen Verkabelungsschemata die minimale Gesamtlänge der Kabel ausgeben.
* Beachte, dass der Rückgabetyp dieser Funktion `int64` ist.

## Beispiel

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Die folgende Darstellung illustriert dieses Beispiel.
![Wiring](wiring.png)

* Der Turm ist horizontal dargestellt.
* In der schwarz-weiss gedruckten Fassung der Aufgabenstellung sind die roten Anschlusspunkte dunkel und die blauen hell dargestellt.
* Es gibt $4$ rote Anschlusspunkte, die sich an den Positionen $1, 2, 3$ und $7$ befinden.
* Es gibt $5$ blaue Anschlusspunkte, die sich an den Positionen $0, 4, 5, 9$ und $10$ befinden.
* Eine optimale Lösung wird in der obigen Darstellung gezeigt.
* In dieser Lösung beträgt die Gesamtlänge der Kabel $1 + 2 + 2 + 2 + 3 = 10$. Dies ist optimal. Deshalb sollte die Funktion $10$ ausgeben.
* Beachte, dass am Anschlusspunkt an Position $7$ zwei Kabel angeschlossen sind.

## Beschränkungen 

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (für alle $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (für alle $0 \leq i \leq m-1$),
* Jeder der Arrays $r$ und $b$ ist in aufsteigender Reihenfolge geordnet.
* Alle $n+m$ Werte in den Arrays $r$ und $b$ sind verschieden.

## Subtasks

1. (7 Punkte) $n, m \leq 200$,
1. (13 Punkte) Die Positionen aller roten Anschlusspunkte sind kleiner als die eines jeden blauen Anschlusspunktes.
1. (10 Punkte) Unter jeweils $7$ aufeinanderfolgenden  Anschlusspunkten gibt es mindestens einen roten Anschlusspunkt und einen blauen Anschlusspunkt.
1. (25 Punkte) Alle Anschlusspunkte haben verschiedene Positionen im Intervall $[1, n+m]$.
1. (45 Punkte) Keine weiteren Beschränkungen.

## Beispiel-Grader

Der Beispiel-Grader liest die Eingabe in folgendem Format:
* Zeile $1$: $\;\; n \;\; m$
* Zeile $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* Zeile $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Der Beispiel-Grader gibt eine einzige Zeile aus, die den Rückgabewert von `min_total_length` enthält.