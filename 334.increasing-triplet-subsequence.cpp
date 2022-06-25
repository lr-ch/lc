/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
	/*
	 * algorithm - Patience Sorting
	 * ref. 300.Longest Increasing Subsequence
	 *      354.Russian Doll Envelopes
	 */
	int lengthOfLIS(vector<int>& v) {
		vector<int> dp;

		for (auto i : v) {
			// find the position where the element is no bigger than num
			auto iter = lower_bound(dp.begin(), dp.end(), i);

			if (iter == dp.end())
				// not found, create a new pile
				dp.push_back(i);
			else if (i < *iter)
				// put the card on the top of pile
				*iter = i;
		}
		return dp.size();
	}

public:
    bool increasingTriplet(vector<int>& nums) {
		return lengthOfLIS(nums) >= 3;
    }
};
// @lc code=end

