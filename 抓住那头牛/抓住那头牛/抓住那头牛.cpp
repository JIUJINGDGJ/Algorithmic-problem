#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;
queue<int> q;//这个是我们使用的辅助队列
const int maxn = 1e5 + 5;
int dis[maxn];//记录走了多少步
void bfs(int s, int y)
{
	int x;
	while (!q.empty())//清空队列操作，q.empty()返回是否为空
	{
		q.pop();//弹出队尾元素，
	}
	memset(dis, 0x5a5b5c4f, sizeof(dis));//初值设为inf，省去一个vis数组的空间 
	//这一步是给数组里的数据进行最小变量（我也不清楚），
	//inf是一个集合里的最小变量
	dis[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		if (x == y)
		{
			cout << dis[y] << endl;
			return;
		}
		if (x + 1 <= maxn && dis[x + 1] == dis[0])//dis[x + 1] == dis[0],dis[0]里是最小值，这一步是用来判断是否走过这一点，这个图里可能有闭环
		{                                         //x+1<maxn，是为了防止数据出轨
			dis[x + 1] = dis[x] + 1, q.push(x + 1);//dis[x + 1] = dis[x] + 1, q.push(x + 1);等效于
			                                       /*dis[x + 1] = dis[x] + 1；
			                                        q.push(x + 1); */
		}
		if (x - 1 > 0 && dis[x - 1] == dis[0])////x-1>0 比较显然吧，如果小于0你会RE，如果等于0你的dis[0]就会被更新，你整个程序就会崩掉 
		{
			dis[x - 1] = dis[x] + 1, q.push(x - 1);
		}
		if (x * 2 <= maxn && dis[x * 2] == dis[0])
		{
			dis[x * 2] = dis[x] + 1, q.push(x * 2);
		}
	}
}
int main()
{
	int t, x, y;
	cin >> t;
	
	while (t--)
	{
		cin >> x >> y;
		bfs(x, y);
	}
	return 0;
}
//memset(str,'$',7);(str,"This is string.h library function"）
/*strcpy(str, "This is string.h library function");
puts(str);
memset(str, '$', 7);
puts(str);
让我们编译并运行上面的程序，这将产生以下结果：

This is string.h library function
$$$$$$$ string.h library function*/
//memset是个赋值函数
//pust是个输出函数，输出直到空字符，但不包括空字符。换行符会被追加到输出中。
//strcpy是个拷贝字符串的函数


/*strcpy(str1, "RUNOOB1");
strcpy(str2, "RUNOOB2");
puts(str1);
puts(str2);

让我们编译并运行上面的程序，这将产生以下结果：
RUNOOB1
RUNOOB2
*/