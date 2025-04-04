#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
//#include<bits/stdc++.h>
//using namespace std;
//queue<int> q1;//这个是我们使用的辅助队列
//queue<int> q2;//这个是我们使用的辅助队列
//const int maxn = 1e5 + 5;
//int dis[maxn];//记录走了多少步
//int ais[maxn];//记录走了多少步
//void bfs( int n, int m, int s1, int s2, int d)
//{
//	int x, y;
//	int a1=1, a2=1;
//	while (!q1.empty())
//	{
//		q1.pop();
//	}
//	while (!q2.empty())
//	{
//		q2.pop();
//	}
//	memset(dis, 0x5a5b5c4f, sizeof(dis));//初值设为inf，省去一个vis数组的空间
//	memset(ais, 0x5a5b5c4f, sizeof(dis));//初值设为inf，省去一个vis数组的空间 
//
//	dis[1] = 0;
//	ais[1] = 0;
//	q1.push(1);
//	q2.push(1);
// 	while (!q1.empty() || !q2.empty())
//	{
//		if (a1 == 1)
//		{
//			x = q1.front();//如果不能保证会有新的x变量加入队列的话，会报错
//			q1.pop();//弹出队首变量，表明这个值进入了下面的判断
//		}
//		a1 = 0;
//		if (a2 == 1)
//		{
//			y = q2.front();
//			q2.pop();
//		}
//		a2 = 0;
//		
//		if (x == n && y == m)
//		{
//			int c;
//			c = dis[x] + ais[y];
//			cout <<c<< endl;
//			return;
//		}
//		if (x + 1 <= n && dis[x + 1] == dis[0] && abs((x + 1) - s1)>d&&abs(y-s2)>d)
//		{
//			dis[x + 1] = dis[x] + 1, q1.push(x+1);
//			a1 = 1;
//		}
//		else {
//			if (y + 1 <= m && dis[y + 1] == dis[0] && abs(x - s1) > d && abs((y + 1) - s2) > d)
//			{
//				dis[y + 1] = dis[y] + 1, q2.push(y + 1);
//				a2 = 1;
//			}
//		}
//		
//		if (x - 1 <= n && dis[x - 1] == dis[0] && abs((x - 1) - s1) && abs(y - s2) > d)
//		{
//			dis[x - 1] = dis[x] + 1, q1.push(x - 1);
//			a1 = 1;
//		}
//		else {
//			if (y - 1 <= m && dis[y - 1] == dis[0] && abs(x - s1) > d && abs((y - 1) - s2) > d)
//			{
//				dis[y - 1] = dis[y] + 1, q2.push(y - 1);
//				a2 = 1;
//			}
//		}
//		
//	}
//
//
//}
//int main()
//{
//	int t,n, m, s1, s2, d;
//	cin >> t;
//
//	while (t--)
//	{
//		cin >> n >> m >> s1 >> s2 >> d;
//		if (s1 != 1 && s2 != 1 && (abs(s1 - 1) + abs(s2 - 1) - d > 0))
//		{
//			cout << -1 << endl;
//		}
//		else {
//			
//
//			bfs(n, m, s1, s2, d);
//		}
//	}
//	
//
//
//	return 0;
//}
/*上面是失败的方案，正确的解题思路，x先增长到n，y先增长到m，
 如果采用广度搜索，会有路程折返的情况，并且，很容易让机器人折返进入死胡同*/
#include<bits/stdc++.h>
using namespace std;
int t;
int cal(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		int n, m, sx, sy, d;
		scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &d);
		if
			(
				cal(sx, sy, n, m) <= d ||
				(sx - d <= 1 && sx + d >= n) ||
				(sy - d <= 1 && sy + d >= m) ||
				(sx - d <= 1 && sy - d <= 1) ||
				(sx + d >= n && sy + d >= m)
				)
			printf("-1\n");
		else printf("%d\n", n + m - 2);
	}
	return 0;
}
/*考虑挖掘题目特殊性质，发现只有五种情况会输出 −1−1，否则输出图上最短路，即 �+�−2n+m−2。
五种情况分别为：
1.	不能走的区域覆盖 (�,�)(n,m)。
2.	不能走的区域覆盖 (1,1)(1,1)。
3.	不能走的区域覆盖完整的，且在第 �n 行前的某一行。
4.	不能走的区域覆盖完整的，且在第 �m 列前的某一列。
5.	不能走的区域覆盖完整地图。
按

*/