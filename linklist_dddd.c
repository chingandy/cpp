#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
struct node{
  int data;
  struct node* next ;

};

//typedef struct _node node ;

struct node* insert(struct node* h, int x){
    struct node* ptr = NULL ;
    if (h == NULL){
      h = (struct node*)malloc(sizeof(struct node));
      h->data = x ;
      h->next = NULL ;
    }
    else {
      ptr = h;
      h = (struct node*)malloc(sizeof(struct node));
      h->data = x;
      h->next = ptr;
    }
    return h ;
}

bool find(struct node* h, int x){
    if(h == NULL){
      return false;
    }
    while(h->data != x && h->next != NULL)
      h = h-> next;
    if(h->data == x ){
      return true ;
    }
    else{
      return false;
    }

}

struct node* delete(struct node* h , int x ){
    struct node* ptr = h ;
    struct node* prev;
    while(ptr->data != x ){
      prev = ptr;
      ptr = ptr-> next;
    }
    if(ptr != h && ptr->next != NULL){          //結點在中間
      prev->next = ptr->next;
      //free(ptr);
    }
    else if(ptr == h){            //節點在第一個
      h = h-> next;
      //free(ptr);
      //return h;
    }
    else{                             //節點在最後
      prev->next = NULL;
      //free(ptr);
    }
    free(ptr);
    return h ;

}
int main(){
   struct node* head = NULL ;
   struct node* ptr;
   int value;
   int op ;

   while(1){
     puts("1 insert a number");
     puts("2 find a number");
     puts("3 delete a number");
     puts("4 print out all the numbers");
     puts("0 quit");

     scanf("%d", &op);
     switch(op){

        case 1 :
          scanf("%d", &value);
          head = insert(head , value);
          break;

        case 2 :
          scanf("%d", &value);
          if(find(head, value)){
            printf("found %d\n" , value);
          }
          else{
            printf("Not found\n" );
          }
          break;

        case 3 :
          scanf("%d", &value);

          if(find(head, value)){
            head = delete(head, value);
            printf("Deleted %d!\n" , value);
          }
          else{
            printf("Not found\n" );
          }
          break;

        case 4 :
            ptr = head;
          while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
          }
          printf("\n");
          break;

        case 0:
          return 0 ;
          break;

     }
     system("pause");
     system("cls");
   }



  return 0 ;
}
