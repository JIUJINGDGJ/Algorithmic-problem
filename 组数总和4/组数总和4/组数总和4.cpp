#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target + 2, 0);
        dp[0] = 1;//dp[0]�����壬ֻ��Ϊ�˷����Ƶ�
        for(int i=0;i<=target;i++)
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0&& dp[i] < INT_MAX - dp[i - nums[j]])
                {//C++������������������ӳ���int�����ݣ�������Ҫ��if�����dp[i] < INT_MAX - dp[i - num]
                    dp[i] += dp[i - nums[j]];
                }
            }
        return dp[target];
    }
};

/*���ԭ��
�� dp[i] �Ѿ��ǳ��ӽ� INT_MAX���� dp[i - nums[j]] ����һ���ϴ������ʱ����������ӿ��ܻᵼ�½������ INT_MAX���Ӷ��������������
��������ķ�����
�ڽ����ۼӲ���ǰ��ͨ���Ƚ� dp[i] �� INT_MAX - dp[i - nums[j]] ���ж��Ƿ�ᳬ����Χ��
��� dp[i] ���� dp[i - nums[j]] ���ᵼ���������ִ���ۼӲ�����������������ۼӡ�*/
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,2,1,1 };

    return 0;
}