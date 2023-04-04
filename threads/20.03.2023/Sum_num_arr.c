#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int prime[10] = {2,3,5,7,11,13,17,19,23,29};

void* sum (void* pass)
{  
   int ind = *(int*)pass; 
   int sum = 0;
   for(int i = 0; i<5; i++){
       sum = sum + prime[ind + i];
   }
   printf("local sum = %d\n",sum);
   *(int*)pass = sum;
   return pass;
}

int main ()
{
    pthread_t th[2];
    for(int i = 0 ; i<2;i++){
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &sum, a);
    }
    int tsum;
    for(int i = 0; i<2; i++){
        int *r;
        pthread_join(th[i],(void**)&r);
        tsum = tsum + *r;
        free(r);
    }

    printf("toter sum = %d\n", tsum);
    
    return 0;
}
