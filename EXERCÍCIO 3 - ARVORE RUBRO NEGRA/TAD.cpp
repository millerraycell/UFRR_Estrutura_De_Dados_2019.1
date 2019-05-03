//
// Created by Miller on 03/05/2019.
//
#include <iostream>
#include "TAD.h"

using namespace std;

/**
 * Função que inicializa a árvore
 * @return -> arv criada
 */
RB_TREE *rbt_create()
{
    RB_TREE *tree = (RB_TREE *)malloc(sizeof(RB_TREE));
    Node *n = (Node*)malloc(sizeof(Node));
    tree->nil = n;
    tree->nil->color = BLACK;
    tree->root = tree->nil;
    return tree;
}

void print_tree(RB_TREE *tree)
{
    cout << "PRE ORDEM:"<<endl;
    prefix_print_tree(tree);
    cout << endl;
    cout << "IN ORDEM:"<<endl;
    infix_print_tree(tree);
    cout << endl;
    cout << "POS ORDEM:"<<endl;
    postfix_print_tree(tree);
    cout << endl;

}

/**
 * Método que chama a função para fazer o print em forma
 * infixa
 * @param tree -> Árvore que vai ser printada
 */

void infix_print_tree(RB_TREE *tree)
{
    infix_print_node(tree,tree->root);
}

/**
 * Função que percorre nodo a nodo fazendo o
 * print da forma infixa
 * @param tree -> Àrvore que possui o nodo tree->nil para se fazer a veficação
 * da condição de parada
 * @param root -> Nodo raiz da árvore a ser printada
 */

void infix_print_node(RB_TREE *tree ,Node *root)
{
    if(root != tree->nil)
    {
        infix_print_node(tree,root->left);
        cout << "[" <<root->key << " ";
        if(root->color == RED)
        {
            cout << "RED";
        } else{
            cout << "BLACK";
        }
        cout << "] ";
        infix_print_node(tree,root->right);
    }
}

/**
 * Método que chama a função para fazer o print em forma
 * posfixa
 * @param tree -> Árvore que vai ser printada
 */

void postfix_print_tree(RB_TREE *tree)
{
    postfix_print_node(tree,tree->root);
}

/**
 * Função que percorre nodo a nodo fazendo o
 * print da forma posfixa
 * @param tree -> Àrvore que possui o nodo tree->nil para se fazer a veficação
 * da condição de parada
 * @param root -> Nodo raiz da árvore a ser printada
 */

void postfix_print_node(RB_TREE *tree ,Node *root)
{
    if(root != tree->nil)
    {
        postfix_print_node(tree,root->left);
        postfix_print_node(tree,root->right);
        cout << "[" <<root->key << " ";
        if(root->color == RED)
        {
            cout << "RED";
        } else{
            cout << "BLACK";
        }
        cout << "] ";
    }
}

/**
 * Método que chama a função para fazer o print em forma
 * prefixa
 * @param tree -> Árvore que vai ser printada
 */

void prefix_print_tree(RB_TREE *tree)
{
    prefix_print_node(tree,tree->root);
}

/**
 * Função que percorre nodo a nodo fazendo o
 * print da forma infixa
 * @param tree -> Àrvore que possui o nodo tree->nil para se fazer a veficação
 * da condição de parada
 * @param root -> Nodo raiz da árvore a ser printada
 */

void prefix_print_node(RB_TREE *tree ,Node *root)
{
    if(root != tree->nil)
    {
        cout << "[" <<root->key << " ";
        if(root->color == RED)
        {
            cout << "RED";
        } else{
            cout << "BLACK";
        }
        cout << "] ";
        prefix_print_node(tree,root->left);
        prefix_print_node(tree,root->right);
    }
}

/**
 * Função para fazer a rotação para a esquerda
 * dos nodos da árvore
 * @param tree -> Árvore que vai ser rodada, árvore usada como parâmetro para se acessar o tree->nil
 * @param x -> Nodo a ser rodado para a esquerda
 */

void left_rotate(RB_TREE *tree, Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if(y->left != tree->nil)
    {
        y->left->father = x;
    }
    y->father = x->father;
    if(x->father == tree->nil)
    {
        tree->root = y;
    }
    else if (x == x->father->left)
    {
        x->father->left = y;
    }
    else
    {
        x->father->right = y;
    }
    y->left = x;
    x->father = y;
}

