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
        vector<vector<int>>dp(100006, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < length; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] -prices[i]);//�����dp[i][0] ��֮ǰ����i֮ǰ��ĳ��Ĺ�Ʊ
            /*
            ������dp��ʽ����������ϸ�ڣ�������һ�仰������ǣ�
            dp[i][0]0��i���й�Ʊ�����ֵ
             dp[i][1]0��i�����й�Ʊ�����ֵ��������ֵ��������һϵ�����ⶼ��Ϊ��ά��������ֵ
            */
            /* ������ɭ����ô�죬������һ�仰�������𣨶Խ��۳��󣩣�ֻ�������һ����*/
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);//
            
        }

        return dp[length - 1][1];
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