/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class Solution {
public:
	int minOperations(vector<int>& nums) {
		set<int> nums_set(nums.begin(), nums.end());
		vector<int> nums_uni;
		for (int n : nums_set)
			nums_uni.push_back(n);

		int ans = nums.size();		// at most nums.size() moves
		for (int i = 0, j = 0; i < nums_uni.size(); i++) {
			while (j < nums_uni.size() && nums_uni[i] + nums.size() > nums_uni[j])
				j++;    			// nums_uni[j] -> not in range (nums_uni[i], nums_uni[i] + nums.size())
			ans = min(ans, (int)nums.size() - (j - i));
		}

		return ans;
	}
};
// @lc code=end
