#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ans = 0;
        int next = 0;
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            next = max(nums[i] + i, next);//更新可以到达的最大距离
            if (i == c)
            {
                if (c != nums.size() - 1)
                {
                    c = next;
                    ans++;
                    if (next >= nums.size() - 1)break;
                }
                else break;

            }

        }
        return ans;
    }
};


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}