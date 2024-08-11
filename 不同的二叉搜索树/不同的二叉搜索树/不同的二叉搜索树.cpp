#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n + 1, 0);
        //�����Ŀ��Щ������dp[i]=dp[j-1]+dp[i-j],,
        //�����ʽ�����Ǵ�dp[0]�Ƶ��ģ����ǹ۲���dp[0]��dp[1]��dp[2]��dp[3]��
        //�غϲ��֣���������dp[3]�еĵ�ʹ�ã���һ������Ҫһ������ʽһ��Ҳ����
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