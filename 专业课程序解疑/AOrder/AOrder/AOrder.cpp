#include<iostream>
using namespace std;
typedef struct Node{
	char data;
	Node * lchild,*rchild;
}Node;
char Rec[]={'-','+','a','#','#','*','b','#','#','-','c','#','#','d','#','#','/','e','#','#','f','#','#'};
int count=0;
class stack
{
	int top;
	Node* Stack[100];
public:
	stack()
	{
		top=-1;
	}
	void InitStack()
	{
		top=-1;
	}
	bool IsStack()
	{
		if(top==-1)return 1;
		else return 0;
	}
	void Push(Node *p)
	{
		Stack[++top]=p;
	}
	Node * Pop()
	{
		Node*temp=Stack[top--];
		Stack[top+1]=NULL;
		return temp;
	}
	Node* Gettop()
	{
		return Stack[top];
	}
};
void f(Node*&T)
{
	char c;
	c=Rec[count++];
	if(c=='#')T=NULL;
	else{
		T=(Node*)malloc(sizeof( Node));
		T->data=c;
		f(T->lchild);
		f(T->rchild);
	}
}
void AOrder(Node *T)
{
	if(T->lchild)AOrder(T->lchild);
	if(T->rchild)AOrder(T->rchild);
	cout<<T->data;
}
void POrder(Node *T)
{
	cout<<T->data;
	if(T->lchild)POrder(T->lchild);
	if(T->rchild)POrder(T->rchild);
}
void InOrder(Node *T)
{
	if(T->lchild)InOrder(T->lchild);
	cout<<T->data;
	if(T->rchild)InOrder(T->rchild);
}
void AAOrder(Node *T)
{
	Node *p,*q;
	p=T;
	stack s;
	while(p||!s.IsStack())
	{
		if(p)
		{
			s.Push(p);
			p=p->lchild;
		}
		else
		{
			q=s.Gettop();
			while(p==q->rchild)
			{
				p=s.Pop();
				cout<<p->data;
				if(!s.IsStack())
				{
					q=s.Gettop();
				}
				else
				{
					p=NULL;
					break;
				}//else
			}//while
			p=q->rchild;
		}//else
	}//while
}//AAOrder

void main ()
{
	Node * T=new Node;
	f(T);
	cout<<endl<<"adsfasdfasdf"<<endl;
	POrder(T);
	cout<<endl<<"adsfasdfasdf"<<endl;
	InOrder(T);
	cout<<endl<<"adsfasdfasdf"<<endl;
	AOrder(T);
	cout<<endl<<"adsfasdfasdf"<<endl;
	AAOrder(T);
	system("pause");
}