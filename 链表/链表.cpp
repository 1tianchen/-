#include <iostream>
using namespace std;
struct  student
{

};
struct node
{
	int val;
	struct student stu;
	struct node* pre;//前面
	struct node* next;//后面
	
};
struct node* head=NULL;
struct node* tail=NULL;
void init_with_headnode()//带头结点 双向链表
{
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	head->pre = NULL;
	head->val = 0;
	tail = head;
	//if是循环链表
	//if(head) head->pre=tail;
	//if(tail) tail->next=head;
}
void init_without_headnode()//不带头结点
{
	head = NULL;
	tail = head;
}
void insert(struct node*pos,struct node *temp)//只有数据 要分配
{//前面pos  代插入是temp 
	if(pos)
		temp->next = pos->next;
	if (pos)
		pos->next = temp;
	if (temp->next)
		temp->next->pre = temp;
	//双向链表
		temp->pre = pos;
	if (pos == NULL)
		head = temp;
	if (tail == pos)
		tail = temp;
	//if是循环链表
	//head->pre=tail;
	//tail->next=head;
}
void head_insert_without_headnode(struct node* head, struct node* temp)
{
	temp -> next=head;
	//双向链表
	if(head)//NULL 
		head->pre = temp;
	else
		tail = temp;
	//tmep 要初始化
	head = temp;

}
void head_insert_with_headnode(struct node* temp)
{
	insert(head, temp);
	if (tail == head)
		tail = temp;
	//if是循环链表
	//if(head) head->pre=tail;
	//if(tail) tail->next=head;

}
void tail_insert(struct node*tail, struct node* temp)
{
	if (tail)
		tail->next = temp;
	else
		head = temp;
	//双向链表
	temp->pre = tail;

	tail = temp;
	//if是循环链表
	//if(head) head->pre=tail;
	//if(tail) tail->next=head;
}
void delete_s(struct node*pre,struct node*pos)//前面的节点 单向链表
{
	if (pre)
		pre->next = pos->next;
	if (head ==pos)
		head = pos->next;
	if (tail == pos)
		tail = pre;
	//不带头结点 pre=null
	//if是循环链表
	//if(head) head->pre=tail;
	//if(tail) tail->next=head;
}
void delete_d(struct node*pos)//双向链表
{
	if (pos->pre)
		pos->pre->next = pos->next;
	if(pos->next)
		pos->next->pre = pos->pre;
	if (head == pos)
		head = pos->next;
	if (tail == pos)
		tail = pos->pre;
	free(pos);
	 //if是循环链表
	 //if(head) head->pre=tail;
	 //if(tail) tail->next=head;
}
void destory()
{
	while (head!=NULL)
	{
		struct node* temp = head;
		head = head->next;
		free(temp);
	}
	head = tail = NULL;
}
int main()
{
	
	init_with_headnode();
	for (int i = 0; i < 5; i++)
	{
		struct node* temp =(struct node*)calloc(1, sizeof(struct node));
		temp->val = i+1;
		temp->next = temp->pre = NULL;
		head_insert_with_headnode(temp);
	}
	struct node* p = head->next;
	for (int i = 0; i < 2; i++)
	{
		p = p->next;
	}
	delete_d(p);
	for (struct node* index = head->next; index != NULL; index = index->next)
	{
		cout << index->val;
	}
	cout << endl;
	destory();
}	  