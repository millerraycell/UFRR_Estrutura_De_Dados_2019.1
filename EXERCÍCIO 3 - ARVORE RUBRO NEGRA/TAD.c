#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

/**
 * Função que cria a árvore
 * @return arv -> Arvore criada
 */
Arv_bin* arv_cria()
{
    Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));
    arv->raiz = NULL;
    return arv;
}


/**
 * Função para criar os nodos da arvore
 * @param c -> Informação do nodo
 * @param esq -> Ponteiro para a o nodo a esquerda
 * @param dir -> Ponteiro para o nodo a direita
 * @return -> Nodo criado
 */
Nodo* arv_cria_no(int c, Nodo* esq, Nodo* dir)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->info = c;
    return nodo;
}


/**
 * Função que faz a impressão dos elementos da Árvore, de forma infixa
 * @param raiz -> Nodo para começar a fazer a impressão
 */
void arv_imprime(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_imprime(raiz->esq);
        printf("%d ",raiz->info);
        arv_imprime(raiz->dir);
    }
}

/**
 * Função que faz a impressão dos elementos da Árvore, de forma pré fixa
 * @param raiz -> Nodo para começar a fazer a impressão
 */
void arv_pre_imprime(Nodo* raiz)
{
    if (raiz != NULL)
    {
        printf("%d ",raiz->info);
        arv_pre_imprime(raiz->esq);
        arv_pre_imprime(raiz->dir);
    }
}
 /**
  * Função para liberar os elementos da árvore
  * @param raiz -> Nodo pai da árvore
  */
void arv_libera_arvore(Nodo* raiz)
{
    if (raiz != NULL)
    {
        arv_libera_arvore(raiz->esq);
        arv_libera_arvore(raiz->dir);
        free(raiz);
    }
}
/**
 * Função que chama a busca da árvore pelos nodos
 * @param arv -> árvore que vai ser feita a busca
 * @param k -> elemento a ser procurado
 */
 void arv_bin_busca(Arv_bin *arv, int k)
{
    Nodo *aux = arv_busca_no(arv->raiz, k);
    if(aux != NULL)
    {
        printf("ELEMENTO ENCONTRADO: %d\n",aux->info);
    }
    else
    {
        printf("ELEMENTO NÃO %d PRESENTE NA ÁRVORE\n",k);
    }
}

/**
 * Função que faz a busca em cada nodo, fazendo o percurso
 * de acordo com o elemento que está sendo procurado
 *
 * @param raiz -> Nodo pai da arvore onde será realizada a busca
 * @param k -> Elemento a ser procurado na árvore
 * @return -> Nodo com a informação, caso o elemento procurado esteja na árvore, NULL, no caso do elemento
 * não estiver na árvore
 */
Nodo *arv_busca_no(Nodo* raiz, int k)
{
    if(raiz == NULL || raiz->info == k)
    {
        return raiz;
    }
    else if(k < raiz->info)
    {
        return arv_busca_no(raiz->esq,k);
    }
    else
    {
        return arv_busca_no(raiz->esq,k);
    }
}
/**
 * Função que chama a função que faz inserção de elemento no nodo
 * da árvore desejada
 *
 * @param arv -> Árvore a ter os elementos inseridos
 * @param k -> Elemento a ser inserido
 */
void arv_insere(Arv_bin *arv, int k)
{
    arv->raiz = arv_insere_no(arv->raiz,k);
}

/**
 * Função que insere elemento no nodo desejado
 * @param raiz -> Nodo da árvore que vai ter o elemento inserido
 * @param k -> Elemento a ser inserido
 * @return -> Nodo com o elemento inserido
 */
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
/**
 * Função que chama a função que faz remoção de elemento no nodo
 * da árvore desejada
 *
 * @param arv -> Árvore a ter os elementos inseridos
 * @param k -> Elemento a ser removido
 */
