/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
	struct PairComp {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
			if (a.first != b.first) return a.first > b.first;
			return a.second > b.second;
		}
	};

public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, PairComp> pq;
		for (int i : arr) pq.push({ abs(i - x), i });

		vector<int> ans;
		for (int j = 0; j < k; j++) {
			ans.push_back(pq.top().second);
			pq.pop();
		}
		sort(ans.begin(), ans.end());

		return ans;
	}
};
// @lc code=end

