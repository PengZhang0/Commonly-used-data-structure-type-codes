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

/*��ʮ��������nת��Ϊd(2��8)������*/
void convert10toD(int n, int d) 
{  
    struct stack *s = NULL; 
    int k,i=0;
    s=stack_init(); 
    /* ������е���������ջ  */ 
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

