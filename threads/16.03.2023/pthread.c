#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int x = 5;

void* rot(){
    
    x++;
    printf("velue of c is %d",x);  
}

void* rot2(){
    
    x--;
    printf("velue of c is %d",x);  
}


int main ()
{
   pthread_t t1,t2 ;
   pthread_create(&t1, NULL, &rot, NULL);
   pthread_create(&t2, NULL, &rot2, NULL);
   pthread_join(t1, NULL);
    pthread_join(t2, NULL);
   return 0;
}