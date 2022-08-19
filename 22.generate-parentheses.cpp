/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Backtrack {
	// left  : counter of "("
	// right : counter of ")"
	void bt(int left, int right, string& candidate) {
		if (left > right) return;
		if (left < 0 || right < 0) return;
		if (left == 0 && right == 0) {
			ans.push_back(candidate);
			return;
		}

		candidate.push_back('(');
		bt(left - 1, right, candidate);
		candidate.pop_back();

		candidate.push_back(')');
		bt(left, right - 1, candidate);
		candidate.pop_back();
	}

	vector<string> ans;
public:
	vector<string> generateParenthesis(int n) {
		string tmp;
		bt(n, n, tmp);
		return ans;
	}
};

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;

		if (n) {
			for (int i = 0; i < n; i++)
				for (auto& left : generateParenthesis(i))
					for (auto& right : generateParenthesis(n - 1 - i))
						ans.push_back('(' + left + ')' + right);
		} else
			ans.push_back("");

		return ans;
	}
};
// @lc code=end
