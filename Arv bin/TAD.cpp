#include "TAD.h"
#include<stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

//FUNCAO PARA CRIAR ARVORE
Arv_bin* arv_cria(Nodo *raiz)
{
    Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}
//FUNCAO PARA CRIAR NODO DA ARVORE
Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->info = c;
    return nodo;
}

//FUNCAO PARA FAZER IMPRESSAO PRE ORDEM
void arv_imprime_pre_ordem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%c",raiz->info);
        arv_imprime_pre_ordem(raiz->esq);
        arv_imprime_pre_ordem(raiz->dir);
    }
}
//FUNCAO PARA FAZER IMPRESSAO IN ORDEM
void arv_imprime_infixa(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_imprime_infixa(raiz->esq);
        printf("%c",raiz->info);
        arv_imprime_infixa(raiz->dir);
    }
}
//FUNCAO PARA FAZER IMPRESSAO POS ORDEM
void arv_imprime_pos_ordem(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_imprime_pos_ordem(raiz->esq);
        arv_imprime_pos_ordem(raiz->dir);
        printf("%c",raiz->info);
    }
}
//FUNCAO PARA SELECIONAR QUAL FORMA DESEJA IMPRIMIR A ARVORE
void arv_imprime_escolhendo_ordem(Arv_bin* arv, int ordem)
{
    if (ordem == 1)
    {
        arv_imprime_pre_ordem(arv->raiz);
    }
    else if (ordem == 2)
    {
        arv_imprime_infixa(arv->raiz);
    }
    else if (ordem == 3)
    {
        arv_imprime_pos_ordem(arv->raiz);
    }
    else
    {
        printf("VALOR INVALIDO\n");
    }
}


//FUNCAO PARA IMPRIMIR COM A FORMATACAO
void arv_imprime_formatado_no(Nodo* raiz)
{
    printf(" <");
    if (raiz != NULL)
    {
        printf("%c",raiz->info);
        arv_imprime_formatado_no(raiz->esq);
        arv_imprime_formatado_no(raiz->dir);
    }
    printf("> ");
}
//FUNCAO PARA CHAMAR A IMPRESSAO FORMATADA DA ARVORE
void arv_imprime_formatado(Arv_bin* arv)
{
    arv_imprime_formatado_no(arv->raiz);
}


//FUNCAO PARA DESALOCAR A ARVORE
void arv_libera_arvore(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_libera_arvore(raiz->esq);
        arv_libera_arvore(raiz->dir);
        free(raiz);
    }
}

//FUNCAO PARA VERIFICAR SE UM ELEMENTO PERTENCE A ARVORE (VERIFICANDO NODO A NODO)
int arv_pertence_no(Nodo *raiz, char c)
{
    if(raiz == NULL)
    {
        return 0;
    }
    else if (raiz-> info == c)
    {
        return 1;
    }
    else if (arv_pertence_no(raiz->esq,c))
    {
        return 1;
    }
    return arv_pertence_no(raiz->dir,c);
}
// FUNCAO PARA CHAMAR A FUNCAO PARA VERIFICAR SE UM ELEMENTO PERTENCE A ARVORE
int arv_pertence(Arv_bin *arv, char c)
{
    return arv_pertence_no(arv->raiz,c);
}


//FUNCAO PARA FAZER A CHAMADA DA BUSCA
Nodo* arv_busca(Arv_bin *arv, char k)
{
    return arv_busca_no(arv->raiz,k);
}


//FUNCAO PARA FAZER A BUSCA NA ARVORE NODO A NODO
Nodo* arv_busca_no(Nodo *raiz, char k)
{
    if(raiz == NULL)
    {
        return NULL;
    }
    else if (raiz-> info == k)
    {
        return raiz;
    }
    else if (arv_busca_no(raiz->esq,k))
    {
        return raiz;
    }
    return arv_busca_no(raiz->dir,k);
}


//FUNCAO PARA SE VERIFICAR O MAXIMO DE DOIS NUMEROS
int max(int a, int b)
{
    return a>b ? a:b;
}
//FUNCAO PARA VERIFICAR A ALTURA NODO A NODO
int arv_altura_no(Nodo* raiz)
{
    if(raiz == NULL)
    {
        return -1;
    }
    int alt_sae = 1 + arv_altura_no(raiz->esq);
    int alt_sad = 1 + arv_altura_no(raiz->dir);

    return max(alt_sad,alt_sae);
}
//FUNCAO PARA FAZER A CHAMADA DA FUNCAO PARA VERIFICAR A ALTURA DE UMA ARVORE
int arv_altura(Arv_bin* arv)
{
    return arv_altura_no(arv->raiz);
}


//FUNCAO PARA VERIFICAR NODO A NODO PARA SE SABER QUANTOS NODOS EXITEM NA ARVORE
int quant_no(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return 1 + quant_no(raiz->esq) + quant_no(raiz->dir);
}
//FUNCAO PARA FAZER A CHAMADA DA FUNCAO QUE VERIFICA A QUANTIDADE DE NODOS
int tamanho(Arv_bin* arv)
{
    return quant_no(arv->raiz);
}


