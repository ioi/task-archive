# Nowruz

Faltan pocos días para Nowruz (año nuevo persa), y el abuelo ha invitado a la familia a su jardín.
Entre los invitados hay $k$ niños.
Para hacer la la reunión más divertida para ellos, el abuelo va a organizar un juego de las escondidas.

El jardín puede ser representado como una cuadrícula de $m \times n$ celdas. 
Algunas celdas (posiblemente ninguna) están bloqueadas por rocas y las demás celdas se denominan *libres*.
Dos celdas son *vecinas* si comparten un lado.
Es decir, cada celda tiene hasta 4 vecinos: dos horizontales y dos verticales. 
El abuelo quiere convertir el jardín en un laberinto.
Para esto puede bloquear algunas celdas plantando arbustos en ellas.
Las celdas con arbustos ya no se consideran libres.

Un laberinto debe cumplir lo siguiente:
Para cada par $a$ y $b$ de celdas libres, debe haber exactamente un *camino simple* entre ellas.
Un camino simple entre las celdas $a$ y $b$ es una secuencia de celdas libres en la que la primera celda es $a$ y la última es $b$, todas las celdas son distintas y cada par de celdas consecutivas son vecinas.

Un niño se puede esconder en una celda si y solo si esa celda es libre y tiene *exactamente* un vecino libre.
Dos niños no se pueden esconder en la misma celda.

Se te dará el mapa del jardín como entrada.
Tu tarea es ayudar al abuelo a crear un laberinto donde muchos niños se puedan esconder.

## Detalles de implementación

Este es un problema de sólo salida con puntos parciales.
Se te darán 10 archivos de entrada, cada uno describiendo el jardín del abuelo.
Para cada archivo de entrada deberás mandar un archivo de salida con el mapa del laberinto.
Para cada archivo de salida se te darán puntos dependiendo del número de niños que se pueden esconder en tu laberinto.

No debes enviar código fuente para este problema.

<br>
<br>
<br>
<br>
<br>
<br>
## Formato de entrada

Cada archivo describe una cuadrícula que representa el jardín y te da el número de niños $k$ invitados por el abuelo. El formato es el siguiente:
* La primera línea contiene $\;\; m \;\; n \;\; k$.
* Las siguientes $m$ líneas contienen una cadena de $n$ caracteres (sin espacios) donde:
  - '`.`' es una casilla libre,
  - '`#`' es una roca.

## Formato de salida

* $m$ líneas que representan los renglones del laberinto (el jardín después de que se plantaron los arbustos). Cada línea es una cadena de $n$ caracteres (sin espacios) donde:
  - '`.`' es una casilla libre,
  - '`#`' es una roca,
  - '`X`' es un arbusto (La letra X debe ser mayúscula).

## Restricciones

* $1 \leq m, n \leq 1024$

## Puntuación

Un archivo de salida se considera *válido* si todas las siguientes condiciones se cumplen:
* El archivo de salida debe coincidir con el archivo de entrada con la única excepción de que los caracteres '`.`' se pueden cambiar por '`X`' (celdas bloqueadas por arbustos)
* El archivo de salida debe cumplir las propiedades de un laberinto como se definió anteriormente.

Si la salida de un caso de prueba no es válida, tu puntaje será $0$ para ese caso. 
Si es válida, el puntaje será $\min(10, 10 \cdot l/k)$ redondeado hacia abajo con dos decimales.
$l$ es el número de niños que se pueden esconder en tu laberinto de salida y $k$ es el número definido en la entrada.
Obtendrás $10$ puntos por caso de prueba si y solo si tu salida es un laberinto en el que $k$ o más niños se pueden esconder.
Para cada caso existe una solución que puede sacar $10$ puntos.

Si tu solución es válida pero saca $0$ puntos de acuerdo a la formula anterior, el veredicto que verás en el CMS será 'Wrong Answer'.

<br>
<br>
<br>
## Ejemplo

Considera la siguiente entrada:

```
4 5 5
....#
.#..#
...#.
....#
```

La siguiente es una posible solución válida:

```
.X.X#
.#..#
...#X
XX..#
```

Como $l=4$ niños se pueden esconder en este laberinto, esta solución recibirá $10 \cdot 4 / 5 = 8$ puntos. Las celdas en las que los niños se pueden esconder están marcadas con `O` a continuación:

```
OXOX#
.#.O#
...#X
XX.O#
```

Las siguientes 3 salidas no son válidas:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

En la izquierda no hay un camino libre entre la celda libre en la esquina superior izquierda y la celda libre en la columna de hasta la derecha. En las otras dos salidas, para cada par de celdas libres hay exactamente dos caminos libres distintos entre ellas. 
