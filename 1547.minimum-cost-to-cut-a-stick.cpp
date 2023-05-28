/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
/*
 *  Time Limit Exceeded
 *   - 12/100 cases passed (N/A)
 *   - Testcase
 *     - 30
 *     - [13,25,16,20,26,5,27,8,23,14,6,15,21,24,29,1,19,9,3]
 *   - Expected Answer
 *     - 127
 */
class SolutionTLE {
	int dfs(vector<int>& c, int left, int right) {
		// no cost if stick length is 1
		if (right - left == 1) return 0;

		// try out all combination cut order
		int cost = 0, res = INT_MAX;
		for (int cut = left + 1; cut < right; cut++) {
			cost = dfs(c, left, cut) + dfs(c, cut, right) + c[right] - c[left];
			res = min(res, cost);
		}
		return res;
	}

public:
	int minCost(int n, vector<int>& cuts) {
		// Add begin and end points
		cuts.insert(cuts.begin(), 0);
		cuts.push_back(n);
		sort(cuts.begin(), cuts.end());

		return dfs(cuts, 0, cuts.size() - 1);
	}
};

class Solution {
	int dfs(vector<int>& c, int left, int right) {
		// no cost if stick length is 1
		if (right - left == 1) return 0;

		if (memo[left][right] != -1) return memo[left][right];

		// try out all combination cut order
		int cost = 0, res = INT_MAX;
		for (int cut = left + 1; cut < right; cut++) {
			cost = dfs(c, left, cut) + dfs(c, cut, right) + c[right] - c[left];
			res = min(res, cost);
		}
		return memo[left][right] = res;
	}

	vector<vector<int>> memo;
public:
	int minCost(int n, vector<int>& cuts) {
		// Add begin and end points
		cuts.insert(cuts.begin(), 0);
		cuts.push_back(n);
		sort(cuts.begin(), cuts.end());

		memo.resize(cuts.size(), vector<int>(cuts.size(), -1));

		return dfs(cuts, 0, cuts.size() - 1);
	}
};
// @lc code=end
