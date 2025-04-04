#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
private:
    int result = 0;
public:
    int longestPalindromeSubseq(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            extend(s, i, i, s.size());
            extend(s, i, i + 1, s.size());

        }
        return result;
    }
    void extend(const string s, int r, int l, int n)
    {
        int q = 0;
        while (r >= 0 && l < n )
        { 
            if (s[r] == s[l])
            {
                int t = l - r + 1-q;
                result = max(result, t);
             
            }
            else {
                q++;
            }
            r--;
            l++;

        }

    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size() + 1, vector<int>(s.size() + 1,0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;//本身就是回文子序列
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size();j++)
            {
                if (s[i] == s[j])dp[i][j] = dp[i + 1][j - 1] + 2;
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size()-1];

    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* vector<int>w = { -2,1,-3,4,-1,2,1,-5,4 };*/

    string w = "bbbab";
     Solution s;
     s.longestPalindromeSubseq(w);
    return 0;
}