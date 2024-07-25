#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int index = 0;
//		if (nums.size() == 1)
//		{
//			if (target == nums[0])
//			{
//				return 0;
//			}
//			else {
//				return -1;
//			}
//		}
//		if (nums.size() == 2)
//		{
//			if (nums[0] == target )
//			{
//				return 0;
//			}
//
//			if ( nums[1] == target)
//			{
//				return 1;
//			}
//			return -1;
//		}
//		bool t = false;
//		if (nums.size() == 0)return 0;
//		for (int i = 0; i < nums.size()-1; i++)
//		{
//			if (nums[i + 1] < nums[i])
//			{
//				index = i + 1;
//				t = true;
//				break;
//			} 
//		}
//		if (t == false) {
//			if (nums[0] > target || nums[nums.size() - 1] < target)return -1;
//			int l = -1, r = nums.size();
//			
//			while (l + 1 != r)
//			{
//				int mid = (l + r) / 2;
//				if (nums[mid] >= target)
//				{
//					r = mid;
//				}
//				else {
//					l = mid;
//				}
//			}
//			if (nums[r] == target)
//			{
//				return r;
//			}
//			else {
//				return -1;
//			}
//		}
//		//if (nums[0] > target && nums[nums.size() - 1] < target)return -1;
//		if (nums[index - 1] >= target&&nums[0]<=target)
//		{
//			
//			int l = -1, r = index;
//			while (l + 1 != r)
//			{
//				int mid = (l + r)/2;
//				if (nums[mid] >= target)
//				{
//					r = mid;
//				}
//				else {
//					l = mid;
//				}
//			}
//			if (nums[r] == target)
//			{
//				return r;
//			}
//		}
//		
//			int l = index - 1, r = nums.size();
//			while (l + 1 != r)
//			{
//				int mid = (l + r)/2;
//				if (nums[mid] >= target)
//				{
//					r = mid;
//				}
//				else {
//					l = mid;
//				}
//			}
//			if (nums[r] == target)
//			{
//				return r;
//			}
//		
//		
//		
//		return -1;
//	}
//};
class Solution {
public:
	int search(vector<int>& nums, int target) {
				if (nums.size() == 1)
		{
			if (target == nums[0])
			{
				return 0;
			}
			else {
				return -1;
			}
		}
		if (nums.size() == 2)
		{
			if (nums[0] == target )
			{
				return 0;
			}

			if ( nums[1] == target)
			{
				return 1;
			}
			return -1;
		}
		int l = -1, r = nums.size();//为什么要加上面的这一段，因为当数组太小的时候l+1！=r这个判断条件就失灵了
		/*   int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]){
                l = mid;
            }
            else r = mid - 1;
        }
		//要改成这样，说明这个方法对于太小的数组来说是有问题的，要是用传统的二分法
。*/
		while (l + 1 != r)
		{
			int mid = (l + r) / 2;//用来判断这一段是不是全部大于nums[0],如果是，
			//这里利用了二分法的两端性，二分法不止针对数字，也可以针对两端不同的数字
			if (nums[mid] >= nums[0])//找到旋转点
			{
				l = mid;
			}
			else {
				r = mid;
			}
		}
			if (target >= nums[0])
			{
				l = -1;
			}
			else {
				l = l;
				r = nums.size();

			}
			while (l + 1 != r)
			{
				int mid = (l + r) / 2;//用来判断这一段是不是全部大于nums[0],如果是，
				//这里利用了二分法的两端性，二分法不止针对数字，也可以针对两端不同的数字
				if (nums[mid] >= target)//找到旋转点
				{
					r = mid;
				}
				else {
					l = mid;
				}
			}
			return (nums[r] == target ? r : -1);

		
	}
};

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int>nums = { 1,3,5 };
	Solution s;
	s.search(nums, 1);
	return 0;
}