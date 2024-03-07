# Nowruz

Faltam poucos dias para o Nowruz (ano novo persa) e o avô convidou a sua família para o seu jardim. Existem $k$ crianças entre os seus convidados. Para tornar o encontro mais divertido, o avô vai organizar um jogo das escondidas.

O jardim pode ser representando por uma matriz de $m \cdot n$ células unitárias. Algumas (possivelmente zero) células estão bloqueadas por rochas, e as restantes células são chamadas de *livres*. Duas células são chamadas de *vizinhas* se partilharem um lado, ou seja, cada célula tem 4 vizinhos: dois na direção horizontal e dois na direção vertical. O avô quer transformar o seu jardim num labirinto. Para atingir esse propósito, ele pode bloquear algumas células livres plantando arbustos. As células onde são plantados arbustos deixam de ser consideradas como sendo livres.

Um labirinto tem de ter a seguinte propriedade: para cada par $a$ e $b$ de células livres no labirinto deve existir exatamente um *caminho simples* entre elas. Um caminho simples entre as células $a$ e $b$ é uma sequência de células livres em que a primeira célula é $a$, a última é $b$, todas as células são distintas e duas células consecutivas são vizinhas.

Uma criança pode esconder-se numa célula se e só se essa célula for livre e tiver *exatamente* um vizinho livre. Duas crianças diferentes não podem esconder-se na mesma célula.

Será dado um mapa do jardim como *input*. A sua tarefa é ajudar o avô a criar um labirinto no qual muitas crianças se podem esconder.

## Detalhes de Implementação

Esta é uma tarefa de *output-only* com pontuações parciais. Serão dados dez ficheiros de *input*, cada um descrevendo o jardim do avô. Para cada um dos ficheiros de *input* deverá submeter um ficheiro de *output* com um mapa do labirinto. Para cada ficheiro de *output* irá receber pontos de acordo com o número de crianças que se conseguem esconder no labirinto.

Não é suposto que submeta código-fonte para este problema.

## Formato de input

Cada ficheiro de *input* descreve uma matriz representando um jardim e indica o número de crianças convidadas pelo avô. O formato é o seguinte:

* linha $1$: $\;\; m \;\; n \;\; k$
* linha $1+i$ (para $i \leq i \leq m$): linha $i$ da matriz, que é uma string de tamanho $n$, consistindo no seguintes caracteres (sem nenhum tipo de espaçamento entre eles):
 - '.': uma célula livre,
 - '#': uma rocha.

## Formato de output

* linha $i$ (para $1 \leq i \leq m$): linha $i$ do labirinto (o jardim, depois dos arbustos plantados). É uma *string* de tamanho $n$, consistindo nos seguintes caracteres (sem nenhum tipo de espaçamento entre eles):
 - `'.'`: uma célula livre,
 - `'#'`: uma rocha,
 - `'X'`: um arbusto. (Note que a letra X deve ser maiúscula)

## Restrições

* $1 \leq m,n \leq 1024$

## Pontuação

Um ficheiro de *output* é considerado *válido* se respeitar as seguintes condições:

* O mapa do output deve coincidir com o mapa do input com a exceção de que um número arbitrário de caracteres `'.'` do mapa de input pode ser modificado para um carácter `'X'` (células bloqueadas por arbustos).
* O mapa de output deve ter a propriedade de ser um labirinto, tal como definido no enunciado.

Se o output de um caso de saída não for válido, a sua pontuação para esse caso será 0. Caso contrário, a pontuação será de $\min(10, 10 \cdot l/k)$ pontos, arredondada para duas casas decimais. Nesta fórmula, $l$ é o número de crianças que se podem esconder no labirinto do output e $k$ é o número dado no input. Você terá 10 pontos num caso de teste se e só se o seu output é um labirinto no qual $k$ crianças se podem esconder. Para cada caso de teste é garantido que existe uma solução que consegue os 10 pontos. 

Note que se a sua solução for válida mas mesmo assim recebe 0 pontos de acordo com a fórmula dada acima, a mensagem que irá ver no CMS é um 'Wrong Answer".

## Exemplo

Considere o seguinte *input*:

```
4 5 5
....#
.#..#
...#.
....#
```

Em baixo está um possível *output* válido:

```
4 5 5
....#
.#..#
...#.
....#
```

Como $l=4$ crianças se conseguem esconder no labirinto, esta solução irá receber $10 \cdot 4/5 = 8$ pontos. As células nas quais as crianças se podem esconder estão marcadas em baixo com o carácter `O`:

```
OXOX#
.#.O#
...#X
XX.O#
``` 

Os seguintes três *outputs* não são válidos:

```
.XXX# ...X# XXXX#
.#XX# .#.X# X#XX#
...#. ...#X ..X#X
XX..# XXXX# ..XX#

```

No *output* da esquerda não existe um caminho simples entre a célula livre do canto superior esquerdo e a célula livre da coluna mais à direita. Nos outros dois outputs, para cada par de células livres distintas existem exatamente dois caminhos simples entre elas.