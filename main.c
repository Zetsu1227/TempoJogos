//EDUARDO BRITTO PIRES
//OBJETIVO DO CODIGO: le uma lista de item duplo dizendo nome do jogo e tempo medio jogado, le outra lista com jogos que o usuario quer jogar
// com essas informacoes, o codigo cria um arquivo de texto dizendo o tempo total e as informacoes relacionadas a implementacao do codigo em ABP e AVL

#include "tadEDPrototipos.h"

//Exemplo de chamda, digite "exemplo entrada.txt entrada2.txt saida.txt"

//Essa parte da chamada do terminal eu utilizei um pouco do codigo da viviane que ela disponibilizou no moodle

int main(int argc, char *argv[]) //argc conta o numero de parametros e argv armazena as strings correspondentes aos paramentros digitados
{

    FILE *steam; //jogos steam
    FILE *listaJogador; //lista do jogador
    FILE *saida; //arquivo de saida

    //inicializa abp e avl
    Nodo *abp = inicializa();
    Nodo *avl = inicializa();

    if (argc!=4)  //o numero de parametros esperado eh 3: nome do programa (argv[0]), nome do arq da steam(argv[1]), nome do arq da listaJogador(argv[2]) nome do arq de saida(argv[3])
    {
        printf ("Numero incorreto de parametros.\n Para chamar o programa digite: exemplo <arq_entrada1> <arq_entrada2> <arq_saida>\n");
        return 1;
    }
    else
    {

        steam = fopen (argv[1], "r"); // abre o arquivo para leitura -- argv[1] lista da steam
        listaJogador = fopen(argv[2], "r"); // abre o arquivo para leitura -- arv[2] lista do jogador

        if(steam == NULL) //se nao conseguiu abrir o arquivo
        {
            printf ("Erro ao abrir o arquivo %s",argv[1]);
            return 1;
        }
        if(listaJogador == NULL)
        {
            printf("Erro ao abrir o arquivo %s", argv[2]);
            return 1;
        }
        else // arquivo de entrada OK
        {
            saida = fopen (argv[3], "w"); // abre o arquivo para saida -- argv[2] eh o segundo parametro apos o nome do arquivo.

            //percorre o arquivo com as informacoes e coloca na abp e avl
            percorreSteam(steam, &abp, &avl);

            int compABP = 0; //comparacoes abp
            int compAVL = 0; //comparacoes avl
            float tempoTotal = 0; //conta o tempo total dos jogos do jogador encontrados na arvore(tanto faz a arvore)


            // percorre o arquivo do jogador e verifica a sua presenca nas arvores e completando as informacoes
            percorreJogador(listaJogador, abp, avl, &compABP, &compAVL, &tempoTotal);

            int rotAVL = retornaRot(); //rotacoes feitas para ordenar avl
            int rotABP = 0; //nao faz rotacoes --> achei desnecessário chamar a função

            // tem mesmo numero de nodos... desnecessário tambem chamar a funcao contaNodos duas vezes
            int nodosABP = contaNodos(abp); //numero de nodos no abp
            int nodosAVL = contaNodos(avl); //numero de nodos no avl

            //obrigatorio chamar altura pra cada --> uma das mudanças principais entre abp e avl seria a altura
            int alturaABP = Altura(abp); //altura da abp
            int alturaAVL = Altura(avl); //altura da avl

            // ESCRITAS NO ARQUIVO DE SAIDA
            imprimeNoArquivo(saida, tempoTotal, nodosABP, nodosAVL, alturaABP, alturaAVL, rotABP, rotAVL, compABP, compAVL);

            //avisar que foi gerado a saida UwU
            printf("\nArquivo %s gerado com sucesso.\n",argv[3]);

        }
        fclose(steam); //fecha os arquivos
        fclose(listaJogador);
        fclose(saida);
        return 0;
    }
}
