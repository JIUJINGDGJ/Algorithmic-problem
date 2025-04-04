#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;

void reversal(string& s, int start, int end)
{
	for (; start < end; start++, end--)
	{
		swap(s[start], s[end]);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//这道题目感觉很简单，在创建一个新的字符串，然后将后k位压入，接着压入0到size-1-k
	int k;
	string s;
	cin >> k;
	cin >> s;
	
	//第二解题方法
	//先整体反转，然后再局部反转
	reversal(s, 0, s.size() - 1);
	reversal(s, 0, k - 1);
	reversal(s, k , s.size() - 1);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	return 0;
}