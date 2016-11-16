/*
148. Sort List   My Submissions QuestionEditorial Solution
Total Accepted: 69382 Total Submissions: 280023 Difficulty: Medium
Sort a linked list in O(n log n) time using constant space complexity.
*/

#include"leetcode.h"


class Solution {
public:
	ListNode* findLast(ListNode* head) {
		ListNode* p = head;
		int cnt = 1;
		while( p->next ){
			p = p->next;
			cnt ++;
		}
		ListNode* res = new ListNode(cnt);
		res->next = p;
		return res;
	}

    ListNode* sortList(ListNode* head) {
		if(!head) return head;

		//ListNode* info = findLast(head);
		//ListNode* tail = info->next;
		//int count = info->val;

		//vector<ListNode*> res = _sortList( head, NULL );
		//res[1]->next = NULL;
		//return res[0];
		ListNode* aHead = new ListNode(0);
		aHead->next = head;
		MergeSort(aHead, NULL);
		return aHead->next;
    }
	/// tail pivot
	//void sortList(ListNode* head, ListNode* tail){
	//	if( ! (head - tail) ) return ;
	//	ListNode *p = head, *pre = head, *subTail = head;
	//	bool needSorted = false;
	//	int temp = 0;
	//	while( p != tail ){
	//		if( p->val <= tail->val ){
	//			needSorted = true;
	//			temp = p->val;
	//			p->val = pre->val;
	//			pre->val = temp;
	//			if( pre == subTail ) pre = pre->next;
	//			else{
	//				pre = pre->next;
	//				subTail = subTail->next;
	//			}
	//		}
	//		p = p->next;
	//	}
	//	temp = p->val;
	//	p->val = pre->val;
	//	pre->val = temp;
	//	if( needSorted ){
	//		if(pre - head)sortList( head, subTail );
	//	}
	//	if(pre - tail)sortList( pre->next, tail );
	//}
	/// 72ms head pivot 返回首尾元素指针构成的vector，第一元素为首指针，第二元素是尾元素。
	//vector<ListNode*> _sortList(ListNode* head, ListNode* tail){
	//	vector<ListNode*> res;
	//	if( (!(head - tail)) ) {
	//		res.push_back(head);
	//		res.push_back(tail);
	//		return res;
	//	}
	//	if(!(head->next-tail))	{
	//		if(tail){
	//			if( tail->val < head->val ){
	//				tail->next = head;
	//				head->next = NULL;
	//				res.push_back(tail);
	//				res.push_back(head);
	//			}
	//			else{
	//				res.push_back(head);
	//				res.push_back(tail);
	//			}
	//		}
	//		else{
	//			res.push_back(head);
	//			res.push_back(head);
	//		}
	//		return res;
	//	}
	//	ListNode *pivot = head, *ppivot = NULL;
	//	ListNode *p = head;
	//	ListNode *big = NULL, *small = NULL, *pb = NULL, *ps = NULL;
	//	while(p){
	//		if( p->val > pivot->val ) {
	//			if( !big ) {
	//				big = p;
	//				pb = p;
	//			}
	//			else {
	//				pb->next = p;
	//				pb = pb->next;
	//			}
	//		}
	//		else if( p->val < pivot->val ) {
	//			if( !small ) {
	//				small = p;
	//				ps = p;
	//			}
	//			else {
	//				ps->next = p;
	//				ps = ps->next;
	//			}
	//		}
	//		else {
	//			if(ppivot){
	//				ppivot->next = p;
	//				ppivot = ppivot->next;
	//			}
	//			else ppivot = pivot;
	//		}
	//		p = p->next;
	//	}
	//	if(small){
	//		ps->next = NULL;
	//		vector<ListNode*> v1 = _sortList(small,ps);
	//		head = v1[0];
	//		v1[1]->next = pivot;
	//		res.push_back(head);
	//	}
	//	else {
	//		res.push_back(pivot);
	//	}
	//	if(big){
	//		pb->next = NULL;
	//		vector<ListNode*> v2 = _sortList(big,pb);
	//		ppivot->next = v2[0];
	//		v2[1]->next = NULL;
	//		res.push_back(v2[1]);
	//	}
	//	else res.push_back(ppivot);
	//	return res;
	//}
	/// 56ms Head Insert Quick Sort
	//void _sortList( ListNode* head, ListNode* tail ){
	//	if( !(head->next - tail) ) return;
	//	ListNode* pre = head, *cur = head, *pivot = head->next, *tem = NULL;
	//	while( cur->next && (cur->next - tail) ){
	//		if( pivot->val > cur->next->val ){
	//			tem = cur->next;
	//			cur->next = cur->next->next;
	//			tem->next = pre->next;
	//			pre->next = tem;
	//		}
	//		else cur = cur->next;
	//	}
	//	_sortList( head, pivot );
	//	while( pivot->next - tail && !(pivot->val - pivot->next->val) ) pivot = pivot->next;
	//	if( pivot - tail ) _sortList( pivot, tail );
	//}
	/// 60ms Merge Sort 靠返回值传参
	//ListNode* MergeList( ListNode* headA, ListNode* headB ){
	//	if( !headA ) return headB;
	//	if( !headB ) return headA;
	//	ListNode * pa = headA, *pb = headB, *res = NULL, *p = NULL;
	//	(pa->val > pb->val) ? (res = pb) : (res = pa);
	//	p = res;
	//	(p - pa) ? ( pb = pb->next ) : ( pa = pa->next );
	//	while( pa && pb ){
	//		if( pa->val < pb->val ){
	//			p->next = pa;
	//			pa = pa->next;
	//			p = p->next;
	//		}
	//		else if( pa->val > pb->val ) {
	//			p->next = pb;
	//			pb = pb->next;
	//			p = p->next;
	//		}
	//		else {
	//			p->next = pa;
	//			pa = pa->next;
	//			p = p->next;
	//			p->next = pb;
	//			pb = pb->next;
	//			p = p->next;
	//		}
	//	}
	//	if( pa ) p->next = pa;
	//	if( pb ) p->next = pb;
	//	return res;
	//}
	//ListNode* MergeSort( ListNode* head, ListNode* tail ){
	//	if( !(head - tail) ) return head;
	//	if( !(head->next - tail) ){
	//		if( tail && tail->val < head->val ) {
	//			head->val += tail->val;
	//			tail->val = head->val - tail->val;
	//			head->val = head->val - tail->val;
	//		}
	//		return head;
	//	}
	//	ListNode* pre = head, *cur = head, *tem = NULL;
	//	while( cur && cur->next ){
	//		pre = pre->next;
	//		cur = cur->next;
	//		cur = cur->next;
	//	}
	//	tem = pre->next;
	//	pre->next = NULL;
	//	ListNode* ppre = MergeSort( head, pre );
	//	ListNode* qpre = MergeSort( tem, cur );
	//	tem = MergeList( ppre, qpre );
	//	return tem;
	//}
	/// 65ms Merge Sort 靠头结点传参。
	ListNode* MergeList( ListNode* headA, ListNode* headB ){
		if( !headA ) return headB;
		if( !headB ) return headA;
		ListNode * pa = headA, *pb = headB, *res = NULL, *p = NULL;
		(pa->val > pb->val) ? (res = pb) : (res = pa);
		p = res;
		(p - pa) ? ( pb = pb->next ) : ( pa = pa->next );
		while( pa && pb ){
			if( pa->val < pb->val ){
				p->next = pa;
				pa = pa->next;
				p = p->next;
			}
			else if( pa->val > pb->val ) {
				p->next = pb;
				pb = pb->next;
				p = p->next;
			}
			else {
				p->next = pa;
				pa = pa->next;
				p = p->next;
				p->next = pb;
				pb = pb->next;
				p = p->next;
			}
		}
		if( pa ) p->next = pa;
		if( pb ) p->next = pb;
		return res;
	}
	void MergeSort( ListNode* _head, ListNode* tail ){
		ListNode *head = _head->next;
		if( !(head - tail) ) return ;
		if( !(head->next - tail) ){
			if( tail && tail->val < head->val ) {
				head->val += tail->val;
				tail->val = head->val - tail->val;
				head->val = head->val - tail->val;
			}
			return ;
		}
		ListNode* pre = head, *cur = head, *tem = NULL;
		while( cur && cur->next ){
			pre = pre->next;
			cur = cur->next;
			cur = cur->next;
		}
		tem = new ListNode(0);
		tem->next = pre->next;
		pre->next = NULL;
		MergeSort( _head, pre );
		MergeSort( tem, cur );
		_head->next = MergeList( _head->next, tem->next );
	}

