#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *esq;
    struct no *dir;

}Nodo;

typedef struct arv_bin
{
    Nodo* raiz;

}Arv_bin;

Arv_bin* arv_cria()
{
    Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));
    arv->raiz = NULL;
    return arv;
}

Nodo* arv_cria_no(int c, Nodo* esq, Nodo* dir)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->info = c;
    return nodo;
}

void arv_in_imprime(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_in_imprime(raiz->esq);
        printf(" %d",raiz->info);
        arv_in_imprime(raiz->dir);
    }
}

void arv_pre_imprime(Nodo* raiz)
{
    if (raiz != NULL)
    {
        printf(" %d",raiz->info);
        arv_pre_imprime(raiz->esq);
        arv_pre_imprime(raiz->dir);
    }
}

void arv_pos_imprime(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_pos_imprime(raiz->esq);
        arv_pos_imprime(raiz->dir);
        printf(" %d",raiz->info);
    }
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

Nodo *arv_insere_no(Nodo *raiz, int k)
{
    if (raiz == NULL)
    {
        return arv_cria_no(k,NULL,NULL);
    }
    else if (k < raiz->info)
    {
        raiz->esq = arv_insere_no(raiz->esq, k);
    }
    else
    {
        raiz->dir = arv_insere_no(raiz->dir, k);
    }
    return raiz;
}

void arv_insere(Arv_bin *arv, int k)
{
    arv->raiz = arv_insere_no(arv->raiz,k);
}

int main()
{
    Arv_bin *arv;
    int quant,quantele,cont1 = 1,cont2 = 0, vet[600],i;
    scanf("%d",&quant);
    while(quant != 0)
    {
        arv = arv_cria();
        scanf("%d",&quantele);
        for(i = 0; i < quantele; i++)
        {
            scanf("%d",&vet[i]);
        }
        for(i=0;i<quantele;i++)
        {
            arv_insere(arv,vet[i]);
        }
        printf("Case %d:\n",cont1);
        printf("Pre.:" );
        arv_pre_imprime(arv->raiz);
        printf("\n");
        printf("In..:" );
        arv_in_imprime(arv->raiz);
        printf("\n");
        printf("Post:" );
        arv_pos_imprime(arv->raiz);
        printf("\n\n");
        arv_libera_arvore(arv->raiz);
        cont1++;
        quant--;
    }
}