#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t mutex;

void * trylock()
{
   if(pthread_mutex_trylock(&mutex)==0){
   printf("get in lock\n");
   sleep(2);
   pthread_mutex_unlock(&mutex);
   }else{
   printf("did not get lock\n");
   }
}

int main()
{
    pthread_t th[4];

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i<4; i++){
        pthread_create(&th[i],NULL, &trylock, NULL);
    }
    for(int i = 0; i<4; i++){
        pthread_join(th[i],NULL);
    }

    pthread_mutex_destroy(&mutex);


    return 0;
}
