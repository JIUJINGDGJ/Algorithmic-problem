#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);//dp数组定义，nums[0]到nums[i]，，最长的递增子序列
        dp[0] = 1;
        //动规五部曲检查每一步，dp含义，递归公式，dp的初始化，遍历顺序，打印dp数组
        int result = 1;//这个是最长的子序列的最大值
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                //cout << "i=" << i << " " << "j=" << j << endl;
               // cout << "nums[i]" << nums[i] << " " << "nums[j]" << nums[j] << endl;
                //cout <<"更新之前" << "dp[i]=" << dp[i] << " " << "dp[j]+1=" << dp[j] << endl;
                if (nums[i] > nums[j])dp[i] = max(dp[i], dp[j] + 1);
                //这个判断句是核心语句，他遍历0-j，选取其中最长的递增子序列
                //cout <<"更新之后" << "dp[i]=" << dp[i] << " " << "dp[j]+1=" << dp[j] << endl;
            }
            if (dp[i] >= result)result = dp[i];
        }
           
        return result;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>w = { 10,9,2,5,3,7,101,18 };
    Solution s;
    s.lengthOfLIS(w);
    return 0;
}