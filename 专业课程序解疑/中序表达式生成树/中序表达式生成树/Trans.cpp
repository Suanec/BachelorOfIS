#include"Trans.h"
#include"Add.h"
class CStack
{
	char * elements ;
	int top;
	int NUM;
public:
	CStack():top(-1),NUM(10){elements=new char[20];}
	CStack(int n):top(-1),NUM(10)
	{
		elements=new char[n];
	}
	~CStack(){delete []elements;}
	void Push(const char &data)
	{
		elements[++top]=data;
	}
	char Pop()
	{
		return elements[top--];
	}
	char GetTop(){return elements[top];}
	bool IsEmpty() const {return top==-1;}
};

char * Trans(char a[],int &n)
{
	CStack S,T;
	char b[100];
	char ch,temp;
	int i=0;
	ch=a[i++];
	if(ch!='#')return NULL;
	else S.Push(ch);
	while(!S.IsEmpty())
	{
		ch=a[i++];
		if(datajudge(ch))
			T.Push(ch);
		else if(compare(S.GetTop(),ch)=='<')S.Push(ch);
		else if(compare(S.GetTop(),ch)=='>')
		{
			temp=S.Pop();
			T.Push(temp);
			i--;
		}
		else S.Pop();
	}
	for(i=0;!T.IsEmpty();i++)
		b[i]=T.Pop();
	char * result = new char[i];
	n=i;
	for(i=0;i<n;i++)result[n-i-1]=b[i];
	return result;
}
