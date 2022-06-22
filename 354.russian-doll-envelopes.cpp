/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
	// Works, but TLE
/*
	int lengthOfLIS(vector<vector<int>>& v) {
		vector<int> memo(v.size(), 1);
		int maxLength = 0;

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < i; j++)
				if (v[i][1] > v[j][1])
					memo[i] = max(memo[i], memo[j] + 1);

			maxLength = max(maxLength, memo[i]);
		}
		return maxLength;
	}
*/
	int lengthOfLIS(vector<pair<int, int>>& v) {
		vector<int> dp;

		for (auto i : v) {
			// find the position where the element is bigger or equal to i.second
			auto iter = lower_bound(dp.begin(), dp.end(), i.second);

			if (iter == dp.end())
				// not found, create a new pile
				dp.push_back(i.second);
			else if (*iter > i.second)
				// put the card on the top of pile
				*iter = i.second;
		}
		// the content of dp is the LIS, the size of dp is the length of the LIS
		return dp.size();
	}

public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		vector<pair<int, int>> es;

		for (auto e : envelopes) es.push_back(make_pair(e[0], e[1]));
		sort(es.begin(), es.end(), [](const auto& v1, const auto& v2) {
			return v1.first == v2.first ? v1.second > v2.second : v1.first < v2.first;
		});

		return lengthOfLIS(es);
	}
};
// @lc code=end
