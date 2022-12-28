/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
class Solution {
public:
	int minStoneSum(vector<int>& piles, int k) {
		priority_queue<int> pq(piles.begin(), piles.end());

		while (k--) {
			int largest = pq.top();
			pq.pop();
			largest -= (largest / 2);
			pq.push(largest);
		}

		int ans = 0;
		while (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
		return ans;
	}
};
// @lc code=end

