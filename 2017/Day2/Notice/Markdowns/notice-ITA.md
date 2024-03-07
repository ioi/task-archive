# Nota di implementazione

Ogni task ha degli allegati che sono disponibili sia su CMS che sul tuo desktop.

* Gli allegati contengono i grader di prova, i template, i casi di esempio e gli script di compilazione.
* Devi sottoporre esattamente un file per volta, e puoi fare fino a 50 sottoposizioni.
* Le soluzioni non devono leggere da standard input, scrivere su standard output o interagire con alcun file. È invece consentito scrivere su standard error.
* Il nome del file che devi sottoporre è riportato nell'intestazione del testo del problema. Devi implementare le funzioni descritte nel testo usando i prototipi forniti nei template.
* È consentito implementare altre funzioni.
* In fase di test del programma con il grader di prova, i casi di input da te prodotti devono rispettare il formato e i limiti del testo, altrimenti potrebbero avvenire degli *undefined behaviour.*.

## Convenzioni

I prototipi nei testi usano i nomi generici di tipo  `bool`, `integer`, `int64`, and `int[]` (array).

In ciascuno dei linguaggi di programmazione supportati, i grader utilizzano i seguenti tipi o implementazioni corrispondenti:

Language | `bool` | `integer` | `int64` |  `int[]` | length of array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limiti

Task | Limite di tempo | Limite di memoria
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>