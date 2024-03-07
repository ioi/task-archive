# Kabely

Maryam je elektrotechnička, která má za úkol navrhnout kabeláž na komunikační věži. Na věži jsou přípojné body umístěné v různých výškách. K propojení dvou přípojných bodů lze použít kabel. Ke každému přípojnému bodu může být připojen libovolný počet kabelů. Existují dva typy přípojných bodů: červený a modrý.

Pro účely jednodušší reprezentace tohoto problému je věž považována za úsečku a přípojné body jsou reprezentovány modrými a červenými body ležícími na této úsečce na nezáporných celočíselných souřadnicích. Délka kabelu odpovídá vzdálenosti mezi dvěma přípojnými body, které tento kabel propojuje.

Vaším cílem je pomoci Maryam najít takové schéma zapojení kabelů k přípojným bodům, aby:

1. Z každého přípojného bodu vedl aspoň jeden kabel k přípojnému bodu jiné barvy.
1. Délka kabeláže, tj. součet délek kabelů, je minimální možná.
 
Takové schéma zapojení označujeme jako _platné_.

## Podrobnosti k implementaci

Máte za úkol implementovat následující proceduru:

```
int64 min_total_length(int[] r, int[] b)
```
 
* $r$: pole délky $n$ obsahující pozice červených přípojných bodů ve vzestupném  pořadí.
* $b$: pole délky $m$ obsahující pozice modrých přípojných bodů ve vzestupném pořadí.
* Tato procedura by měla vrátit minimální celkovou délku kabelů ze všech platných schémat zapojení.
* Povšimněte si, že návratový typ této procedury je `int64`.

## Příklad

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Níže uvedený obrázek ilustruje tento příklad.
![Wiring](wiring.png)

* Věž je zobrazena horizontálně.
* V černobílé tištěné verzi zadání jsou červené přípojné body tmavé a modré světlé.
* Jsou zde 4 červené přípojné body umístěné na pozicích $1, 2, 3$ a $7$.
* Je zde 5 modrých přípojných bodů na pozicích $0, 4, 5, 9$ a $10$.
* Na obrázku výše je vidět jedno optimální řešení.
* V tomto řešení je celková délka kabelu $1 + 2 + 2 + 2 + 3 = 10$, což je optimální.
Procedura by tedy měla vrátit $10$.
* Všimněte si, že k přípojnému bodu na pozici $7$ jsou připojeny dva kabely.

## Omezení

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (pro všechna $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (pro všechna $0 \leq i \leq m-1$),
* Obě pole $r$ a $b$ jsou uspořádaná vzestupně.
* Všech $n+m$ hodnot v polích $r$ a $b$ je navzájem různých.

## Podúlohy

1. (7 bodů) $ n, m \leq 200 $,
1. (13 bodů) Všechny červené přípojné body jsou na nižších pozicích než kterýkoli modrý přípojný bod.
1. (10 bodů) Mezi každými 7 po sobě jdoucími přípojnými body je alespoň jeden červený a jeden modrý přípojný bod.
1. (25 bodů) Všechny přípojné body mají různé pozice v rozsahu $[1, n + m]$.
1. (45 bodů) Žádná další omezení.

## Ukázkový vyhodnocovač

Ukázkový vyhodnocovač čte vstup v následujícím formátu:
* řádek $1$: $\;\; n \;\; m$
* řádek $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* řádek $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Ukázkový vyhodnocovač vytiskne jeden řádek s návratovou hodnotu `min_total_length`.