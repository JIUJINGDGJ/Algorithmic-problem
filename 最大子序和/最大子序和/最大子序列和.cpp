#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size() + 1, 0);
        //数组定义，0到i，dp[i]所能取到的最大值
        int result = 0;
        if (nums.size() == 1)return nums[0];
       dp[0] = nums[0],result=nums[0];
       //dp[0],根据dp数组的定义，和为了方便后面的推到，我们定义为nums[0]
       //如果定义成0，而数组全是复数，，逻辑会出问题
        for (int i = 1; i < nums.size(); i++)
        {
            //if (nums[i] > 0)dp[i] = dp[i - 1] + nums[i];
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            //dp[i]可以由两个方向退出来，dp[i - 1] + nums[i]和nums[i]即：从头开始计算当前连续子序列和
                
                if (dp[i] > result)result = dp[i];
            
        }
        return result;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     vector<int>w = { -2,1,-3,4,-1,2,1,-5,4 };
     Solution s;
     s.maxSubArray(w);
    return 0;
}