#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

int main()
{
    Arv_bin *arv = arv_cria(
            arv_cria_no('a',arv_cria_no('b',NULL,arv_cria_no('d',NULL,NULL)),
            arv_cria_no('c',arv_cria_no('e',NULL,NULL),arv_cria_no('f',NULL,NULL))
            ));

    Arv_bin *esp = espelho(arv);


    printf("QUESTAO 2: PERCURSO EM LARGURA:\n");
    largura(arv);

    printf("\n\nQUESTAO 3: NUMERO DE NOS DA ARVORE:\n%d",tamanho(arv));

    printf("\n\nQUESTAO 4: ESPELHO DA ARVORE:\nARVORE EM PRE ORDEM:\n");
    arv_imprime_pre_ordem(arv->raiz);
    printf("\nESPELHO:\n");
    arv_imprime_pre_ordem(esp->raiz);

    printf("\n\nQUESTAO 5: PERCURSO IN ORDEM ITERATIVO:\n");
    imprime_in_ordem_iterativo(arv);

    printf("\n\nQUESTAO 6: PERCURSO POS ORDEM ITERATIVO:\n");
    imprime_pos_ordem_iterativo(arv);

    printf("\n\nQUESTAO 7: NUMERO DE FOLHAS DE UMA ARVORE:\n%d",conta_numero_folhas(arv));

    printf("\n\nQUESTAO 8: VERFICAR ARVORE BINARIA ESTRITAMENTE BINARIA:\n");
    if(verifica_est_bin(arv))
    {
        printf("\nARVORE ESTRITAMENTE BINARIA\n");
    }
    else
    {
        printf("ARVORE NAO ESTRITAMENTE BINARIA\n");
    }

    printf("\n\nQUESTAO 9: ARVORE BINARIA COMPLETA:\n");
    if(verficar_arv_bin_comp(arv))
    {
        printf("\nARVORE COMPLETA\n");
    }
    else
    {
        printf("ARVORE NAO COMPLETA\n");
    }

    arv_libera_arvore(arv->raiz);

    return 0;
}
