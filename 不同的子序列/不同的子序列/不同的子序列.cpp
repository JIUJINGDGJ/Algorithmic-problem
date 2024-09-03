#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t >>dp(s.size()+1, vector<uint64_t>(t.size()+1));
        //����ע��������dp[i-1][j-1]��s[i-1],t[j-1]��λ��ȣ����ǽ�����ǰһ����ĸ��ȵ�Ϊ�̳й���
        // ,dp[i-1][j],�����ĸ��ƥ�䣬ɾ����Ҳ���ǲ����������ĸ��
        for (int i = 0; i <= s.size(); i++)dp[i][0] = 1;
        for (int i = 1; i < t.size(); i++)dp[0][i] = 0;
        for(int i=1;i<=s.size();i++)
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        return dp[s.size()][t.size()];
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