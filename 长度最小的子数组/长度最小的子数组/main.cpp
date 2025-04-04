#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //采用快慢指针，两指针中间的部分，记录中间部分的的总和，如果达到要求就将
        //指针的位置记录，然后求出最小值
        int size = nums.size();
        int sum = 0;
        sum += nums[0];
        vector<pair<int, int>>s;
        for (int r = 0, l = 0; r <=l&&l<size;)//
        {
            
            if (sum >= target)
            {
                
                s.push_back({ r,l });
                sum -= nums[r];
                r++;
            }
            else {
               
                l++;
                if (l == size)break;
                sum += nums[l];
            }
           
        }
        if (s.size() == 0)return 0;
        int r = 0, l = 0, q=INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            int w = s[i].second - s[i].first+1;
            if (w < q)
            {
                r = s[i].first;
                l = s[i].second;
                q = w;

            }

        }
        return q;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,3,1,2,4,3 };
    Solution q;
    q.minSubArrayLen(7, s);

    return 0;
}