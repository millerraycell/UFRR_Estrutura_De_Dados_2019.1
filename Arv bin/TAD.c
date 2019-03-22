#include "TAD.h"
#include<stdio.h>
#include <stdlib.h>


Arv_bin* arv_cria(Nodo *raiz)
{
    Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}

Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->info = c;
    return nodo;
}

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

void arv_imprime_pre_ordem(Nodo *raiz)
{
    if (raiz != NULL)
    {
        printf("%c",raiz->info);
        arv_imprime_pre_ordem(raiz->esq);
        arv_imprime_pre_ordem(raiz->dir);
    }
}

void arv_imprime_infixa(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_imprime_infixa(raiz->esq);
        printf("%c",raiz->info);
        arv_imprime_infixa(raiz->dir);
    }
}

void arv_imprime_pos_ordem(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_imprime_pos_ordem(raiz->esq);
        printf("%c",raiz->info);
        arv_imprime_pos_ordem(raiz->dir);
    }
}

void arv_imprime_formatado(Arv_bin* arv)
{
    arv_imprime_formatado_no(arv->raiz);
}

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

void arv_libera_arvore(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_libera_arvore(raiz->esq);
        arv_libera_arvore(raiz->dir);
        free(raiz);
    }
}

int arv_pertence(Arv_bin *arv, char c)
{
    return arv_pertence_no(arv->raiz,c);
}
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

Nodo* arv_busca(Arv_bin *arv, char k)
{
    return arv_busca_no(arv->raiz,k);
}
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

int arv_altura(Arv_bin* arv)
{
    return arv_altura_no(arv->raiz);
}

int max(int a, int b)
{
    return a>b ? a:b;
}

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

int quant_no(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    return 1 + quant_no(raiz->esq) + quant_no(raiz->dir);
}

int tamanho(Arv_bin* arv)
{
    return quant_no(arv->raiz);
}

Nodo *trocar(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return raiz;
    }
    return arv_cria_no(raiz->info,trocar(raiz->dir),trocar(raiz->esq));
}


Arv_bin* espelho(Arv_bin *orig)
{
    return arv_cria(trocar(orig->raiz));
}

