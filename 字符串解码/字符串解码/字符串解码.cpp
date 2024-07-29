#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {

public:
    string decodeString(string s) {
        string res = "";
        stack<int>stk;
        stack<string>q;
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';//����10��123[a]�����������12��12*10=120��120+3=123
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                res += s[i];
            }
            else if(s[i]=='[') {
                stk.push(num);
                num = 0;
                q.push(res);
                res = "";
            }
            else {
                int times = stk.top();
                stk.pop();//�ַ����ظ��Ĵ������һ�������������йأ�
                for (int i = 0; i < times; i++)
                    q.top() += res;
                res = q.top();//������һ���ַ��ĺ��棬���ǰ�����ַ����ͻ����ǰ���ַ��ĺ��棬����������ַ���������ַ�
                // res += s[i];��ͨ����������д����Զ����ں���
                q.pop();
            }
        }
        return res;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string q = "abc3[cd]xyz";
    Solution s;
    s.decodeString(q);

    return 0;
}