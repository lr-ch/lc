/*
 * @lc app=leetcode id=2389 lang=cpp
 *
 * [2389] Longest Subsequence With Limited Sum
 */

// @lc code=start
class SolutionBF {
public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		int N = nums.size(), Q = queries.size();
		sort(nums.begin(), nums.end());

		vector<int> ans;
		for (int i = 0; i < Q; i++) {
			int sum = 0;
			int j;
			for (j = 0; j < N && sum <= queries[i]; j++)
				sum += nums[j];

			// is sum still smaller than queries?
			if (sum <= queries[i])
				ans.push_back(j);
			else
				ans.push_back(j - 1);
		}

		return ans;
	}
};

class SolutionPresfixSum {
public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(), nums.end());

		// create prefix sum in place
		for (int i = 1; i < nums.size(); i++)
			nums[i] += nums[i - 1];

		vector<int> ans;
		for (int q : queries) {
			auto iter = upper_bound(nums.begin(), nums.end(), q);
			ans.push_back(distance(nums.begin(), iter));
		}

		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  ??/?? cases passed (45 ms)
	 *  Your runtime beats 55.90 % of cpp submissions
	 *  Your memory usage beats 36.20 % of cpp submissions (13.8 MB)
	 */
	SolutionBF bruteForce;

	/*
	 * Accepted
	 *  ??/?? cases passed (15 ms)
	 *  Your runtime beats 96.60 % of cpp submissions
	 *  Your memory usage beats 36.20 % of cpp submissions (13.8 MB)
	 */
	SolutionPresfixSum prefixSum;

public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
	//	return bruteForce.answerQueries(nums, queries);
		return prefixSum.answerQueries(nums, queries);
	}
};
// @lc code=end
