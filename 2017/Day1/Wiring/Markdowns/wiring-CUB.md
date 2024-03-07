## Cableado

Maryam es una ingeniera eléctrica. Ella está diseñando el cableado en una torre de comunicación. En la torre hay algunos puntos de conexión, colocados a distintas alturas. Se puede utilizar un cable para conectar cualesquiera dos puntos de conexión. Cada punto de conexión se puede conectar a un número arbitrario de cables. Hay dos tipos de puntos de conexión: rojos y azules.

En este problema la torre debe ser vista como una línea y los puntos de conexión como puntos azules y rojos que están en coordenadas enteras no negativas sobre esta línea. La longitud de un cable es la distancia entre los dos puntos de conexión que conecta.

Su objetivo es ayudar a Maryam a encontrar un esquema de cableado tal que:

1. Cada punto de conexión tenga al menos un cable a un punto del otro color.
1. La longitud total de los cables sea minima.

## Detalles de implementación

Debe implementar el siguiente procedimiento:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: Arreglo de longitud $n$ que contiene las posiciones de los puntos de conexión rojos en orden creciente.
* $b$: Arreglo de longitud $m$ que contiene las posiciones de los puntos de conexión azules en orden creciente.
* Este procedimiento debe devolver la longitud total mínima de cables, entre todos los esquemas de cables válidos.
* Tenga en cuenta que el tipo de retorno de este procedimiento es int64.

## Ejemplo

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

La siguiente figura ilustra este ejemplo.
![Wiring](wiring.png)

* La torre se muestra horizontalmente.
* En la versión impresa en blanco y negro del problema, los puntos de conexión rojos son oscuros y los azules son claros.
* Hay $4$ puntos de conexión rojos, situados en las posiciones $1, 2, 3$ y $7$.
* Hay $5$ puntos de conexión azules, situados en las posiciones $0, 4, 5, 9$ y $10$.
* Una solución óptima se muestra en la figura anterior.
* En esta solución, la longitud total de los cables es $1 + 2 + 2 + 2 + 3 = 10$, lo que es óptimo. Asi que, el procedimiento debe retornar $10$.
* Tenga en cuenta que dos cables están conectados al punto de conexión de la posición $7$.

## Restriciones

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (for all $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (for all $0 \leq i \leq m-1$),
* Cada arreglo $r$ y $b$ está ordenado en orden ascendente.
* Todos los $n+m$ valores en los arreglos $r$ y $b$ son distintos.

## Subtareas

1. (7 points) $n, m \leq 200$,
1. (13 points) Todos los puntos rojos tienen posiciones más pequeñas que cualquier punto azul. 
1. (10 points) Hay al menos un punto de conexión rojo y un punto de conexión azul entre cada $7$ puntos de conexión consecutivos. 
1. (25 points) Todos los puntos de conexión tienen diferentes posiciones en el rango $[1, n+m]$.
1. (45 points) Sin restricciones adicionales.

## Evaluador de ejemplo

El evaluador de ejemplo lee la entrada en el siguiente formato:
* Línea $1$: $\;\; n \;\; m$
* Línea $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* Línea $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

El evaluador de ejemplo imprime una línea con el valor devuelto de `min_total_length`.
