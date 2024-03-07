 # Notice

Cada tarefa tem um pacote anexo que está disponível tanto no CMS como na sua área de trabalho.

Para tarefas do tipo *output-only*:

* O pacote anexo contém casos de teste de *input* e casos de teste de exemplo. Cada caso de teste é uma sub-tarefa separada.
* Você pode submeter múltiplos ficheiros de *output* como um arquivo zip. Para isso, seus ficheiros de *output* devem ser nomeados  `??.out`, onde `??` é o número do caso de teste (ex., `03.out`). Pode zipar múltiplos ficheiros usando o seguinte comando:  `zip output.zip *.out`
* Você pode realizar até 100 submissões para tarefas do tipo *output-only*. Em cada submissão, pode submeter os ficheiros de *output* para qualquer subconjunto dos casos de teste.

Para outras tarefas:
* O pacote anexo contém exemplos de corretores, exemplo de implementações, exemplos de casos de teste e scripts de compilação.
* Deve submeter exatamente um ficheiro, e pode realizar até 50 submissões.
* As suas submissões não devem ler do *standard input*, escrever no *standard output* ou interagir com qualquer outro ficheiro. No entanto, elas podem escrever no *standard error*.
* O nome do ficheiro que você deve submeter é dado no cabeçalho do enunciado da tarefa. Sua solução deve implementar os procedimentos descritos no enunciado da tarefa usando as assinaturas disponibilizadas nos exemplos de implementação.
* Pode implementar outros procedimentos, se quiser.
* Ao testar os seus programas com o avaliador de exemplo, o seu *input* deve obedecer ao formato e restrições do enunciado do problema, caso contrário comportamentos não especificados podem ocorrer. 

## Convenções

Os enunciados das tarefas especificam assinaturas usando tipos de nomes genéricos como   `bool`, `integer`, `int64`, e `int[]` (vetor).

Em cada uma das linguagens de programação disponíveis os avaliadores usam tipos de dados ou implementações apropriados, como listado a seguir:

Linguagem | `bool` | `integer` | `int64` |  `int[]` | comprimento do vetor `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `comprimento de longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limites

Tarefa | Limite de tempo | Limite de memória
--- | --- | ---
nowruz | *output-only* | *output-only*
wiring | 1 seg | 256 MB
train | 2 seg | 256 MB