void abb_remove(Arv_bin* arv, int c)
{
    arv->raiz = remove_no(arv->raiz,c);
}
/**
 * Função que analisa os nodos e faz a remoção caso encontre o elemento
 * que deseja que seja removido
 *
 * @param raiz -> Nodo da árvore que vai ter o elemento inserido
 * @param k -> Elemento a ser removido
 * @return Nodo pai da árvore sem o elemento, caso o mesmo tenha sido encontrado
 */
Nodo *remove_no(Nodo *raiz, int c)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else if(c < raiz->info)
    {
        raiz->esq = remove_no(raiz->esq, c);
    }
    else if(c > raiz->info)
    {
        raiz->dir = remove_no(raiz->dir, c);
    }
    else
    {
        if(raiz -> esq == NULL && raiz -> dir == NULL)
        {
            free(raiz);
            raiz = NULL;
        }
        else if(raiz -> esq == NULL)
        {
            Nodo *aux = raiz;
            raiz = raiz -> dir;
            free(aux);
        }
        else if(raiz -> dir == NULL)
        {
            Nodo *aux = raiz;
            raiz = raiz -> esq;
            free(aux);
        }
        else
        {
            Nodo *aux = raiz->esq;
            while(aux->dir != NULL)
            {
                aux= aux->dir;
            }
            raiz->info = aux->info;
            aux->info = c;
            raiz->esq = remove_no(raiz->esq, c);
        }

    }
    return raiz;
}

/**
 * Função que chama a função que faz a remoção usando o sucessor
 * @param arv -> arvore a ser analisada
 * @param c => elemento que se deseja remover
 */
void abb_remove_invertido(Arv_bin* arv, int c)
{
    arv->raiz = remove_no_invertido(arv->raiz,c);
}
/**
 * Função que analisa os nodos e faz a remoção caso encontre o elemento
 * que deseja que seja removido, usando o sucessor, ao invés do precessor
 * sendo assim o inverso da função anterior
 *
 * @param raiz -> Nodo da árvore que vai ter o elemento inserido
 * @param k -> Elemento a ser inserido
 * @return -> Nodo com o elemento inserido
 */
Nodo *remove_no_invertido(Nodo *raiz, int c)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else if(c < raiz->info)
    {
        raiz->esq = remove_no(raiz->esq, c);
    }
    else if(c > raiz->info)
    {
        raiz->dir = remove_no(raiz->dir, c);
    }
    else
    {
        if(raiz -> esq == NULL && raiz -> dir == NULL)
        {
            free(raiz);
            raiz = NULL;
        }
        else if(raiz -> dir == NULL)
        {
            Nodo *aux = raiz;
            raiz = raiz -> esq;
            free(aux);
        }
        else if(raiz -> esq == NULL)
        {
            Nodo *aux = raiz;
            raiz = raiz -> dir;
            free(aux);
        }
        else
        {
            Nodo *aux = raiz->dir;
            while(aux->dir != NULL)
            {
                aux= aux->esq;
            }
            raiz->info = aux->info;
            aux->info = c;
            raiz->dir = remove_no(raiz->dir, c);
        }

    }
    return raiz;
}
/**
 * Função que chama a função que verifica os nodos para saber
 * se uma arvore é binária de busca
 * @param arv -> arvore a ser analisada
 */
void is_abb(Arv_bin *arv)
{
    int aux = is_abb_no(arv->raiz);
    if(aux == 1)
    {
        printf("ARVORE BINÁRIA DE BUSCA\n");
    }
    else
    {
        printf("NÃO É ARVORE BINÁRIA DE BUSCA");
    }
}

/**
 * Função que verifica nodo por nodo caso a arvore vai ser ou não
 * binária de busca
 * @param raiz -> Nodo pai da árvore que vai ser analisado
 * @return ->1 - arvore binaria de busca, 0 - Não é arvore binaria de busca
 */
