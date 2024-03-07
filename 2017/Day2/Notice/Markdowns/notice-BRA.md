# Notice
Cada tarefa tem um pacote anexo que está disponível tanto no CMS como na sua área de trabalho.

* O pacote anexo contém exemplos de corretores, exemplo de implementações, exemplos de casos de teste e scripts de compilação.
* Você deve submeter exatamente um arquivo, e pode realizar até 50 submissões.
* Suas submissões não devem ler da entrada padrão, escrever na saída padrão ou interagir com qualquer outro arquivo. No entanto, elas podem escrever na saída de erro padrão.
* O nome do arquivo que você deve submeter é dado no cabeçalho do enunciado da tarefa. Sua solução deve implementar as funções descritas no enunciado da tarefa usando as assinaturas disponibilizadas nos exemplos de implementação.
* Você pode implementar outras funções, se quiser.
* Ao testar seus programas com o corretor de exemplo, sua entrada deve obedecer o formato e restrições do enunciado do problema, caso contrário comportamentos não especificados podem ocorrer. 

## Convenções

Os enunciados das tarefas especificam assinaturas usando tipos de nomes genéricos como   `bool`, `integer`, `int64`, e `int[]` (vetor).

Em cada uma das linguagens de programação disponíveis os corretores usam tipos de dados ou implementações apropriados, como listado a seguir:

Linguagem | `bool` | `integer` | `int64` |  `int[]` | comprimento do vetor `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `comprimento de longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limites

Tarefa | Limite de tempo | Limite de memória
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB
