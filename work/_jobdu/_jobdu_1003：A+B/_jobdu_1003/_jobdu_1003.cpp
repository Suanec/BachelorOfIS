/************************************************************************/
/* 题目描述：
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
现在请计算A+B的结果，并以正常形式输出。
输入：
输入包含多组数据数据，每组数据占一行，由两个整数A和B组成（-10^9 < A,B < 10^9）。
输出：
请计算A+B的结果，并以正常形式输出，每组数据占一行。
样例输入：
-234,567,890 123,456,789
1,234 2,345,678
样例输出：
-111111101
2346912                                                                     */
/************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ZERO '0' 
#define NINE '9' 
int main()
{
    string aStr,bStr;
    char   p;
    int    aInt,bInt;
    int    sum,i,ptem;
    bool   isNegative = false;
    aInt = bInt = sum = i = ptem = 0;
    while(cin>>aStr>>bStr)
    {
        if(aStr.empty()&&bStr.empty())return 0;
        for(i = 0; i<aStr.length(); i++)
        {
            p = aStr.at(i);
            if(p>='0'&&p<='9')
            {
                aInt *= 10;
                aInt += (p-'0');
            }
            else if (p == '-')
                isNegative = true;             
        }
        if(isNegative)aInt = (0-aInt);
        isNegative = false;
        for(i = 0; i<bStr.length(); i++)
        {
            p = bStr.at(i);
            if(p>='0'&&p<='9')
            {
                bInt *= 10;
                bInt += (p-'0');
            }
            else if (p == '-')
                isNegative = true;             
        }
        if(isNegative)bInt = (0-bInt);
        isNegative = false;
        sum = aInt + bInt;
        cout<<sum<<endl;
        sum = aInt = bInt = ptem = 0;
    }
    return 1;
}