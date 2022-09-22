/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
	void split(string& str, vector<string>& output) {
		string ln;
		stringstream ss(str);
		while (getline(ss, ln, ' ')) output.push_back(ln);
	}
public:
	string reverseWords(string s) {
		vector<string> splitted;
		split(s, splitted);

		string ans;
		for (auto& ss : splitted)
			ans += string(ss.rbegin(), ss.rend()) + ' ';

		// remove trailing space
		return ans.substr(0, ans.length() - 1);
	}
};
// @lc code=end

