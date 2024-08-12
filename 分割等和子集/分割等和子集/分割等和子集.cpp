#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>copy(nums.size(),0);//ֱ�Ӹ���
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
        //�����Ĺؼ�ʽ���ڽ����ָ�����ת��Ϊ���������ϵĺ�Ϊ
        //����͵�һ�룬
         // dp[i]�е�i��ʾ�������ܺ�
        // ��Ŀ��˵��ÿ�������е�Ԫ�ز��ᳬ�� 100������Ĵ�С���ᳬ�� 200
        // �ܺͲ������20000���������ֻ��Ҫ����һ�룬����10001��С�Ϳ�����
        vector<int>dp(20001, 0);//��ʼ��dp����
        sort(nums.begin(), nums.end());
        //dp����ĺ��壬dp[j]ʱ��j�Ŀռ��С�£�dp����ȡ�������ֵ
        int sum = 0;//�����
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)return false;//�������������˵���޷��ֳ�����
        int target = sum / 2;
        for(int i=0;i<nums.size();i++)
            for (int j = target; j >= nums[i]; j--)//������ʱ��j����С��nums[i]�����С�ڣ�vector���������
            {//dp�����ﲻ�ܷ������С����Ʒ
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);//����֮��ʣ�µĿռ���Ҫ�����Ž⣬��֮ǰ
                //��Ҫ�ȽϷ���֮��Ͳ��ŵ�ֵ�Ǹ���
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