#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
private: vector<vector<int>>res;
    void backtrack(vector<int>num,vector<int>& ans,int start)
    {//终止条件
        res.push_back(ans);//这里在最开始的时候压入了一个空集合
        for (int i = start; i < num.size(); i++)
        {
            ans.push_back(num[i]);
            backtrack(num, ans, i + 1);
            ans.pop_back();//弹出最后一个元素，就是我们刚才压入的元素
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
       
        backtrack(nums, ans, 0);
        return res;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 1,2,3 };
    Solution q;
    q.subsets(s);



    return 0;
}