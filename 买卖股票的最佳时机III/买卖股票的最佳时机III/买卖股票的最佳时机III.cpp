#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        int length = prices.size();
        vector<vector<int>>dp(100006, vector<int>(5));
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < length; i++)
        {
            dp[i][1] = max(dp[i - 1][1], - prices[i]);//�����dp[i][0] ��֮ǰ����i֮ǰ��ĳ��Ĺ�Ʊ
            /*
            ������dp��ʽ����������ϸ�ڣ�������һ�仰������ǣ�
            dp[i][0]0��i���й�Ʊ�����ֵ
             dp[i][1]0��i�����й�Ʊ�����ֵ��������ֵ��������һϵ�����ⶼ��Ϊ��ά��������ֵ
            */
            /* ������ɭ����ô�죬������һ�仰�������𣨶Խ��۳��󣩣�ֻ�������һ����*/
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);//
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
               
        }

        return max(dp[length - 1][2], dp[length - 1][4]);
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>w = { 7,1,5,3,6,4 };
    Solution s;
    s.maxProfit(w);
    return 0;
}