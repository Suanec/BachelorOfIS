#include <iostream>
using namespace std;
int main()
{
	int height;
	char ** pPointer;
	char *  pWork;
	int  i, j, k;
	int  totalchar;
	char star = '*';
	while(cin>>height)
	{
		totalchar = height + 2*(height-1);
		pPointer = new char *[height];
		for(i = 0; i<height; i++)
		{
			k = height + 2 * i;
			for(j = 0; j<(totalchar-k); j++)
				cout<<' ';
			for(j = 0; j < k ; j++)
				cout<<'*';
			cout<<endl;
		}
	}
	return 0;
}