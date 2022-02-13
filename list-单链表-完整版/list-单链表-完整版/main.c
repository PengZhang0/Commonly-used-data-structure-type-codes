#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char *argv[])
{
    struct list *lista = NULL;
    struct list *listb = NULL;
    int i;
    
    lista = list_init();
    listb = list_init();
    
    //7,4,1,6,3
    list_add(lista, 0, 7);
    list_add(lista, 1, 4);
    list_add(lista, 2, 1);
    list_add(lista, 3, 6);
    list_add(lista, 4, 3);
    for (i = 0; i < list_count(lista); i++) {
       printf("%d ", list_get(lista, i));    
    }
    printf("\n");
    
    // 8,4,1,12,3
    list_add(listb, 0, 8);
    list_add(listb, 1, 4);
    list_add(listb, 2, 1);
    list_add(listb, 3, 12);
    list_add(listb, 4, 3);
    for (i = 0; i < list_count(listb); i++) {
       printf("%d ", list_get(listb, i));    
    }
    printf("\n");
    
    for (i = 0; i < list_count(listb); i++) {
        int elem = list_get(listb, i);
        if (list_lookup(lista, elem) == 0) {
            list_add(lista, list_count(lista), elem);                       
        }
    }
    
    for (i = 0; i < list_count(lista); i++) {
       printf("%d ", list_get(lista, i));    
    }
    printf("\n");
    
    list_free(lista);
    list_free(listb);  
  
  system("PAUSE");	
  return 0;
}
