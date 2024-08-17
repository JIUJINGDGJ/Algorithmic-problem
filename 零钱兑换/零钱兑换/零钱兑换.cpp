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
//    {//失败，因为这个解法的存取次数是无限的，复杂度不能单纯的依靠数组长度来推推导
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
            for (int j = coins[i]; j <= amount; j++)//从j = coins[i]开始
            {
                if (dp[j - coins[i]] != INT_MAX) { // 如果dp[j - coins[i]]是初始值则跳过
                    //为什么需要检查 dp[j - coins[i]] != INT_MAX？
                    //避免无效更新：如果 dp[j - coins[i]] 为 INT_MAX，那么 dp[j - coins[i]] + 1 也是 INT_MAX，这意味着我们无法通过添加 coins[i] 来减少所需的硬币数量。因此，此时更新 dp[j] 没有任何意义
                    cout << "dp[j - coins[i]]=" << dp[j - coins[i]] << "";
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1); //dp[j - coins[i]] + 1代表将这个硬币放入
                    //dp[j]代表更新dp[j]数组
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