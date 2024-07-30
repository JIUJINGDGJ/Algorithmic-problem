#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {//����ջ�ⷨ
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
                    ans[t.second] = i - t.second;//���´�
                    int s = ans[t.second];
                    mon.pop();//����ջ��Ԫ�أ���Ϊ����ά������һ������ջ
                    if(!mon.empty()) t = mon.top();//��ǰ��ջ�������ˣ�������Ҫ����ջ��,ǰ����ջ��Ϊ��
                   
                }
                
               
            }
           
                mon.push({ temperatures[i],i });//���ѹ����һ��Ҫ����
            
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