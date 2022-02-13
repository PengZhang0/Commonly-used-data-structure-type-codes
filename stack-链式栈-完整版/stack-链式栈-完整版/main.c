#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void convert10toD(int n, int d);

int main(int argc, char *argv[])
{
    
    convert10toD(159, 8);
  
    system("PAUSE");	
    return 0;
}

/*将十进制整数n转换为d(2或8)进制数*/
void convert10toD(int n, int d) 
{  
    struct stack *s = NULL; 
    int k,i=0;
    s=stack_init(); 
    /* 求出所有的余数，进栈  */ 
    while (n>0) {
       k=n%d; 
       stack_push(s, k); 
       n=n/d; 
    } 
    while(!stack_isempty(s)) {
       printf("%d",stack_pop(s));
    } /* stack_print(s); */
    printf("\n");
    stack_free(s);
    return;
}

