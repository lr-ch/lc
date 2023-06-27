/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<tuple<int, int, int>> pq;	// (sum, nums1[i], nums2[j])
		for (int i = 0; i < nums1.size(); i++) {
			for (int j = 0; j < nums2.size(); j++) {
				if (pq.size() < k) {
					pq.push({ nums1[i] + nums2[j], nums1[i], nums2[j] });
				} else if (nums1[i] + nums2[j] < get<0>(pq.top())) {
					pq.pop();
					pq.push({ nums1[i] + nums2[j], nums1[i], nums2[j] });
				} else
					break;
			}
		}

		vector<vector<int>> ans;
		while (!pq.empty()) {
			auto& [_, a, b] = pq.top();
			ans.push_back({a, b});
			pq.pop();
		}
		return ans;
	}
};
// @lc code=end
