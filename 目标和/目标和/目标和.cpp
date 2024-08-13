#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if ((sum + target) % 2 == 1)return 0;//(sum+target)/2不能有余数
        int x = (sum + target) / 2;
        if (abs(target) > sum) return 0; // 此时没有方案
        vector<int>dp(x + 10, 0);//这里初始化为x，x式背包容量
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = x; j >= nums[i]; j--)//j >= nums[i]这一步很关键，背包的空间大于这一层物品
            {
                dp[j] += dp[j - nums[i]];//如果j空间大小要放一个nums[i]大小的物品，那么剩下的空间有多少中方法从前面推到
            }
        }
        return dp[x];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,2,1,1 };
  
    return 0;
}