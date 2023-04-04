#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int prime[10] = {2, 3,5,7,11,13,17,19,23,29};

void *rut(void *ag)
{
   int index = *(int*)ag;
   printf("%d  ", prime[index]);
   free(ag);
}

int main()
{
    pthread_t th[2];

    for(int i = 0; i<2; i++)
    {
        int*a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &rut, a);
    }
    for(int i = 0; i<10; i++)
    {
        pthread_join(th[i],NULL);
    }

    return 0;
}