/**
 * Função para fazer a rotação para a direita
 * dos nodos da árvore
 * @param tree -> Árvore que vai ser rodada, árvore usada como parâmetro para se acessar o tree->nil
 * @param x -> Nodo a ser rodado para a direita
 */

void right_rotate(RB_TREE *tree, Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    if(y->right != tree->nil)
    {
        y->right->father = x;
    }
    y->father = x->father;
    if(x->father == tree->nil)
    {
        tree->root = y;
    }
    else if (x == x->father->right)
    {
        x->father->right = y;
    }
    else
    {
        x->father->left = y;
    }
    y->right = x;
    x->father = y;
}

/**
 * Função encapsuladora da função que vai fazer a inserção de um elemento na árvore
 * na função será criado um nodo que possui o inteiro passado como parâmetro, que será
 * enviado para a função que inserirá o nodo na árvore.
 *
 * @param tree -> Árvore a ser inserido o Nodo
 * @param z -> Informação do nodo que será inserido
 */
void rb_insert(RB_TREE *tree, int z)
{
    Node *k = (Node*)malloc(sizeof(Node));
    k->left = k->right = k->father = tree->nil;
    k->color = RED;
    k->key = z;
    rb_insert_node(tree,k);
}

/**
 * Função que irá percorrer a árvore e encontrará a posição devida para que se deva
 * ser inserido o nodo, de acordo com as especifiações da árvore.
 *
 * @param tree -> Árvore que será inserido o nodo
 * @param z -> Nodo a ser inserido
 */
void rb_insert_node(RB_TREE *tree, Node *z)
{
    Node *y = tree->nil;
    Node *x = tree->root;

    while (x!= tree->nil)
    {
        y = x;
        x = z->key < x->key ? x->left : x->right;
    }

    z->father = y;

    if(y == tree->nil)
    {
        tree->root = z;
    }
    else if(z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }

    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;
    tree->root = rb_insert_fixup(tree,z);
}

/**
 * Função criada para corrigir os problemas na inserção da árvore, o trabalho da
 * função é manter as regras da árvore rubro negra.
 *
 * @param tree -> Árvore que foi inserido o nodo.
 * @param k -> Nodo que foi inserido.
 * @return -> Será retornada o nodo raiz da árvore consertada.
 */

Node *rb_insert_fixup(RB_TREE *tree, Node *k)
{
    Node *y;
    while (k->father->color == RED)
    {
        if(k->father->father->left == k->father)
        {
            y = k->father->father->right;
            if(y->color == RED) //caso 1
            {
                k->father->color = BLACK;
                y->color = BLACK;
                k->father->father->color = RED;
                k = k->father->father;
            }
            else
            {
                if(k == k->father->right) // caso 2
                {
                    k = k->father;
                    left_rotate(tree,k);
                }
                //caso 3
                k->father->color = BLACK;
                k->father->father->color = RED;
                right_rotate(tree,k->father->father);
            }
        }
        else
        {
            if(k->father->father->right == k->father)
            {
                y = k->father->father->left;
                if(y->color == RED) //caso 1
                {
                    k->father->color = BLACK;
                    y->color = BLACK;
                    k->father->father->color = RED;
                    k = k->father->father;
                }
                else
                {
                    if(k == k->father->left) // caso 2
                    {
                        k = k->father;
                        right_rotate(tree,k);
                    }
                    //caso 3
                    k->father->color = BLACK;
                    k->father->father->color = RED;
                    left_rotate(tree,k->father->father);
                }
            }
        }
    }
    tree->root->color = BLACK;
    return tree->root;
}

/**
 * Função que encapsula a função que faz a busca na árvore.
 *
 * @param tree -> Árvore a ser buscada.
 * @param info -> Informação que se deseja verificar se está na árvore.
 * @return -> Se a informação está presente na árvore, será retornado o nodo que possui tal
 * informação, caso não se encontre a informação na árvore será retornado o tree->nil, indicando que
 * a informação não está presente na árvore
 */

int rb_research(RB_TREE *tree, int info)
{
    Node *aux = rb_search(tree,info);
    if(aux == NULL)
    {
        return 0;
    } else
    {
        return 1;
    }
}

