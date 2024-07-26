#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {

		int n = nums.size();
		if (n == 1)return nums[0];
		if (n == 2)
		{
			return nums[0] > nums[1] ?  nums[1] :  nums[0];
		}
		
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (nums[mid] > nums[0])
			{
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		if (l == n - 1)
		{
			return nums[0];
		}
		else {
			return nums[l+1];
		}
		//cout << nums[l] << nums[r];
		//return l;
	}
};
class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (nums[l] <= nums[mid]) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		return r + 1 < nums.size() ? nums[r + 1] : nums[0];//更为精简的解法
	}
};


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int>nums = {3,1 };//3,4,5,1,2
	Solution s;
	s.findMin(nums);
	return 0;
}