#include <stdlib.h>
#include <stdio.h>
struct node{
       char name[40];
       char number[10];
       char email[40];
       struct node* next;

};
typedef struct node node ;

node *getnode () /* 此函數產生一個新節點 */
{
    node *p;
    p = (node *) malloc(sizeof(node));
    /* malloc 會動態地配置大小為sizeof 的記憶體*/
    /* sizeof 會傳回一個型態為node之值*/
    if ( p == NULL)
    {
    printf ("記憶體不足");
    exit(1);
    }
    return(p);
}


node *insert_node (node *head, node *ptr, node data)
{
    node *new_node; /* 新節點指標變數 */
    new_node = getnode(); /* 建立新節點,取得一個可用節點 */
    *new_node = data; /* 建立節點內容 */
    new_node->next = NULL; /* 設定指標初值 */
    if ( ptr == NULL ) /* 指標ptr是否是NULL */
    {
    /* 第一種情況: 插入第一個節點 */
       new_node->next = head; /* 新節點成為串列開始 */
       head = new_node;
    }
    else
    {
        if ( ptr->next == NULL ) /* 是否是串列結束 */
        /* 第二種情況: 插入最後一個節點 */
        ptr->next = new_node; /* 最後指向新節點 */
    else
    {
        /* 第三種情況: 插入成為中間節點 */
        new_node->next = ptr->next; /* (3) 新節點指向下一節點 (3)*/
        ptr->next = new_node; /* 節點ptr指向新節點 (4)*/
        }
    }
    return (head);
}

int main(){
    node *head, *ptr;
    node insert;
    char key;
    head = NULL;
    while(1){
         puts("i  insert new data");
         puts("l  list all data");
         puts("q  quit");
         scanf("%c", &key);
         switch(key){
              case 'i':
                    scanf("%s", insert.name);
                    scanf("%s", insert.number);
                    scanf("%s", insert.email);
                    ptr = head;
                    if(head==NULL){
                      head=insert_node(head, NULL, insert);
                    }
                    else {
                      while(ptr->next != NULL)
                        ptr = ptr->next;
                      head=insert_node(head, ptr, insert);
                    }
                    printf("Insert ok\n");
                   break;

              case 'd':
                char del[40];
                scanf("%s" , del);

                break;

              case 'f':



                break;
              case 'l':
                   ptr = head ;
                   while(ptr != NULL){
                        printf("%s\n", ptr->name);
                        printf("%s\n" , ptr->number);
                        printf("%s\n" , ptr->email);
                        ptr = ptr->next;
                    }
                   break;

              case 'q':
                   return 0;
                   break;

         }

        system("pause");
        system("cls");
    }
    return 0 ;
}
