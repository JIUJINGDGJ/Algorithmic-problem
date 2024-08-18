#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int square = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i * i < n)square = i;
            
            if (i * i == n)return 1;
            if (i * i > n)break;
        }
        vector<int>dp(n + 11, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=square;i++)
            for (int j = 1; j <= n; j++)
            {
                if (j - i * i >= 0)
                {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        return dp[n];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution s;
    s.numSquares(12);
    return 0;
}