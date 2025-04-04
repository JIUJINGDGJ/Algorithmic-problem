#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 100000;
int n, k;
int s1[N],w[N];
int temp,temp1;
int t;//指向最小值
void solve()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s1[i];
	}
	
	while (k--)
	{
		for (int i = 0; i < n; i++)//将t指向第一个没有访问过的点
		{
			if (!w[i])
			{
				t = i;
				temp = s1[i];
				break;
			}
		}
		for (int i = 0; i < n ; i++)//找循环的最小值
		{
			
			if (s1[t]>s1[i] && !w[i])//没有访问过，且前面的比后面的大
			{
				t = i;
				temp = s1[i];
			}
		}
		w[t]++;//标记访问过了
		for (int i = t+1; i < n ; i++)//既然是第一个大于t的数，那么我们就可以访问到终点n-1
		{
			if (!w[i]&&i>t)//第一个在右边的点且没有访问过
			{
				s1[i] += temp;//不出界，且没有访问过
				break;
			}
		}
		
		for (int i = t - 1; i >= 0; i--)
		{
			if (!w[i] && i < t)//第一个在t左边的点，且没有访问过
			{
				s1[i] += temp;
				break;
			}
		}
		
			
		

	}
	
	for (int i = 0; i < n; i++)
	{
		if (!w[i])//没有访问过的点
		{
			cout << s1[i]<<" ";
		}
	}


}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}
