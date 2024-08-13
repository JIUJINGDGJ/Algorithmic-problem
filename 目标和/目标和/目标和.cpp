#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if ((sum + target) % 2 == 1)return 0;//(sum+target)/2����������
        int x = (sum + target) / 2;
        if (abs(target) > sum) return 0; // ��ʱû�з���
        vector<int>dp(x + 10, 0);//�����ʼ��Ϊx��xʽ��������
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = x; j >= nums[i]; j--)//j >= nums[i]��һ���ܹؼ��������Ŀռ������һ����Ʒ
            {
                dp[j] += dp[j - nums[i]];//���j�ռ��СҪ��һ��nums[i]��С����Ʒ����ôʣ�µĿռ��ж����з�����ǰ���Ƶ�
            }
        }
        return dp[x];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,2,1,1 };
  
    return 0;
}