#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {//单调栈解法
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>mon;
        vector<int>ans(temperatures.size(), 0);
        mon.push({ temperatures[0],0 });
        for (int i = 1; i < temperatures.size(); i++)
        {
            auto t = mon.top();

            if (temperatures[i] > t.first)
            {
                while (!mon.empty() && temperatures[i] > t.first)
                {
                    ans[t.second] = i - t.second;//更新答案
                    int s = ans[t.second];
                    mon.pop();//弹出栈顶元素，因为我们维护的是一个单调栈
                    if(!mon.empty()) t = mon.top();//先前的栈顶弹出了，这里需要更新栈顶,前提是栈不为空
                   
                }
                
               
            }
           
                mon.push({ temperatures[i],i });//这个压入是一定要做的
            
        }
        return ans;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 73,74,75,71,69,72,76,73 };
    Solution qw;
    qw.dailyTemperatures(s);
    return 0;
}