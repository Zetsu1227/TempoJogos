#include "tadEDPrototipos.h"

// ====================================================================================================
// =======================================VARIAVEIS GLOBAIS E FUNCOES==================================
// ====================================================================================================


//numero de comparacoes para as consultas
int comp = 0;

//numero de rotacoes para ordenar avl
int rot = 0;


//retorna a variavel global de comparacoes para main
int retornaComp()
{
    return comp;
}

//zera as comparacoes
void zeraComp()
{
    comp = 0;
}

//retorna a variavel global de rotacoes para main
int retornaRot()
{
    return rot;
}

// ====================================================================================================
// =======================================FUNCOES ABP e AVL============================================
// ====================================================================================================

//inicializa a arvore binaria
Nodo* inicializa()
{
    return NULL;
}


// Peguei do laboratório 19
//calcula a altura de uma arvore binaria
int Altura (Nodo *a)
{
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
        return 0;
    else
    {
        Alt_Esq = Altura (a->esq);
        Alt_Dir = Altura (a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}


//conta o numero de nodos de uma arvore binaria
int contaNodos(Nodo* raiz)
{
    int soma = 0;

    if(raiz != NULL)
        soma += contaNodos(raiz->esq) + contaNodos(raiz->dir) + 1;

    return soma;

}

// funcao consulta que o prof deu no trabailho
Nodo* consulta(Nodo *a, char *chave)
{
    while (a != NULL)
    {
        comp++;
        if (!strcmp(a->jogo, chave))
        {
            return a;
        }
        else
        {
            if (strcmp(a->jogo, chave) > 0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return NULL;
}


// ====================================================================================================
// ===========================================FUNCOES ABP==============================================
// ====================================================================================================


//insere --> ABP
//fiz a mudanca de utilizar a ordem alfabetica da tabela ascii por meio do strcmp
Nodo* insere(Nodo* raiz, char *nome,float chave)
{

    if(raiz == NULL)
    {

        raiz = (Nodo*)malloc(sizeof(Nodo));

        if(raiz == NULL)
        {
            printf("Deu ruim na memoria!\n");
            return NULL;
        }

        raiz->info = chave;
        strcpy(raiz->jogo, nome);
        raiz->dir = NULL;
        raiz->esq = NULL;

        return raiz;
    }

    if(strcmp(nome, raiz->jogo) < 0)
        raiz->esq = insere(raiz->esq,nome, chave);
    else
        raiz->dir = insere(raiz->dir,nome, chave);


    return raiz;

}

// ====================================================================================================
// ===========================================FUNCOES AVL==============================================
// ====================================================================================================


Nodo* rotacao_direita(Nodo* p)
{
    rot++;
    Nodo *u;

    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;

    return p;
}

Nodo* rotacao_esquerda(Nodo *p)
{
    rot++;
    Nodo *z;

    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;

    return p;
}



Nodo* rotacao_dupla_direita (Nodo* p)
{
    rot++; //confirmar se conta como 1 ou duas
    Nodo *u, *v;

    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;

    if (v->FB == 1)
        p->FB = -1;
    else
        p->FB = 0;

    if (v->FB == -1)
        u->FB = 1;
    else
        u->FB = 0;

    p = v;
    return p;
}


Nodo* rotacao_dupla_esquerda (Nodo *p)
{
    rot++;
    Nodo *z, *y;

    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;

    if (y->FB == -1)
        p->FB = 1;
    else
        p->FB = 0;

    if (y->FB == 1)
        z->FB = -1;
    else
        z->FB = 0;

    p = y;
    return p;
}

// insere --> AVL
//fiz a mudanca de utilizar a ordem alfabetica da tabela ascii por meio do strcmp
Nodo* insereAVL (Nodo *a, char *nome, float x, int *ok)
{
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
     x, a chave a ser inserida e h a altura da árvore */
    start = clock();
    if (a == NULL)
    {
        a = (Nodo*) malloc(sizeof(Nodo));
        a->info = x;
        strcpy(a->jogo, nome);
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }
    else if (strcmp(nome, a->jogo) < 0)
    {
        a->esq = insereAVL(a->esq,nome,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case -1:
                a->FB = 0;
                *ok = 0;
                break;
            case 0:
                a->FB = 1;
                break;
            case 1:
                a=Caso1(a,ok);
                break;
            }
        }
    }
    else
    {
        a->dir = insereAVL(a->dir,nome,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case 1:
                a->FB = 0;
                *ok = 0;
                break;
            case 0:
                a->FB = -1;
                break;
            case -1:
                a = Caso2(a,ok);
                break;
            }
        }
    }

    return a;
}

Nodo* Caso1 (Nodo *a, int *ok)
{
    Nodo *z;

    z = a->esq;
    if (z->FB == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);

    a->FB = 0;
    *ok = 0;
    return a;
}

Nodo* Caso2 (Nodo *a, int *ok)
{
    Nodo *z;

    z = a->dir;
    if (z->FB == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);

    a->FB = 0;
    *ok = 0;
    return a;
}


// ====================================================================================================
// ===========================================ORGANIZACAO DA MAIN======================================
// ====================================================================================================

//Imprime todas as informacoes necessarias no arquivo
void imprimeNoArquivo(FILE *saida, float tempoTotal, int nodosABP, int nodosAVL, int alturaABP, int alturaAVL, int rotABP, int rotAVL, int compABP, int compAVL)
{

    fprintf(saida, "Tempo total estimado: %.2f horas\n\n", tempoTotal);

    fprintf(saida, "======== ESTATISTICAS ABP ========\n");
    fprintf(saida, "Numero de nodos: %d\n", nodosABP);
    fprintf(saida, "Altura: %d\n", alturaABP);
    fprintf(saida, "Rotacoes: %d\n", rotABP);
    fprintf(saida, "Comparacoes: %d\n\n", compABP);

    fprintf(saida,"======== ESTATISTICAS AVL ========\n");
    fprintf(saida, "Numero de nodos: %d\n", nodosAVL);
    fprintf(saida, "Altura: %d\n", alturaAVL);
    fprintf(saida, "Rotacoes: %d\n", rotAVL);
    fprintf(saida, "Comparacoes: %d\n\n", compAVL);

}


//percorre o arquivo de entrada steam e coloca nas arvores
//usei double pointer para modificar o nodo original
void percorreSteam(FILE *steam, Nodo **abp, Nodo **avl)
{
    char nome[100], linha[1000]; // linhas a serem lidas do arquivo
    char *tok;
    float tempo;
    int ok; //pra chamar funcao InsereAVL

    // percorre todo o arquivo
    while (fgets(linha, 1000, steam))
    {
        // remove o \n do final
        linha[strcspn(linha, "\n")] = '\0';

        // remove \r pros arquivos q vem do windows --> tive problemas com testes por causa disso
        if (linha[strlen(linha) - 1] == '\r')
            linha[strlen(linha) - 1] = '\0';

        tok = strtok(linha, ","); //pega a palavra antes da virgula
        if (tok != NULL)
            strcpy(nome, tok);

        tok = strtok(NULL, ","); // pega o tempo dps da virgula
        if (tok != NULL)
            tempo = atof(tok); //converte de string pra float

        *abp = insere(*abp, nome, tempo);
        *avl = insereAVL(*avl, nome, tempo, &ok);
    }
}

//percorre o arquivo do jogador, verifica se os jogos estao nas arvores e coloca as informacoes de comparacao e de tempo total
void percorreJogador(FILE *listaJogador, Nodo *abp, Nodo *avl, int *compABP, int *compAVL, float *tempoTotal)
{

    char linha[1000]; // linhas a serem lidas do arquivo

    Nodo *aux; //nodo auxiliar para fazer as consultas

    while(fgets(linha, 1000, listaJogador))
    {
        //tira o \n
        linha[strcspn(linha, "\n")] = '\0';
        //tira o \r --> tive problemas com testes por causa disso
        if (linha[strlen(linha) - 1] == '\r')
            linha[strlen(linha) - 1] = '\0';

        aux = consulta(abp,linha);
        *compABP += retornaComp();
        zeraComp();

        if(aux == NULL)
            printf("Nao encontrou: %s\n", linha);

        if(aux != NULL)
            *tempoTotal += aux->info;

        aux = consulta(avl,linha);
        *compAVL += retornaComp();
        zeraComp();

        if(aux == NULL)
            printf("Nao encontrou2: %s\n", linha);
    }

}




