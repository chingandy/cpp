
#include <iostream>
//#include <conio.h>
#include<cstdlib>
#include<cstdio>
using namespace std;

class node
{
	private:
		int data;
 		node *next;
		friend class LinkedList;
};
class LinkedList
{
	public:
		LinkedList();
		void insert(int value);
		void remove(int value);
		void find(int value);
		void getlength();
		void print();
	private:
		node *getnode ();
		void freenode (node *p) ;
		void insert_node (node *ptr, int value);
		void delete_node(node *ptr);
		node *find_node(int num);
		int length ();

		node *head;
};


LinkedList::LinkedList()
{
	head = NULL;
}

node *LinkedList::getnode () /* 此函數產生一個新節點 */
{
	node *p;
	p = new node;
	if ( p == NULL)
	{
		cout << "記憶體不足" << endl;
		exit(1);
	}
	return(p);
}
void LinkedList::freenode (node *p) /* 此函數將節點還給記憶體 */
{
	delete p;
}

void LinkedList::insert_node ( node *ptr, int value)
{
	node *new_node;            /* 新節點指標變數 */
	new_node = getnode();    /* 建立新節點,取得一個可用節點 */
	new_node->data = value; /* 建立節點內容 */
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
}

void LinkedList::delete_node(node *ptr)
{
	node *previous; /* 指向前一節點 */
	if ( ptr == head ) /* 是否是串列開始 */
	/* 第一種情況: 刪除第一個節點 */
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr ) /* 找節點ptr的前節點 */
			previous = previous->next;
		if ( ptr->next == NULL ) /* 是否是串列結束 */
		/* 第二種情況: 刪除最後一個節點 */
			previous->next = NULL; /* 最後一個節點 */
		else
		/* 第三種情況: 刪除中間節點 */
			previous->next = ptr->next; /* 圖(3)之步驟(1) */
	}
	freenode(ptr); /* 此函數將節點歸還給記憶體 */
}
node *LinkedList::find_node(int num)
{
	node *ptr;
	ptr = head; /* 指向串列起始 */
	while ( ptr != NULL ) /* 走訪串列 */
	{
		if ( ptr->data == num ) /* 找尋data */
		return (ptr);
		ptr = ptr->next; /* 指向下一節點 */
	}
	return (ptr);
}
int LinkedList::length () /* 此函數計算節點之鏈結長度 */
{
	int num=0;
	node *q = head;
	while (q != NULL)
	{
		num ++;
		q = q->next;
	}
	return(num);
}

void LinkedList::insert(int value)
{
	node *ptr;

	ptr = head;
	if(head==NULL)
	{
		insert_node(NULL, value);
	}
	else
	{
		while(ptr->next != NULL)
			ptr = ptr->next;
		insert_node(ptr, value);
	}
	//cout << "資料插入成功!" <<  endl;
}

void LinkedList::remove(int value)
{
	node *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		delete_node(ptr);
		cout << "Delete ok" <<  endl;
	}
	else
	{
		cout << "無此資料!" <<  endl;
	}
}

void LinkedList::find(int value)
{
	node *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		cout << "found " <<  ptr->data << endl;
	}
	else
	{
		cout << "找不到該節點資料" << endl;
	}
}

void LinkedList::print()
{
	node *q = head;
	while (q != NULL)
	{
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}
void LinkedList::getlength(){
	cout << length();
}

int main()
{
	LinkedList list;
	int key;
	int value;

	while(1)
	{
		/*
		cout << "1: 插入" << endl;
		cout << "2: 刪除" << endl;
		cout << "3: 尋找" << endl;
		cout << "4: 離開" << endl;
		cout << "5: 長度" << endl;
		cout << "6: 列印"<<endl;
		*/
		cin>>key;
		switch(key)
		{
			case 1:
				//cout << "輸入插入資料內容: ";
				cin >> value;
				list.insert(value);
				break;
			case 2:
				//cout << "輸入刪除資料內容: ";
				cin >> value;
				list.remove(value);
				break;
			case 3:
				//cout << "輸入尋找資料內容: ";
				cin >> value;
				list.find(value);
				break;
			case 5:
				list.getlength();
				break;
			case 6:
				 list.print();
				break;
			case 4:
				//cout << "ByeBye!" << endl;
				return 0 ;
				break;
			default:
				cout << "輸入值錯誤!" << endl;
		}

	}
	return 0;
}
