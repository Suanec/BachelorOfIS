#include <iostream>
#include <string>
using namespace std;
int main()
{
	string strTem;
	string strResult;
	char   cc,cWork;
	int    i,nLength ;
	while(cin>>strTem)
	{
		cin>>cc;
		if(!strTem.length())continue;
		nLength = strTem.length();
		for(i = 0; i<nLength; i++)
		{
			cWork = strTem.at(i);
			if(cWork != cc)
				strResult+=cWork;
		}
		cout<<strResult<<endl;
		strResult.clear();
	}
	return 0;
}