#include<iostream>
#include<assert.h>
#include<list>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

typedef int DataType;

class Solution {
public:
	Solution()
		:_phead(nullptr)
	{}

	ListNode* BuyNewNode(DataType val){
		ListNode * NewNode = (ListNode*)new ListNode(val);
		return NewNode;
	}
	void PushFront(DataType data){
		ListNode* NewNode = BuyNewNode(data);
		if (NewNode == nullptr){
			assert(NewNode);
			return;
		}
		NewNode->next = _phead;
		_phead = NewNode;
	}
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* cur = pListHead;
		ListNode* pre = pListHead;
		int count = 0;
		while (cur != nullptr&&count < k){
			cur = cur->next;
			++count;
		}
		if (count < k&&cur==nullptr){
			return nullptr;
		}
		while (cur != nullptr){
			cur = cur->next;
			pre = pre->next;
		}
		return pre;
	}

	ListNode* ReverseList1(ListNode* pHead){
		//定义三个指针
		ListNode* pre = pHead;
		ListNode* cur = pHead;
		ListNode* nPhead = nullptr;
		while (nullptr != cur){
			pre = cur;
			cur = cur->next;
			//头插放入新的链表中
			pre->next = nPhead;
			nPhead = pre;
		}
		return nPhead;
	}

	~Solution(){
		ListNode* cur = _phead;
		while (cur){
			cur = cur->next;
			delete _phead;
			_phead = cur;
		}
	}
public:
	ListNode* _phead;
};


void TestFunc(){
	Solution s1;
	//先创建链表
	s1.PushFront(1);
	s1.PushFront(2);
	s1.PushFront(3);
	s1.PushFront(4);
	s1.PushFront(5);

	//找倒数第k个结点
	ListNode* cur = s1.FindKthToTail(s1._phead, 3);
	//找倒数第三个，应该是3；
	cout << "倒数第k个结点为:";
	cout << cur->val << " " << endl;
}

void TestFunc2(){
	Solution s1;
	ListNode* cur = nullptr;
	//先创建链表
	s1.PushFront(1);
	s1.PushFront(2);
	s1.PushFront(3);
	s1.PushFront(4);
	s1.PushFront(5);
	cur = s1._phead;
	cout << "逆转前的链表为：" << endl;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
	cout <<"逆转后的链表为："<< endl;
	cur = s1.ReverseList1(s1._phead);
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
}

int main(){

	TestFunc2();
	//Solution s1;
	////先创建链表
	//s1.PushFront(1);
	//s1.PushFront(2);
	//s1.PushFront(3);
	//s1.PushFront(4);
	//s1.PushFront(5);

	////找倒数第k个结点
	//ListNode* cur = s1.FindKthToTail(s1._phead, 3);
	////找倒数第三个，应该是3；
	//cout << "倒数第k个结点为:";
	//cout << cur->val << " " << endl;

	system("pause");
	return 0;
}