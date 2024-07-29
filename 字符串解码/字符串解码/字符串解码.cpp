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
                num = num * 10 + s[i] - '0';//乘以10：123[a]，假设读到了12，12*10=120，120+3=123
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
                stk.pop();//字符的重复的次数与第一个遇到的数字有关，
                for (int i = 0; i < times; i++)
                    q.top() += res;
                res = q.top();//接在下一个字符的后面，如果前面有字符，就会接在前面字符的后面，如果后面有字符，后面的字符
                // res += s[i];会通过上面的这行代码自动接在后面
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