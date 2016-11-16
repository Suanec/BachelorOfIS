#include<iostream>
using namespace std;
template <typename T>
class PushOnFull
{
	T _value;
public:
	PushOnFull(T i)
	{
		_value=i;
	}
	T value()
	{
		return _value;
	}
	void Print()
	{
		cout<<"Stack is full:"<<value()<<"is not pushed!"<<endl;
	}
};
template <typename T>
class PopOnEmpty
{
public:
	void Print()
	{
		cout<<"Stack is empty,can not pop!"<<endl;
	}
};
template <typename T>
class Stack
{
	int top;
	T* elements;
	int maxsize;
public:
	Stack(int = 20);//
	~Stack(){delete []elements;}
	void Push(const T & data);
	T Pop();
	T GetElement(int i){return elements[i];}
	void MakeEmpty(){top=-1;}
	bool IsEmpty()const{return top==-1;}
	bool IsFull()const{return top==maxsize-1;}
	void PrintStack();
};
template <typename T>
Stack <typename T>::Stack(int maxs)
{
	maxsize=maxs;
	top=-1;
	elements=new T [maxsize];
}
template <typename T>//
void Stack <typename T>::PrintStack()
{
	for(int i=0;i<=top;i++)
		cout<<elements[i]<<" ";
	cout<<endl;
}
template <typename T>
void Stack <typename T>::Push(const T &data)
{
	if(IsFull())throw PushOnFull <typename T>(data);
	elements[++top]=data;
}
template <typename T>
T Stack <typename T>::Pop()
{
	if(IsEmpty())throw PopOnEmpty <typename T>();
	return elements[top--];
}
int main()
{
	int a[9]={1,8,7,6,5,4,3,2,9};
	int b[9]={0};int i;
	Stack<int>istack(8);//
	try
	{
		for(i=0;i<9;i++)
			istack.Push(a[i]);
		istack.PrintStack();
	}
	catch(PushOnFull<int>&eObj)
	{
		eObj.Print();
	}
	try
	{
		for(i=0;i<9;i++)
			b[i]=istack.Pop();
	}
	catch(PopOnEmpty<int>&eObj)
	{
		eObj.Print();
	}
	cout<<"Pop order is:"<<" ";
	for(i=0;i<9;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}