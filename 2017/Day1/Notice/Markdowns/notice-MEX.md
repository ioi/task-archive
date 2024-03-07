# Notas

Cada tarea tiene un paquete adjunto que está disponible en el CMS y en tu escritorio.

Para tareas de sólo salida:
* El paquete adjunto contiene los archivos de entrada y casos de ejemplo.
Cada archivo de entrada es una subtarea.
* Puedes enviar varios archivos de salida dentro de un zip. En este caso, los archivos de entrada se deben llamar `??.out`, donde `??` es el número de caso (por ejemplo, `03.out`). puedes comprimir varios archivos usando el siguiente comando: `zip output.zip *.out`
* Puedes hacer hasta 100 envíos para tareas de sólo salida. Enviar un zip con varias subtareas se considera como solo un envío.

Para las demás tareas:
* El paquete contiene evaluadores de ejemplo, implementaciones de ejemplo, casos de ejemplo, y scripts para compilar.
* Debes enviar exactamente un archivo y puedes hacer hasta 50 envíos.
* Tus envíos no deben leer de la entrada estándar, escribir a la salida estándar o interactuar con cualquier otro archivo.
Sin embargo, puedes escribir al error estándar.
* El nombre del archivo que envíes debe llamarse como se indica en el encabezado de la tarea.
Debe implementar los procedimientos definidos en la descripción de la tarea usando las firmas como se muestran en las implementaciones de ejemplo.
* Puedes implementar otros procedimientos.
* Cuando estés usando el evaluador de ejemplo, tu entrada debe coincidir con el formato y las restricciones de la descripción de la tarea. Si no lo haces, pueden ocurrir comportamientos inesperados.

## Convenciones

Las descripciones de las tareas especifican las firmas usando nombres de tipos de datos genéricos `bool`, `integer`, `int64`, e `int[]` (arreglo).

En cada lenguaje de programación soportado, los evaluadores usan el tipo de datos como se muestra a continuación:

Lenguaje | `bool` | `integer` | `int64` |  `int[]` | Tamaño del arreglo `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Límites

Tarea | Límite de tiempo | Límite de memoria
--- | --- | ---
Nowruz | Sólo salida | Sólo salida
Cableado | 1 sec | 256 MB
Tren de juguete | 2 sec | 256 MB