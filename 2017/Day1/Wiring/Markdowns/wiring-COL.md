# Cableado

Maryam es una ingeniero eléctrico.
Ella está diseñando el cableado en una torre de comunicaciones.
En la torre hay algunos puntos de conexión ubicados a distintas alturas.
Un cable puede ser usado para conectar cualquier par de puntos de conexión.
Cada punto de conexión puede ser conectado a un número arbitrario de cables.
Existen dos tipos de puntos de conexión: rojo y azul.

Para los propósitos de este problema, la torre debe ser vista como una línea y los puntos de conexión
como puntos rojos y azules que se encuentran en coordenadas enteras no negativas sobre esta línea.
La longitud de un cable es la distancia entre los dos puntos de conexión que este conecta.

Su objetivo es ayudar a Maryam a encontrar un esquema de cableado tal que:
1. Cada punto de conexión tenga al menos un cable hacia un punto de conexión de color diferente.
1. La longitud total de los cables sea minimizada.

## Detalles de implementación

Debe implementar el siguiente procedimiento:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: arreglo de largo $n$ que contiene las posiciones de los puntos de conexión rojos en orden ascendente.
* $b$: arreglo de largo $m$ que contiene las posiciones de los puntos de conexión azules en orden ascendente.
* Este procedimiento debe retornar la longitud total mínima de los cables, entre todos los esquemas de conexión válidos.
* Note que el tipo de retorno de este procedimiento es `int64`.

## Ejemplo

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

La figura de abajo ilustra este ejemplo.
![Wiring](wiring.png)

* La torre se muestra horizontalmente.
* En la versión impresa en blanco y negro del enunciado del problema, los puntos de conexión rojos son los oscuros y los azules son claros.
* Hay $4$ puntos de conexión rojos, ubicados en las posiciones $1, 2, 3,$ y $7$.
* Hay $5$ puntos de conexión azules, ubicados en las posiciones $0, 4, 5, 9,$ y $10$.
* Una solución óptima se muestra en la figura de arriba.
* En esta solución, la longitud total de los cables es $1 + 2 + 2 + 2 + 3 = 10$, que es óptima. Por lo tanto, el procedimiento debe retornar $10$.
* Note que dos cables han sido conectados al punto en la posición $7$.

## Restricciones

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (para todo $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (para todo $0 \leq i \leq m-1$),
* Cada uno de los arreglos $r$ y $b$ están ordenados de forma ascendente.
* Todos los $n + m$ valores en los arreglos $r$ y $b$ son distintos.

## Subtareas

1. (7 puntos) $n, m \leq 200$.
1. (13 puntos) Todos los puntos de conexión rojos tienen posiciones menores que cualquier punto de conexión azul.
1. (10 puntos) Hay al menos un punto de conexión rojo y un punto de conexión azul entre cada $7$ puntos de conexión consecutivos.
1. (25 puntos) Todos los puntos de conexión tienen posiciones diferentes en el rango  $[1, n+m]$.
1. (45 puntos) No existen restricciones adicionales.

## Calificador de prueba

El calificador de prueba lee la entrada en el formato siguiente:
* línea $1$: $\;\; n \;\; m$
* línea $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* línea $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

El calificador de prueba imprime una sóla línea que contiene el valor de retorno de `min_total_length`.
