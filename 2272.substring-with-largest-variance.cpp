/*
 * @lc app=leetcode id=2272 lang=cpp
 *
 * [2272] Substring With Largest Variance
 */

// @lc code=start
class SolutionPOC {
public:
	/*
	 *  ref. [53] Maximum Subarray
	 */
	int largestVariance(string s) {
		unordered_set<char> chars(s.begin(), s.end());
		vector<int> dp0(s.length() + 1),    // dp0[i] the maximun sum of subarray end at i, and subarray contains NO -1
					dp1(s.length() + 1);    // dp1[i] the maximun sum of subarray end at i, and subarray contains -1
		int ret = 0;

		for (const char& a : chars) {       // a as 1
			for (const char& b : chars) {   // b as -1
				if (a == b) continue;

				dp0[0] = 0, dp1[0] = INT_MIN / 2;

				for (int i = 0; i < s.length(); i++) {
					if (s[i] == a) {
						dp0[i + 1] = dp0[i] + 1;
						dp1[i + 1] = dp1[i] + 1;
					} else if (s[i] == b) {
						dp0[i + 1] = 0;
						dp1[i + 1] = max(dp0[i] - 1, dp1[i] - 1);
					} else {
						dp0[i + 1] = dp0[i];
						dp1[i + 1] = dp1[i];
					}
					ret = max(ret, dp1[i + 1]);
				}
			}
		}

		return ret;
	}
};

class SolutionOpt {
public:
	int largestVariance(string s) {
		unordered_set<char> chars(s.begin(), s.end());
		int ret = 0;

		for (const char& a : chars) {       // a as 1
			for (const char& b : chars) {   // b as -1
				if (a == b) continue;

				int dp0 = 0, dp1 = INT_MIN / 2;

				for (int i = 0; i < s.length(); i++) {
					if (s[i] == a) {
						dp0 = dp0 + 1;
						dp1 = dp1 + 1;
					} else if (s[i] == b) {
						dp1 = max(dp0 - 1, dp1 - 1);
						dp0 = 0;
					}
					ret = max(ret, dp1);
				}
			}
		}

		return ret;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 138/138 cases passed (859 ms)
	 *  - Your runtime beats 5.03 % of cpp submissions
	 *  - Your memory usage beats 7.55 % of cpp submissions (9.1 MB)
	 */
	SolutionPOC poc;

	/*
	 * Accepted
	 *  - 138/138 cases passed (202 ms)
	 *  - Your runtime beats 70.44 % of cpp submissions
	 *  - Your memory usage beats 11.95 % of cpp submissions (8.1 MB)
	 */
	SolutionOpt opt;
public:
	int largestVariance(string s) {
	//	return poc.largestVariance(s);
		return opt.largestVariance(s);
	}
};
// @lc code=end
