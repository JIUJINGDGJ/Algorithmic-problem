#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;
int num[20][20];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		num[i][0]=1;
	}
	num[0][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			num[j][i - j] = num[j - 1][i-j] + num[j + 1][i - j - 1];
			
		}
		num[0][i] = num[1][i - 1];
	}
	cout << num[0][n] << endl;
	return 0;
}
/*本题主要考察数学知识，递归思想，说白了就是往后推，推导出
规律，还可以用深度优先搜索dfs*/
/*
栈和队的区别，栈只有一个进出口，而队前后都可以进出*/