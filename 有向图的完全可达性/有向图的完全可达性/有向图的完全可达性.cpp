#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin >> n>>k;
	vector<vector<int>>map(n + 1, vector<int>(n + 1, 0));//地图，标记为1的地方就是有连接
	vector<int>sign(n + 1, 0);//标记数组
	for (int i = 1; i <= k; i++)//有多少条边，输入取决与这个
	{
		int s, t;
		cin >> s >> t;
		map[s][t]=1;//这里是将左边的行作为出发点
	}

	queue<int>q;
	q.push(1);
	sign[1] = 1;//
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[t][i] && !sign[i])
			{
				q.push(i);//加入队列
				sign[i] = 1;//标记为走过
			}
		}
	}
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		if (sign[i] == 0)
		{
			result = -1;
			break;
		}
	}
	cout << result << endl;
	return 0;
}