#include <iostream>
#include <string>
using namespace std;
int Satoi( string _str )
{
	if(!_str.length())return 0;
	char c = _str.at(0);
	switch(c)
	{
	case 'o' :
		return 1;
	case 'e' :
		return 8;
	case 'n' :
		return 9;
	case 'z' :
		return 0;
	case 't' :
		c = _str.at(1);
		switch(c)
		{
		case 'w' :
			return 2;
		case 'h' :
			return 3;
		default:
			return 0;

		}
	case 'f' :
		c = _str.at(1);
		switch(c)
		{
		case 'o' :
			return 4;
		case 'i' :
			return 5;
		default:
			return 0;

		}
	case 's' :
		c = _str.at(1);
		switch(c)
		{
		case 'i' :
			return 6;
		case 'e' :
			return 7;
		default:
			return 0;

		}
	default:
		return 0;
	}
}
int main()
{
	string strTotal,strTem;
	string strWork;
	char   cc;
	int  i, length, nWork, nSum;
	while(cin>>strTem)
	{
		strTotal.clear();
		strWork.clear();
		nSum = nWork = 0;
		while(strTem.compare("="))
		{
			strTotal += strTem;
			strTotal += ' ';
			cin>>strTem;
		}
		strTotal += strTem;
		length = strTotal.length();
		for(i=0; i<length; i++)
		{
			cc = strTotal.at(i);
			if(cc == '+') 
			{
				nSum += nWork;
				nWork = 0;
				strWork.clear();
			}
			else if(cc == ' ')
			{
				nWork = nWork*10 + Satoi(strWork.c_str());
				strWork.clear();
			}
			else if(cc != '=')strWork+=cc;
		}
		nSum += nWork;
		if(!nSum)break;
		cout<<nSum<<endl;
		strTotal.clear();
		strWork.clear();
		nSum = nWork = 0;

	}
	return 0;
}