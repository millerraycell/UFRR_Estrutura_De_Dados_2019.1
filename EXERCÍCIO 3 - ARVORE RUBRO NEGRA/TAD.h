//
// Created by Miller on 03/05/2019.
//

#ifndef ARB_TAD_H
#define ARB_TAD_H

enum Color {RED, BLACK};

typedef struct node
{
    struct node *father;
    struct node *left;
    struct node *right;
    enum Color color;
    int key;
}Node;

typedef struct tree
{
    Node *root;
    Node *nil;
}RB_TREE;

RB_TREE *rbt_create();

void print_tree(RB_TREE *tree);

void infix_print_node(RB_TREE *tree, Node *root);
void infix_print_tree(RB_TREE *tree);

void prefix_print_node(RB_TREE *tree ,Node *root);
void prefix_print_tree(RB_TREE *tree);

void postfix_print_node(RB_TREE *tree,Node *root);
void postfix_print_tree(RB_TREE *tree);


void left_rotate(RB_TREE *tree, Node *x);
void right_rotate(RB_TREE *tree, Node *x);

void rb_insert(RB_TREE *tree, int z);
void rb_insert_node(RB_TREE *tree, Node *z);
Node *rb_insert_fixup(RB_TREE *tree, Node *k);

int rb_research(RB_TREE *tree, int info);
Node *rb_search(RB_TREE *tree, int info);
Node *rb_search_node(RB_TREE *tree,Node *root, int info);

void rb_transplant(RB_TREE *tree, Node *u, Node* v);
Node *tree_minimum(RB_TREE *tree,Node *x);
void rb_delete(RB_TREE *tree, int info);
void rb_delete_node(RB_TREE *tree, Node *z);
void rb_delete_fixup(RB_TREE *tree, Node *x);

void free_tree_nodes(RB_TREE *tree, Node* root);
void free_tree(RB_TREE *tree);

#endif //ARB_TAD_H
