#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int>ans(50, 0);

        ans[1] = 1;
        ans[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        return ans[n];

    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}