#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<vector<int>>dp(nums.size());
        for (int i = 1; i <= nums.size(); i++)
        {
            dp[i].resize(nums.size());
            for (int j = 1; j <= nums.size()-1; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= nums.size(); i++)
        {
           
            for (int j = 1; j <= nums.size()-1; j++)
            {
                if (j < nums[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }
        }
        if (dp[nums.size()][nums.size() - 1] == nums.size() - 1)
        {
            return true;
        }else{
            return false;
        }
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // ֻ��һ��Ԫ�أ������ܴﵽ
        for (int i = 0; i <= cover; i++) { // ע��������С�ڵ���cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // ˵�����Ը��ǵ��յ���
        }
        return false;
    }
};


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}