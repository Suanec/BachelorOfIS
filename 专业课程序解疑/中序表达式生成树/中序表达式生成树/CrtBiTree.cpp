#include"CrtBiTree.h"
#include"Add.h"
class NStack
{
	node * * elements ;
	int top;
	int NUM;
public:
	NStack():top(-1),NUM(10){elements=new node*[20];}
	NStack(int n):top(-1),NUM(10)
	{
		elements=new node*[n];
	}
	~NStack(){delete []elements;}
	void Push(node * data)
	{
		elements[++top]=data;
	}
	node* Pop()
	{
		return elements[top--];
	}
	node* GetTop(){return elements[top];}
};
node * CrtBiTree(char a[],int n)
{
	char ch=NULL;
	node * p=NULL;
	NStack  S;
	for(int i=0;i<n;i++)
	{
		if(datajudge(a[i]))
		{
			p=new node;
			p->data=a[i];
			p->lchild=p->rchild=NULL;
			S.Push(p);
		}
		else
		{
			p=new node;
			p->data=a[i];
			p->rchild=S.Pop();
			p->lchild=S.Pop();
			S.Push(p);
		}
	}
	p=S.Pop();
	return p;
}
