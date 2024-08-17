#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target + 2, 0);
        dp[0] = 1;//dp[0]无意义，只是为了方便推导
        for(int i=0;i<=target;i++)
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0&& dp[i] < INT_MAX - dp[i - nums[j]])
                {//C++测试用例有两个数相加超过int的数据，所以需要在if里加上dp[i] < INT_MAX - dp[i - num]
                    dp[i] += dp[i - nums[j]];
                }
            }
        return dp[target];
    }
};

/*溢出原因：
当 dp[i] 已经非常接近 INT_MAX，而 dp[i - nums[j]] 又是一个较大的正数时，将两者相加可能会导致结果超过 INT_MAX，从而发生整数溢出。
避免溢出的方法：
在进行累加操作前，通过比较 dp[i] 和 INT_MAX - dp[i - nums[j]] 来判断是否会超出范围。
如果 dp[i] 加上 dp[i - nums[j]] 不会导致溢出，则执行累加操作；否则跳过这次累加。*/
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,2,1,1 };

    return 0;
}