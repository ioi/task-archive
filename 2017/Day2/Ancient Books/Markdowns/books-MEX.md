# Libros Antiguos 
<br>
La ciudad de Teherán es hogar de la Biblioteca Nacional de Irán. 
El principal atractivo de esta biblioteca, se encuentra en el largo pasillo con una fila de $n$ mesas, numeradas de izquierda a derecha del $0$ a $n-1$.
En cada mesa hay un antiguo libro escrito a mano siendo exhibido.
Estos libros están ordenados con base a su antigüedad, haciendo complicado a los visitantes buscar los libros por su nombre.
Para solucionar esto, el encargado de la biblioteca ha decidido ordenar los libros en orden alfabético de acuerdo a sus títulos. 
<br>

Aryan, el bibliotecario, realizara el trabajo.
Él ha creado una lista $p$ de tamaño $n$, que contiene diferentes enteros entre $0$ y $n-1$.
Esta lista describe los cambios necesarios para reacomodar los libros en orden alfabético:
para todo $0 \leq i < n$, el libro que está actualmente sobre la mesa $i$ debe ser trasladado a la mesa $p[i]$.
<br>

Aryan comienza el trabajo en la mesa $s$.
Él desea regresar a la misma mesa una vez que termine de ordenar los libros.
Debido a que los libros son muy valiosos, él no puede cargar más de un libro al mismo tiempo.

Mientras ordena los libros, Aryan realizará una serie de acciones.
Cada una de estas acciones, puede ser alguna de las siguientes:
* Si él no está cargando un libro y hay un libro sobre la mesa frente a él, puede tomar ese libro.
* Si él está cargando un libro y hay un libro sobre la mesa frente a él, puede cambiar el libro que está cargando por el que está sobre la mesa. 
* Si él está cargando un libro y la mesa está vacía, puede dejar el libro que carga sobre esa mesa.
* Él puede caminar hacia cualquier mesa y cargar a lo más un solo libro mientras lo hace.

Para todo $0 \leq i, j \leq n - 1$, la distancia entre las mesas $i$ y $j$ es exactamente $|j-i|$ metros. Tu tarea es calcular la distancia total mínima que debe caminar Aryan para ordenar todos los libros alfabéticamente y regresar a donde comenzó.
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>

## Detalles de implementación

Deberás implementar el siguiente procedimiento:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ es un arreglo de tamaño $n$.
El libro que está inicialmente sobre la mesa $i$, debe ser llevado por Aryan a la mesa $p[i]$ (para todo $0 \leq i < n$).
* $s$ es la posición de la mesa donde Aryan comienza, y a la cual debe regresar después de terminar de ordenar los libros.
* Este procedimiento deberá regresar la distancia total mínima en metros, que Aryan debe caminar para ordenar los libros alfabéticamente.

## Ejemplo

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

En este ejemplo, $n=4$ y Aryan comienza en la mesa $0$.
Él ordena los libros de la siguiente forma:
* Camina de a la mesa $1$ y recoge el libro que esta sobre ella. Este libro debe ser llevado a la mesa $2$.
* Luego, camina a la mesa $2$ y cambia el libro que está cargando por el que está sobre la mesa.
El libro que acaba de tomar, debe ser llevado a la mesa $3$.
* Después, Aryan camina a la mesa $3$ y cambia el libro que está cargando por el que está sobre la mesa.
El libro que acaba de tomar, debe ser llevado a la mesa $1$.
* Posteriormente, camina a la mesa $1$ y deja el libro que está cargando sobre la mesa.
* Finalmente, él camina de regreso a la mesa $0$.

Observa que el libro de la mesa $0$ estaba inicialmente en lugar correcto (mesa $0$), entonces Aryan no tuvo que moverlo.
La distancia total que Aryan camina en esta solución es de $6$ metros.
Esta es la solución óptima. Por lo tanto, tu procedimiento debe regresar $6$.

## Restricciones

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* El arreglo $p$ contiene $n$ números enteros distintos entre $0$ y $n-1$, inclusive.

## Subtareas

1. (12 puntos) $n \le 4$ y $s = 0$
1. (10 puntos) $n \le 1000$ y $s = 0$
1. (28 puntos) $s = 0$
1. (20 puntos) $n \le 1000$
1. (30 puntos) sin restricciones adicionales. 

## Evaluador de ejemplo

El evaluador de ejemplo lee la entrada en el siguiente formato:

- Línea $1$: $\;\; n \;\; s$
- Línea $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

El evaluador de ejemplo imprime una sola línea que contiene el valor retornado por el procedimiento `minimum_walk`.