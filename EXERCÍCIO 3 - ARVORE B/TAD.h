//
// Created by miller on 30/04/19.
//

#ifndef BTREE_TAD_H
#define BTREE_TAD_H

typedef struct node
{
    int isLeaf;
    int numKeys;
    int *keys;
    int order;
    struct node **c;
}Node;

typedef struct btree
{
    Node *root;
    int order;
}BTree;

BTree *btree_create(int order);
Node *btree_create_node(int order);

Node* btree_search_node(Node *root, int info);
void btree_search(BTree *tree, int info);

void btree_split_child(Node *root, int i, Node *y);
void btree_insert_nonfull(Node *root,int k);
void btree_insert(BTree *tree, int info);

#endif //BTREE_TAD_H
