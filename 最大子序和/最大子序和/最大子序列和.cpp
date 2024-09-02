#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size() + 1, 0);
        //���鶨�壬0��i��dp[i]����ȡ�������ֵ
        int result = 0;
        if (nums.size() == 1)return nums[0];
       dp[0] = nums[0],result=nums[0];
       //dp[0],����dp����Ķ��壬��Ϊ�˷��������Ƶ������Ƕ���Ϊnums[0]
       //��������0��������ȫ�Ǹ��������߼��������
        for (int i = 1; i < nums.size(); i++)
        {
            //if (nums[i] > 0)dp[i] = dp[i - 1] + nums[i];
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            //dp[i]���������������˳�����dp[i - 1] + nums[i]��nums[i]������ͷ��ʼ���㵱ǰ���������к�
                
                if (dp[i] > result)result = dp[i];
            
        }
        return result;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     vector<int>w = { -2,1,-3,4,-1,2,1,-5,4 };
     Solution s;
     s.maxSubArray(w);
    return 0;
}