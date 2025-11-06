# TempoJogos
Código simples em C com objetivo de comparar árvores ABP e AVL.


 # Introdução

O objetivo deste trabalho é implementar um código que utilize duas formas diferentes de árvore binária, sendo ABP e AVL, e comparar o desempenho das duas em armazenamento e em consulta de informações de jogos da Steam. O programa lê dois arquivos: um contendo uma lista de jogos e seus tempos médios de jogatina(.csv), e outro contendo a lista de jogos de um usuário(.txt). Com isso, ele cria um arquivo de saída(.txt) com o tempo total dos jogos que o usuário escolheu junto com informações sobre as duas árvores utilizadas para fazer essa busca.


 # Implementação do código

O programa é divido em 3 partes, todos repletos de comentários e explicações:

tadEDPrototipos  -  contém os protótipos das funções e a estrutura.
tadEDFuncoes - contém as funções principais do código e as variáveis globais, como as das árvores e de organização da main.
main - é a função principal, recebe os parâmetros das entradas e chama tudo que é preciso pro código rodar.


 # Complexidades do programa

Para analisar a complexidade do programa, o ideal é fazer por partes e focar nas áreas que têm os códigos principais. Além disso, a complexidade vai sempre ser em relação ao pior caso possível. 

A função "percorreSteam" percorre todas as linhas do arquivo dos jogos e insere cada jogo na ABP e na AVL. Em n jogos:

	-Para ABP, essa função chama "insere", sua complexidade está relacionado com o ponto certo para se inserir. Nessa lógica, o pior caso em ABP seria se a altura fosse igual ao número de nodos, ou seja, para inserir seria O(n). Logo, para n jogos, a complexidade desse algoritmo em "percorreSteam" fica de O(n^2).

	-Para AVL, essa função chama "insereAVL", como essa árvore está balanceada, sua complexidade é O(logn), que reflete a sua altura. Assim, para n jogos, a complexidade desse algoritmo em "percorreSteam" fica de O(nlogn).

Na análise de algoritmos e suas complexidades, a maior complexidade é a que cresce mais rapidamente com o tamanho de entrada n; consequentemente, tende a ser a parte mais custosa quanto maior a entrada. Sabendo disso, a complexidade de "percorreSteam é O(n^2).

A função "percorreJogador" lê o arquivo do usuário e para cada jogo faz uma busca na ABP e na AVL, além de atualizar as comparações e o tempo total. Nesse algoritmo, a parte de maior complexidade está centrada na chamada de "consulta" para ABP e para AVL. Em m linhas:

	-Para ABP, no pior caso de uma árvore desbalanceada com a altura igual ao número de nodos, a consulta teria que percorrer todos os nodos, assim O(n).

	-Para AVL, a árvore já estaria balanceada, sendo necessário percorrer uma quantidade significativamente menor, dessa forma O(logn).

Com essas informações, usando a mesma lógica que defendi anteriormente, a complexidade de "percorreJogador" é O(mn), visto que ABP é a que tem o maior custo e é necessário percorrer todas as m linhas.


# Como eu chamava no Ubuntu(Linux)

	Local dos arquivos:
		cd /mnt/c/Users/LocalDoArquivo

	Criar o executavel:
		gcc -o main main.c tadEDFuncoes.c tadEDPrototipos.h

	Executar o programa e suas entradas:
		./main dataset.csv lista_jogador1.txt saida1.txt




