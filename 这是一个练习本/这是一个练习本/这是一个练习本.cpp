#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<stdio.h>
#include<bits/stdc++.h>
#include <fstream>      // for file I/O
using namespace std;
typedef unsigned char *byte;

int main(void)
{
    using namespace std;
    string chest;
    cout << "输入胸围" << endl;
    cin >> chest;
    ofstream outfile;//创建一个输入对象
    outfile.open("text2.txt");//卧槽，原来是没加“”会输入到这里
    outfile << "美少女" << chest << endl;//输入
    return 0;
}