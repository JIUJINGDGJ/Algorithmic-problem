#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>word(wordDict.begin(), wordDict.end());//set���ϣ�ʱ�临�ӶȽӽ�1
        //�����ǽ�wordDict��������ַ�����ӽ���set������
        vector<bool>dp(s.size() + 1, false);
        dp[0] = true;//�����dp[0]û�����壬ֻ��Ϊ�˷������Ƕ������ʼ��
        for(int i=1;i<=s.size();i++)//����������
            for (int j = 0; j < i; j++)//������Ʒ��������ַ�������˳���
            {
                string w = s.substr(j, i - j);//����ʽ��ȡ�ַ���//substr(��ʼλ�ã���ȡ�ĸ���)
                if (word.find(w) != word.end() && dp[j])//����ַ������ҵ��������ܸ�ǰ����ַ�������
                {
                    dp[i] = true;//z�����Ǹ�һά����
                }
            }
        return dp[s.size()];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    return 0;
}