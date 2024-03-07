# Nota di implementazione

Ogni task ha degli allegati che sono disponibili sia su CMS che sul tuo desktop.

<br>
<br>

## Per i task "output-only":

* Gli allegati contengono i casi di input ed i casi di esempio.
Ogni caso di esempio è considerato come un subtask a sé.
* Puoi sottoporre più file di output in un unico file zip. In questo caso, i tuoi file di output devono chiamarsi `??.out`, dove `??` è il numero del caso di input (per esempio, `03.out`). Per produrre un archivio zip da terminale, puoi usare il comando: `zip output.zip *.out`
* Puoi fare fino a 100 sottoposizioni per task output-only. In ogni sottoposizione, puoi sottoporre gli output di un qualunque sottoinsieme dei casi di input.

<br>
<br>

## Per tutti gli altri task:

* Gli allegati contengono i grader di prova, i template, i casi di esempio e gli script di compilazione.
* Devi sottoporre esattamente un file per volta, e puoi fare fino a 50 sottoposizioni.
* Le soluzioni non devono leggere da standard input, scrivere su standard output o interagire con alcun file. È invece consentito scrivere su standard error.
* Il nome del file che devi sottoporre è riportato nell'intestazione del testo del problema. Devi implementare le funzioni descritte nel testo usando i prototipi forniti nei template.
* È consentito implementare altre funzioni.
* In fase di test del programma con il grader di prova, i casi di input da te prodotti devono rispettare il formato e i limiti del testo, altrimenti potrebbero avvenire degli *undefined behaviour*.


<br>
<br>
<br>
<br>
<br>

## Convenzioni

I prototipi nei testi usano i nomi generici di tipo  `bool`, `integer`, `int64`, and `int[]` (array).

In ciascuno dei linguaggi di programmazione supportati, i grader utilizzano i seguenti tipi o implementazioni corrispondenti:

Language | `bool` | `integer` | `int64` |  `int[]` | length of array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`


<br>

## Limiti

Task | Limite di tempo | Limite di memoria
--- | --- | ---
nowruz | output-only | output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB
