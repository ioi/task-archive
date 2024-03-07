# Aviso

Cada tarea tiene un paquete adjunto que está disponible en el sistema y en el escritorio de su computador.

Para tareas "output-only":
* El paquete adjunto contiene casos de prueba y ejemplos de casos de prueba. Cada caso de prueba es una subtarea.
* Usted puede enviar varios archivos de salida como un archivo zip. Para esto, sus archivos deben estar nombrados  `??.out`, donde `??` es el número de caso de prueba (por ejemplo, `03.out`). Puede comprimir múltiples archivos usando el siguiente comando: `zip output.zip *.out`
* Puede hacer hasta 100 envíos para tareas output-only. En cada envío puede enviar los archivos de salida para cualquier subconjunto de los casos de prueba.

Para otras tareas:

* Los paquetes adjuntos contienen calificadores de ejemplo, implementaciones de ejemplo, casos de ejemplo y comandos de compilación.
* Usted debe enviar exactamente un archivo, y puede hacer hasta 50 envíos.
* Los envíos no deben leer de entrada estándar, imprimir a salida estándar o interactuar con archivos. Sin embargo, si puede imprimir a la salida de error estándar.
* El nombre del archivo a enviar está dado en el encabezado del enunciado del problema. Debe implementar los procedimientos descritos en el enunciado usando los esqueletos dados en las implementaciones ejemplo.
* Usted esta en libertar de implementar otros procedimientos.
* Al probar los programas con el calificador de ejemplo, su entrada debe tener el formato y cumplir las restricciones del enunciado, de otra manera, pueden ocurrir comportamientos inesperados.

## Convenciones

Las firmas de los enunciados usan los nombres de tipo genéricos  `bool`, `integer`, `int64`, y `int[]` (arreglo).

En cada una de los lenguajes soportados, los calificadores usan la estructura de datos apropiada, como se muestra a continuación:

Lenguaje | `bool` | `integer` | `int64` |  `int[]` | longitud de arreglo `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Límites

Tarea | Límite de tiempo | Límite de memoria
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 seg | 256 MB
train | 2 seg | 256 MB