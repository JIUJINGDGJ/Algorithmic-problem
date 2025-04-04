#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result(nums.size());
        //双指针风骚起来也是无敌
        int i = 0, j = nums.size() - 1;
        int index = j;
        while (i <= j)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                result[index] = nums[i] * nums[i];
                index--;
                i++;
            }
            else {
                result[index] = nums[j] * nums[j];
                index--;
                j--;
            }
        }
        return result;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { -4,-1,0,3,10 };
    Solution q;
    q.sortedSquares(s);

    return 0;
}