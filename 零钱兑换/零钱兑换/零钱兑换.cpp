#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
//class Solution {
//private:
//    int amount;
//    int ans = 15;
//    void dfs(long long sum,vector<int>& coins,int cnums)
//    {//ʧ�ܣ���Ϊ����ⷨ�Ĵ�ȡ���������޵ģ����ӶȲ��ܵ������������鳤�������Ƶ�
//        
//        if (sum == amount)
//        {
//            ans = min(cnums, ans);
//            return;
//        }
//        if (sum > amount)
//        {
//            return;
//        }
//        for (int i = 0; i < coins.size(); i++)
//        {
//            dfs(sum + coins[i], coins, cnums + 1);
//        }
//    }
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        if (amount == 0)return 0;
//        if (coins.size() == 1)
//        {
//            if (amount % coins[0] != 0)
//            {
//                return -1;
//            }
//        }
//
//        this->amount = amount;
//        dfs(0, coins, 0);
//        return ans;
//    }
//};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)return 0;
        vector<int>dp(amount+4, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<coins.size();i++)
            for (int j = coins[i]; j <= amount; j++)//��j = coins[i]��ʼ
            {
                if (dp[j - coins[i]] != INT_MAX) { // ���dp[j - coins[i]]�ǳ�ʼֵ������
                    //Ϊʲô��Ҫ��� dp[j - coins[i]] != INT_MAX��
                    //������Ч���£���� dp[j - coins[i]] Ϊ INT_MAX����ô dp[j - coins[i]] + 1 Ҳ�� INT_MAX������ζ�������޷�ͨ����� coins[i] �����������Ӳ����������ˣ���ʱ���� dp[j] û���κ�����
                    cout << "dp[j - coins[i]]=" << dp[j - coins[i]] << "";
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1); //dp[j - coins[i]] + 1�������Ӳ�ҷ���
                    //dp[j]�������dp[j]����
                    cout << "dp[i]=" << dp[i] << "dp[j]= " << dp[j];
                    cout << "" << endl;
                }
            }
        if (dp[amount] == INT_MAX) return -1;
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
    w.coinChange(s, 11);
    return 0;
}