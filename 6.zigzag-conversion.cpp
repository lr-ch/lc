/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> strRow(numRows, "");
		bool down = true;
		int currentRow = 0;
		for (int i = 0; i < s.length(); i++) {
			strRow[currentRow] += s[i];
			down ? currentRow++ : currentRow--;

			if (currentRow == numRows - 1)
				down = false;
			else if (currentRow == 0)
				down = true;
		}

		string ans = "";
		for (auto& str : strRow) ans += str;
		return ans;
	}
};
// @lc code=end
