#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = -1, r = nums.size();
		vector<int>ans;
		if (r == 0||nums[r-1]<target)//注意这两种特殊情况，一个是空数组，另一个是元素大于数组内的全部元素
		{
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}
		
		while (l + 1 != r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] >= target)
			{
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (nums[r] == target)
		{
			ans.push_back(r);
		}
		else {
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}
		l = -1;
		r = nums.size();
		while (l + 1 != r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] > target)
			{
				r = mid;
			}
			else {
				l = mid;
			}
		}
		
			ans.push_back(l);
		
		
			return ans;
	}
};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int>nums = { 2,2 };
	Solution s;
	s.searchRange(nums, 3);
	
	return 0;
}