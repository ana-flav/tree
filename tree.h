#ifndef TREE_H
#define TREE_H  
#include <stddef.h>
#include <stdbool.h>

typedef struct no{
    int key;
    struct no *left;
    struct no *right;
} TNo;

typedef struct{
    TNo *root;
}BinTree;

BinTree *BinTree_create();
bool Tree_insert(BinTree *, int);
bool Tree_insert_r(TNo **,TNo*, int);
TNo* insert_tree(char*, int *);
void in_order(TNo*);
int check_tree(TNo*);

void pre_order(TNo*);
#endif

