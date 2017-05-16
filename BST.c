#include <stdlib.h>
#include <stdio.h>

struct binary_tree {
  int data;
  struct binary_tree* left;
  struct binary_tree* right;

};
typedef struct binary_tree node;

node *insert_node(node* root, int value){

    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if(root == NULL){
      return new_node;
    }
    node* ptr = root;
    node* prev = root;
    int way = 0 ;
    //node* next = root;
    while(ptr != NULL){
        if(value < ptr->data){
          prev = ptr;
          ptr = ptr->left;
          way = 1;
        }
        else{
          prev = ptr ;
          ptr = ptr -> right ;
          way = 0 ;
        }
    }
    if(way == 1){
      prev->left = new_node ;
    }
    else{
      prev->right = new_node ;
    }
    return root ;
}

void print_inorder(node* ptr)
{
  if(ptr != NULL)
  {
    print_inorder(ptr->left);
    printf("%d ", ptr->data);
    print_inorder(ptr->right);
  }
}

void print_preorder(node* ptr)
{
  if(ptr != NULL)
  {
    printf("%d ", ptr->data);
    print_preorder(ptr->left);
    print_preorder(ptr->right);
  }
}
void print_postorder(node* ptr)
{
  if(ptr != NULL)
  {
    print_postorder(ptr->left);
    print_postorder(ptr->right);
    printf("%d ", ptr->data);
  }
}

int main(){

  int op ;
  int invalue;
  node* root = NULL;

  while(1){

    puts("1 insert a new node");
    puts("2 inorder print");
    puts("3 preorder print");
    puts("4 postorder print");
    puts("0 exit");


    scanf("%d" , &op);
    switch(op){
      case 1:
        scanf("%d", &invalue);
        root= insert_node(root, invalue);
        break;
      case 2:
        //printf( "Address of root: %p\n", ( void * )root );
        print_inorder(root);
        puts("");
        break;
      case 3:
        print_preorder(root);
        puts("");
        break;
      case 4:
        print_postorder(root);
        puts("");
        break;
      case 0 :
        return 0 ;
        break;
    }

  }

  return 0 ;
}
