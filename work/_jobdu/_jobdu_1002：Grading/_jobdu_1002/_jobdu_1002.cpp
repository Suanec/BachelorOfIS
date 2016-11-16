/************************************************************************/
/* 题目1002：Grading
	时间限制：1 秒
	内存限制：32 兆
	特殊判题：否

	题目描述：
	Grading hundreds of thousands of Graduate Entrance Exams is a hard work. 
	It is even harder to design a process to make the results as fair as possible. 
	One way is to assign each exam problem to 3 independent experts.
	If they do not agree to each other,
	a judge is invited to make the final decision.
	Now you are asked to write a program to help this process.
	For each problem, there is a full-mark P and a tolerance T(<P) given. 
	The grading rules are:
	P满分、T公差。
	• A problem will first be assigned to 2 experts, to obtain G1 and G2.
	If the difference is within the tolerance, 
	that is, if |G1 - G2| ≤ T, 
	this problem's grade will be the average of G1 and G2.
	·如果G1和G2的差小于公差，则取平均。
	• If the difference exceeds T, the 3rd expert will give G3.
	·如果G1和G2差大于公差，则看G3.
	• If G3 is within the tolerance with either G1 or G2, but NOT both, 
	then this problem's grade will be the average of G3 and the closest grade.
	·如果G3与G1或G2中一个差小于公差，则取G3及相近一成绩的平均。
	• If G3 is within the tolerance with both G1 and G2,
	then this problem's grade will be the maximum of the three grades.
	·如果G3与G1、G2差均小于公差。则最终成绩取最大值。
	• If G3 is within the tolerance with neither G1 nor G2, 
	a judge will give the final grade GJ.
	·如果G3与G1、G2差值均大于公差，则由GJ决定最终成绩。
	输入：
	Each input file may contain more than one test case.
	Each case occupies a line containing six positive integers: 
	P, T, G1, G2, G3, and GJ, as described in the problem.
	It is guaranteed that all the grades are valid,
	that is, in the interval [0, P].
	输出：
	For each test case you should output the final grade of the problem in a line.
	The answer must be accurate to 1 decimal place.
	样例输入：
	20 2 15 13 10 18
	样例输出：
	14.0
*/
/************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
double sAbs(double x)
{
	if(x>=0)return x;
	else return -x;
}
double max(double x, double y , double z)
{
    return
    (x>y)?
        ((x>z)?x:z)
        :((y>z)?y:z);
}
int main()
{
	double P,T,G1,G2,G3,GJ;
	double temp,temp3,final;
	bool   isTwoLarger;
	P = T = G1 = G2 = G3 = GJ = 0;
	isTwoLarger = false;
    while(cin>>P>>T>>G1>>G2>>G3>>GJ)
	{
		if(T>P)cout<<"Data Error!"<<endl;
		//((G1-G2)<=0)?(isTwoLarger = true):(isTwoLarger = false);
		//if(isTwoLarger)temp = G2 - G1;
		//else temp = G1 - G2;
		//if(temp<=T)final = (G1+G2)/2.0;
		//else if(isTwoLarger)
		//{
		//	if(G3<=G1)
		//		if((G1-G3)>T)final = GJ;
		//		else final = (G3+G1)/2.0;
		//	else if(G3>G2)
		//		if((G3-G2)>T)final = GJ;
		//		else final = (G3+G2)/2.0;
		//	else 
		//	{
		//		temp = G3-G1;
		//		temp3 = G2-G3;
		//		if((temp<=T)&&(temp3<=T))final = G2;
		//		else if((temp>T)&&(temp3>T))final = GJ;
		//		else if((temp3-temp)>0)
		//			final = (G3+G1)/2.0;
		//		else final = (G3+G2)/2.0;
		//	}
		//}
		//else
		//{
		//	if(G3<=G2)
		//		if((G2-G3)>T)final = GJ;
		//		else final = (G3+G2)/2.0;
		//	else if(G3>G1)
		//		if((G3-G1)>T)final = GJ;
		//		else final = (G3+G1)/2.0;
		//	else 
		//	{
		//		temp = G3-G2;
		//		temp3 = G1-G3;
		//		if((temp<=T)&&(temp3<=T))final = G1;
		//		else if((temp>T)&&(temp3>T))final = GJ;
		//		else if((temp3-temp)>0)
		//			final = (G3+G2)/2.0;
		//		else final = (G3+G1)/2.0;
		//	}
		//}
		if(sAbs(G1-G2)<=T)final = (G1+G2)/2.0;
		else if((sAbs(G1-G3)<=T)&&(sAbs(G2-G3)<=T)) final = max(G1,G2,G3);
		else if(sAbs(G2-G3)<=T) final = (G2+G3)/2.0;
		else if(sAbs(G1-G3)<=T)final = (G1+G3)/2.0;
		else final = GJ;
		cout<<fixed<<::setprecision(1)<<final<<endl;
		//printf("%.1f\n",final);
	}
	return 1;
}

//#include <iostream>
//#include <iomanip>
//#include <cmath>
//using namespace std;
//double getMax( double x, double y, double z)
//{
//    return
//    (x>y)?
//        ((x>z)?x:z)
//        :((y>z)?y:z);
//
//}
//int main()
//{
//    double P,T,G1,G2,G3,GJ;
//    double final;
//    cin>>P>>T>>G1>>G2>>G3>>GJ;
//    if(abs(G1-G2)<=T)
//    {
//        cout<<fixed<<::setprecision(1)<<(G1+G2)/2.0<<endl;
//    }
//    else if(abs(G3-G1)<=T&&abs(G3-G2)<=T)
//    {
//        cout<<fixed<<::setprecision(1)<<getMax(G1,G2,G3)<<endl;
//    }
//    else if(abs(G3-G2)<=T)
//    {
//        cout<<fixed<<::setprecision(1)<<(G3+G2)/2.0<<endl;
//    }
//    else if(abs(G3-G1)<=T)
//    {
//        cout<<fixed<<::setprecision(1)<<(G3+G1)/2.0<<endl;
//    }
//    else
//    {
//        cout<<fixed<<::setprecision(1)<<GJ<<endl;
//    }
//    return 0;
//
//}