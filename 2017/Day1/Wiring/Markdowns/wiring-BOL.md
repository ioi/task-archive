# Cableado

Maryam es una ingeniera eléctrica. Ella está diseñando el cableado en una torre de comunicación. En la torre hay algunos puntos de conexión, posicionados en distintas alturas. Un cable puede ser conectado a cualquier par de puntos de conexión. Cada punto de conexión puede estar conectado a un número arbitrario de cables. Hay dos tipos de puntos de conexión: rojos y azules.

En este problema la torre debe ser vista como una linea y los puntos de conexión como puntos azules y rojos que estan en coordenadas enteras no negativas sorbre esta linea. La longitud de un cable es la distancia entre los dos puntos de conexión que conecta.

Tu tarea es ayudar a Maryam a encontrar una configuración tal que:
1. Cada punto de conexión tiene al menos un cable a un punto de diferente color.
2. La longitud total de los cables sea minima.

## Detalles de implementación

Debes implementar la siguiente función:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: arreglo de tamaño $n$ que contiene las posiciones de los puntos de conexión rojos en orden creciente.
* $b$: arreglo de tamaño $m$ que contiene las posiciones de los puntos de conexión azules en orden creciente.
* Esta funcion debe retornar, de todas las configuraciones validas, la minima longitud total de los cables.
* Notese que la funcion retorna un valor de tipo `int64`.

## Ejemplo

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

La figura de abajo ilustra el ejemplo.
![Wiring](wiring.png)

* Se ve la torre de forma horizontal.
* En la version blanco y negro del enunciado, los puntos de conexion rojos son oscuros y los azules son claros.
* Hay $4$ puntos rojos de conexion, ubicados en las pocisiones $1, 2, 3$ y $7$.
* Hay $5$ puntos azules de conexion, ubicados en las posiciones $0, 4, 5, 9$ y $10$.
* Una solucion optima es mostrada en la figura de arriba.
* En esta solucion, la longitud total de cables es $1 + 2 + 2 + 2 + 3 = 10$, la cual es optima.
Asi que la funcion debe retornar $10$.
* Notese que dos cables estan conectados al punto de conexion en la posicion $7$.

## Restricciones

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (para todo $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (para todo $0 \leq i \leq m-1$),
* Ambos arreglos $r$ y $b$ estan en orden creciente.
* Todos los $n+m$ valores en los arreglos $r$ y $b$ son distintos.

## Subtareas

1. (7 puntos) $n, m \leq 200$,
1. (13 puntos) Todos los puntos de conexion rojos tienen posiciones menores que cualquier punto de conexion azul.
1. (10 puntos) Hay al menos un punto de conexion rojo y un punto de conexion azul dentro de cada $7$ puntos de conexion consecutivos.
1. (25 puntos) Todos los puntos de conexion tienen diferentes posiciones en el rango $[1, n+m]$.
1. (45 puntos) No hay restricciones adicionales.

## Evaluador de ejemplo

El evaluador de ejemplo lee la entrada en el siguiente formato:
* linea $1$: $\;\; n \;\; m$
* linea $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* linea $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

El evaluador de ejemplo imprime una sola linea que contiene el valor que retorna `min_total_length`.
