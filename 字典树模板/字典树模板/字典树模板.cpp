#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

//上面的是另一种解
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;//e或者E代表底数10，n代表幂值。 例如： 3e5 等价于 3乘以10的5次幂 
int son[N][27], idx = 1;
void add(string std)//插入函数
{
	int p = 0;//从第一层开始
	for (int i = 0; i < (int)std.size(); i++)//遍历整个字符串
	{
		int t = std[i] - 'a';//判断这个字符在26个字符中的位置
		if (!son[p][t])son[p][t] = idx++;//添加新的节点
		p = son[p][t];//让当前的指针指向新的节点
	}
}
int query(string std)
{
	int p = 0;
	for (int i = 0; i < std.size(); i++)
	{
		int t = std[i] - 'a';
		if (!son[p][t])return 0;//没找到
		p = son[p][t];//往下条，往下一层找
	}
	return 1;//找到了

}


int main()
{
	int t = 1;
	while (t--)
	{
		string st;
		cout << "输入字符" << endl;
		cin >> st;

		add(st);
		cout << "找到了就是返回1 " << query(st) << endl;;
	}
	return 0;
}