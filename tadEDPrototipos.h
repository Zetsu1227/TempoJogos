#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 100

//estrutura para os nodos da arvore de ABP e AVL
//para os casos em ABP o FB é ignorado, já que nao vai ser acessado
typedef struct str_nodo Nodo;
struct str_nodo
{

    float info; // tempo medio em float :(
    int FB;
    char jogo[TAM]; //nome do jogo
    Nodo* esq;
    Nodo* dir;
};


//FUNCOES DAS VARIAVEIS GLOBAIS
int retornaComp(); //retorna o valor de comp para main :)
void zeraComp(); //zera comp para fazer o prox teste de arvore
int retornaRot(); //retorna a variavel global de rotacoes para main


//ABP e AVL --> alguns eu fiz e outros sao dos slides ou de outros laboratorios
Nodo* inicializa(); //inicializa arvore
int contaNodos(Nodo* raiz); //conta quantidade de nodos
int Altura (Nodo *a); //conta a altura de uma arvore binaria -- pego do laboratório 19
Nodo* consulta(Nodo *a, char *chave);


//ABP
Nodo* insere(Nodo* raiz,char *nome, float chave); //insere em ABP


//AVL --> funcoes dos slides do moodle
Nodo* rotacao_direita(Nodo* p); //rotaciona a direita a arvore
Nodo* rotacao_esquerda(Nodo *p); //rotaciona a esquerda a arvore
Nodo* rotacao_dupla_direita (Nodo* p); //rotaciona duas vezes a direita
Nodo* rotacao_dupla_esquerda (Nodo *p); //rotaciona duas vezes a esquerda
Nodo* insereAVL (Nodo *a, char *nome ,float x, int *ok); //insere em avl
Nodo* Caso1 (Nodo *a, int *ok); //caso de inclusao avl na direita
Nodo* Caso2 (Nodo *a, int *ok); // caso de inclusao avl na esquerda


//Funcoes para organizar mais a main

//imprime as informacoes pedidas no arquivo de saida -- bastante parametro :(
void imprimeNoArquivo(FILE *saida, float tempoTotal, int nodosABP, int nodosAVL, int alturaABP, int alturaAVL, int rotABP, int rotAVL, int compABP, int compAVL);
void percorreSteam(FILE *steam, Nodo **abp, Nodo **avl); //percorre o arquivo de entrada e coloca as informacoes nas arvores
void percorreJogador(FILE *listaJogador, Nodo *abp, Nodo *avl, int *compABP, int *compAVL, float *tempoTotal); //percorre o arquivo do jogador e verifica os seus jogos e suas informacoes



