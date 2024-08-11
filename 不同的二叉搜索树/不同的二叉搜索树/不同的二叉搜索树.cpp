#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n + 1, 0);
        //这道题目有些启发，dp[i]=dp[j-1]+dp[i-j],,
        //这个公式是我们从dp[0]推导的，我们观察了dp[0]和dp[1]，dp[2]与dp[3]的
        //重合部分，将两者在dp[3]中的到使用，不一定数字要一样，形式一样也可以
        dp[0] = 1;
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        return dp[n];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}