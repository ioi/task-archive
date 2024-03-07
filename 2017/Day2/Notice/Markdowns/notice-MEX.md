# Notas
Cada tarea tiene un paquete adjunto que está disponible en el CMS y en tu escritorio.

* El paquete contiene evaluadores de ejemplo, implementaciones de ejemplo, casos de ejemplo, y scripts para compilar.
* Debes enviar exactamente un archivo y puedes hacer hasta 50 envíos.
* Tus envíos no deben leer de la entrada estándar, escribir a la salida estándar o interactuar con cualquier otro archivo. 
Sin embargo, puedes escribir al error estándar.
* El nombre del archivo que envíes debe llamarse como se indica en el encabezado de la tarea. 
Debe implementar los procedimientos definidos en la descripción de la tarea usando las firmas como se muestran en las implementaciones de ejemplo.
* Puedes implementar otros procedimientos.
* Cuando estés usando el evaluador de ejemplo, tu entrada debe coincidir con el formato y las restricciones de la descripción de la tarea. Si no lo haces, pueden ocurrir comportamientos inesperados.

## Convenciones

Las descripciones de las tareas especifican las firmas usando nombres de tipos de datos genéricos   `bool`, `int`, `int64`, and `int[]` (arreglo). En cada lenguaje de programación soportado, los evaluadores usan los tipo de datos como se muestra a continuación:

Lenguaje | `bool` | `int` | `int64` |  `int[]` | Tamaño arreglo `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Límites
Tarea | 	Límite de tiempo | Límite de memoria
--- | --- | ---
El gran premio | 1 segundo | 1024 MB
Simurgh | 3 segundos | 1024 MB
Libros Antiguos | 2 segundos | 1024 MB

<div style="margin-top:-1em"></div>