#include <stdio.h>
#include <stdlib.h>
#include "TAD.c"

int main()
{
    int x,y,k;
    Nodo *aux = arv_cria_no('v',NULL,NULL);

    Arv_bin *arv = arv_cria(
            arv_cria_no('a',arv_cria_no('b',NULL,arv_cria_no('d',NULL,NULL)),
            arv_cria_no('c',arv_cria_no('e',NULL,NULL),arv_cria_no('f',NULL,NULL))
            ));

    arv_imprime_pre_ordem(arv->raiz);
    printf("\n");

    Arv_bin *esp = espelho(arv);

    arv_imprime_pre_ordem(esp->raiz);
    printf("\n");

    x = arv_pertence(arv,'e');
    if (x == 1)
    {
        printf("ELEMENTO ENCONTRADO\n");
    }
    else
    {
        printf("ELEMENTO NAO ENCONTRADO\n");
    }

    aux = arv_busca(arv,'c');
    arv_imprime_formatado_no(aux);

    y = arv_altura(arv);
    printf("\n%d\n",y);

    k = tamanho(arv);
    printf("%d\n",k);

    arv_libera_arvore(arv->raiz);

    return 0;
}



