#include <iostream>
#include<string.h>
#include<stack> 
using namespace std;

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}BinTree;

typedef struct node1
{
	BinTree *btnode;
	bool isFirst;
}BTNode;


void creatBinTree(char *s, BinTree *&root)  //������������sΪ����A(B,C(D,E))��ʽ���ַ��� 
{
	int i;
	bool isRight = false;
	stack<BinTree*> s1;          //��Ž�� 
	stack<char> s2;              //��ŷָ���
	BinTree *p, *temp;
	root->data = s[0];
	root->lchild = NULL;
	root->rchild = NULL;
	s1.push(root);
	i = 1;
	while (i<strlen(s))
	{
		if (s[i] == '(')
		{
			s2.push(s[i]);
			isRight = false;
		}
		else if (s[i] == ',')
		{
			isRight = true;
		}
		else if (s[i] == ')')
		{
			s1.pop();
			s2.pop();
		}
		else if (isalpha(s[i]))
		{
			p = (BinTree *)malloc(sizeof(BinTree));
			p->data = s[i];
			p->lchild = NULL;
			p->rchild = NULL;
			temp = s1.top();
			if (isRight == true)
			{
				temp->rchild = p;
				cout << temp->data << "���Һ�����" << s[i] << endl;
			}
			else
			{
				temp->lchild = p;
				cout << temp->data << "��������" << s[i] << endl;
			}
			if (s[i + 1] == '(')
				s1.push(p);
		}
		i++;
	}
}

void display(BinTree *root)        //��ʾ���νṹ 
{
	if (root != NULL)
	{
		cout << root->data;
		if (root->lchild != NULL)
		{
			cout << '(';
			display(root->lchild);
		}
		if (root->rchild != NULL)
		{
			cout << ',';
			display(root->rchild);
			cout << ')';
		}
	}
}





void postOrder3(BinTree *root)     //�ǵݹ�������
{
	stack<BinTree*> s;
	BinTree *cur;                      //��ǰ��� 
	BinTree *pre = NULL;                 //ǰһ�η��ʵĽ�� 
	s.push(root);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->lchild == NULL&&cur->rchild == NULL) ||
			(pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
		{
			cout << cur->data << " ";  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->rchild != NULL)
				s.push(cur->rchild);
			if (cur->lchild != NULL)
				s.push(cur->lchild);
		}
	}
}

int main(int argc, char *argv[])
{
	char s[100];
	while (scanf("%s", s) == 1)
	{
		BinTree *root = (BinTree *)malloc(sizeof(BinTree));
		creatBinTree(s, root);
		display(root);
	
		
		cout << endl;
		postOrder3(root);
	
	}
	return 0;
}