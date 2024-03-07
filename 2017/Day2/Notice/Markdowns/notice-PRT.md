# Notice
Cada tarefa tem um pacote anexo que está disponível tanto no CMS como na sua área de trabalho.

* O pacote anexo contém exemplos de avaliadores, exemplo de implementações, exemplos de casos de teste e *scripts* de compilação.
* Deve submeter exatamente um arquivo, e pode realizar até 50 submissões.
* Suas submissões não devem ler do *standard input*, escrever no *standard output* ou interagir com qualquer outro ficheiro. No entanto, elas podem escrever no *standard error*.
* O nome do ficheiro que deve submeter é dado no cabeçalho do enunciado da tarefa. A sua solução deve implementar as funções descritas no enunciado da tarefa usando as assinaturas disponibilizadas nos exemplos de implementação.
* Pode implementar outras funções, se quiser.
* Ao testar os programas com o avaliador de exemplo, o *input* deve obedecer ao formato e restrições do enunciado, caso contrário podem ocorrer comportamentos não especificados. 

## Convenções

Os enunciados das tarefas especificam assinaturas usando tipos de nomes genéricos como `bool`, `integer`, `int64`, e `int[]` (vetor).

Em cada uma das linguagens de programação disponíveis os avaliadores usam tipos de dados ou implementações apropriados, como listado a seguir:

`Ling`. | `bool` | `integer` | `int64` |  `int[]` | comp. do vetor `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limites

Tarefa | Limite de tempo | Limite de memória
--- | --- | ---
prize | 1 segundos | 1024 MB
simurgh | 3 segundos | 1024 MB
books | 2 segundos | 1024 MB