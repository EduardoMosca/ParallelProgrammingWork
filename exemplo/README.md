# PPC

Códigos do trabalho de Programação Paralela e Concorrente (Problema do Banheiro Unisex)

Descrição do problema:
Suponha que em um local público exista apenas um banheiro com n boxes (um compartimento com um sanitário). O banheiro pode ser usado tanto por homens, mulheres e outros gêneros, mas não ao mesmo tempo. Apesar de reconhecer a variedade de gêneros existentes possíveis, neste problema vamos considerar apenas 3 (três).

Faça a implementação com um algoritmo concorrente que controle o uso do banheiro.

A entrada no banheiro é feita pelo procedimento enterRestroom. Depois de entrar no banheiro com sucesso, use o procedimento getStall, para usar um box. Se todos os boxes estiverem em uso então eles esperam em uma fila fora (não há espaço suficiente no banheiro). Depois de usar o box, cada pessoa avisa para que os outros usuários possam usá-lo.

O programa deve ser justo no sentido de dividir justamente o tempo do banheiro de forma que todos os gêneros esperem um tempo semelhante.. 
Regras

Suponha que, em um determinado instante, o banheiro está em uso por x pessoas de um determinado gênero (alguns usando boxes e outros em espera), e a primeira pessoa de gênero diferente chega, chamada P.

Então:

    P entra no banheiro, logo depois da saída de todos o x indivíduos que estavam no banheiro,
    Enquanto P está no banheiro, se outros indivíduos do mesmo gênero chegam, eles usarão o banheiro simultaneamente com P até ocupar todos os n boxes,
    Enquanto P está em espera fora do banheiro esperando uma vaga, se indivíduos de gênero diferente chegar para usar o banheiro, este vai entrar no banheiro logo depois de P (e seus companheiros do mesmo gênero que estavam no banheiro anteriormente, se for o caso) saírem do banheiro,
    Enquanto P (e companheiros do mesmo gênero) estão usando o banheiro, se pessoas do mesmo gênero de P chega e houver pessoas de gênero diferente esperando, P vai esperar todas as pessoas do gênero diferente de P saírem antes de começar a usar o banheiro.
    Caso haja duas filas P e P' em espera fora do banheiro pela vaga, será atendido inicialmente P do gênero a mais tempo na fila de espera, permitindo a entrada de todos os Ps do mesmo gênero que chegaram antes de P'.  

Escreva um programa em C, C++, Java ou Python para simular o controle concorrente do acesso ao banheiro.

Cada pessoa deve ser um processo separado. Não existe uma pessoa controlando o acesso ao banheiro, mas todas as pessoas sabem das regras de uso do banheiro e as obedece (ninguém fura a fila....) e  sabem qual o gênero está usando no instante.
Problema 1:

Considere que o banheiro tem apenas um box (n = 1).

Ao todo, 60 pessoas irão usar o banheiro, com um gerador de números aleatórios definindo o gênero (com probabilidade igual). Use um contador para gerar exatamente 20 pessoas de cada gênero

Use um gerador de números aleatórios, de modo que o tempo entre chegada de pessoas seja entre 1 e 7 segundos.

Cada pessoa usa o banheiro durante exatamente 5 segundos.

Use threads e algum mecanismo para sincronização. Você pode usar memória compartilhada.

Ao final da execução do programa deve ser exibido um relatório contendo:

    Quantidade de pessoas de cada gênero.
    Tempo médio de espera para usar o banheiro para cada gènero.
    Taxa de ocupação do box (tempo em uso / tempo total).

Problema 2:

Considere agora que o banheiro tenha 3 boxes (n=3) e que o número total de pessoas é 150.
Problema 3:

Considere agora que o banheiro tenha 5 boxes (n=5) e que o número total de pessoas é 300.