//FUNCAO PARA VERIFICAR O PERCURSO EM LARGURA DA ARVORE
void largura(Arv_bin *arv)
{
    queue <Nodo *> fila;
    Nodo *aux;
    fila.push(arv->raiz);
    while(!fila.empty())
    {
        aux = fila.front();
        fila.pop();
        if(aux != NULL)
        {
            printf("%c",aux->info);
            fila.push(aux->esq);
            fila.push(aux->dir);
        }
    }
}


//FUNCAO PARA FAZER A TROCA DE LADO DOS NODOS PARA SE OBTER A ARVORE ESPELHADA
Nodo *trocar(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return raiz;
    }
    return arv_cria_no(raiz->info,trocar(raiz->dir),trocar(raiz->esq));
}
//FUNCAO PARA FAZER A CHAMADA DA FUNCAO QUE TROCA OS NODOS DE UMA ARVORE
Arv_bin* espelho(Arv_bin *orig)
{
    return arv_cria(trocar(orig->raiz));
}


//FUNCAO PARA IMPRIMIR A ARVORE NO PERCURSO IN ORDEM ITERATIVAMENTE
//CODIGO PARECIDO COM O DO ALUNO TARLISON, POIS O MESMO ME AUXILIOU NESSA FUNCAO
void imprime_in_ordem_iterativo(Arv_bin *arv)
{
    stack <Nodo *> pilha;
    Nodo *corr = NULL;

    pilha.push(arv->raiz);

    while(!pilha.empty())
    {
        corr = pilha.top();
        while(corr->esq != NULL)
        {
            pilha.push(corr->esq);
            corr = pilha.top();
        }
        printf("%c",corr->info);
        pilha.pop();

        if(corr->dir != NULL)
        {
            pilha.push(corr->dir);
        }
        else
        {
            if(!pilha.empty())
            {
                corr = pilha.top();
                printf("%c",corr->info);
                pilha.pop();
                if(corr->dir!=NULL)
                {
                    pilha.push(corr->dir);
                }
            }
        }
    }
}


//FUNCAO PARA IMPRIMIR A ARVORE NO PERCURSO POS ORDEM ITERATIVAMENTE
//FIZ SOZINHO, MAS CODIGO PARECIDO COM O DO ALUNO TARLISON, POIS O MESMO ME AUXILIOU NA FUNCAO ANTERIOR
void imprime_pos_ordem_iterativo(Arv_bin *arv)
{
    stack<Nodo *> pilha;
    stack<Nodo *> pilha2;
    Nodo *corr = NULL;

    pilha.push(arv->raiz);
    pilha2.push(arv->raiz);
    while(!pilha.empty())
    {
        corr = pilha.top();
        while(corr->dir != NULL)
        {
            pilha2.push(corr->dir);
            pilha.push(corr->dir);
            corr = pilha.top();
        }
        pilha.pop();

        if(corr->esq != NULL)
        {
            pilha2.push(corr->esq);
            pilha.push(corr->esq);
        }
        else
        {
            if(!pilha.empty())
            {
                corr = pilha.top();
                pilha.pop();
                if(corr->esq!=NULL)
                {
                    pilha2.push(corr->esq);
                    pilha.push(corr->esq);
                }
            }
        }
    }
    while(!pilha2.empty())
    {
        corr = pilha2.top();
        printf("%c",corr->info);
        pilha2.pop();
    }
}


//FUNCAO PARA CONTAR O NUMERO DE FOLHAS DE UMA ARVORE
int conta_numero_folhas_no(Nodo* raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    else if(raiz->esq == NULL && raiz->dir == NULL)
    {
        return 1;
    }
    else
    {
        return conta_numero_folhas_no(raiz->dir) + conta_numero_folhas_no(raiz->esq);
    }
}
//FUNCAO PARA FAZER A CHAMADA DA FUNCAO QUE CONTA O NUMERO DE FOLHAS DE UMA ARVORE
int conta_numero_folhas(Arv_bin *arv)
{
    return conta_numero_folhas_no(arv->raiz);
}


//FUNCAO QUE VERIFICA SE UMA ARVORE E ESTRITAMENTE BINARIA
int verifica_est_bin_no(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }
    if((raiz->dir != NULL && raiz->esq == NULL) || (raiz->dir == NULL && raiz->esq != NULL))
    {
        return 0;
    }
    return 1 & verifica_est_bin_no(raiz->dir) & verifica_est_bin_no(raiz->esq);
}
//FUNCAO PARA FAZER A CHAMADA DA FUNCAO QUE VERIFICA SE UMA ARVORE E OU NAO ESTRITAMENTE BINARIA
int verifica_est_bin(Arv_bin *arv)
{
    return verifica_est_bin_no(arv->raiz);
}


//FUNCAO PARA VERIFICAR SE UMA ARVORE E COMPLETA
int verficar_arv_bin_comp(Arv_bin* arv)
{
    if(conta_numero_folhas(arv) == (tamanho(arv)*tamanho(arv)))
    {
        return 1;
    }
    else
    {
       return 0;
    }
}
