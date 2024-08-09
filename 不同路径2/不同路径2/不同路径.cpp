#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int  uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 1 && n == 1)
        {
            if (obstacleGrid[0][0] == 1)return 0;
            else {
                return 1;
            }
        }
        if (obstacleGrid[0][0] == 1)return 0;
        if (obstacleGrid[1][0] == 1 && obstacleGrid[0][1] == 1)return 0;
        if (m == 1 && obstacleGrid[0][1] == 1)return 0;
        vector<vector<int>>map(120, vector<int>(120, 0));
        map[1][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)continue;
                map[i][j] += map[i - 1][j] + map[i][j - 1];
            }
        return map[m][n];
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}