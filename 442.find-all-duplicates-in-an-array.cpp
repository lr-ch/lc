/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class SolutionItera {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ans;

		// is this O(n)???
		sort(nums.begin(), nums.end());

		// because "each integer appears once or twice"
		for (int i = 0; i < nums.size() - 1; i++)
			if (nums[i] == nums[i + 1]) ans.push_back(nums[i]);
		return ans;
	}
};

class SolutionMap {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		unordered_map<int, int> mp;
		for (auto& n : nums) mp[n]++;

		vector<int> ans;
		for (auto& m : mp)
			if (m.second > 1) ans.push_back(m.first);
		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 28/28 cases passed (150 ms)
	 *  - Your runtime beats 31.08 % of cpp submissions
	 *  - Your memory usage beats 79.46 % of cpp submissions (33.6 MB)
	 */
	SolutionItera solItera;

	/*
	 * Accepted
	 *  - 28/28 cases passed (200 ms)
	 *  - Your runtime beats 14.3 % of cpp submissions
	 *  - Your memory usage beats 10.87 % of cpp submissions (44.7 MB)
	 */
	SolutionMap solMap;

public:
	vector<int> findDuplicates(vector<int>& nums) {
	//	return solItera.findDuplicates(nums);
		return solMap.findDuplicates(nums);
	}
};
// @lc code=end
