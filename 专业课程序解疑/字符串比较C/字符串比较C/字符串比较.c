#include<stdio.h>
#include<string.h>
//#include<iostream>

void main ()
{
	int check(char c);
	char ScrToLvl(int score);
	char s1[20]="China",s2[20]="for",s[10];
	char c1='B',c2='O',c3='Y',c4='\101',c5='\116',c6='A',c7='Z';
	int x=15,n=2,a=3,b=4,c=5,m,i;
	float y=2.9876543;
	char * f1(char *s,char ch);
	char s2012[]="abcdabc!",ch1='b';
	char * ps;
	
	if(strcmp(s1,s2))
		printf("%s\n",strcat(s2,s1));
	else
		printf("%s\n",strlen(s1));
	printf("-----------------------------------------\n");
	printf("a%cb%c\tc%c\tabc\n",c1,c2,c3);
	printf("\t\b%c%c\n",c4,c5);
	printf("-----------------------------------------\n");
	x%=(n+=3);
	printf("%d   %d   %d\n",x,c6,c7);
	printf("%d\n",check(c6));
	printf("%d\n",(!(a+b)+c-1&&b+c/2));
	printf("%15.2f\n",y);
	printf("please input the score that needs discharge to level:\n");
	scanf("%d",&m);
	i=6;
	while(i--)
	printf("%c,%d\n",ScrToLvl(m+=10),m);
	printf("-----------------------------------------\n");
	ps = f1(s2012,ch1);
	while(ps)
	{
		puts(ps);
		ps=f1(NULL,ch1);
	}
	system("pause");
}
int check(char c)
{
	return (('A'<=c)&&('z'>=c))?(1):(0);
}
char ScrToLvl(int score)
{
	return ((score>90)?'A':
		((score>80)?'B':
		((score>70)?'C':
		((score>60)?'D':'E'))));
}
char * f1(char *s,char ch)
	{
		static char *p;
		char * p1;
		if(s)
			p=s;
		if(*p=='\0')
			return NULL;
		p1=p;
		while(*p&&*p!=ch)p++;
		if(*p)
			*p++='\0';
		return p1;
	}