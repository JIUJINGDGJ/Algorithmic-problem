#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 30000;
const int N1 = 1e6 + 10;
typedef pair<int, float>pii;
int n, m;
pii g[N];
//float s[]
set<float>v;


//求最简分数，分子和分母的最大公约数是1，分数的比较，将两个分数乘上他们的公约数
int check(int a, int b)//返回最小公约数
{
	return b ? check(b, a % b) : a;
}


bool cmp(pii a,pii b)//的到x到1的所有小数
{
	return a.first * b.second > a.second* b.first;
}
void solve()
{
	cin >> n;
	for (int i = 1; i <=n; i++)//遍历分母
	{
		for (int j = 0; j <= i; j++)//遍历分子
		{
			if (check(i, j) == 1)
			{
				g[m++] = { i,j };//传入最简分数
			}
		}
	}

	sort(g, g + m, cmp);
	//cout <<"0/1" << endl;
	for (int i = 0; i <m; i++)
	{
		cout << g[i].second << "/" << g[i].first<< endl;
	}

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}