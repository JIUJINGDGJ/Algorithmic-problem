#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        int length = prices.size();
        vector<vector<int>>dp(100006, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < length; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] -prices[i]);//这里的dp[i][0] 从之前买了i之前的某天的股票
            /*
            这两个dp公式包含大量的细节，但是用一句话解决就是，
            dp[i][0]0到i持有股票的最大值
             dp[i][1]0到i不持有股票的最大值，这两个值所引出的一系列问题都是为了维护这两个值
            */
            /* 陷入了森林怎么办，你能用一句话解释他吗（对结论抽象），只看问题的一部分*/
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);//
            
        }

        return dp[length - 1][1];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>w = { 7,1,5,3,6,4 };
    Solution s;
    s.maxProfit(w);
    return 0;
}