Node *rb_search(RB_TREE *tree, int info)
{
    return rb_search_node(tree,tree->root,info);
}

/**
 * Função que percorre a árvore em busca da informação que se deseja que seja verificada.
 * @param tree -> Árvore que se deseja fazer a busca, a árvore é utilizada por causa do nodo tree->nil,
 * que indica a condição de parada da função
 * @param root -> Nodo raiz da arvore que será feita a busca
 * @param info -> Informação que se deseja verificar se está presente na árvore
 * @return
 */

Node *rb_search_node(RB_TREE *tree, Node *root, int info)
{
    if(root == tree->nil || root->key == info)
    {
        return root;
    }
    else if(root->key > info)
    {
        return rb_search_node(tree,root->left,info);
    }
    else
    {
        return rb_search_node(tree,root->right,info);
    }
}

void rb_transplant(RB_TREE *tree, Node *u, Node* v)
{
    if(u->father == tree->nil)
    {
        tree->root = v;
    }
    else if(u == u->father->left)
    {
        u->father->left = v;
    }
    else
    {
        u->father->right = v;
    }
    v->father = u->father;
}

Node *tree_minimum(RB_TREE *tree,Node *x)
{
    while(x->left != tree->nil)
    {
        x = x->left;
    }
    return x;
}


void rb_delete(RB_TREE *tree, int info)
{
    Node *y = rb_search(tree,info);
    if(y != tree->nil)
    {
        rb_delete_node(tree,y);
        cout << "ARVORE ATUALIZADA"<< endl;
        print_tree(tree);
    }
    else
    {
        cout << "Value isn't present on the tree" << endl;
    }
}

void rb_delete_node(RB_TREE *tree, Node *z)
{
    Node *y = z;
    Node *x;
    int y_original_color = y->color;

    if(z->left == tree->nil)
    {
        x = z->right;
        rb_transplant(tree,z,z->right);
    }
    else if (z->right == tree->nil)
    {
        x = z->left;
        rb_transplant(tree,z,z->left);
    }
    else
    {
        y = tree_minimum(tree,z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->father == z)
        {
            x->father = y;
        }
        else
        {
            rb_transplant(tree,y,y->right);
            y->right = z->right;
            y->right->father = y;
        }
        rb_transplant(tree,z,y);
        y->left = z->left;
        y->left->father = y;
        y->color = z->color;
    }

    if(y_original_color == BLACK)
    {
        rb_delete_fixup(tree, x);
    }
}

void rb_delete_fixup(RB_TREE *tree, Node *x)
{
    while(x != tree->root && x->color == BLACK)
    {
        if(x == x->father->left)
        {
            Node *w = x->father->right;
            /*
             * Caso 1
             */
            if(w->color == RED)
            {
                w->color = BLACK;
                x->father->color = RED;
                left_rotate(tree,x->father);
                w = x->father->right;
            }
            /*
             * Caso 2
             */
            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->father;
            }
                /*
                 *Caso 3
                 */
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = x->father->right;

                }
                /**
                 * Caso 4
                 */
                w->color = x->father->color;
                x->father->color = BLACK;
                w->right->color = BLACK;
                left_rotate(tree, x->father);
                x = tree->root;
            }
        }
        else
        {
            Node *w = x->father->left;
            /*
             * Caso 1
             */
            if(w->color == RED)
            {
                w->color = BLACK;
                x->father->color = RED;
                right_rotate(tree,x->father);
                w = x->father->left;
            }
            /*
             * Caso 2
             */
            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->father;
            }
                /*
                 *Caso 3
                 */
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = x->father->left;

                }
                /**
                 * Caso 4
                 */
                w->color = x->father->color;
                x->father->color = BLACK;
                w->left->color = BLACK;
                right_rotate(tree, x->father);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;
}

void free_tree_nodes(RB_TREE *tree, Node* root)
{
    if(root != tree->nil)
    {
        free_tree_nodes(tree,root->left);
        free_tree_nodes(tree,root->right);
        free(root);
    }
}

void free_tree(RB_TREE *tree)
{
    free_tree_nodes(tree,tree->root);
    free(tree);
}