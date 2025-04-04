#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}

};
class Solution {
public:
	bool isAnagram(string s, string t) {
		int record[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			record[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++)
		{
			record[t[i] - 'a']--;
		}
		for (int i = 0; i < 25; i++)
		{
			if (record[i] != 0)
			{
				return false;
			}
		}
		return true;
	}
};
signed main()
{

	return 0;
}
