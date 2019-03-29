#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char info;
    struct no *dir;
    struct no *esq;
}Nodo;

typedef struct
{
    Nodo *raiz;
}arvore;

arvore* arv_cria(Nodo *raiz)
{
    arvore* arv = (arvore*) malloc(sizeof(arvore));
    arv->raiz = raiz;
    return arv;
}

Nodo* arv_cria_no(char c)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->esq = NULL;
    nodo->dir = NULL;
    nodo->info = c;
    return nodo;
}

void arv_imprime_pos_ordem(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_imprime_pos_ordem(raiz->esq);
        arv_imprime_pos_ordem(raiz->dir);
        printf("%c",raiz->info);
    }
}

void arv_libera_arvore(Nodo *raiz)
{
    if (raiz != NULL)
    {
        arv_libera_arvore(raiz->esq);
        arv_libera_arvore(raiz->dir);
        free(raiz);
    }
}

int busca_raiz (char *infixa, int inicio, int fim, char info)
{
    int i;
    for(i = inicio; i <= fim ; i++)
    {
        if (infixa[i] == info)
        {
            return i;
        }
    }
}

int indice_pre = 0;

Nodo *criar_nodo(char *pre, char *in, int inicio, int fim)
{
    Nodo *raiz;
    int indice_raiz;

    if(inicio>fim)
    {
        return NULL;
    }
    else if(inicio == fim)
    {
        raiz = arv_cria_no(pre[indice_pre++]);
        return raiz;
    }
    else
    {
        raiz = arv_cria_no(pre[indice_pre]);
        indice_raiz = busca_raiz(in,inicio,fim,pre[indice_pre++]);
        raiz->esq = criar_nodo(pre, in, inicio, indice_raiz-1);
        raiz->dir = criar_nodo(pre, in, indice_raiz+1,fim);

        return raiz;
    }
}

int main()
{
    arvore *arv;
    int tamanho;
    char pre[30],in[30];

    while(scanf(" %s %s",&pre,&in) != EOF)
    {
        tamanho = strlen(pre);
        arv = arv_cria(criar_nodo(pre, in, 0, tamanho-1));

        arv_imprime_pos_ordem(arv->raiz);
        arv_libera_arvore(arv->raiz);
        indice_pre = 0;
        printf("\n");
    }
    return 0;
}
