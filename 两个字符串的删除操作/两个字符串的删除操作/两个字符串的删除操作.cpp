#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1));
        //dp����Ķ���ʽ������Сɾ��Ԫ�ظ��������ǵ�ǰ����������dp[i][j]�����ɾ����ǰԪ��
        //��Ҫ�̳�ǰһ��״̬��dp[i-1][j],����ǰһ��״̬��dp[i-1][j]�������Ѿ��������״̬
        //��������Ϊ�еĵ�s[i-1]��Ԫ��
        if (word1.size() == 1 && word2.size() == 1)
        {
            if (word1[0] != word2[0])
            {
                return 2;
            }
            else {
                return 0;
            }
        }
        for (int i = 1; i <= word1.size(); i++)dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++)dp[0][j] = j;
        for(int i=1;i<=word1.size();i++)
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
                    //����ļ�һ�ʹ���������ǰԪ�أ�Ҳ����ɾ����ǰԪ��
                }
            }
        return dp[word1.size()][word2.size()];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* vector<int>w = { -2,1,-3,4,-1,2,1,-5,4 };
     Solution s;
     s.maxSubArray(w);*/
    return 0;
}