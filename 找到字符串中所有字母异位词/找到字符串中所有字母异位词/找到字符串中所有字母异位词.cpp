#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int x = s.size();
		int y = p.size();
		vector<int>w(256, 0);//统计数组，统计窗口内的元素出现了多少次
		vector<int>m(256, 0);//统计窗口内的元素出现了多少次
		vector<int>res;

		if (x > y)
		{
			for (int i = 0; i < y; i++)
			{
				int q = p[i];
				w[q]++;
			}
			int ans = 0;
			for (int l = 0, r = 0; r < x;)
			{
				
				m[s[r]]++;
				if (m[s[r]] == w[s[r]])ans+=w[s[r]];
				while ((r - l + 1) > p.size())
				{
					if (m[s[l]] == w[s[l]])
					{
						ans-=w[s[l]];
					}
					m[s[l]]--;

					l++;
				}
				r++;
				if (ans == y)
				{
					res.push_back(l);
				}



			}




		}
		else {
			if (x < y)
			{
				for (int i = 0; i < x; i++)
				{
					int q = s[i];
					w[q]++;
				}
				int ans = 0;
				for (int l = 0, r = 0; r < y;)
				{

					m[p[r]]++;
					if (m[p[r]] == w[p[r]])ans+w[p[r]];
					while ((r - l + 1) > x)
					{
						if (m[p[l]] == w[p[l]])
						{
							ans- w[p[r]];
						}
						m[p[l]]--;

						l++;
					}
					r++;
					if (ans == x)
					{
						res.push_back(l);
					}
				}
			}
			
		}
		if (x == y)
		{
			for (int i = 0; i < x; i++)
			{
				int q = p[i];
				w[q]++;
			}
			for (int i = 0; i < x; i++)
			{
				m[s[i]]++;

			}
			int t = 0;
			for (int i = 0; i < x; i++)
			{
				if (w[s[i]] != m[s[i]])
				{
					t = 1;
				}
			}
			
			if (t != 1)
			{
				res.push_back(0);
			}
		}

		/*for (auto i : res)
		{
			cout << i << " ";
		}*/

		return res;
	}
};

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1 = "ababababab";
	string s2 = "aab";
	Solution s;
	s.findAnagrams(s1, s2);

	return 0;
}