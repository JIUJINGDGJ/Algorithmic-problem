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
	int n = 0;
	string beginStr, endStr, str;
	unordered_set<string> strSet;//这个集合用来存放str字符串
	cin >> n;
	cin >> beginStr >> endStr;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		strSet.insert(str);
	}
	//因为是无向图，为了防止死循环。所以添加访问标记
	unordered_map<string, int>visitMap;//这个映射是用来反应寻找到这个字符串走了多少条路径
	 
	queue<string>q;
	q.push(beginStr);//
	visitMap.insert(pair<string, int>(beginStr, 1));//初始化map映射，为什么设为1，还有待商榷
	while (!q.empty())
	{
		string word = q.front();
		q.pop();
		int path = visitMap[word]; // 这个字符串在路径中的长度
		//这里说是广度优先访问，，最先到达的即为最短路径，头一次见到这种题目

		for (int i = 0; i < word.size(); i++)
		{
			string newWord = word;
			for (int j = 0; j < 26; j++)
			{
				newWord[i] = j + 'a';
				if (newWord == endStr)
				{
					cout << path + 1 << endl;
					return 0;
				}
				//字符集合里有，并且没有访问过
				if (strSet.find(newWord) != strSet.end() && visitMap.find(newWord) == visitMap.end())
				{
					visitMap.insert(pair<string, int>(newWord, path + 1));//标记为访问过
					q.push(newWord);
				}

			}
		}
	}

	cout << "0" << endl;


	return 0;
}