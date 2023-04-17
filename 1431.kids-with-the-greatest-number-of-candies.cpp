/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int maxi = *max_element(candies.begin(), candies.end());
		vector<bool> res;
		for (const auto& c : candies)
			res.push_back(c + extraCandies >= maxi ? true : false);
		return res;
	}
};
// @lc code=end
