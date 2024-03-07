# Cableado

Maryam es una Ingeniera Eléctrica.
Ella está diseñando el cableado de una torre de comunicaciones.
En la torre hay varios *puntos de conexión*, distribuidos en distintas alturas. 
Cada cable puede ser utilizado para conectar dos *puntos de conexión* cualquiera.
Cada *punto de conexión* puede ser conectado por un numero arbitrario de cables.
Existen dos tipos de *puntos de conexión*: rojos y azules.

Para propósitos de este problema, la torre puede ser vista como una línea, y los *puntos de conexión* son puntos rojos y azules con coordenadas no negativas sobre esta línea.
El tamaño de un cable es la distancia entre los dos *puntos de conexión* que conecta.

Tu objetivo es ayudar a Maryam a diseñar un cableado con las siguientes características:
1. Cada *punto de conexión* tiene por lo menos un cable que lo conecta a otro *punto de conexión* de diferente color.
1. La suma total del tamaño de los cables sea mínima. 

## Detalles de implementación

Deberás implementar el siguiente procedimiento:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: Arreglo de tamaño $n$ que contiene las posiciones de los *puntos de conexión* rojos en orden creciente. 
* $b$: Arreglo de tamaño $m$ que contiene las posiciones de los *puntos de conexión* azules en orden creciente. 
* Tu procedimiento debe regresar la mínima longitud de cable usado, de entre todos los diseños de conexión válidos.
* Observa que el tipo de dato que regresa este procedimiento es `int64`.

## Ejemplo

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

La imagen de abajo ilustra este ejemplo.
![Wiring](wiring.png)

* La torre se muestra horizontalmente en la imagen.
* En la versión impresa en blanco y negro, los puntos rojos son oscuros y los azules son claros. 
* Hay $4$ *puntos de conexión* rojos, localizados en las posiciones  $1, 2, 3,$ y $7$.
* Hay $5$ *puntos de conexión* azules, localizados en las posiciones $0, 4, 5, 9,$ y $10$.
* La imagen de arriba muestra una solución óptima.
* En esta solución, la suma total del tamaño de los cables es  $1 + 2 + 2 + 2 + 3 = 10$, la cual es óptima.
Entonces el procedimiento deberá de regresar $10$.
* Observa que se conectaron dos cables en el *punto de conexión*  $7$.

## Restricciones

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (para toda $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (para toda $0 \leq i \leq m-1$),
* Cada uno de los arreglos $r$ y $b$ están ordenados en orden ascendente.
* Todos los $n+m$ valores en los arreglos $r$ y $b$ son distintos.

## Subtareas

1. (7 puntos) $n, m \leq 200$,
1. (13 puntos) Todos los *puntos de conexión* rojos tienen posiciones menores a las posiciones de cualquier *punto de conexión* azul.
1. (10 puntos) Hay al menos un *punto de conexión* rojo y un *punto de conexión* azul entre cada $7$ puntos de conexión consecutivos.
1. (25 puntos) Todos los *puntos de conexión* tienen posiciones distintas en el rango  $[1, n+m]$.
1. (45 puntos) Sin ninguna restricción adicional.

## Evaluador de ejemplo

El evaluador de ejemplo lee la entrada en el siguiente formato:
* Línea $1$: $\;\; n \;\; m$
* Línea $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* Línea $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

El evaluador de ejemplo imprime una sola línea con el valor retornado por  `min_total_length`.