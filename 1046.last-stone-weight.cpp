/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq(stones.begin(), stones.end());

		while (pq.size() >= 2) {
			int h1 = pq.top(); pq.pop();
			int h2 = pq.top(); pq.pop();
			if (abs(h1 - h2))
				pq.push(abs(h1 - h2));
		}
		return pq.empty() ? 0 : pq.top();
	}
};
// @lc code=end
