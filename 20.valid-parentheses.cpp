/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
	stack<char> st;
public:
	bool isValid(string s) {
		for (const auto& ch : s) {
			if (ch == '(' || ch == '{' || ch == '[') {
				st.push(ch);
			} else if (!st.empty() && ch == ')') {
				if (st.top() != '(') return false;
				st.pop();
			} else if (!st.empty() && ch == '}') {
				if (st.top() != '{') return false;
				st.pop();
			} else if (!st.empty() && ch == ']') {
				if (st.top() != '[') return false;
				st.pop();
			} else if (st.empty())
				return false;
		}

		return st.empty();
	}
};
// @lc code=end
