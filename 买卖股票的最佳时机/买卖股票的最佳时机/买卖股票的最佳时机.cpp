#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        vector<int>dp(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++)
        {
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[prices.size() - 1];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}