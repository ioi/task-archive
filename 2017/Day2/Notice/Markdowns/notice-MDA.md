# Precizări

Fiecare problemă are anexat un pachet disponibil atât pe CMS cât și pe stațiile voastre. 

* Pachetul anexat conține evaluatorul local, implementări simple, exemple de teste, și scripturi de compilare. 
* Veți submita exact un fișier și puteți face până la 50 de submisii.
* Submisiile voastre nu trebuie să citească de la intrarea standard, afișa la ieșirea standard sau
interacționa cu oricare alt fișier. Cu toate acestea, submisiile pot scrie in stream-ul standard
error.
* Numele fișierului pe care trebuie să-l submitați este dat în antetul enunțului problemei. Fișierul
trebuie să conțină implementarea procedurilor descrise în enunțul problemei utilizând aceleași
semnături din exemplele de implementare oferite.
* Sunteți liberi să implementați alte proceduri decât cele indicate în enunțul problemei.
* Când testați programele voastre cu evaluatorul local, intrarea voastră trebuie să corespundă
formatului și constrângerilor din enunțul problemei, altfel, pot apărea comportamente
nespecificate.

## Convenții

Enunțurile problemelor specifică semnături utilizând denumiri generice de tipuri `bool`, `int`, `int64`, și `int[]` (array).
În fiecare limbaj de programare acceptat, evaluatorul utilizează tipuri de date și implementări
corespunzătoare fiecărui limbaj de programare după cum urmează:

Limbajul | `bool` | `int` | `int64` |  `int[]` | lungimea tabloului `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limite

Problemă | Limita de timp | Limita de memorie
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>