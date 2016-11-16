#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} NODE;
NODE *head,*p,*q;

NODE *creat(int n)
{
    NODE *head,*p,*q;
    int i=n;
    if(n==0)return(NULL);
    head=(NODE * )malloc(sizeof(NODE));
    p=head;
	while(i--)
	{
		p->data=getchar();getchar();
        q=(NODE * )malloc(sizeof(NODE));
		if(i)
		{
			p->link=q;
			p=q;
		}
		else
		{
			free(q);
			q=p;
		}
    }
	p->link=NULL;
    return(head);
}

void insert(NODE **p_head,char a,char b)
{	
	NODE *p,*q;
	q=(NODE * )malloc(sizeof(NODE));
	q->data=b;
	q->link=NULL;
	if(*p_head==NULL)
	  *p_head=q;
	else
	{
		p=*p_head;
		while(p->data!=a&&p->link!=NULL)
			p=p->link;
		q->link=p->link;
		p->link=q;
	}
}

int deletes(NODE **p_head,char a)
{
    NODE *p,*q;
    q=*p_head;
    if(*p_head==NULL)return(1);
    if(q->data==a)
    {*p_head=q->link;
    free(q);
    return(1);
    }
    else
    {
        while(q->data!=a&&q->link!=NULL)
        {
            p=q;
            q=q->link;
        }
        if(q->data==a)
        {
            p->link=q->link;
            free(q);
            return(1);
        }
        else
            return(0);
    }
}

void prints(NODE*head)
{
    NODE *p;
    printf("\n���ڽ��Ϊ��\n");
    p=head;
    if(head!=NULL)
        do
        {
            printf("%c",p->data);
            p=p->link;
        }while(p!=NULL);
}

int main()
{
    NODE *creat(int n);
    void insert(NODE **p_head,char a,char b);
    int deletes(NODE **p_head,char a);
    void prints(NODE*);
    NODE *head,*zifu;
    char t,s;
    int n=6,fal;
    printf("�������ַ�\n");
    head=creat(n);//��������
    prints(head);
    printf("\n������Ҫ�����λ�ü��ַ���\n");//�����ַ�
    zifu=(NODE*)malloc(sizeof(NODE));
    scanf("%c",&t);getchar();
	scanf("%c",&zifu->data);getchar();
    insert(&head,t,zifu->data);
    prints(head);
    printf("\n������Ҫɾ�����ַ�:\n");//ɾ���ַ�
    scanf("%c",&s);getchar();
    fal=deletes(&head,s);
    if(fal==0)printf("ɾ���ɹ�");
    else printf("ɾ��ʧ��");
    prints(head);
    printf("\n");
	system("pause");
    return 0;
}