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
        //dp数组的定义式我们最小删除元素个数，我们当前操作的数组dp[i][j]，如果删除当前元素
        //则要继承前一种状态，dp[i-1][j],就是前一种状态，dp[i-1][j]是我们已经更新完的状态
        //不计算作为列的第s[i-1]个元素
        if (word1.size() == 1 && word2.size() == 1)
        {
            if (word1[0] != word2[0])
            {
                return 2;
            }
            else {
                return 0;
            }
        }
        for (int i = 1; i <= word1.size(); i++)dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++)dp[0][j] = j;
        for(int i=1;i<=word1.size();i++)
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
                    //这里的加一就代表跳过当前元素，也就是删除当前元素
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