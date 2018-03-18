#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct binary_tree
{
	char name[30];
  char phone[10];
	struct binary_tree *left;
	struct binary_tree *right;
};
typedef struct binary_tree node;


node *insert_node(node *root, node data)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    *new_node = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL)
    {
        return new_node;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            parent = current;
            if(strcmp(current->name , data.name) > 0)//current->name > value
                current = current->left;
            else
                current = current->right;
        }
        if(strcmp(parent->name, data.name) > 0)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}


void print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %s\n\n", ptr->phone);
        print_inorder(ptr->right);
    }
}

void print_preorder(node *ptr)
{
    if(ptr != NULL)
    {
        printf("Name: %s\n", ptr->name);
        printf("Phone: %s\n\n", ptr->phone);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}

void print_postorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %s\n\n", ptr->phone);
    }
}

void release(node *ptr)
{
    if(ptr != NULL)
    {
        release(ptr->left);
        release(ptr->right);
        //printf("%d ", ptr->data);
        free(ptr);
    }
}

node *search_node(node *ptr, node data)
{
    node *temp;

    if(ptr != NULL)
    {
        if(strcmp(ptr->name, data.name)== 0 )
            return ptr;
        else
        {
            temp = search_node(ptr->left, data);
            if(temp != NULL)
                return temp;
            temp = search_node(ptr->right, data);
            if(temp != NULL)
                return temp;
        }
    }
    return NULL;
}

node *find_node(node *ptr, node data)
{
    while(ptr != NULL)
    {
        if(strcmp(ptr->name, data.name) == 0)
            return ptr;
        else
        {
            if(strcmp(ptr->name, data.name) > 0)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    return NULL;
}


// 找某值之父節點
node *find_parent(node *ptr,node data, int *pos)
{
	node *parent;

	parent = ptr;	// 從ptr開始找
	*pos = 0;
	while(ptr != NULL)
	{
		if(strcmp(ptr->name,data.name) == 0)	// 找到目標
			return parent;		// 回傳此節點之父節點
		else
		{
			parent = ptr;
			if(strcmp(ptr->name, data.name) > 0)
			{
				*pos = -1;			// ptr在parent左子樹
				ptr = ptr->left;	// 往左找
			}
			else
			{
				*pos = 1;			// ptr在parent右子樹
				ptr = ptr->right;	// 往右找
			}
		}
	}
	return NULL;	// 找不到
}

// 刪除節點
node *delete_node(node *root, node data)
{
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = find_parent(root, data, &pos);	// 從root開始,找value之父節點
	if(parent != NULL)	// 有找到, 準備刪除
	{
  		switch(pos)	// 判斷目前節點再父節點左邊或右邊
  		{
  			case -1:
  				ptr = parent->left;
  				break;
  			case 1:
  				ptr = parent->right;
  				break;
  			case 0:
  				ptr = parent;
  				break;
  		}
		if(ptr->left == NULL)		// 情況1: 節點沒有左子樹 如果要刪的是根節點
		{
			if(parent == ptr)	// 如果要刪的是根節點
				root = root->right;
			else				// 其他
			{
				if( pos == 1 )
				{
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的右節點
					parent->right = ptr->right;
				}
				else
				{
					//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的右節點
					parent->left = ptr->right;
				}
			}
			free(ptr);
		}
		else if(ptr->right == NULL)	// 情況2: 節點沒有右子樹
		{
			if(parent != ptr)
			{
				if( pos == 1 )
				{
					//要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的左節點
					parent->right = ptr->left;
				}
				else
				{
					//要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的左節點
					parent->left = ptr->left;
				}
			}
			else
				root = root->left;
			free(ptr);
		}
		else						// 情況3: 節點有左右子樹
		{
      parent = ptr;
      next = ptr->left;//找取代點next,從左邊開始找
      while(next->right != NULL)
      { // 往左子節點之右子樹找最大值當取代點
        parent = next; //parent為next父節點
        next = next->right;
      } // 繞過next節點
      *ptr = *next;
      parent->right = next->left;
      free(next);
    }


  }
	return root;	// 回傳此樹
}


int main()
{
	char op;
	node data;
	node *root = NULL, *ptr;

	while(1){
    /*
		puts("i 加入節點");
		puts("l 順序列印");
		puts("m 前序列印");
		puts("n 後序列印");
		puts("f 查詢");
		puts("d 刪除");
		puts("q 離開");
    */
		scanf(" %c", &op);
		switch(op){
			case 'i':
				scanf("%s", data.name);
        scanf("%s", data.phone);
				root = insert_node(root, data);
				break;
			case 'l':
				print_inorder(root);
        //puts("");
				break;
			case 'm':
				print_preorder(root);
				//puts("");
				break;
			case 'n':
				print_postorder(root);
				//puts("");
				break;
			case 'f':
				scanf("%s", data.name);
				ptr = find_node(root, data);
				if(ptr!=NULL){
					printf("found:\n");
          printf("Name: %s\n", ptr->name);
          printf("Phone: %s\n\n", ptr->phone);
				}
				else{
					puts("not found");
				}
				break;
			case 'd':
				scanf("%s", data.name);
				ptr = find_node(root, data);
				if(ptr!=NULL){
					root = delete_node(root, data);
          printf("delete %s ok\n\n", data.name );
				}
				else{
					puts("cannot delete");
				}

				break;

			case 'q':
				return 0;
				break;


		}
		//system("pause");
		//system("cls");
	}

	return 0;
}
