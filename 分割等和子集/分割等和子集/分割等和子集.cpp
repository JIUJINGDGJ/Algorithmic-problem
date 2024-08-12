#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>copy(nums.size(),0);//直接复制
        copy[0] = nums[0];
        for (int i = 1; i < copy.size(); i++)
        {
            copy[i] = copy[i - 1] + nums[i];
            int s = copy[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (copy[i] == copy[nums.size() - 1] - copy[i])
            {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //这道题的关键式在于将求解分割数组转化为求解数字组合的和为
        //数组和的一半，
         // dp[i]中的i表示背包内总和
        // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        vector<int>dp(20001, 0);//初始化dp数组
        sort(nums.begin(), nums.end());
        //dp数组的含义，dp[j]时，j的空间大小下，dp可以取到的最大值
        int sum = 0;//数组和
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)return false;//如果是奇数，则说明无法分成两半
        int target = sum / 2;
        for(int i=0;i<nums.size();i++)
            for (int j = target; j >= nums[i]; j--)//遍历的时候j不能小于nums[i]，如果小于，vector数组胡报错
            {//dp数组里不能放入比他小的物品
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);//放了之后，剩下的空间是要求最优解，放之前
                //还要比较放了之后和不放的值那个大
            }
        if (dp[target] == target)return true;
        else {
            return false;
        }
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,2,1,1 };
    Solution wl;
    wl.canPartition(s);

    return 0;
}