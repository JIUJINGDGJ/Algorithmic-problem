#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1));
        //我发现一点，我们前面定义的dp，在后面推导的过程中可以直接使用，我们后面遇到问题，可以直接
        //从前面的基础上推导出来，不用在从0到1造个轮子
        for (int i = 0; i <= word1.size(); i++)dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)dp[0][j] = j;
        for(int i=1;i<=word1.size();i++)
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j] + 1,min( dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                    //dp[i - 1][j - 1] + 1代表替换操作
                }
            }
        return dp[word1.size()][word2.size()];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* vector<int>w = { -2,1,-3,4,-1,2,1,-5,4 };
     Solution s;
     s.maxSubArray(w);*/
    return 0;
}