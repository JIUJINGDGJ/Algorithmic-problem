#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class MinStack {
private:
    struct Node{
        int val;
        int m;
        Node *next;
        Node(int x,int y):val(x),m(y),next(nullptr){}

    };
    Node *head;//����ͷ�ڵ�
public:
    MinStack() {
        head = nullptr;//��ʼ��ͷ�ڵ�
    }

    void push(int val) {
        if (head == nullptr)//��ջΪ�գ��򴴽�һ���½ڵ�
        {
            head = new Node(val, val);
        }
        else {//��Ϊ�������һ���½ڵ�
            int tmp = val < head->m ? val : head->m;
            Node* cur = new Node(val, tmp);
            cur->next = head;//���ｫcur����½��ڵ��������ͷ��������ĸ�ֵ�൱�����������ĸ�ֵ��headָ��Ľڵ㸶����cur->next
            head = cur;
        }
    }

    void pop() {
        // ��ͷ�ڵ�ָ���������һ���ڵ㼴��
        // ���ùܳ�ջ֮�����Сֵ�仯����ʹ��ǰ��ջԪ�ؾ�����СֵҲ�޷���
        // ��Ϊÿ���ڵ�� min ֵ��¼�Ķ���ջ�׵��˽ڵ��Ԫ����Сֵ

       // ���ߣ�echofzoe
        //    ���ӣ�https ://leetcode.cn/problems/min-stack/solutions/172174/cbu-shi-yong-fu-zhu-rong-qi-jiu-chun-shou-xie-dai-/
        //��Դ�����ۣ�LeetCode��
     //       ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
        head = head->next;
    }

    int top() {
        // ֱ�ӷ���ͷ�ڵ� val ֵ���ɣ�ͷ�ڵ���Զָ��ջ��
        return head->val;
    }

    int getMin() {
        // ֱ�ӷ���ͷ�ڵ� min ֵ���ɣ�ͷ�ڵ�� min ֵ��Զ��ջ������Ԫ�ص���Сֵ
        return head->m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  

    return 0;
}