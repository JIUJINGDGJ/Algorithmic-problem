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
		int l = -1, r = nums.size();//ΪʲôҪ���������һ�Σ���Ϊ������̫С��ʱ��l+1��=r����ж�������ʧ����
		/*   int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]){
                l = mid;
            }
            else r = mid - 1;
        }
		//Ҫ�ĳ�������˵�������������̫С��������˵��������ģ�Ҫ���ô�ͳ�Ķ��ַ�
��*/
		while (l + 1 != r)
		{
			int mid = (l + r) / 2;//�����ж���һ���ǲ���ȫ������nums[0],����ǣ�
			//���������˶��ַ��������ԣ����ַ���ֹ������֣�Ҳ����������˲�ͬ������
			if (nums[mid] >= nums[0])//�ҵ���ת��
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
				int mid = (l + r) / 2;//�����ж���һ���ǲ���ȫ������nums[0],����ǣ�
				//���������˶��ַ��������ԣ����ַ���ֹ������֣�Ҳ����������˲�ͬ������
				if (nums[mid] >= target)//�ҵ���ת��
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