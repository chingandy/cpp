#include <stdlib.h>
#include <stdio.h>

struct _node{
	int data ;
	struct _node* next;
};
typedef struct _node node;
int main(){
	node *head , *ptr;
  int i ;
	head = NULL;
	int value;
	for (i = 0 ; i < 5 ; i ++){
		scanf("%d", &value);

		if(head == NULL){
			head = (node *)malloc(sizeof(node));
			//head->data = value;
			head->next = NULL;
			//ptr = head;
		}
		else{
			head = (node *)malloc(sizeof(node));
			//head->data = value;
			head->next = ptr ;
			//ptr = head ;
		}
		head->data = value;
		ptr = head ;
	}


	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}

	//printf("%d", head->data);


	return 0 ;
}
