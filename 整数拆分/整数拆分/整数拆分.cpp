#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(60, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
            for (int j = 1; j < i - 1; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                //最开始想的是通过数学规律来求，写了一些例子发现要想得到最大值，就要写成3和2的拆分
                //dp的精髓在与利用之前的状态，j*dp[i-j]确实写的非常精妙，可以借助之前的状态，也就是之前分割好的
                //dp[i],强
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