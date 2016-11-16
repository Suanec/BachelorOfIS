#include<iostream>
using namespace std;

class p
{
public:
	int value;
	p *next;
};
void main()
{
	int quit=1;
	while(quit)
	{
		cout<<"请输入斐波那契数列问题的项数："<<endl;
		int m;
		cin>>m;
		p *s,*e,*t;
		s=new p;
		e=new p;
		int one,two;
		two=one=s->value=1;
		e->value=1;
		for(int i=0;i<m;i++)
		{
			if(i%2)
			{
				two=one+two;
			}
			else
			{	
				one=one+two;
			}
			t=new p;
			if(one<two)
			{
				t->value=two;
			}
			else
			{
				t->value=one;
			}
			e->next=t;
			e=t;
		}
		t=s;
		while(t->next)
		{
			cout<<t->value<<endl;
			t=t->next;
		}
		
		free(s);

		cout<<"input number except zero to continue,zero to exit:"<<endl;
		cin>>quit;

	}
}