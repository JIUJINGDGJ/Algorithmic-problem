#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(5500, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)//int j = coins[i]注意这一点
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 1,2,5 };
    Solution w;
    w.change(5, s);
    return 0;
}