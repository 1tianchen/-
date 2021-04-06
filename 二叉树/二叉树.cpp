//#include <iostream>
//using namespace std;
//int n, root, l[100], r[100];
//string s;
//void preorder(int t)
//{
//		if (t != '*' - 'a')
//		{
//			cout << char(t + 'a');
//			preorder(l[t]);
//			preorder(r[t]);
//		}
//}	 
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s;
//		if (!i)//树根
//			root = s[0] - 'a';
//
//		l[s[0] - 'a'] = s[1] - 'a';
//		r[s[0] - 'a'] = s[2] - 'a';
//	}
//	preorder(root);
//	return 0;
//} 
//

#include <iostream>
#include <queue>
using namespace std;
typedef struct Bnode 
{
	char data;
	struct Bnode* lchild, * rchild;
}Bnode,*Btree;
void Createtree(Btree & T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new Bnode;
		T->data = ch;
		Createtree(T->lchild);
		Createtree(T->rchild);
	}
}
void preorder(Btree T)//先序遍历
{
	if (T)
	{
		cout << T->data << " ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
void inorder(Btree T)//中序遍历
{
	if (T)
	{
		inorder(T->lchild);
		cout << T->data << " ";
		inorder(T ->rchild);
	}
}
void inorder(Btree T)//后序遍历
{
	if (T)
	{
		inorder(T->lchild);
		inorder(T->rchild);
		cout << T->data << " ";
	}
}
bool Leveltraverse(Btree T)//层次遍历
{
	Btree P;
	if (!T)
		return false;
	queue<Btree>Q;
	Q.push(T);
	while (!Q.empty())
	{
		P = Q.front();
		Q.pop();
		cout << P->data << " ";
		if (P->lchild)
			Q.push(P->lchild);
		if (P->rchild)
			Q.push(P->rchild);
	}
	return true;
}
int main()
{//abcdefg
	Btree mytree;
	Createtree(mytree);
	cout << endl;
	preorder(mytree);
	cout << endl;

}
//已知中序排列和先序排列求,求出它的后序排列
#include <iostream>
using namespace std;
typedef struct node
{
	char data;
	struct node* lchild, * rchild;
}BiTNode, * BiTree;
BiTree pre_mid(char* pre, char* mid, int len)
{
	if (len == 0)
		return NULL;
	char ch = pre[0];
	int index = 0;
	while (mid[index] != ch)
	{
		index++;
	}
	BiTree T = new BiTNode;
	T->data = ch;
	T->lchild = pre_mid(pre + 1, mid, index);
	T->rchild = pre_mid(pre + index + 1, mid + index + 1, len - index - 1);
	return T;
}
void inorder(BiTree T)//后序遍历
{
	if (T)
	{
		inorder(T->lchild);
		inorder(T->rchild);
		cout << T->data;
	}
}
int main()
{
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	string pre1, mid1;
	cin >> mid1 >> pre1;
	char pre[100]{}, mid[100]{};
	for (int i = 0; i < pre1.length(); i++)
	{
		pre[i] = pre1[i];
	}
	for (int i = 0; i < mid1.length(); i++)
	{
		mid[i] = mid1[i];
	}
	int len = 0;
	BiTree mytree = pre_mid(pre, mid, pre1.length());
	inorder(mytree);
}