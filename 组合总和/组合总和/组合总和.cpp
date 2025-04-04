#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
    void backtrack(int index,int target, vector<vector<int>>& ans,vector<int> varable,int place,vector<int>& candidates)
    {
        if (index == target) {
            ans.push_back(varable);
        }
        if (index > target)//因为是无限制选取，所以不用考虑选多少次，如何去重，2，3，7这三个数字，目标7：223，322，7
        {
            return;
        }
        if (place == candidates.size())
        {
            return;
        }
        if (target - candidates[place] < 0)return;
        for (int i = place; i < candidates.size(); i++)//每回从place开始，主要是为了去重
        {
            varable.push_back(candidates[i]);
            backtrack(index + candidates[i], target, ans, varable, i, candidates);
            varable.pop_back();//弹出刚刚压入的元素
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
       
            vector<int> varable;
            backtrack(0, target, ans, varable, 0, candidates);
        
        return ans;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>s = { 2,3,7 };
    int q = 7;
    Solution w;
    w.combinationSum(s, q);




    return 0;
}
