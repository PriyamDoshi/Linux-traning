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
    fuel+= 100;
    printf("feeling fuel... \n %d \n", fuel);
    pthread_mutex_unlock(&m1);
    pthread_cond_signal(&confuel);
    sleep(1);
    }
}

void * car(void * arg)
{
    pthread_mutex_lock(&m1);
    while(fuel <40){
    printf("NO fuel...\n");
    pthread_cond_wait(&confuel, &m1);
    // equ to :-
    //1. pthread_mutex_unlock(&m1);
    //2. wait on signal on confuel
    //3. pthread_mutex_unlock(&m1);
    }
    fuel-=80;
    printf("got fuel .. %d\n",fuel);
    pthread_mutex_unlock(&m1);
}

int main()
{
    pthread_t th[5];

    pthread_mutex_init(&m1, NULL);
    pthread_cond_init(&confuel, NULL);
    
    for(int i = 0; i< 5;i++){
        if(i == 4){
            pthread_create(&th[i], NULL , &fuelff, NULL);
        }else{
            pthread_create(&th[i], NULL, &car, NULL);
        
    }
    }

    for(int i = 0 ; i<5; i++){

    pthread_join(th[i], NULL);
  
    }
    
    pthread_mutex_destroy(&m1);
    pthread_cond_destroy(&confuel);
   
    return 0;
}