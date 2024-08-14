#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>num;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 默认初始化0
        for (int i = 0; i < strs.size(); i++)
        {
            int n1 = 0, m1 = 0;
           
            for (int j = 0; j < strs[i].size(); j++)
            {
                if (strs[i][j] == '0') {
                    m1++;
                }
                else {
                    n1++;
                }
            }
            num.push_back({ m1,n1 });
        }
       //这道题可以想想一个三维的坐标系，在一个被分割的空间李选取
        int temp = num.size()-1;
        for (int k = 0; k < temp; k++)
        {
            int m1 = num[k].first, n1 = num[k].second;
            for (int i = m; i >= m1; i--)
                for (int j = n; j >= n1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - m1][j - n1] + 1);
                    int s = dp[i][j];
                }
         }//太困了，不查了，有些测试点没过，检查检查
       
          
      return dp[m][n];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,2,1,1 };
    std::vector<std::string> strs = { "10", "0001", "111001", "1", "0" };
    int m = 5;
    int n = 3;
    Solution q;
    q.findMaxForm(strs, m, n);
    return 0;
}