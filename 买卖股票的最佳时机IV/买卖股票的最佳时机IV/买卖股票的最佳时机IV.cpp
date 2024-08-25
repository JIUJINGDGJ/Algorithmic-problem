#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxProfit(int k ,vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        int length = prices.size();
        vector<vector<int>>dp(prices.size(), vector<int>(k*3));
       /* dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;*/
        for (int i = 1; i <= 2 * k; i++)
        {
            if(i%2==1)dp[0][i] = -prices[0];
            else {
                dp[0][i] = 0;
            }
        }
        for (int i = 1; i < length; i++)
        {
            for (int j = 1; j <= 2*k; j++)
            {
                if(j==1) dp[i][1] = max(dp[i - 1][1], -prices[i]);
                if (j % 2 == 0)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                if(j%2==1)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            }
            //dp[i][1] = max(dp[i - 1][1], -prices[i]);//这里的dp[i][0] 从之前买了i之前的某天的股票
            ///*
            //这两个dp公式包含大量的细节，但是用一句话解决就是，
            //dp[i][0]0到i持有股票的最大值
            // dp[i][1]0到i不持有股票的最大值，这两个值所引出的一系列问题都是为了维护这两个值
            //*/
            ///* 陷入了森林怎么办，你能用一句话解释他吗（对结论抽象），只看问题的一部分*/
            //dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);//
            //dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            //dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);

        }

        return max(dp[length - 1][2 * k], dp[length - 1][2 * k-1]);
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k = 2;
    vector<int>s = { 2,4,1 };
    Solution w;
    w.maxProfit(k, s);
    return 0;
}