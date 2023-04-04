#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int fuel = 0;
pthread_mutex_t m1;
pthread_cond_t confuel;

void * fuelff(void * arg)
{   
    for (int i = 0; i <5; i++){
    pthread_mutex_lock(&m1);
    fuel+= 15;
    printf("feeling fuel... \n %d \n", fuel);
    pthread_mutex_unlock(&m1);
    pthread_cond_signal(&confuel);
    sleep(1);
    }
}

void * car(void * arg)
{
    pthread_mutex_lock(&m1);
    while(fuel <75){
    printf("NO fuel...\n");
    pthread_cond_wait(&confuel, &m1);
    // equ to :-
    //1. pthread_mutex_unlock(&m1);
    //2. wait on signal on confuel
    //3. pthread_mutex_unlock(&m1);
    }
    fuel+=100;
    printf("got fuel .. %d\n",fuel);
    pthread_mutex_unlock(&m1);
}

int main()
{
    pthread_t th1, th2;

    pthread_mutex_init(&m1, NULL);
    pthread_cond_init(&confuel, NULL);
    
    for(int i = 0; i< 2;i++){
        if(i == 1){
            pthread_create(&th1, NULL , &fuelff, NULL);
        }else{
            pthread_create(&th2, NULL, &car, NULL);
        }
    }

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    pthread_mutex_destroy(&m1);
    pthread_cond_destroy(&confuel);
   
    return 0;
}