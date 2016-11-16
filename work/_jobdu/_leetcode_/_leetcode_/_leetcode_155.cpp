/**
155. Min Stack My Submissions Question
Total Accepted: 65334 Total Submissions: 300688 Difficulty: Easy
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include"leetcode.h"
#include<iostream>
#include<stack>
using namespace std;
/// STL ///
class MinStack {
public:
    void push(int x) {
		value.push(x);
		if(min.empty() || x <= min.top()) min.push(x);
    }

    void pop() {
		int tmp = value.top();
		value.pop();
		if( tmp == min.top() ) min.pop();
    }

    int top() {
        return value.top();
    }

    int getMin() {
        return min.top();
    }
private:
	stack<int> value;
	stack<int> min;
};
/// Self List Stack ///
//class MinStack {
//public:
//	MinStack(){
//		isEmpty = true;
//		m_head.m_value = 47477297;
//		m_head.next = NULL;
//	}
//    void push(int x) {
//        Node * pTem = new Node;
//		pTem->m_value = x;
//		pTem->next = m_head.next;
//		m_head.next = pTem;
//		if(pTem->next == NULL) m_min = pTem->m_value;
//		else if( pTem->m_value < m_min ) m_min = pTem->m_value;
//		pTem = NULL;
//    }
//	int findMin(){
//		Node* pTem = m_head.next;
//		int res = ( pTem == NULL ) ? 0 : pTem->m_value;
//		while(pTem != NULL){
//			res = ( pTem->m_value < res ) ? pTem->m_value : res;
//			pTem = pTem->next;
//		}
//		return res;
//	}
//    void pop() {
//		Node * pTem = m_head.next;
//		if(pTem == NULL) return;
//		m_head.next = pTem->next;
//		pTem->next = NULL;
//		if( m_min == pTem->m_value ) m_min = findMin();
//		delete(pTem);
//    }
//
//    int top() {
//		return m_head.next->m_value;
//    }
//
//    int getMin() {
//        return m_min;
//    }
//private:
//	struct Node{
//		int m_value;
//		Node* next;
//	};
//	int m_min;
//	Node m_head;
//	bool isEmpty;
//};
/*********************************************************

                         main()

*********************************************************/
//void main(){
//	MinStack s;
//	//s.push(2);
//	//s.push(0);
//	//s.push(3);
//	//s.push(0);
//	//cout<<s.getMin()<<endl;
//	//s.pop();
//	//cout<<s.getMin()<<endl;
//	//s.pop();
//	//cout<<s.getMin()<<endl;
//	//s.pop();
//	//cout<<s.getMin()<<endl;
//	s.push(2147483646);
//	s.push(2147483646);
//	s.push(2147483647);
//	s.top();
//	s.pop();
//	s.getMin();
//	s.pop();
//	s.getMin();
//	s.pop();
//	s.push(2147483647);
//	s.top();
//	s.getMin();
//	s.push(-2147483648);
//	s.top();
//	s.getMin();
//	s.pop();
//	s.getMin();
//	system("pause");
//}