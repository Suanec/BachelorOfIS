#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node * lchild,*rchild;
	//~Node(){cout<<"destructing"<<endl;}
};
Node* CreBiTr(int mid[],int beh[],int low1,int high1,int low2,int high2)
{
	if((high2-low2)!=(high1-low1))return NULL;
	Node* p=new Node;
	if(!(high2-low2))
	{
	//	Node* p=new Node;
		p->data=beh[high2];p->lchild=p->rchild=NULL;
	}//if  µÝ¹é³ö¿Ú
	else
	{
	//	Node* p=new Node;
		p->data=beh[high2];
		int i=high1;
		while(p->data!=mid[i])--i;
		p->lchild=CreBiTr(mid,beh,low1,i-1,low2,high2-high1+i-1);
		p->rchild=CreBiTr(mid,beh,i+1,high1,high2-high1+i,high2-1);
	}//else
	return p;
}//CreBiTr();

void AOrder(Node *T)
{
	if(T->lchild)AOrder(T->lchild);
	if(T->rchild)AOrder(T->rchild);
	cout<<" "<<T->data;
}
int mid[]={1,2,3,4,5,6,7,8,9,10,11};
int beh[]={1,3,5,7,6,4,2,9,11,10,8};
int main()
{
	Node * Th;
	Th=CreBiTr(mid,beh,0,10,0,10);
	AOrder(Th);	
	system("pause");return 0;
}
