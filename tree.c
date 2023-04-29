#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"
#include <ctype.h>

void in_order(TNo* root){
    if(root != NULL){
        in_order(root->left);
        printf(" %d ", root->key);
        in_order(root->right);
    }
}
int check_tree(TNo *root){
  if(root!=NULL){
    if(root->left != NULL && root->left->key>root->key){
      return 0;
    }
    if(root->right != NULL && root->right->key<root->key){
      return 0;
    }
    if(!check_tree(root->left) || !check_tree(root->right)){
      return 0;
    }else{
      return 1;
    }
  }else{
    return 1;
  }

}
TNo* insert_tree(char *string, int *i){
  if(string[*i]=='(' && string[*i+1]==')'){
      *i+=2;
      return NULL;
  }
  *i += 1;
  int aux = *i;

  while(isdigit(string[*i]))
  {
   *i += 1;
  }

  if(aux < *i){
    char* ponteiro;
    int tam = *i-aux;
    char string_value[tam+1];
    int j = 0, value;
    for (int x = aux; x<=*i; x++){
      string_value[j]=string[x];
      j++;
    }
    string_value[tam+1] = '\0';
    value = atoi(string_value);

    TNo* no = malloc(sizeof(TNo));
    no->key = value;
    no->left= insert_tree(string, i);
    no->right = insert_tree(string, i);
    return no;
  }
  return NULL;
}
void pre_order(TNo* root){
    if(root != NULL){
        printf(" %d ", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }
}
