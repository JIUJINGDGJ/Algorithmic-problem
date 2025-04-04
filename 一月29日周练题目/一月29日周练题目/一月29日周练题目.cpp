#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;
/*vector<char>*/
char a[200][200];
int t;
//void sovle() {
//int n, m; cin >> n >> m;
//for (int i = 1; i <= n; i++) {
//	for (int j = 1; j <= m; j++) {
//		cin >> arr[i][j];
//	}
//}
//string s = "vika";
//int cnt = 0;
//for (int i = 1; i <= m; i++) {
//	for (int j = 1; j <= n; j++) {
//		if (arr[j][i] == s[cnt]) {
//			cnt++; break;
//		}
//	}
//}
//if (cnt == 4)cout << "YES" << endl;
//else cout << "NO" << endl;
//}
int solve()
{
	//int n, m;
	int ans=0;
	
	int n, m;
	cin >> n >> m;
	
	vector<string> an(n);
	for (auto& i : an) cin >> i;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			

		}
	}
	for (int i = 1; i <= an.size(); i++)
	{
		cout << an[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];


		}
	}
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		//char x= a[i][j];
	//		if (a[i][j] == 'v' && ans == 0)
	//		{
	//			ans += 1;
	//			break;
	//		}
	//		else {
	//			if (a[i][j] == 'i' && ans == 1)
	//			{
	//				ans += 1;
	//				//break;
	//			}
	//			else {
	//				if (a[i][j] == 'k' && ans == 2)
	//				{
	//					ans += 1;
	//					break;
	//				}
	//				else {
	//					if (a[i][j] == 'a' && ans == 3)
	//					{
	//						ans += 1;
	//						break;
	//					}
	//				}
	//			}

	//		}

	//	}
	//}
	//
	//if (ans == 4)cout << "YES" << endl;
	//else {
	//	cout<<"NO" << endl;
	//}
	//return 0;
}
signed main()
{
	cin >> t;
	while (t--)
	{
		
		solve();
	}
	
}
