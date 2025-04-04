#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);//dp数组定义，nums[0]到nums[i]，，最长的递增子序列
        dp[0] = 1;
        //动规五部曲检查每一步，dp含义，递归公式，dp的初始化，遍历顺序，打印dp数组
        int result = 1;//这个是最长的子序列的最大值
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])dp[i] = dp[i] = dp[i - 1] + 1;
            if (dp[i] >= result)result = dp[i];
        }

        return result;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>w = { 1,3,5,4,7 };
    Solution s;
    s.lengthOfLIS(w);
    return 0;
}