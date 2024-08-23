#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

 //Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int>result=robtree(root);//这个是根节点的值，它有两种结果，选与不选，
        //这道题目与二叉树结合，从二叉树的后续遍历开始，京题目的相邻的条件转化为了
        //有没有线相连，如果选了当前节点那么，与他相邻的根节点都不能选
        return max(result[0], result[1]);

    }
    vector<int> robtree(TreeNode* cur)
    {
        if (cur == nullptr)return vector<int>{0, 0};

        vector<int>left = robtree(cur->left);
        vector<int>right = robtree(cur->right);
        vector<int>q;

        //选择当前节点
       int temp1 = cur->val + left[0] + right[0];
        //不选当前节点
       int temp2 = max(left[0], left[1]) + max(right[0], right[1]);
       return {temp2,temp1};
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}