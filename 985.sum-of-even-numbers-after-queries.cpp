/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *   56/58 cases passed (N/A)
 */
class SolutionTLE {
public:
	vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
		vector<int> ans;
		for (auto& q : queries) {
			nums[q[1]] += q[0];

			int sum = 0;
			for (auto& n : nums)
				if (n % 2 == 0) sum += n;
			ans.push_back(sum);
		}
		return ans;
	}
};

class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
		// calculate the even value's sum and maintain it
		int esum = 0;
		for (auto& n : nums)
			if (n % 2 == 0) esum += n;

		vector<int> ans;
		for (auto& q : queries) {
			// if the nums[index] is even, substract the sum of its value
			// value <- q[0], index <- q[1]
			if (nums[q[1]] % 2 == 0) esum -= nums[q[1]];

			// add queries' value to nums[index]
			nums[q[1]] += q[0];

			// if the new nums[index] is even, add its value back to sum, or just ignore it
			if (nums[q[1]] % 2 == 0) esum += nums[q[1]];
			ans.push_back(esum);
		}
		return ans;
	}
};
// @lc code=end
