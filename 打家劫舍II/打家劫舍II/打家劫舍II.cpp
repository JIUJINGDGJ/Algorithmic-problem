#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() + 1, 0);
        int n = nums.size();
        if (n == 3||n==2||n==1)
        {
            int m = -1;
            for (int i = 0; i < n; i++)
            {
                m = max(m, nums[i]);
            }
            return m;
        }
        vector<bool>sign(nums.size() + 1, false);
        dp[0] = nums[0];
        sign[0] = true;
        dp[1] = max(nums[0], nums[1]);
        if (dp[1] == nums[0])sign[1] = true;
        if (nums[0] == nums[1])sign[1] = false;
        int q = sign[1];
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            if (dp[i] == dp[i - 1])sign[i] = sign[i - 1];
            else {
                sign[i] = sign[i - 2];
            }
       }
        if (dp[n - 1] == dp[n - 3] + nums[n - 1])
        {
            if (sign[n - 3])
            {
                dp[n - 1] = dp[n - 2];
            }
      }
        return dp[nums.size() - 1];
    }
};
// ע��ע���е��������������Լ���198.��ҽ���Ĵ�����������
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2); // �����
        int result2 = robRange(nums, 1, nums.size() - 1); // �����
        return max(result1, result2);
    }//�������д��ʱ���ҷ���һ���������û��ȫ�г�������˼���ĵ�����Ԫ�ر�ѡ������£�βԪ��
    //ѡ�벻ѡ�����⣬����û����βԪ�ر�ѡ
    // ��ô�죬��ͼ�����뵽��һ���йصģ���ȥ�ù��Ľ���취��������ô����������˼�����ж�
    // 198.��ҽ�����߼�
    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 1,1,1,2 };
    Solution w;
    w.rob(s);
    return 0;
}