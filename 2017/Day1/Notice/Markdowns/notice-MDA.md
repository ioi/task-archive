# Precizări

Fiecare problemă are anexat un pachet disponibil atât pe CMS cât și pe stația voastră.

Pentru problemele de tipul "Output-only":
* Pachetul anexat conține teste de intrare și exemple de teste.
Fiecare test este o subproblemă separată.
* Puteți submita mai multe fișiere de ieșire ca un fișier zip. În acest caz, fișierul de ieșire trebuie să aibă numele `??.out`, unde `??` este numărul testului (e.g., `03.out`). Puteți arhiva mai multe fișiere utilizând următoarea comanda : `zip output.zip *.out`
* Puteți face până la 100 submisii pentru problemele de tip output-only. La fiecare submisie, puteți submita fișierele de ieșire ce corespund oricărui subset de teste.

Pentru alte tipuri de probleme:
* Pachetul anexat conține evaluatoare locale, implementări simple, exemple de teste și scripturi de compilare.
* Trebuie să submitați exact un fișier, și puteți face până la 50 de submisii.
* Submisiile voastre nu trebuie să citească de la intrarea standard, afișa la ieșirea standard sau interacționa cu oricare alt fișier. Cu toate acestea, submisiile pot scrie in stream-ul standard error.
* Numele fișierului pe care trebuie sa-l submitați este dat în antetul enunțului problemei. Fișierul trebuie să conțină implementarea procedurilor descrise în enunțul problemei utilizând aceleasi semnaturi din exemplele de implementare oferite. 
* Sunteți liberi să implementați alte proceduri decât cele indicate în enunțul problemei.
* Când testați programele voastre cu evaluatorul local, intrarea voastră trebuie să corespundă formatului și constrângerilor din enunțul problemei, altfel, pot aparea comportamente nespecificate. 

## Convenții

Enunțurile problemelor specifică semnaturi utilizând denumiri generice de tipuri `bool`, `integer`, `int64`, și `int[]` (array).

În fiecare limbaj de programare acceptat, evaluatorul utilizează tipuri de date și implementări corespunzătoare fiecărui limbaj de programare după cum urmează:

Limbaj | `bool` | `integer` | `int64` |  `int[]` | lungimea tabloului `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limite

Problemă | Limita de timp | Limita de memorie
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB
