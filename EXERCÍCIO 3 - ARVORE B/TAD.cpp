//
// Created by miller on 30/04/19.
//
#include <iostream>
#include "TAD.h"


using namespace std;

Node *btree_create_node(int order)
{
    Node *root = (Node *) malloc(sizeof(Node));
    root->order = order;
    root->numKeys = 0;
    root->isLeaf = 1;
    root->c = (Node **) malloc((order-1)*sizeof(Node));
    root->keys = (int *) malloc((order)*sizeof(int));
    return root;
}

BTree *btree_create(int order)
{
    BTree *tree = (BTree *)malloc(sizeof(BTree));
    Node *x = btree_create_node(order);
    tree->order = order;
    tree->root = x;

    return tree;
}

Node* btree_search_node(Node *root, int info)
{
    int i = 1;
    while(i < root->numKeys && info > root->keys[i])
    {
        i++;
    }
    if(root->keys[i] == info)
    {
        return root;
    }
    if(root->isLeaf)
    {
        return NULL;
    }

    return btree_search_node(root->c[i],info);
}

void btree_search(BTree *tree, int info)
{
    Node *aux = btree_search_node(tree->root,info);
    if(aux != NULL)
    {
        cout << "The number is on the tree" <<endl;
    }
    else
    {
        cout << "The number isn't on the tree" << endl;
    }
}

void btree_split_child(Node *root, int i,Node *y)
{
    Node *z = btree_create_node(root->order);
    int j;
    z->isLeaf = y->isLeaf;
    z->numKeys = root->order - 1;
    for(j=1; j < root->order-1 ;j++)
    {
        z->keys[j] = y->keys[j+root->order];
    }
    if(!y->isLeaf)
    {
        for(j=1;j<root->order;j++)
        {
            z->c[j] = y->c[j+root->order];
        }
    }
    y->numKeys = root->order -1;
    for(j = root->order+1; j>i+1 ; j--)
    {
        root->c[j+1] = root->c[j];
    }
    root->c[i+1] = z;
    for(j = root->numKeys ; j > i ; j--)
    {
        root->keys[j+1] = root->keys[j];
    }
    root->keys[i] = y->keys[root->order];
    root->numKeys +=1;
}

void btree_insert_nonfull(Node *root,int k)
{
    int i = root->numKeys;
    if(root->isLeaf)
    {
        while(i>=1 && k < root->keys[i])
        {
            root->keys[i+1] = root->keys[i];
            i--;
        }
        root->keys[i+1] = k;
        root->numKeys++;
    }
    else
    {
        while(i>=1 && k < root->keys[i])
        {
            i--;
        }
        i++;
        if(root->c[i]->numKeys == 2*root->order-1)
        {
            btree_split_child(root,i,root->c[i]);
            if(k > root->keys[i])
            {
                i++;
            }
        }
        btree_insert_nonfull(root->c[i],k);
    }
}

void btree_insert(BTree *tree, int info)
{
    Node* r = tree->root;
    if(r->numKeys == 2*tree->root->order-1)
    {
        Node *s = btree_create_node(r->order);
        tree->root = s;
        s->isLeaf = 0;
        s->numKeys = 0;
        s->c[1] = r;
        btree_split_child(s,1,r);
        btree_insert_nonfull(s,info);
    }
    else
    {
        btree_insert_nonfull(r,info);
    }
}