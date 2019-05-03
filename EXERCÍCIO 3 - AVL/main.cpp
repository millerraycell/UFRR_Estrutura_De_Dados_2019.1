#include <iostream>
#include "TAD.h"

using namespace std;

int main()
{
    AVL *arv = arv_cria();
    char escolha[3];
    int x,aux,aux2;

    while(true)
    {
        cout << "\t\tARVORE AVL\t\t" << endl;
        cout << "OPÇÕES: " << endl;
        cout << "1 - INSERIR NA ÁRVORE\n" <<endl;
        cout << "2 - IMPRIMIR A ÁRVORE\n" << endl;
        cout << "3 - BUSCAR NA ÁRVORE\n" << endl;
        cout << "4 - REMOVER ELEMENTO DA ÁRVORE\n" << endl;
        cout << "5 - SAIR\n\n" << endl;
        cout << "INSIRA A OPÇÃO QUE DESEJA:\n" << endl;
        cin >> escolha;
        switch (escolha[0]) {
            case '1':
                cout << "INSIRA A QUANTIDADE DE ELEMENTOS QUE DESEJA INSERIR NA ARVORE" << endl;
                cin >> x;
                cout << endl << endl;
                for (int i = 0; i < x; i++) {
                    cout << "INSIRA O ELEMENTO " << i + 1 << " QUE DESEJA ADICIONAR NA ARVORE" << endl;
                    cin >> aux;
                    arv_insere(arv,aux);
                }break;
            case '2':
                imprime_arvores(arv);
                break;
            case '3':
                cout << "INSIRA O NUMERO QUE DESEJA PROCURAR NA ARVORE" <<endl;
                cin >> aux;
                aux2 = search_avl(arv,aux);
                if(aux2)
                {
                    cout << "ELEMENTO ESTÁ NA ARVORE" << endl;
                } else{
                    cout << "ELEMENTO NÃO ESTÁ NA ÁRVORE" <<endl;
                }break;
            case '4':
                cout << "INSIRA O ELEMENTO QUE DESEJA REMOVER DA ÁRVORE" << endl;
                cin >> aux;
                remover_arv(arv,aux);break;
            case '5':
                liberando_arvore(arv);
                return 0;
            default:
                cout << "OPÇÃO INCORRETA" << endl <<"INSIRA UMA OPÇÃO VÁLIDA"<< endl;
        }
    }
}