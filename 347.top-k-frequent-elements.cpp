/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> freq;
		for (const auto& n : nums) freq[n]++;

		priority_queue<pair<int, int>> q;
		for (const auto& f : freq) q.push({ f.second, f.first });

		vector<int> ans;
		while (k--) {
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
	}
};
// @lc code=end
