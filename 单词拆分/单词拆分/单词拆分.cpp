#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>word(wordDict.begin(), wordDict.end());//set集合，时间复杂度接近1
        //这里是将wordDict里的所有字符串添加进了set集合里
        vector<bool>dp(s.size() + 1, false);
        dp[0] = true;//这里的dp[0]没有意义，只是为了方便我们对数组初始化
        for(int i=1;i<=s.size();i++)//遍历背包，
            for (int j = 0; j < i; j++)//遍历物品，这里的字符串是有顺序的
            {
                string w = s.substr(j, i - j);//这里式截取字符串//substr(起始位置，截取的个数)
                if (word.find(w) != word.end() && dp[j])//这段字符串能找到，并且能跟前面的字符串接上
                {
                    dp[i] = true;//z这里是个一维背包
                }
            }
        return dp[s.size()];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    return 0;
}