	/// 56ms QuickSort
	/*
	    void sortListHelper(ListNode* head, ListNode* tail) {
        if (head -> next == tail) return;
        //* Partition the list. 
        ListNode* pre = head;
        ListNode* cur = head -> next; 
        ListNode* pivot = cur;
        while (cur -> next && cur -> next != tail) {        
            if (pivot -> val > cur -> next -> val) {
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
            }
            else cur = cur -> next;
        }
        sortListHelper(head, pivot);
        ///* Here is the trick. 
        while (pivot -> next != tail && pivot -> next -> val == pivot -> val)
            pivot = pivot -> next;
        if (pivot -> next != tail) sortListHelper(pivot, tail);
    } 

    ListNode* sortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        sortListHelper(new_head, NULL);
        return new_head -> next;
    }
	*/
};

/*********************************************************

                         main()

//*********************************************************/
//void main(){
//	int a[] = {4,2,1,3};
//	//ListNode *head = new ListNode(1);
//	//ListNode *p = head;
//	//for( int i = 0; i < 5; i++ ) {
//	//	cout<<p->val<<"->";
//	//	p->next = new ListNode(::rand()%10);
//	//	p = p->next;
//	//}
//	ListNode *head = new ListNode(a[0]);
//	ListNode *p = head;
//	for( int i = 1; i < 4; i++ ) {
//		cout<<p->val<<"->";
//		p->next = new ListNode(a[i]);
//		p = p->next;
//	}
//	cout<<p->val<<endl;
//	Solution slt;
//	p = slt.sortList(head);
//	//p = head;
//	while( p ){
//		cout<<p->val<<"->";
//		p = p->next;
//	}
// 	//system("pause");
//}
