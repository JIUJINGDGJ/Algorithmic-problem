#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1,0));
        //dp数组含义，dp[i][j]=1代表dp[i-1][j-1]的元素是相等的，没错是i-1和j-1
        int result = 0;//这个是最长的子序列的最大值
        for(int i=1;i<= nums1.size();i++)
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > result)result = dp[i][j];
            }
        return result;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   /* vector<int>w = { 1,3,5,4,7 };
    Solution s;
    s.lengthOfLIS(w);*/
    return 0;
}