#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        //这题的思路不好象，如何抽象为，单调栈思路，如何观察出我们用每个矩形的高位基准线去求其中的最大值

        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        //修改：这里是递减栈，我们求，两边第一个比他小的矩形,从而求出宽
        int result = 0;

        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[i] >= heights[st.top()])
            {
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()])
                {
                    int mid = st.top();//取出栈顶元素
                    st.pop();
                    if (!st.empty())
                    {
                        int right = i;
                        int left = st.top();
                        int w = right - left - 1;
                        int s = w * heights[mid];
                        result = max(result, s);
                    }
                }
                st.push(i);
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
    //vector<int>s2 = { 1,3,4,2 };
    vector<int>s1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    //////string w = "bbbab";
    //Solution s;
    //s.trap(s1);
    return 0;
}