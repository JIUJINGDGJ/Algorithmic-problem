#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)return 0;
        vector<vector<int>>map(120, vector<int>(120, 0));
        map[1][2] = 1;
        map[2][1] = 1;
        for(int i=1;i<=m;i++)
            for (int j = 1; j <= n; j++)
            {
                map[i][j] += map[i - 1][j] + map[i][j - 1];
            }
        return map[m][n];
    }
};
class Solution {//dfs版
private:
    int dfs(int i, int j, int m, int n) {
        if (i > m || j > n) return 0; // 越界了
        if (i == m && j == n) return 1; // 找到一种方法，相当于找到了叶子节点
        return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
    }
public:
    int uniquePaths(int m, int n) {
        return dfs(1, 1, m, n);
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}