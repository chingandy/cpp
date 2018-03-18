#include<iostream>
#include<cstdio>
#include<cstdlib>


using namespace std;

class node
{
private:
	int data;
	node *left;
  node *right;
  friend class binary_tree;
};
//typedef struct binary_tree node;
class binary_tree{
public:
  binary_tree();
  void insert(int value);
  void inorder();
  void preorder();
  void postorder();
  void ___delete(int value);
  void find(int value);

private:
  node *insert_node(node *root, int value);
  void print_inorder(node *ptr);
  void print_preorder(node *ptr);
  void print_postorder(node *ptr);
  void release(node *ptr);
  node *search_node(node *ptr, int value);
  node *find_node(node *ptr, int value);
  node *find_parent(node *ptr, int value, int *pos);
  node *delete_node(node *root, int value);
  node *root;
  node *ptr;

};

node *binary_tree::insert_node(node *root, int value)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
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
            if(current->data > value)
                current = current->left;
            else
                current = current->right;
        }
        if(parent->data > value)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}


void binary_tree::print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("%d ", ptr->data);
        print_inorder(ptr->right);
    }
}

void binary_tree::print_preorder(node *ptr)
{
    if(ptr != NULL)
    {
        printf("%d ", ptr->data);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}

void binary_tree::print_postorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void binary_tree::release(node *ptr)
{
    if(ptr != NULL)
    {
        release(ptr->left);
        release(ptr->right);
        //printf("%d ", ptr->data);
        delete ptr;
    }
}

node *binary_tree::search_node(node *ptr, int value)
{
    node *temp;

    if(ptr != NULL)
    {
        if(ptr->data == value)
            return ptr;
        else
        {
            temp = search_node(ptr->left, value);
            if(temp != NULL)
                return temp;
            temp = search_node(ptr->right, value);
            if(temp != NULL)
                return temp;
        }
    }
    return NULL;
}

node *binary_tree::find_node(node *ptr, int value)
{
    while(ptr != NULL)
    {
        if(ptr->data == value)
            return ptr;
        else
        {
            if(ptr->data > value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    return NULL;
}


// 找某值之父節點
node *binary_tree::find_parent(node *ptr, int value, int *pos)
{
	node *parent;

	parent = ptr;	// 從ptr開始找
	*pos = 0;
	while(ptr != NULL)
	{
		if(ptr->data == value)	// 找到目標
			return parent;		// 回傳此節點之父節點
		else
		{
			parent = ptr;
			if(ptr->data > value)
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
node *binary_tree::delete_node(node *root, int value)
{
	node *parent;
	node *ptr;
	node *next;
	int pos;

	parent = find_parent(root, value, &pos);	// 從root開始,找value之父節點
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
			delete ptr;
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
			delete ptr;
		}
		else						// 情況3: 節點有左右子樹
		{
      parent = ptr;
      next = ptr->left;//找取代點next,從左邊開始找
      if(next->right != NULL) {
        while(next->right != NULL)
        { // 往左子節點之右子樹找最大值當取代點
          parent = next; //parent為next父節點
          next = next->right;
        } // 繞過next節點
          parent->right = next->left;
      }
      else {
        ptr->left = NULL;
      }
      ptr->data = next->data; // 取代!!
      delete next;
	   }
  }
	return root;	// 回傳此樹
}

//binary_tree public member

binary_tree::binary_tree(){
  root = NULL ;
}
void binary_tree::insert(int value){
  root = insert_node(root, value);
}
void binary_tree::inorder(){
  print_inorder(root);
  cout << endl;
}
void binary_tree::preorder(){
  print_preorder(root);
  cout << endl;
}
void binary_tree::postorder(){
  print_postorder(root);
  cout << endl;
}
void binary_tree::___delete(int value){
  ptr = find_node(root, value);
  if(ptr!=NULL){
    root = delete_node(root, value);
    cout << "delete "<<value << " ok" << endl;
  }
  else{
    cout << "cannot delete"<<endl;
  }
}
void binary_tree::find(int value){
  ptr = find_node(root, value);
  if(ptr!=NULL){
    cout << "found: " << ptr->data << endl;
  }
  else{
    cout << "Not found" ;
  }
}

int main()
{
	int op;
	int value;
  binary_tree b1;
	//node *root = NULL, *ptr;

	while(1){
    /*
    cout << "1 insert data"<<endl;
    cout << "2 inorder print"<<endl;
    cout << "3 preorder print"<<endl;
    cout << "4 postorder print"<<endl;
    cout << "5 delete node"<<endl;
    cout << "6 find node"<<endl;
    cout << "8 exit"<<endl;
    */
    cin >> op ;

		switch(op){
			case 1:
        cin >> value ;
				b1.insert(value);
				break;

			case 2:
				b1.inorder();
				break;

			case 3:
				b1.preorder();
				break;

			case 4:
				b1.postorder();
				break;

			case 5:
        cin >> value ;
        b1.___delete(value);
				break;
			case 6:

        cin >> value ;
				b1.find(value);
				break;

			case 8:
				return 0;
				break;


		}

	}

	return 0;
}
