#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *start;

struct node newll(){
   printf("in function\n");
   struct node *new = (struct node*) malloc(sizeof(struct node));
   struct node *ptr;
   new->data = 5;
   new->next = NULL;
   ptr = new;
   start = new;
   
   for(int i = 0 ; i < 2 ; i++){
      struct node *new = (struct node*) malloc(sizeof(struct node));
      ptr->next = new;
      printf("inter data:\n");
      int n;
      scanf("%d", &n);
      new->data = n;
      new->next = NULL;
      ptr = new;
   }

}

void traversal(){
   printf("we are in function\n");
   struct node *ptr;
   ptr=start;
   while(ptr->next!=NULL)
   {
      printf("%d ",ptr->data);
      ptr=ptr->next;
   }
   printf("%d ",ptr->data);
}

int main (){
   printf("creating new linklist \n");
   newll();
   traversal();

}