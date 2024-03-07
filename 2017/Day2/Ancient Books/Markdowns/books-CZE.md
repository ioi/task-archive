# Starobylé knihy

Město Teherán je domovem Národní knihovny Íránu.
Hlavní poklad této knihovny je umístěn v dlouhé hale s řadou $n$ stolů očíslovaných $0$ až $n-1$ zleva doprava.
Na každém stole je zobrazena jedna starověká ručně psaná kniha.
Knihy jsou seřazeny podle stáří, tudíž je pro návštěvníky těžké vyhledávat je podle názvu.
Správce knihovny se tedy rozhodl uspořádat knihy v abecedním pořadí podle názvu.

Knihovník Aryan to dostal za úkol udělat.
Vytvořil seznam $p$ délky $n$ obsahující navzájem různá celá čísla od $0$ do $n-1$.
Tento seznam popisuje změny nutné k přeuspořádání knih do abecedního pořadí:
Pro všechna $0 \leq i < n$ se má kniha, která je aktuálně na stole $i$, přesunout na stůl $p[i]$.

Aryan začne uspořádávat knihy od stolu $s$ a tam se na konci chce i vrátit.
Vzhledem k tomu, že knihy jsou velmi cenné, nemůže nést současně více než jednu knihu.
Při uspořádávání knih Aryan provádí posloupnost právě následujících akcí:
* Pokud nenese knihu a na stole, u nějž se právě nachází, kniha je, může tuto knihu vyzvednout.
* Pokud nese knihu a na stole, u nějž se právě nachází, je další kniha, je schopen je mezi sebou vyměnit, tzn. knihu, kterou nese, dát na stůl a odnést tu, která tam byla.
* Pokud nese knihu a je u prázdného stolu, může ji na něj položit.
* Může přejít k libovolnému stolu a přitom nést nejvýše jednu knihu.

Pro všechna $0 \leq i, j \leq n - 1$ je vzdálenost mezi stoly $i$ a $j$ přesně $|j-i|$ metrů. Vaším úkolem je spočítat nejmenší možnou celkovou vzdálenost, kterou Aryan musí ujít, aby seřadil všechny knihy.

## Podrobnosti k implementaci

Máte za úkol implementovat následující proceduru:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ je pole délky $n$.
Knihu, která je na začátku na stole $i$, by měl Aryan přemístit na stůl $p[i]$ (pro všechna $0 \leq i < n$).
* $s$ je číslo stolu, kde Aryan začíná a také končí po uspořádání knih.
* Procedura by měla vrátit minimální možnou celkovou vzdálenost (v metrech), kterou musí Aryan během uspořádávání ujít.

## Příklad

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

V tomto příkladu je $n = 4$ a Aryan začíná u stolu $0$.
Přemísťuje knihy takto:
* Jde ke stolu $1$ a bere z něj knihu. Tato kniha by měla být umístěna na stůl $2$.
* Následně jde ke stolu $2$ a vymění knihu, kterou nese, s knihou na stole.
Kniha, kterou nese nyní, by měla být položena na stůl $3$.
* Pak jde ke stolu $3$  a vymění knihu, kterou nese, s knihou na stole.
Kniha, kterou nese nyní, by měla být položena na stůl $1$.
* Pak jde ke stolu $1$ a umístí zde knihu, kterou nese.
* Nakonec se vrátí ke stolu $0$.

Všimněte si, že kniha na stole $0$ je již na správném místě, takže Aryan ji nikam přenášet nemusí.
Celková vzdálenost, kterou urazí v tomto řešení, činí $6$ metrů.
Toto je optimální řešení, procedura by tedy měla vrátit $6$.

## Omezení

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Pole $p$ obsahuje $n$ navzájem různých celých čísel mezi $0$ a $n-1$ včetně.

## Podúlohy

1. (12 bodů) $n \le 4$ a $s = 0$
1. (10 bodů) $n \le 1000$ a $s = 0$
1. (28 bodů) $s = 0$
1. (20 bodů) $n \le 1000$
1. (30 bodů) žádná další omezení

## Ukázkový vyhodnocovač

Ukázkový vyhodnocovač čte vstup v následujícím formátu:

- řádek $1$: $\;\; n \;\; s$
- řádek $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Ukázkový vyhodnocovač vypíše jediný řádek obsahující číslo vrácené procedurou `minimum_walk`.
