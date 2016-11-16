////////////////////
/******ListDeleteRRNode.h**********
    存在一链表，有序，有重复元素，位置数目均未知，
    试写一高效算法，删除所有重复的元素。
**************************/

class NODE 
{
private :
    float value;
    NODE * next;
public :
    NODE()
    {
        value = 0.0;
        next = NULL;
    }
    NODE( float m )
    {
        value = m ;
        next = NULL ;
    }
    ~NODE();
    void SetValue ( float lm )
    {
        value = lm ;
    }
    float GetValue ()
    {
        return value ;
    }
    NODE * GetNext()
    {
        return next ;
    }
    void SetNext( NODE * des )
    {
        next = des ;
    }

};/// NODE 类定义

class HEAD : public NODE
{
public :
    void DelReNode();
    int print();
};
void HEAD::DelReNode()
{
    NODE * pre, * pValue;
    float value ;
    pre = this ;
    pValue = this ->GetNext();
    value = pValue->GetValue();
    while ( pValue != NULL && pValue->GetNext() )
    {
        value = pre->GetValue();
        if( pre == this )
        {
            pre = pre->GetNext();
            pValue = pValue->GetNext();
            continue ;
        }///if( pre == this )
        if( value == pValue->GetValue() )
        {
            pre->SetNext( pValue->GetNext() ) ;
            free( pValue ) ;
            pValue = pre->GetNext();
            continue ;
        }///if( nv == value->GetValue() )
        else
        {
            pre = pValue ;
            pValue = pValue->GetNext();
            continue ;
        }///else
    }///while
}///DelReNode()

int HEAD::print()
{
    int count = 0 ;
    NODE * p ;
    int i = 10 ;
    p = this->GetNext();
    while( p )
    {
        cout<< p->GetValue() <<"  ";
        count++ ;
        if( !( i-- ) )
        {
            cout <<endl;
            i = 10 ;
        }
        p = p->GetNext();
    }
    cout<<endl;
    return count ;
}