int is_abb_no(Nodo *raiz)
{
    if(raiz == NULL)
    {
        return 1;
    }
    else if (raiz->dir == NULL)
    {
        return is_abb_no(raiz->esq);
    }
    else if (raiz->esq == NULL)
    {
        return is_abb_no(raiz->dir);
    }
    else if ((raiz->info < raiz->esq->info) || (raiz->info > raiz->dir->info))
    {
        return 0;
    }
    else
    {
        return is_abb_no(raiz->esq) && is_abb_no(raiz->dir);
    }

}

/**
 * Função que chama a função para saber o maior valor da árvore
 * @param arv -> arvore a ser analisada
 * @return -> maior número da árvore
 */
int maior_valor_arv(Arv_bin *arv)
{
    return maior_valor_no(arv->raiz);
}
/**
 * Função que vai analisando nodo por nodo até chegar ao nodo
 * mais a direta, pois em uma arvore binária de busca o maior valor
 * será a folha mais a direita
 *
 * @param raiz -> Nodo pai da árvore
 * @return -> maior elemento da árvore
 */
int maior_valor_no(Nodo *raiz)
{
    if(raiz->dir != NULL)
    {
        return maior_valor_no(raiz->dir);
    }
    else
    {
        return raiz->info;
    }
}
/**
 * Função que chama a função que faz a procura do menor
 * elemento da árvore de forma iterativa
 * @param arv -> Árvore a ser analisada
 * @return inteiro que é o menor valor da árvore
 */
int menor_valor_arv(Arv_bin *arv)
{
    return menor_valor_no(arv->raiz);
}

/**
 * Função que verifica iterativamente a folha da árvore mais a esquerda,
 * pois em uma árvore binária de busca o menor elemento será armazenado na folha mais
 * a esquerda
 *
 * @param raiz -> Nodo pai da árvore
 * @return Menor valor da Árvore
 */
int menor_valor_no(Nodo *raiz)
{
    while(raiz->esq !=NULL)
    {
        raiz = raiz->esq;
    }
    return raiz->info;
}
/**
 * Função que retorna o k-ésimo menor valor da árvore
 *
 * @param raiz -> Nodo pai da árvore a ser analisada
 * @param k -> valor que se deseja encontrar na árvore
 */
void encontrar_k_menor_valor_nodo(Nodo *raiz, int *k)
{
    if(raiz != NULL)
    {
        encontrar_k_menor_valor_nodo(raiz->esq,k);
        (*k)--;
        if(*k == 0)
        {
            printf("VALOR DESEJADO: %d\n",raiz->info);
            return;
        }
        else
        {
            encontrar_k_menor_valor_nodo(raiz->dir,k);
        }
    }
}
/**
 * Função que chama a função que verifica se duas árvores
 * binárias de busca são iguais
 * @param arv1 -> Primeira arvore a ser analisada
 * @param arv2 -> Segunda Árvore a ser analisada
 */
void arvores_iguais(Arv_bin *arv1, Arv_bin *arv2)
{
    int aux = arvores_iguais_nodo(arv1->raiz,arv2->raiz);
    if(aux == 1)
    {
        printf("ARVORES BINARIAS DE BUSCA IDÊNTICAS\n");
    }
    else
    {
        printf("ÁRVORES NÃO IDÊNTICAS\n");
    }
}
/**
 * Função que verifica se duas árvores binárias de
 * busca são iguais tendo como referência seus nodos pais
 *
 * @param raiz1 -> Nodo pai da primeira árvore a ser analisada
 * @param raiz2 -> Nodo pai da primeira árvore a ser analisada
 * @return 1-> Arvores iguais, 0-> Arvores diferentes
 */
