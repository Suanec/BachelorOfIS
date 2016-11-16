#include<iostream>
using namespace std;
#include"Trans.h"
#include"CrtBiTree.h"
void main()
{
	char a[]={'#','d','/','(','a','+','b',')','*','c','+','(','e','+','f',')','*','(','g','-','h',')','#'};//d/(a+b)*c+(e+f)*(g-h)
	int n=0;
	char *b;
	b=Trans(a,n);
	node * T;
	node * T2;
	char c[]={'d','a','b','+','c','*','/','e','f','+','g','h','-','*','+'};
	T=CrtBiTree(c,n);
	T2=CrtBiTree(b,n);
	system("pause");
}