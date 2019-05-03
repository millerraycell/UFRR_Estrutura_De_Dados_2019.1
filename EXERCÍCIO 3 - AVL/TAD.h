//
// Created by Miller on 03/05/2019.
//

#ifndef AVL_TAD_H
#define AVL_TAD_H

typedef struct no
{
    int info;
    struct no *dir;
    struct no *esq;
    int altura;
}Nodo;

typedef struct
{
    Nodo *raiz;
}AVL;

AVL *arv_cria();
Nodo *cria_nodo(int k);

int altura_nodo(Nodo *r);
int fb_nodo(Nodo *r);
int max(int a, int b);

void imprime_arvores(AVL *tree);
void imprime_pre_ordem(Nodo *root);
void imprime_in_ordem(Nodo *root);
void imprime_pos_ordem(Nodo *root);

Nodo *rot_right(Nodo *z);
Nodo *rot_left(Nodo *z);

void arv_insere(AVL *tree, int k);
Nodo *arv_insere_no(Nodo *raiz, int k);

Nodo *search_avl_nodes(Nodo *root, int x);
int search_avl(AVL *arv, int x);

void remover_arv(AVL *arv, int k);
Nodo *remover(Nodo *raiz, int k);

void liberando_arvore(AVL *arv);
void liberando_arvore_nodo(Nodo *raiz);

#endif //AVL_TAD_H
