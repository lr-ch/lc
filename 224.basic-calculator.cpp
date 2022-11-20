/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
	bool isDigit(char& c) {
		return (c - '0') >= 0 && (c - '0') <= 9;
	}

	vector<int> st{1};
public:
	int calculate(string s) {
		int res = 0, sum = 0, sign = 1;
		for (auto& ch: s) {
			if (isDigit(ch))
				sum = sum * 10 + (ch - '0');
			else {
				res += sum * sign * st.back();
				sum = 0;

				if (ch == '-')
					sign = -1;
				else if (ch == '+')
					sign = 1;
				else if (ch == '(')
					st.push_back(st.back() * sign), sign = 1;
				else if (ch == ')')
					st.pop_back();
			}
		}
		return res += (sum * sign);
	}
};
// @lc code=end