int arvores_iguais_nodo(Nodo *raiz1, Nodo *raiz2)
{
    if(raiz1 == NULL)
    {
        return raiz2 == NULL ? 1 : 0;
    }
    else if(raiz1 == raiz2)
    {
        return 1;
    }
    else if (raiz1->info != raiz2->info)
    {
        return 0;
    }
    else if(raiz1->esq == raiz2->esq)
    {
        return arvores_iguais_nodo(raiz1->dir,raiz2->dir);
    }
    else if(raiz1->dir == raiz2->dir)
    {
        return arvores_iguais_nodo(raiz1->esq,raiz2->esq);
    }
    else
    {
        return arvores_iguais_nodo(raiz1->esq,raiz2->esq) && arvores_iguais_nodo(raiz1->dir,raiz2->dir);
    }
}

/**
 * Função na qual é feita a chamada da função que analisa
 * se algum elemento da arvore binária de busca possui apenas um
 * filho
 *
 * @param arv -> arvore a ser analisada
 * @return 1-> Algum elemento possui apenas um filho, 0-> Nenhum elemento tem apenas um filho
 */
int arv_binaria_um_filho(Arv_bin *arv)
{
    return arv_binaria_um_filho_no(arv->raiz);
}

/**
 * Função na qual é feita a analise se algum elemento
 * da arvore binária de busca possui apenas um
 * filho
 *
 * @param raiz -> Nodo pai da árvore a ser analisada
 * @return 1-> Algum elemento possui apenas um filho, 0-> Nenhum elemento tem apenas um filho
 */
int arv_binaria_um_filho_no(Nodo *raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    else if(raiz->dir == NULL && raiz->esq == NULL)
    {
        return 0;
    }
    else if(raiz->esq == NULL && raiz->dir != NULL)
    {
        return 1;
    }
    else if(raiz->esq != NULL && raiz->dir == NULL)
    {
        return 1;
    }
    else
    {
        return arv_binaria_um_filho_no(raiz->dir) + arv_binaria_um_filho_no(raiz->esq);
    }
}
/**
 * Função que recebe um vetor que representa uma árvore binária
 * de busca representada em pré forma, e retorna a arvore.
 * @param v -> vetor com elementos
 * @param tam -> número de elementos
 * @return Árvore resultante
 */
Arv_bin *cria_com_pre_ordem_no(int *v, int tam)
{
    Arv_bin *arv = arv_cria();
    int i;
    for (i=0 ; i < tam ; i++)
    {
        arv_insere(arv,v[i]);
    }
    return arv;
}
/**
 * Função que chama a função que verifica se uma
 * sequência ordenada pertence ou não a uma árvore
 * binária de busca.
 *
 * @param arv -> arvore a ser analisada
 * @param v -> Vetor com a sequência a ser analisada
 */
void verifica_sequencia(Arv_bin *arv, int *v)
{
    int aux = verifica_sequencia_no(arv->raiz,v);
    if(aux == 1)
    {
        printf("SEQUÊNCIA FAZ PARTE DA ÁRVORE\n");
    }
    else
    {
        printf("SEQUÊNCIA NÃO FAZ PARTE DA ÁRVORE\n");
    }
}
/**
 * Função que verifica se uma sequência ordenada pertence
 * ou não a uma árvore binária de busca, de acordo com o
 * nodo pai da árvore e o vetor com os elementos
 * @param raiz -> Nodo pai da árvore
 * @param v -> vetor com os elementos ordenados
 * @return 1-> Sequência faz parte da árvore, 0 -> Sequência não faz parte da árvore
 */
int verifica_sequencia_no(Nodo *raiz, int *v)
{
    int i = 0;
    if(raiz == NULL)
    {
        return 0;
    }
    else if(raiz->info == v[i])
    {
        return 1;
    }
    else if(raiz->info > v[i])
    {
        i++;
        return verifica_sequencia_no(raiz->esq,v);
    }
    else if(raiz->info < v[i])
    {
        i++;
        return verifica_sequencia_no(raiz->dir,v);
    }
    else
    {
        return verifica_sequencia_no(raiz->esq,v) && verifica_sequencia_no(raiz->dir,v);
    }
}