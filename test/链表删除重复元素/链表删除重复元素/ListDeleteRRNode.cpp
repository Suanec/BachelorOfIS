#include <iostream>
using namespace std;
#include "ListDeleteRRNode.h"
#define MAXNUM 100 
typedef  NODE node ;
void main ()
{
    cout<<"/******ListDeleteRRNode**********"<<endl
        <<"����һ�����������ظ�Ԫ�أ�λ����Ŀ��δ֪��"<<endl
        <<"��дһ��Ч�㷨��ɾ�������ظ���Ԫ�ء�"<<endl
        <<"*******ListDeleteRRNode**********/"<<endl<<endl;
    HEAD *head = new HEAD() ;
    int i = MAXNUM /*-95*/ ;
    float m = 1 ;
    node * p = head/*->GetNext()*/ ;
    while( i-- )
    {
        if( !( i%( ( (rand()+1) % 7 )+1 ) ) )
        {
            m += ( rand() % 50 ) + 1 ;
            //p->SetNext( new node ( m ) );
            //p = p->GetNext();
        }
        //else
        //{
        //    p->SetNext( new node ( m ) );
        //    p = p->GetNext();
        //}
        //if( p == head->GetNext() ) p = new node ( m ) ;
        //else 
        //{
            //node* q = new node ( m ) ;
            p->SetNext( new node ( m ) );
        p = p->GetNext();
    }///while new
    //p->SetNext( NULL );
    cout<<"���ɵ����������ֵ��ʾ��"<<endl<<endl;
    cout<<endl<<"��"<<head->print()<<"��Ԫ�ء�"<<endl<<endl;
    head->DelReNode();
    cout<<"ɾ�����������ֵ��ʾ��"<<endl<<endl;
    cout<<endl<<"��"<<head->print()<<"��Ԫ�ء�"<<endl<<endl;


    //while ( i-- )
    //{
    //    cin >> m ;
    //    p->SetNext( new node( m ) );
    //    p = p->GetNext();
    //    //cout<<p->GetValue();
    //}
    //i = 10 ;
    //p = head->GetNext() ;
    //while ( i-- )
    //{
    //    cout << p->GetValue() <<" -> " ;
    //    p = p->GetNext();
    //}
    
}    
    
    
   