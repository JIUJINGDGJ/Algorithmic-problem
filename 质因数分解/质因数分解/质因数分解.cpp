#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <iostream>
#include<string>
using namespace std;
/*如何跳出for循环，如何判断质数。质数从2开始，2是最小的质数，%是取余数
/是去商，还有认真读题
*/
int main()
{
	int figure = 0,j=0,i=2;
	int max = 0;
	
	cin >> figure;
	for (; i <= figure / 2; i++)
	{
		if (figure % i == 0)//判断是不是因数
		{
			j = figure / i;
			if (i > j)
			{
				max = i;
			}
			else {
				max = j;
			}
			cout << max << endl;

			break;
		}
	}
	

	system("pause");
	return 0;

}
