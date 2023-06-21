/*
 * @lc app=leetcode id=2448 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
 */

// @lc code=start
class Solution {
	long long calCost(int base) {
		long long res = 0;
		for (const auto& [val, cost] : valCost)
			res += (long long)abs(val - base) * cost;
		return res;
	}

	vector<pair<int, int>> valCost;
public:
	long long minCost(vector<int>& nums, vector<int>& cost) {
		for (int i = 0; i < nums.size(); i++)
			valCost.push_back({ nums[i], cost[i] });
		sort(valCost.begin(), valCost.end());

		long long left = valCost.front().first, right = valCost.back().first;
		long long ans = 0;
		while (left < right) {
			long long mid = left + (right - left) / 2;
			long long cost1 = calCost(mid), cost2 = calCost(mid + 1);
			ans = min(cost1, cost2);

			if (cost1 > cost2)
				left = mid + 1;
			else
				right = mid;
		}

		return ans;
	}
};
// @lc code=end
