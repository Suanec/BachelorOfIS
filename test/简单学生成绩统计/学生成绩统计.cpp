/*////////////////////////////ѧ���ɼ�ͳ��(��c����)
�Ӽ�������һ���ࣨȫ����಻����30�ˣ�
ѧ��ĳ�ſεĳɼ�(score)��
������ɼ�Ϊ��ʱ�����������
�ֱ�ʵ�����й��ܣ�
1��ͳ�Ƴ���������ƽ����
2�����ɼ����ɸߵ���˳���������������*/
#include <stdio.h>
void Sort ( float a[],int num);
void main()
{
	float a[30] ;
	float temp,sum,ave;
	int num,i;
	printf("����ѧ���ɼ�:\n");
	sum = temp = i = 0;
	while(i<30)
	{
		scanf("%f",&temp);
		if(temp>100)
			printf("��Ч����!\n");
		else if(temp>0)
		{
			a[i++] = temp;
			sum += temp;
		}
		else break;
	}
	num = i;//�����±���㿪ʼ����¼��������
	ave = sum / num;
	printf("��������");
	printf("%d\n",num);
	printf("ƽ������");
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
            if(a[i]>a[i+1])//����Ԫ�ش�С����������
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