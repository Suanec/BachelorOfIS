#include"Add.h"
char compare(char s,char d)
{
	switch(s)
	{
	case '+':switch(d)
			 {
				 case '+':
				 case '-':
				 case '*':
				 case '(':
				 case '/':return '<';
				 case ')':
				 case '#':return '>';
			 }
	case '-':switch(d)
			 {
				 case '+':
				 case '-':
				 case '*':
				 case '(':
				 case '/':return '<';
				 case ')':
				 case '#':return '>';
			 }
	case '*':switch(d)
			 {
				 case '*':
				 case '(':
				 case '/':return '<';
				 case '+':
				 case '-':
				 case ')':
				 case '#':return '>';
			 }
	case '/':switch(d)
			 {
				 case '*':
				 case '(':
				 case '/':return '<';
				 case '+':
				 case '-':
				 case ')':
				 case '#':return '>';
			 }
	case '(':switch(d)
			 {
				 case '+':
				 case '-':
				 case '*':
				 case '/':
				 case '(':return '<';
				 case ')':return '=';
				 case '#':return '&';
			 }
	case ')':switch(d)
			 {
				 case '+':
				 case '-':
				 case '*':
				 case '/':
				 case ')':
				 case '#':return '>';
				 case '(':return '=';

			 }
	case '#':switch(d)
			 {
				 case '+':
				 case '-':
				 case '*':
				 case '/':
				 case '(':return '<';
				 case ')':return '&';
				 case '#':return '=';
			 }
	default :return '<';
	}
}
bool datajudge(char ch)
{
	if(ch>=97&&ch<=122)return 1;
	else return 0;
}