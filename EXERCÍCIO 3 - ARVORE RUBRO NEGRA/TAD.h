#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED

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

Arv_bin* arv_cria();
Nodo* arv_cria_no(int c, Nodo* esq, Nodo* dir);

void arv_imprime(Nodo* raiz);
void arv_pre_imprime(Nodo* raiz);
void arv_libera_arvore(Nodo* raiz);

void arv_bin_busca(Arv_bin *arv, int k);
Nodo *arv_busca_no(Nodo* raiz, int k);

void arv_insere(Arv_bin *arv, int k);
Nodo *arv_insere_no(Nodo *raiz, int k);

void abb_remove(Arv_bin* arv, int c);
Nodo *remove_no(Nodo *raiz, int c);

void abb_remove_invertido(Arv_bin* arv, int c);
Nodo *remove_no_invertido(Nodo *raiz, int c);

void is_abb(Arv_bin *arv);
int is_abb_no(Nodo *raiz);

int maior_valor_arv(Arv_bin *arv);
int maior_valor_no(Nodo *raiz);

int menor_valor_arv(Arv_bin *arv);
int menor_valor_no(Nodo *raiz);

void encontrar_k_menor_valor_nodo(Nodo *raiz, int *k);

void arvores_iguais(Arv_bin *arv1, Arv_bin *arv2);
int arvores_iguais_nodo(Nodo *raiz1, Nodo* raiz2);

int arv_binaria_um_filho(Arv_bin *arv);
int arv_binaria_um_filho_no(Nodo *raiz);

Arv_bin *cria_com_pre_ordem_no(int *v, int tam);

void verifica_sequencia(Arv_bin *arv, int *v);
int verifica_sequencia_no(Nodo *raiz, int *v);

#endif // TAD_H_INCLUDED
