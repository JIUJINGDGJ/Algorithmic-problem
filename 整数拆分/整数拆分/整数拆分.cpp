#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(60, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
            for (int j = 1; j < i - 1; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                //�ʼ�����ͨ����ѧ��������д��һЩ���ӷ���Ҫ��õ����ֵ����Ҫд��3��2�Ĳ��
                //dp�ľ�����������֮ǰ��״̬��j*dp[i-j]ȷʵд�ķǳ�������Խ���֮ǰ��״̬��Ҳ����֮ǰ�ָ�õ�
                //dp[i],ǿ
            }
        return dp[n];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}