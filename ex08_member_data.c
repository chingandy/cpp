#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
struct node{
  char name[40];
  int number;
  char email[40];
  struct node* next ;
  struct node* previous;

};

//typedef struct _node node ;

struct node* insert(struct node* h, struct node data){
    struct node* ptr = NULL ;
    if (h == NULL){
      h = (struct node*)malloc(sizeof(struct node));
      *h = data ;
      h->next = NULL ;
    }
    else {
      ptr = h;
      h = (struct node*)malloc(sizeof(struct node));
      *h = data;
      h->next = ptr;
      h->previous = NULL;
      ptr->previous = h ;
    }
    return h ;
}

struct node* find(struct node* h, char data[]){
    if(h == NULL){
      return NULL;
    }
    while(strcmp(h->name , data) != 0 && h->next != NULL)
      h = h-> next;
    if(strcmp(h->name , data) == 0){
      return h ;
    }
    else{
      return NULL;
    }

}

struct node* delete(struct node* h , char data[] ){
    struct node* ptr = h ;

    while(strcmp(ptr->name, data) != 0 ){
      ptr = ptr-> next;
    }
    if(ptr != h && ptr->next != NULL){          //結點在中間
      ptr->previous->next = ptr->next;
      ptr->next->previous = ptr->previous;
      //free(ptr);
    }
    else if(ptr == h){            //節點在第一個
      h = h-> next;
      if(h != NULL)
        h->previous = NULL;

      //free(ptr);
      //return h;
    }
    else{                             //節點在最後
      ptr->previous ->next= NULL;
      //free(ptr);
    }
    free(ptr);
    return h ;

}
int main(){
   struct node* head = NULL ;
   struct node* ptr;
   struct node data;
   char findname[40];
   char op ;

   while(1){
     /*
     puts("1 insert a member");
     puts("2 find a member");
     puts("3 delete a member");
     puts("4 print out all the members");
     puts("0 quit");
     */
     scanf("%c", &op);
     switch(op){
        case 'i' :
          scanf("%s", data.name);
          scanf("%s" , data.email);
          scanf("%d" , &data.number);
          head = insert(head , data);
          break;
        case 'f' :
          scanf("%s", findname);
          ptr = find(head, findname );
          if(ptr != NULL){
            printf("found\n");
            printf("%s\n", ptr->name);
            printf("%s\n", ptr->email);
            printf("%010d\n\n", ptr->number);

          }
          else{
            printf("Not found\n" );
          }
          break;
        case 'd':
          scanf("%s", findname);
          ptr = find(head, findname);
          if(ptr != NULL){
            head = delete(head, findname);
            printf("Delete ok\n");
            /*
            printf("%s\n", ptr->name);
            printf("%s\n", ptr->email);
            printf("%010d\n\n", ptr->number);
            */
          }
          else{
            printf("Not found\n" );
          }
          break;
        case 'l' :
          ptr = head;
          if(ptr == NULL){
            printf("no data\n");
            break;
          }
          while(ptr->next != NULL)
            ptr = ptr->next;
          while(ptr != NULL){
            printf("%s\n", ptr->name);
            printf("%s\n", ptr->email);
            printf("%010d\n\n", ptr->number);
            ptr = ptr->previous;
          }
          break;
        case 'q':
          return 0 ;
          break;

     }

   }



  return 0 ;
}
