#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a = 8;
    int *q;
    int *p = malloc(sizeof(int));
    *p = a;
    q = &a;
    printf("value of a = %d\n",a);
    printf("value of p is = %d\n", *p);
    printf("value of q is = %d\n", *q);
    return 0;

}