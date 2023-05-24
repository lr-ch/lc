/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

// @lc code=start
class Solution {
public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> nums;	// <nums1, nums2>
		for (int i = 0; i < nums1.size(); i++)
			nums.push_back({ nums1[i], nums2[i] });

		sort(nums.begin(), nums.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
		});

		priority_queue<int, vector<int>, greater<>> candidates;
		long long sum = 0, ans = 0;
		// now visit all candidates
		for (const auto& [num1, num2] : nums) {
			// if number of candidates reaches k, kick out least num1
			if (candidates.size() == k) {
				sum -= candidates.top();
				candidates.pop();
			}
			candidates.push(num1);
			sum += num1;

			if (candidates.size() == k)
				ans = max(ans, sum * num2);
		}
		return ans;
	}
};
// @lc code=end
