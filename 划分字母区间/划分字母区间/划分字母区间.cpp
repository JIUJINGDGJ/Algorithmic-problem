#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int place[27] = { 0 };//全部定义为0
        for (int i = 0; i < s.size(); i++)
        {
            place[s[i] - 'a'] = i;
        }
        vector<int>res;
        int right=0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, place[s[i]-'a']);//标记字符最远出现边界
            if (i == right)
            {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}