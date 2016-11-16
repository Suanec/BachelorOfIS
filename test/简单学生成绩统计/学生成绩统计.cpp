/*////////////////////////////学生成绩统计(用c语言)
从键盘输入一个班（全班最多不超过30人）
学生某门课的成绩(score)，
当输入成绩为负时，输入结束，
分别实现下列功能：
1：统计出总人数及平均数
2：将成绩按由高到低顺序排列输出。。。*/
#include <stdio.h>
void Sort ( float a[],int num);
void main()
{
	float a[30] ;
	float temp,sum,ave;
	int num,i;
	printf("输入学生成绩:\n");
	sum = temp = i = 0;
	while(i<30)
	{
		scanf("%f",&temp);
		if(temp>100)
			printf("无效数据!\n");
		else if(temp>0)
		{
			a[i++] = temp;
			sum += temp;
		}
		else break;
	}
	num = i;//数组下标从零开始，记录总人数。
	ave = sum / num;
	printf("总人数：");
	printf("%d\n",num);
	printf("平均数：");
	printf("%.2f\n",ave);
	Sort(a,num);
	for(i = 0;i<num;i++)
		printf("\t%.2f",a[i]);
}
void Sort (float a[],const int num)
{
	int i,j,flag;
	float temp = a[0];
    for(j=0;j<num-1;j++)
	{
		flag = 1;
        for(i=0;i<num-1-j;i++)
        {
            if(a[i]>a[i+1])//数组元素大小按升序排列
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
				flag = 0;
            }
        }
		if(flag) break;
	}
}