#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);//dp���鶨�壬nums[0]��nums[i]������ĵ���������
        dp[0] = 1;
        //�����岿�����ÿһ����dp���壬�ݹ鹫ʽ��dp�ĳ�ʼ��������˳�򣬴�ӡdp����
        int result = 1;//�������������е����ֵ
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                //cout << "i=" << i << " " << "j=" << j << endl;
               // cout << "nums[i]" << nums[i] << " " << "nums[j]" << nums[j] << endl;
                //cout <<"����֮ǰ" << "dp[i]=" << dp[i] << " " << "dp[j]+1=" << dp[j] << endl;
                if (nums[i] > nums[j])dp[i] = max(dp[i], dp[j] + 1);
                //����жϾ��Ǻ�����䣬������0-j��ѡȡ������ĵ���������
                //cout <<"����֮��" << "dp[i]=" << dp[i] << " " << "dp[j]+1=" << dp[j] << endl;
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