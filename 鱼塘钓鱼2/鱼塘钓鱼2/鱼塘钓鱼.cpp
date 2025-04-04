#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 200;
int n,t;
int ans;
int s[N], g[N], dn[N];
int r[110];//记录在当前鱼塘掉了几次
int timx;
int dfs(int u,int v,int x)//u多少时间，v钓了多少鱼，x在第几个鱼塘
{
	if (x > n&&u<t) {
		

		
		ans = max(ans, v);
		return 0;
	}
	if (u >= t && x <= n)
	{
		ans = max(ans, v);
		return 0;
	}
	if (u >= t && x > n)//
	{
		ans = max(ans, v);
		return 1;
	}
	
	for (int i = 1; i <= s[x] / g[x]; i++)
	{
		if (i > s[x] / g[x]&&x<n) {
			//跳往下一个鱼塘的判断条件
			//不在最后一个鱼塘，且在上一个鱼塘可钓鱼的时间已经耗完
			u += dn[x];
			x++;
			

		}
		v += s[x] - r[x] * g[x];//此一分钟在这个鱼塘的钓鱼数
		r[x]++;//在这个鱼塘掉过的分钟数
		u++;//总的钓鱼时间
		//先写个答辩
		u += dn[x];
		x++;
		
		if (dfs(u, v, x)) {
			return 1;

		}
		x--;
		u -= dn[x];

	}
	return 0;
}
int get(int k)//得到在当前鱼塘可得到的鱼数
{
	int q;
	q = (s[k] - g[k] * r[k]);
	if (q >= 0)
	{
		return q;
	}
	else {
		return 0;
	}

}
int work(int x,int y)//将剩下的时间分给各个鱼塘
{
	memset(r, 0, sizeof(r));//将分给各个鱼塘的时间清除
	timx = 0;
	int temp=0;
	int  w;
	if (x != y)
	{
		 w = t - dn[y];//剩下的时间
	}
	else {
		w = t;
	}
	
	if (y <= 0)
	{
		return 0;
	}
	for (int i = 1; i <= w; i++)//剩下的时间可以选几个
	{
		int a = 1;
		for (int j = 2; j <= y; j++)//找最大鱼数
		{
			if (get(a) < get(j))
			{
				a = j;//每次取最大的数
			}
		}
		temp += get(a);
		r[a]++;
	}
	return temp;
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)//第一分钟的钓鱼数量
		cin >> s[i];
	for (int i = 1; i <= n; i++)//每分钟的钓鱼减少数
		cin >> g[i];
	for (int i = 2; i <= n; i++)//到下一个鱼塘所需的时间
	{
		cin >> dn[i];
		dn[i] += dn[i - 1];
	}
	cin >> t;
	for (int i = 1; i <= n; i++)
	{
		ans=max(ans,work(1, i));//遍历1号到各个鱼塘
	}

	cout << ans << endl;
	//看了y总的思路，是将路线看作固定的，将剩下的时间分配给各个鱼塘
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m = 1;
	while (m--)
	{
		solve();
	}
	return 0;
}