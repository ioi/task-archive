# Notas

Cada tarea tiene un paquete adjunto que está disponible en el sistema y en el escritorio de su computadora.

* El paquete adjunto contiene evaluadores de ejemplo, implementaciones de ejemplo, casos de prueba de ejemplo, y scripts de compilación.
* Debes enviar exactamente un archivo, y puedes realizar hasta 50 envíos.
* Tus envíos no deben leer de la entrada estándar, imprimir a la salida estándar ni interactuar con ningún archivo.
Sin embargo, se permite escribir a la salida de error estándar.
* El nombre del archivo que debes enviar está dado en la cabecera del enunciado correspondiente.
En él se deben implementar las funciones descritas en el enunciado, utilizando las signaturas provistas en la implementación de ejemplo.
* Tienes permitido implementar otras funciones.
* Al probar tu programa con el evaluador de ejemplo,
tu entrada debería respetar el formato y las restricciones del enunciado. No hacerlo podría producir un comportamiento inesperado.

## Convenciones

Los enunciados especifican las signaturas utilizando tipos genéricos  `bool`, `int`, `int64`, and `int[]` (arreglo).

En cada uno de los lenguajes de programación permitidos, los evaluadores utilizan los tipos de datos apropiados, como se muestra a continuación:

Lenguaje | `bool` | `int` | `int64` |  `int[]` | longitud del arreglo `a`
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