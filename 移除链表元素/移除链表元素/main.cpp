#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) :val(x),next(nullptr) {}
	ListNode(int x,ListNode* next):val(x),next(next){}

};
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode();
		dummyHead->next = head;
		ListNode* cur = dummyHead;//这里复制一个头节点，防止后面找不到
		while (cur->next!=nullptr)//这里是对cur的下一个节点进行操作
		{
			if (cur->next->val == val)
			{
				ListNode* tmp = cur->next;//储存临时节点
				cur->next = cur->next->next;
				delete tmp;
				//怎么解决了尾部节点的问题，因为删除尾部节点后，尾部节点的前一个节点还是为空
				//所以，这里的删除操作仍然适用
			}
			else {
				cur = cur->next;
			}

		}
		head = dummyHead->next;
		delete dummyHead;//释放虚拟头节点
		return head;
	}
};
signed main()
{

	return 0;
}
