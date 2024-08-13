#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //�Բۣ���ô��ô���������˺ܶ���ѡȡʯͷ�ķ�������������Ĺؼ�����ʯͷ��ѡ��
        //��ʮ�������ѡȡʯͷ�������ǵĲ�ֵ��С���ߵ���0
        vector<int> dp(15001, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) sum += stones[i];
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) { // ������Ʒ
            for (int j = target; j >= stones[i]; j--) { // ��������
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
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