#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
private:bool cmp(int x, int y)
{
    return x > y;
}
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),cmp);
       
        return  nums[nums.size()-k];
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

private:
    int quickSelect(vector<int>& nums, int k) {
        // 随机选择基准数
        int pivot = nums[rand() % nums.size()];
        // 将大于、小于、等于 pivot 的元素划分至 big, small, equal 中
        vector<int> big, equal, small;
        for (int num : nums) {
            if (num > pivot)
                big.push_back(num);
            else if (num < pivot)
                small.push_back(num);
            else
                equal.push_back(num);
        }
        if (k <= big.size())
        {
            return quickSelect(big, k);

        }
        if (nums.size() - small.size() < k)
        {
            return quickSelect(small, k - (big.size() + equal.size()));
        }
        return pivot;
    }
};

        
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 3,2,1,5,6,4 };
    Solution nom;
    nom.findKthLargest(s, 2);
    return 0;
}