/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
	int toInt(vector<int>& v) {
		int res = 0;
		for (const auto& i : v)
			res = res * 10 + i;
		return res;
	}

	void backtrack(vector<int>& path, int n, int k) {
		if (n == 0) {
			ans.push_back(toInt(path));
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (path.back() - i == k || i - path.back() == k) {
				path.push_back(i);
				backtrack(path, n - 1, k);
				path.pop_back();
			}
		}
	}

	vector<int> ans;
public:
	vector<int> numsSameConsecDiff(int n, int k) {
		vector<int> digits(n);

		for (int i = 1; i <= 9; i++) {
			digits.push_back(i);
			backtrack(digits, n - 1, k);
			digits.pop_back();
		}
		return ans;
	}
};
// @lc code=end

