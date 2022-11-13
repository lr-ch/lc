/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
	string reverseWords(string s) {
		stack<string> st;

		int i = 0, j = 0;
		while ((i = s.find_first_not_of(' ', j)) != string::npos) {
			j = s.find_first_of(' ', i);
			st.push(s.substr(i, j - i));
		}

		string ans;
		while (!st.empty()) {
			ans += st.top() + " ";
			st.pop();
		}
		ans.pop_back();		// remove trailing space

		return ans;
	}
};
// @lc code=end
