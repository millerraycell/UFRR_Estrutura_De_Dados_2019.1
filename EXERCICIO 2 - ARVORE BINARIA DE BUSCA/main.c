#include <stdio.h>
#include <stdlib.h>
#include "TAD.c"

int main()
{
    Arv_bin *arv = arv_cria(), *arv2 = arv_cria(),*arv3 = arv_cria();
    int valor,*valor1 = (int*)malloc(sizeof(int));
    int tamanho, *vet, i;
    int numero,*vetor;

    printf("QUESTÃO 1:\n");
    printf("ARVORE PREENCHIDA COM OS VALORES:\n");
    arv_insere(arv,50);
    arv_insere(arv,30);
    arv_insere(arv,70);
    arv_insere(arv,20);
    arv_insere(arv,40);
    arv_insere(arv,60);
    arv_insere(arv,80);
    arv_insere(arv,15);
    arv_insere(arv,25);
    arv_insere(arv,35);
    arv_insere(arv,45);
    arv_insere(arv,36);
    arv_imprime(arv->raiz);
    printf("\n");
    arv_bin_busca(arv,30);
    printf("REMOVENDO ELEMENTO 30\n");
    abb_remove(arv,30);
    arv_imprime(arv->raiz);
    printf("\n");
    arv_bin_busca(arv,30);
    printf("\n");


    printf("QUESTÃO 2:\n");
    arv_imprime(arv->raiz);
    printf("\n");
    printf("REMOVENDO ELEMENTO 45\n");
    abb_remove_invertido(arv,45);
    arv_imprime(arv->raiz);
    printf("\n\n");


    printf("QUESTÃO 3\n");
    is_abb(arv);
    printf("\n");


    printf("QUESTÃO 4:\n");
    printf("VALOR MAXIMO DA ARVORE: %d",maior_valor_arv(arv));
    printf("\n\n");


    printf("QUESTAO 5:\n");
    printf("MENOR VALOR DA ARVORE: %d",menor_valor_arv(arv));
    printf("\n\n");


    printf("QUESTÃO 6:\nINSIRA O K-ESIMO MENOR VALOR DESEJADO:\n");
    scanf("%d",&valor);
    *valor1 = valor;
    encontrar_k_menor_valor_nodo(arv->raiz,valor1);
    printf("\n");

    printf("QUESTÃO 7:\n");
    arv_insere(arv2,50);
    arv_insere(arv2,30);
    arv_insere(arv2,70);
    arv_insere(arv2,20);
    arv_insere(arv2,40);
    arv_insere(arv2,60);
    arv_insere(arv2,80);
    arv_insere(arv2,15);
    arv_insere(arv2,25);
    arv_insere(arv2,35);
    arv_insere(arv2,45);
    arv_insere(arv2,36);
    printf("ARVORE 1:\n");
    arv_imprime(arv->raiz);
    printf("\n");
    printf("ARVORE 1:\n");
    arv_imprime(arv2->raiz);
    printf("\n");
    arvores_iguais(arv,arv2);
    printf("\n");


    printf("QUESTÃO 8:\n");
    printf("NUMERO DE NOS DA ARVORE QUE POSSUEM 1 FILHO: %d\n",arv_binaria_um_filho(arv));
    printf("\n");


    printf("QUESTÃO 9:\nINSIRA O TAMANHO DA EXPRESSÃO:\n");
    scanf("%d",&tamanho);
    vet = (int*)malloc(tamanho*sizeof(int));
    for (i = 0; i<tamanho;i++)
    {
        printf("ELEMENTO %d\n",i+1);
        scanf("%d",&vet[i]);
    }
    arv3 = cria_com_pre_ordem_no(vet,tamanho);
    arv_imprime(arv3->raiz);
    printf("\n\n");


    printf("QUESTÃO 10:\nINSIRA O TAMANHO DA EXPRESSÃO QUE DESEJA COMPARAR:\n");
    scanf("%d",&numero);
    vetor = (int*)malloc(numero*sizeof(int));
    for (i = 0; i<tamanho;i++)
    {
        printf("ELEMENTO %d\n",i+1);
        scanf("%d",&vetor[i]);
    }
    verifica_sequencia(arv,vetor);

    arv_libera_arvore(arv->raiz);
    arv_libera_arvore(arv2->raiz);
    arv_libera_arvore(arv3->raiz);
    free(valor1);
    free(vet);
    free(vetor);
    return 0;
}
