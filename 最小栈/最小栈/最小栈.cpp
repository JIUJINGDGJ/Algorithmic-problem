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
    Node *head;//声名头节点
public:
    MinStack() {
        head = nullptr;//初始化头节点
    }

    void push(int val) {
        if (head == nullptr)//若栈为空，则创建一个新节点
        {
            head = new Node(val, val);
        }
        else {//不为空则插入一个新节点
            int tmp = val < head->m ? val : head->m;
            Node* cur = new Node(val, tmp);
            cur->next = head;//这里将cur这个新建节点插入链表头部，链表的赋值相当于整数变量的赋值，head指向的节点付给了cur->next
            head = cur;
        }
    }

    void pop() {
        // 让头节点指向自身的下一个节点即可
        // 不用管出栈之后的最小值变化，即使当前出栈元素就是最小值也无妨，
        // 因为每个节点的 min 值记录的都是栈底到此节点的元素最小值

       // 作者：echofzoe
        //    链接：https ://leetcode.cn/problems/min-stack/solutions/172174/cbu-shi-yong-fu-zhu-rong-qi-jiu-chun-shou-xie-dai-/
        //来源：力扣（LeetCode）
     //       著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        head = head->next;
    }

    int top() {
        // 直接返回头节点 val 值即可，头节点永远指向栈顶
        return head->val;
    }

    int getMin() {
        // 直接返回头节点 min 值即可，头节点的 min 值永远是栈内所有元素的最小值
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