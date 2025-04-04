#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        //dp数组含义，dp[i][j]=1代表dp[i-1][j-1]的元素是相等的，没错是i-1和j-1
        int result = 0;//这个是最长的子序列的最大值
        for (int i = 1; i <= text1.size(); i++)
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    //从前方继承
                }

                if (dp[i][j] > result)result = dp[i][j];
            }
        return result;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   /* vector<int>w = { 10,9,2,5,3,7,101,18 };
    Solution s;
    s.lengthOfLIS(w);*/
    return 0;
}