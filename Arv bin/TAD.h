#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED

typedef struct no
{
    char info;
    struct no *esq;
    struct no *dir;

}Nodo;

typedef struct arv_bin
{
    Nodo* raiz;

}Arv_bin;

Arv_bin* arv_cria(Nodo *raiz);
Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir);

void arv_imprime_escolhendo_ordem(Arv_bin* arv, int ordem);
void arv_imprime_pre_ordem(Nodo *raiz);
void arv_imprime_infixa(Nodo *raiz);
void arv_imprime_pos_ordem(Nodo *raiz);

void arv_imprime_formatado(Arv_bin* arv);
void arv_imprime_formatado_no(Nodo* raiz);

void arv_libera_arvore(Nodo* raiz);

int arv_pertence(Arv_bin *arv, char c);
int arv_pertence_no(Nodo *raiz, char c);

Nodo* arv_busca(Arv_bin *arv, char k);
Nodo* arv_busca_no(Nodo *raiz, char k);

int arv_altura(Arv_bin* arv);
int arv_altura_no(Nodo* raiz);

int tamanho(Arv_bin *arv);

void largura(Arv_bin *arv);

Arv_bin *espelho(Arv_bin *orig);
Nodo *trocar(Nodo *raiz);

void imprime_in_ordem_iterativo(Arv_bin *arv);
void imprime_pos_ordem_iterativo(Arv_bin *arv);

int conta_numero_folhas(Arv_bin *arv);
int conta_numero_folhas_no(Nodo* raiz);

int verifica_est_bin(Arv_bin *arv);
int verifica_est_bin_no(Nodo *raiz);

int verficar_arv_bin_comp(Arv_bin* arv);

#endif // TAD_H_INCLUDED
