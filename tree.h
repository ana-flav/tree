#ifndef TREE_H
#define TREE_H  
#include <stddef.h>
#include <stdbool.h>

typedef struct no{
    int key;
    struct no *left;
    struct no *right;
    struct no *parent;
} TNo;

typedef struct{
    TNo *root;
}BinTree;

BinTree *BinTree_create();
bool Tree_insert(BinTree *, int);
bool Tree_insert_r(TNo **,TNo*, int);
void in_order(TNo*);

void pre_order(TNo*);
#endif

