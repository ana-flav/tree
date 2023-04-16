#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

#include "tree.h"
TNo *TNo_createNFill(int);

BinTree *BinTree_create(){
  BinTree *nova = malloc(sizeof(BinTree));
  if(nova != NULL)
    nova->root=NULL;
  return nova;
}

TNo *TNo_createNFill(int x){
  TNo *aux = malloc(sizeof(TNo));
  if (aux != NULL)
    aux->key = x;
    aux->left=NULL;
    aux->parent=NULL;
    aux->right=NULL;
  return aux;
}

bool Tree_insert(BinTree* T, int key){
  return Tree_insert_r(&(T->root),NULL, key);
}

bool Tree_insert_r(TNo** root, TNo* p, int key){

  if ((*root)==NULL){
    (*root)=TNo_createNFill(key);
    printf("valor:\n");
    printf("%d\n", (*root)->key);
  if((*root)!=NULL){
    (*root)->parent=p;
  }
  return(*root) != NULL;
  }else{
    if(key<(*root)->key){
      return Tree_insert_r(&(*root)->left, (*root), key);
    }else{
      return Tree_insert_r(&(*root)->right, (*root), key);
    }
  }
}
void in_order(TNo* root){
    if(root != NULL){
        in_order(root->left);
        printf("%d", root->key);
        in_order(root->right);
    }
}


void pre_order(TNo* root){
    if(root != NULL){
        printf("%d", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }
}
