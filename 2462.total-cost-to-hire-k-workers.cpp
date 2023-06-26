/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
	long long totalCost(vector<int>& costs, int k, int candidates) {
		// if first and last candidates overlapse
		if (candidates * 2 >= costs.size()) {
			sort(costs.begin(), costs.end());
			return accumulate(costs.begin(), costs.begin() + k, 0);
		}

		priority_queue<int, vector<int>, greater<int>>
			front(costs.begin(), costs.begin() + candidates),
			back(costs.rbegin(), costs.rbegin() + candidates);

		int left = candidates, right = costs.size() - candidates - 1;
		long long cost = 0, count = 0;
		while (count++ < k) {
			if (front.top() <= back.top()) {
				cost += front.top(); front.pop();
				front.push(left <= right ? costs[left++] : INT_MAX);
			} else {
				cost += back.top(); back.pop();
				back.push(left <= right ? costs[right--] : INT_MAX);
			}
		}
		return cost;
	}
};
// @lc code=end
