/*
 * @lc app=leetcode id=3005 lang=cpp
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
class Solution {
public:
	int maxFrequencyElements(vector<int>& nums) {
		array<int, 101> freq;
		int max_freq = INT_MIN;
		freq.fill(0);

		for_each(nums.begin(), nums.end(), [&](const auto& n) {
			freq[n]++;
			max_freq = max(max_freq, freq[n]);
		});

		return count(freq.begin(), freq.end(), max_freq) * max_freq;
	}
};
// @lc code=end
