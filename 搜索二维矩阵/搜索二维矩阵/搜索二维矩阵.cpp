#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int line = matrix.size();
		int row = matrix[0].size();
		int t = 0;
		if (matrix[line - 1][row - 1]<target) {
			return false;
		}
		for (int i = 0; i < line; i++)
		{
			if (matrix[i][row - 1] >= target)
			{
				t = i;
				break;
			}
		}
		int l = -1, r = row;
		while (l + 1 != r)
		{
			int mid = (l + r) / 2;
			if (matrix[t][mid] >= target)
			{
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (matrix[t][r] == target)
		{
			return true;
		}
		return false;


	}
};

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	std::vector<std::vector<int>> matrix = {
	   {1, 3, 5, 7},
	   {10, 11, 16, 20},
	   {23, 30, 34, 60}
	};
	std::vector<std::vector<int>> m = {
   {1},
   {3},
   
	};
	Solution s;

	s.searchMatrix(m, 3);
	return 0;
}