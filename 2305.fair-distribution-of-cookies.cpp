/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=start
class SolutionSimple {
	int bt(vector<int>& c, vector<int>& s, int num) {
		// all cookies already fall into slots
		if (num == c.size())
			return *max_element(s.begin(), s.end());

		int res = INT_MAX;
		for (int i = 0; i < s.size(); i++) {
			s[i] += c[num];		// slot[i] takes this cookie
			res = min(res, bt(c, s, num + 1));
			s[i] -= c[num];		// restore the cookie for next slot
		}

		return res;
	}

public:
	int distributeCookies(vector<int>& cookies, int k) {
		vector<int> slots(k, 0);	// where cookies fall into
		return bt(cookies, slots, 0);
	}
};

class SolutionOptimize {
	int bt(vector<int>& c, vector<int>& s, int num) {
		if (num == c.size())
			return *max_element(s.begin(), s.end());

		int res = INT_MAX;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] > avg) continue;

			s[i] += c[num];		// slot[i] takes this cookie
			res = min(res, bt(c, s, num + 1));
			s[i] -= c[num];		// restore the cookie for next slot
		}

		return res;
	}

	int avg;
public:
	int distributeCookies(vector<int>& cookies, int k) {
		int total = accumulate(cookies.begin(), cookies.end(), 0);
		avg = total / k;

		sort(cookies.begin(), cookies.end(), greater<int>());
		vector<int> slots(k, 0);	// where cookies fall into
		return bt(cookies, slots, 0);
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 38/38 cases passed (1789 ms)
	 *  - Your runtime beats 35.72 % of cpp submissions
	 *  - Your memory usage beats 23.17 % of cpp submissions (7 MB)
	 */
	SolutionSimple simple;

	/*
	 * Accepted
	 *  - 38/38 cases passed (455 ms)
	 *  - Your runtime beats 70.64 % of cpp submissions
	 *  - Your memory usage beats 62.54 % of cpp submissions (6.9 MB)
	 */
	SolutionOptimize opt;
public:
	int distributeCookies(vector<int>& cookies, int k) {
	//	return simple.distributeCookies(cookies, k);
		return opt.distributeCookies(cookies, k);
	}
};
// @lc code=end
