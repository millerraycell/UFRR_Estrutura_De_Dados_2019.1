//
// Created by Miller on 03/05/2019.
//
#include <iostream>
#include "TAD.h"

using namespace std;

AVL *arv_cria()
{
    AVL* arv = (AVL*) malloc(sizeof(AVL));
    arv->raiz = NULL;
    return arv;
}

Nodo *cria_nodo(int k)
{
    Nodo *p = (Nodo*)malloc(sizeof(Nodo));
    p->info = k;
    p->altura = 0;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

int altura_nodo(Nodo *r)
{
    if(r == NULL)
    {
        return -1;
    }
    return r->altura;
}

int fb_nodo(Nodo *r)
{
    if(r == NULL)
    {
        return 0;
    }
    return altura_nodo(r->dir) - altura_nodo(r->esq);
}

int max(int a, int b)
{
    return a > b ? a : b;
}


void imprime_pos_ordem(Nodo *root)
{
    if(root != NULL)
    {
        imprime_pos_ordem(root->esq);
        imprime_pos_ordem(root->dir);
        cout << root->info <<" ";
    }
}

void imprime_in_ordem(Nodo *root)
{
    if(root != NULL)
    {
        imprime_in_ordem(root->esq);
        cout << root->info <<" ";
        imprime_in_ordem(root->dir);
    }
}

void imprime_pre_ordem(Nodo *root)
{
    if(root != NULL)
    {
        cout << root->info <<" ";
        imprime_pre_ordem(root->esq);
        imprime_pre_ordem(root->dir);
    }
}

void imprime_arvores(AVL *tree)
{
    cout << "PRE ORDEM:"<<endl;
    imprime_pre_ordem(tree->raiz);
    cout << endl;
    cout << "IN ORDEM:"<<endl;
    imprime_in_ordem(tree->raiz);
    cout << endl;
    cout << "POS ORDEM:"<<endl;
    imprime_pos_ordem(tree->raiz);
    cout << endl;

}

Nodo *rot_right(Nodo *z)
{
    Nodo *y = z->esq;
    Nodo *w = y->dir;

    y->dir = z;
    z->esq = w;

    y->altura = 1 + max(altura_nodo(y->esq),altura_nodo(y->dir));
    z->altura = 1 + max(altura_nodo(z->esq),altura_nodo(z->dir));

    return y;
}

Nodo *rot_left(Nodo *z)
{
    Nodo *y = z->dir;
    Nodo *x = y->esq;

    y->esq = z;
    z->dir = x;

    y->altura = 1 + max(altura_nodo(y->esq),altura_nodo(y->dir));
    z->altura = 1 + max(altura_nodo(z->esq),altura_nodo(z->dir));

    return y;
}

void arv_insere(AVL *tree, int k)
{
    tree->raiz = arv_insere_no(tree->raiz,k);
}

Nodo *arv_insere_no(Nodo *raiz, int k)
{
    if (raiz == NULL)
    {
        return cria_nodo(k);
    }
    else if (k < raiz->info)
    {
        raiz->esq = arv_insere_no(raiz->esq, k);
    }
    else if (k > raiz->info)
    {
        raiz->dir = arv_insere_no(raiz->dir, k);
    }
    else
    {
        return raiz;
    }

    raiz->altura = 1 + max(altura_nodo(raiz->esq),altura_nodo(raiz->dir));
    int fb = fb_nodo(raiz);

    //Left left case
    if (fb < -1 && k < raiz->esq->info)
    {
        return rot_right(raiz);
    }

    //Right right case
    if(fb > 1 && k > raiz->dir->info)
    {
        return rot_left(raiz);
    }

    //Left right case
    if(fb < -1 && k > raiz->esq->info)
    {
        raiz->esq = rot_left(raiz->esq);
        return rot_right(raiz);
    }

    //Right left case
    if(fb > 1 && k < raiz->esq->info)
    {
        raiz -> dir = rot_right(raiz->dir);
        return rot_left(raiz);
    }
    return raiz;
}

Nodo *search_avl_nodes(Nodo *root, int x)
{
    if(root == NULL || root->info == x)
    {
        return root;
    }
    else if (x < root->info)
    {
        return search_avl_nodes(root->esq,x);
    }
    else
    {
        return search_avl_nodes(root->dir,x);
    }
}

int search_avl(AVL *arv, int x)
{
    Nodo *aux = search_avl_nodes(arv->raiz,x);
    if(aux == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void remover_arv(AVL *arv, int k)
{
    Nodo *aux = remover(arv->raiz, k);
    if(aux == NULL)
    {
        cout << "ELEMENTO NÃO ESTÁ NA ARVORE" <<endl;
    } else{
        cout << "ELEMENTO REMOVIDO COM SUCESSO" << endl;
        cout << "ARVORE ATUALIZADA:" << endl;
        imprime_arvores(arv);
    }
}

Nodo *remover(Nodo *raiz, int k)
{
    if(raiz == NULL)
    {
        return NULL;
    }
    else if(k < raiz->info)
    {
        raiz->esq = remover(raiz->esq,k);
    }
    else if (k > raiz->info)
    {
        raiz->dir = remover(raiz->dir,k);
    }
    else
    {
        /*
         * É uma folha
         */
        if(raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            raiz = NULL;
        }
            /*
             * Tem um filho a direita
             */
        else if(raiz->esq == NULL)
        {
            Nodo *aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
            /*
             * Tem um filho a esquerda
             */
        else if(raiz->dir == NULL)
        {
            Nodo *aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
            /*
             * Tem dois filhos
             */
        else
        {
            Nodo *aux = raiz->esq;
            while(aux->dir!=NULL)
            {
                aux = aux->dir;
            }
            /*
             * Troca as informações da raiz
             * com o nodo mais à direita da SAE
             */
            raiz->info = aux->info;
            aux->info = k;
            raiz->esq = remover(raiz->esq,k);
        }
    }

    /*
     * Árvore com só um nodo entçao
     * vai retornar NULL, pois removeu
     * o unico elemento da árvore
     */
    if(raiz == NULL)
    {
        return raiz;
    }

    /*
     * Atualiza a altura da raiz da
     * subárvore analisada
     */
    raiz->altura = 1 + max(altura_nodo(raiz->dir),altura_nodo(raiz->esq));

    /*
     * Calcula  fator de balnceamento da raiz da subárvore
     * analisada a fim de verificar se o nodo está desbalanceado
     */

    int fator_balanceamento = fb_nodo(raiz);

    /*
     * Caso desbalanceado, tem-se 4 casos
     * possíveis
     */

    /*
     * Left Left Case
     */
    if(fator_balanceamento < -1 && fb_nodo(raiz->esq) <= 0)
    {
        return rot_right(raiz);
    }
    /*
     * Left Right Case
     */
    if(fator_balanceamento < -1 && fb_nodo(raiz->esq) > 0)
    {
        raiz->esq = rot_left(raiz->esq);
        return rot_right(raiz);
    }
    /*
     * Right Right Case
     */
    if(fator_balanceamento > 1 && fb_nodo(raiz->esq) >= 0)
    {
        return rot_left(raiz);
    }
    /*
     * Right Left Case
     */
    if(fator_balanceamento > 1 && fb_nodo(raiz->esq) < 0)
    {
        raiz->dir = rot_left(raiz->dir);
        return rot_left(raiz);
    }
}

void liberando_arvore(AVL *arv)
{
    liberando_arvore_nodo(arv->raiz);
    free(arv);
}

void liberando_arvore_nodo(Nodo *raiz)
{
    if(raiz != NULL)
    {
        liberando_arvore_nodo(raiz->esq);
        liberando_arvore_nodo(raiz->dir);
        free(raiz);
    }
}