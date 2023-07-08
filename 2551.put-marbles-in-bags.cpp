/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551] Put Marbles in Bags
 */

// @lc code=start
class Solution {
public:
	long long putMarbles(vector<int>& weights, int k) {
		vector<long long> scores;
		// e.g. [1, 3, 5, 1]
		// scores : 4(1+ 3), 8(3 + 5), 6(5 + 1)
		for (int i = 0; i < weights.size() - 1; i++)
			scores.push_back(weights[i] + weights[i + 1]);
		sort(scores.begin(), scores.end(), greater<long long>());

		long long ans = 0;
		for (int i = 0; i < k - 1; i++)
			ans += scores[i];                       // select first k - 1 scores for maximun

		for (int j = 0; j < k - 1; j++)
			ans -= scores[scores.size() - 1 - j];   // select last k - 1 scores for minimun

		return ans;
	}
};
// @lc code=end
