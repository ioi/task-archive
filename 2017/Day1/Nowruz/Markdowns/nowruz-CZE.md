# Nowruz

Za několik dní se bude slavit Nowruz (perský nový rok) a dědeček pozval svoji rodinu na zahradu.
Mezi pozvanými je i $k$ dětí.
Aby se děti na setkání zabavily, připravil pro ně dědeček hru na schovávanou.

Zahradu můžeme reprezentovat mřížkou o $m \times n$ polích.
Některá (je možné, že žádné) pole jsou obsazena kameny. Zbývající pole jsou *volná*.
Dvě pole označíme jako *sousední*, pokud spolu sdílejí hranu.
To znamená, že každé pole má až 4 sousední pole: dvě ve vodorovném směru a dvě ve svislém směru.
Dědeček by chtěl ze svojí zahrady udělat bludiště.
K tomuto účelu může zahradit některá pole tak, že na nich vysází keře.
Pole, na kterých vysází keře, poté už nejsou volná.

Bludiště musí mít následující vlastnost. Pro každou dvojici $a$ a $b$ volných polí v bludišti musí existovat právě jedna *cesta*, která je spojuje. Cesta mezi poli $a$ a $b$ je posloupnost volných polí, ve které je první pole $a$, poslední pole $b$, všechna pole jsou navzájem různá a každá dvě po sobě jdoucí pole jsou *sousední*.

Dítě se může schovat na poli právě tehdy, když je dané pole volné a má *právě* jedno volné sousední pole.
Žádné dvě děti se nemohou schovat na stejném poli.

Na vstupu dostanete mapu zahrady.
Vaším úkolem je pomoci dědečkovi vytvořit bludiště, ve kterém se může schovat hodně dětí.

## Implementační detaily

V této úloze odevzdáváte pouze výstupy. Za jednotlivé testovací případy můžete dostat částečné body.
Dostanete $10$ vstupních souborů, každý z nich popisuje dědečkovu zahradu.
Pro každý vstupní soubor musíte odevzdat výstupní soubor s mapou bludiště.
Pro každý výstupní soubor vám budou uděleny body podle počtu dětí, které se mohou v bludišti schovat.

V této úloze nebudete odevzdávat žádné zdrojové kódy.

## Formát vstupu

V každém vstupním souboru je uvedena jedna mřížka popisující zahradu a počet dětí $k$, které dědeček pozval. Soubor je v následujícím tvaru:
* řádek $1$: $\;\; m \;\; n \;\; k$
* řádek $1+i$ (pro $1 \leq i \leq m$): řádek $i$ mřížky, což je řetězec délky $n$, složený z následujících znaků (bez bílých znaků):
  - '`.`': volné pole,
  - '`#`': kámen.

## Formát výstupu

* řádek $i$ (pro $1 \leq i \leq m$): řádek $i$ bludiště (zahrada po vysázení keřů). Jedná se o řetězec délky $n$, složený z následujících znaků (bez bílých znaků):
  -  '`.`': volné pole,
  -  '`#`': kámen,
  -  '`X`': keř. (Mějte na paměti, že musíte použít velké písmeno X.)

## Omezení

* $1 \leq m, n \leq 1024$

## Bodování

Výstupní soubor je považován za *platný*, pokud jsou splněny následující podmínky:
* Výstupní mapa musí souhlasit se vstupní mapou s jedinou výjimkou, že libovolný počet znaků '`.`' může být změněn na znaky '`X`' (pole obsazená keři).
* Výstupní mapa musí splňovat vlastnosti bludiště, které jsou popsány v zadání úlohy.

Pokud váš výstup pro testovací případ nebude platný, bude vám za něj uděleno $0$ bodů.
V opačném případě vám bude uděleno $\min(10, 10 \cdot l/k)$ bodů, zaokrouhleno na dvě místa za desetinnou čárkou.
Číslo $l$ představuje počet dětí, které se mohou schovat ve vašem výstupním bludišti, a číslo $k$ počet dětí, který je uveden na vstupu.
Za testovací případ dostanete $10$ bodů právě tehdy, když vypíšete bludiště, na kterém se může schovat $k$ nebo více dětí.
Pro každý testovací případ existuje řešení, za které lze získat $10$ bodů.

Poznámka: pokud odevzdáte řešení, které bude platné, ale podle výše uvedeného vzorce dostane $0$ bodů, uvidíte v CMS jako výsledek hodnocení 'Wrong Answer'.

## Příklad

Uvažujme následující vstup:

```
4 5 5
....#
.#..#
...#.
....#
```

Níže je jeden z možných platných výstupů:

```
.X.X#
.#..#
...#X
XX..#
```

Protože se v bludišti mohou schovat $l=4$ děti, bude za toto řešení přiděleno $10 \cdot 4 / 5 = 8$ bodů. Pole, ve kterých se mohou děti schovat, jsou níže označena znakem `O`:


```
OXOX#
.#.O#
...#X
XX.O#
```

Následující tři výstupy nejsou platné:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#
```

V levém výstupu není žádná cesta mezi volným polem v levém horním rohu a volným polem v nejpravějším sloupci.
Ve zbylých dvou výstupech existují pro každá dvě volná pole právě dvě různé cesty, které je spojují.
