#include <stdio.h>
#include <stdlib.h>

#include "list.h" 

void list_union(struct list *lista, struct list *listb);

int main(int argc, char *argv[])
{
    struct list *lista = NULL;
    struct list *listb = NULL;
    int i;
    int elem;
    
    lista = list_init();
    listb = list_init();
    
    list_add(lista, 0, 7);
    list_add(lista, 1, 4);
    list_add(lista, 2, 1);
    list_add(lista, 3, 6);
    list_add(lista, 4, 3);  /*  7, 4, 1, 6, 3*/
    for (i = 0; i < list_count(lista); i++) {
        printf("%d ", list_get(lista, i));    
    }
    printf("\n");
    
    list_add(listb, 0, 8);
    list_add(listb, 1, 4);
    list_add(listb, 2, 1);
    list_add(listb, 3, 12);
    list_add(listb, 4, 3);
    for (i = 0; i < list_count(listb); i++) {
        printf("%d ", list_get(listb, i));    
    }
    printf("\n");
    
    list_union(lista, listb);

    
    /* ´òÓ¡ */ 
    for (i = 0; i < list_count(lista); i++) {
        printf("%d ", list_get(lista, i));    
    }
    printf("\n");
    
    list_free(lista);
    list_free(listb);
  
    system("PAUSE");	
    return 0;
}

void list_union(struct list *lista, struct list *listb)
{
     int i;
     int elem;
     
     for (i = 0; i < list_count(listb); i++) {
        elem = list_get(listb, i);
        if (list_lookup(lista, elem) == 0) {
            list_add(lista, list_count(lista), elem);                       
        }
    }
    
    return;
}

