#include <iostream>
#include "TAD.cpp"

using namespace std;

int main()
{
    char escolha[3];
    int x,order,aux;

    cout << "INSIRA A ORDEM DA ÁRVORE QUE DESEJA" << endl;
    cin >> order;
    BTree *tree = btree_create(order);

    while(true)
    {
        cout << "\t\tARVORE B\t\t" << endl;
        cout << "OPÇÕES: " << endl;
        cout << "1 - INSERIR NA ÁRVORE\n" <<endl;
        cout << "2 - BUSCAR NA ÁRVORE\n" << endl;
        cout << "0 - SAIR\n\n" << endl;
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
                    btree_insert(tree,aux);
                }break;
            case '2':
                cout << "INSIRA O NUMERO QUE DESEJA PROCURAR NA ARVORE" <<endl;
                cin >> aux;
                btree_search(tree,aux);
                break;
            case '0':
                return 0;
            default:
                cout << "OPÇÃO INCORRETA" << endl <<"INSIRA UMA OPÇÃO VÁLIDA"<< endl;
        }
    }
}