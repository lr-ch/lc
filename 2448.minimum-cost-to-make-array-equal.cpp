/*
 * @lc app=leetcode id=2448 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
 */

// @lc code=start
class SolutionConvex {
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

class SolutionMid {
public:
	long long minCost(vector<int>& nums, vector<int>& cost) {
		vector<pair<int, int>> valCost;
		for (int i = 0; i < nums.size(); i++)
			valCost.push_back({ nums[i], cost[i] });
		sort(valCost.begin(), valCost.end());

		long long totalCost = accumulate(cost.begin(), cost.end(), 0LL), accu = 0;
		int mid = 0;
		for (int i = 0; i < valCost.size(); i++) {
			accu += valCost[i].second;
			if (accu >= 1.0 * totalCost / 2) {
				mid = i;
				break;
			}
		}

		long long ans =  0;
		for (int i = 0; i < valCost.size(); i++)
			ans += (long long)abs(valCost[i].first - valCost[mid].first) * valCost[i].second;
		return ans;
	}
};

class Solution {

	/*
	 * Accepted
	 *  - 48/48 cases passed (109 ms)
	 *  - Your runtime beats 59.49 % of cpp submissions
	 *  - Your memory usage beats 42.34 % of cpp submissions (41.6 MB)
	 */
	SolutionConvex convex;

	/*
	 * Accepted
	 *  - 48/48 cases passed (89 ms)
	 *  - Your runtime beats 93.8 % of cpp submissions
	 *  - Your memory usage beats 42.34 % of cpp submissions (41.6 MB)
	 */
	SolutionMid mid;
public:
	long long minCost(vector<int>& nums, vector<int>& cost) {
	//	return convex.minCost(nums, cost);
		return mid.minCost(nums, cost);
	}
};
// @lc code=end
