#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void* func()
{
   int value = rand()%6 +1;
   printf("VELUE %d\n",value);
   int *a = malloc(sizeof(int));
   *a = value;
   printf("threar result %p\n", a);
   return (void *)a;
}

int main ()
{
    pthread_t t;
    srand(time(NULL));
  
    int *rs;
    
    pthread_create(&t, NULL, &func, NULL);
    pthread_join(t,(void**)&rs);

    printf("result is %d\n", *rs);
    printf("main result %p\n", rs);

    free(rs);

    return 0;
}