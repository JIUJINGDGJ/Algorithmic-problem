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
private: int ans=0;
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr)return 0;

		dfs(root, 0);
		return ans;
	}
	void dfs(TreeNode* cur,int sign)
	{
		if (cur->left == nullptr && cur->right == nullptr&&sign==1)
		{
			ans += cur->val;
		}
		if (cur->left)
		{
			dfs(cur->left, 1);
		}
		if (cur->right)
		{
			dfs(cur->right, 0);
		}
		//if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {也可以通过这样来判断，判断父节点
		//也可以吧左右子节点看作左右树来处理
		
	}
};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}