#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*>q;
		//if(root==nullptr)return 
		q.push(root);
		int result = 0;
		while (!q.empty())
		{
			int size = q.size();
			vector<TreeNode*> vec;
			
			for (int i = 1; i <= size; i++)
			{
				TreeNode* s = q.front();
				q.pop();
				if (i == 1) result = s->val; // 记录最后一行第一个元素
				if (s->left)q.push(s->left);
				if (s->right)q.push(s->right);

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

	return 0;
}