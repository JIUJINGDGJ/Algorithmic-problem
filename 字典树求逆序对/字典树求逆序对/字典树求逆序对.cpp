#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
const int N = 3e7+ 10, M = 3e7 + 10;//如果测试点报紫色的话就把这两个常量开大点
using namespace std;
typedef long long ll;
int son[N][2], idx = 1;
ll cnt[M];
void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int t = (x >> i) & 1;
		if (!son[p][t])son[p][t] = idx++;
		p = son[p][t];
		cnt[p]++;
	}
}
ll query(int x)
{
	int p = 0;
	ll ans=0;
	for (int i = 30; i >= 0; i--)
	{
		int t = (x >> i) & 1;
		if (t==0)//如果右边的分支不是空，因为右枝大于左边的树枝，所以将右边的所有分支相加
		{
			ans += cnt[son[p][1]];
		}
		p = son[p][t];
		
	}
	return ans;
}

int main()
{
	int n, m;
	ll an = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		
		cin >> m;
		insert(m);
        an += query(m);
		
	}

	cout << an << endl;
	return 0;
}
