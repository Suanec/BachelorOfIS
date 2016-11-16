#include <iostream>
using namespace std;
#include "ListDeleteRRNode.h"
#define MAXNUM 100 
typedef  NODE node ;
void main ()
{
    cout<<"/******ListDeleteRRNode**********"<<endl
        <<"存在一链表，有序，有重复元素，位置数目均未知，"<<endl
        <<"试写一高效算法，删除所有重复的元素。"<<endl
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
    cout<<"生成的随机链表数值显示："<<endl<<endl;
    cout<<endl<<"共"<<head->print()<<"个元素。"<<endl<<endl;
    head->DelReNode();
    cout<<"删除后的链表数值显示："<<endl<<endl;
    cout<<endl<<"共"<<head->print()<<"个元素。"<<endl<<endl;


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
    
    
   