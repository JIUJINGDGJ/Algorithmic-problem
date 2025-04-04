#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int sign = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                sign++;
                for (int j = i + 1; j < size; j++)
                {
                    
                    nums[j - 1] = nums[j];
                    
                }
              /*  for (auto s : nums)
                {
                    cout << s << " " ;
                }
                cout << "结束" << endl;*/
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
            
            
        }
        return size;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 0,1,2,2,3,0,4,2 };
    Solution q;
    q.removeElement(s, 2);
  
    return 0;
}