/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class SolutionIter {
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

class SolutionBs {
public:
	int minOperations(vector<int>& nums) {
		set<int> nums_set(nums.begin(), nums.end());
		vector<int> nums_uni;
		for (int n : nums_set)
			nums_uni.push_back(n);

		int ans = nums.size();		// at most nums.size() moves
		for (int i = 0; i < nums_uni.size(); i++) {
			int boundary = nums_uni[i] + nums.size() - 1;
			int j = upper_bound(nums_uni.begin(), nums_uni.end(), boundary) - nums_uni.begin();
			ans = min(ans, (int)nums.size() - (j - i));
		}

		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 62/62 cases passed (354 ms)
	 *  - Your runtime beats 25.94 % of cpp submissions
	 *  - Your memory usage beats 5.23 % of cpp submissions (110 MB)
	 */
	SolutionIter iter;

	/*
	 * Accepted
	 *  - 62/62 cases passed (385 ms)
	 *  - Your runtime beats 17.78 % of cpp submissions
	 *  - Your memory usage beats 10.67 % of cpp submissions (109.9 MB)
	 */
	SolutionBs binS;
public:
	int minOperations(vector<int>& nums) {
	//	return iter.minOperations(nums);
		return binS.minOperations(nums);
	}
};
// @lc code=end
