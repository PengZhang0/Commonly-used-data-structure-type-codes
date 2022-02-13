#include <stdio.h>
#include <stdlib.h>

#include "table.h"

int main(int argc, char *argv[])
{
   struct table *t = NULL;
   int i;
   
   t = table_init();
   
   table_put(t, 1, 100);
   table_put(t, 2, 100);
   table_put(t, 3, 100);
   table_put(t, 4, 100);
   
   for (i = 1; i <= table_count(t); i++) {
       printf("the element is <%d, %d>\n", 
          table_get(t, i).key, 
          table_get(t, i).value
       ); 
   }
   printf("\n");
   
   table_put(t, 4, 800);
   table_put(t, 3, 300);
   table_remove(t, 1);
   
   for (i = 1; i <= table_count(t)+1; i++) {
       printf("the element is <%d, %d>\n", 
          table_get(t, i).key, 
          table_get(t, i).value
       ); 
   }
   printf("\n");
   
   
   table_clear(t);
   
   for (i = 0; i < table_count(t); i++) {
       printf("the element is <%d, %d>\n", 
          table_get(t, i).key, 
          table_get(t, i).value
       ); 
   }
   printf("\n");
   
   table_free(t);
  
   system("PAUSE");	
   return 0;
}
