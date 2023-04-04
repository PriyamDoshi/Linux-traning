#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int mail =0;
pthread_mutex_t m;


void* fun ()
{
    for(int j = 0; j < 1000; j++)
    {   
        pthread_mutex_lock(&m);
        mail++;
        pthread_mutex_unlock(&m);
    }
}


int main()
{
    pthread_t t[4];

    pthread_mutex_init(&m, NULL);

    for(int i =0; i<4; i++)
    {
        pthread_create(&t[i], NULL, &fun, NULL);
        printf("creating thread number %d\n",i);
    }    

    for(int i =0; i<4; i++)
    {
        pthread_join(t[i], NULL);
        printf("joining thread number %d\n",i);
    }

    pthread_mutex_destroy(&m);

    printf("%d\n",mail);

    return 0;

}