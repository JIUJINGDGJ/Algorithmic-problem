#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1)return 1;//单个元素
        if (nums.size() == 0)return 0;//判断为不为空
        set<int>s;
        for (auto q : nums)
        {
            s.insert(q);//将全部元素压入set集合
        }
        int i = 0;//记数变量.\,跳过第一个元素
        int v = 0;//记录上一个变量
        int res = 1;//初始化为一，因为最短的为一
        int ans = 1;//记录答案
        int mr = 0;
        for (auto w : s)
        {

            if (i != 0)
            {
                if ((v + 1) == w)//表示连续
                {
                    res++;
                    ans = max(ans, res);

                }
                else {
                    res = 1;
                }
            }
            v = w;//存储上一个元素
            i = 1;
        }
        return ans;
    }
    
	
};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    vector<int>t;
    t = { 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 };
    Solution x;
    x.longestConsecutive(t);
	return 0;
}