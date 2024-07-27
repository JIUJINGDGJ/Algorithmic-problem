#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> bracketStack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                bracketStack.push(c);
            }
            else {
                if (bracketStack.empty()) return false;

                char top = bracketStack.top();
                bracketStack.pop();

                if ((top == '(' && c != ')') ||
                    (top == '{' && c != '}') ||
                    (top == '[' && c != ']')) {
                    return false;
                }
            }
        }

        // If the stack is empty, all brackets were properly closed.
        return bracketStack.empty();
    }
};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s = "([)]";
	Solution w;
	w.isValid(s);

	return 0;
}