 # Notice

Cada tarefa tem um pacote anexo que está disponível tanto no CMS como na sua área de trabalho.

Para tarefas do tipo "apenas saída":

* O pacote anexo contém casos de teste de entrada e casos de teste de exemplo. Cada caso de teste é uma sub-tarefa separada.
* Você pode submeter múltiplos arquivos de saída como um arquivo zip. Para isso, seus arquivos de saída devem ser nomeados  `??.out`, onde `??` é o número do caso de teste (ex., `03.out`). Você pode zipar múltiplos arquivos usando o seguinte comando:  `zip output.zip *.out`
* Você pode realizar até 100 submissões para tarefas do tipo "apenas saída". Em cada submissão, você pode submeter os arquivos de saída para qualquer subconjunto dos casos de teste.

Para outras tarefas:
* O pacote anexo contém exemplos de corretores, exemplo de implementações, exemplos de casos de teste e scripts de compilação.
* Você deve submeter exatamente um arquivo, e pode realizar até 50 submissões.
* Suas submissões não devem ler da entrada padrão, escrever na saída padrão ou interagir com qualquer outro arquivo. No entanto, elas podem escrever na saída de erro padrão.
* O nome do arquivo que você deve submeter é dado no cabeçalho do enunciado da tarefa. Sua solução deve implementar os procedimentos descritos no enunciado da tarefa usando as assinaturas disponibilizadas nos exemplos de implementação.
* Você pode implementar outros procedimentos, se quiser.
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
nowruz | Apenas saída | Apenas saída
wiring | 1 seg | 256 MB
train | 2 seg | 256 MB

