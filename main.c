#include "tree.h"
#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>



int main(void) {
  char str[4096]= "(12(5()(6))(10()(1)))";
  BinTree *T = BinTree_create();
  int tam = strlen(str);
  int value_number;

  for(int i=0; i<tam; i++){
      value_number = 0;

      if(str[i] != ')' && str[i] != '(' && str[i] != '\0'){

        if(isdigit(str[i])){
          if(isdigit(str[i+1])){
            char value[3];
            strncpy(value, &str[i], 2);
            value[3] = '\0';
            i=i+2;
            value_number=atoi(value);

            printf("dois digitos:\n");
            printf("%d", value_number);

            Tree_insert(T, value_number);
          }else{
            value_number = str[i] - '0';
            printf("um digitos:\n");
            printf("%d\n", value_number);
            Tree_insert(T, value_number);
          }
        }
      }
}
  printf("\nEM ORDEM:\n");
  in_order(T->root);
  printf("\nPRE ORDEM:\n");

  pre_order(T->root);
  
}  

 