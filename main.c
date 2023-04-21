#include "tree.h"
#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
  char str[4096];
  gets(str);

  int i = 0;
  TNo *raiz;
  raiz = insert_tree(str, &i);

  printf("\nEM ORDEM:\n");
  in_order(raiz);
  printf("\nPRE ORDEM:\n");
  pre_order(raiz);
  printf("\n");
 
  if(check_tree(raiz))
    printf("bst");
  else
    printf("notBst"); 
  
}

  


 