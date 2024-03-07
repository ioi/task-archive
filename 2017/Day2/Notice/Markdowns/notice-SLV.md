# Nota

Cada tarea tiene adjunto un paquete que está disponible en CMS y en su escritorio.

* Los paquetes adjuntos contienen calificadores de ejemplo, implementaciones de ejemplo, casos de ejemplo y comandos de compilación.
* Debe enviar exactamente un archivo, y puede hacer hasta 50 envíos.
* Los envíos no deben leer de entrada estándar, imprimir a salida estándar o interactuar con archivos. Sin embargo, sí puede imprimir a la salida de error estándar.
* El nombre del archivo a enviar está dado en el encabezado del enunciado del problema. Debe implementar los procedimientos descritos en el enunciado usando las firmas dadas en las implementaciones ejemplo.
* Es libre de implementar otros procedimientos.
* Al probar los programas con el calificador de ejemplo, su entrada debe tener el formato y cumplir las restricciones del enunciado; de otra manera, pueden ocurrir comportamientos inesperados.

## Convenciones

Las firmas de los enunciados usan los nombres de tipo genéricos  `bool`, `integer`, `int64`, e `int[]` (arreglo).

En cada uno de los lenguajes soportados, los calificadores usan la estructura de datos apropiada, como se lista a continuación:

Lenguaje | `bool` | `integer` | `int64` |  `int[]` | longitud de arreglo `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Límites

Tarea | Límite de tiempo | Límite de memoria
--- | --- | ---
prize | 1 seg | 1024 MB
simurgh | 3 seg | 1024 MB
books | 2 seg | 1024 MB

<div style="margin-top:-1em"></div>