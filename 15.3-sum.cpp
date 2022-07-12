/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
	/*
	 * Time Limit Exceeded
	 *  308/311 cases passed (N/A)
	 */
/*
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> s;
		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
			for (int j = i + 1; j < nums.size() - 1; j++)
				for (int k = j + 1; k < nums.size(); k++)
					if (nums[i] + nums[j] + nums[k] == 0)
						s.insert(vector<int>{nums[i], nums[j], nums[k]});

		for (auto i : s)
			ans.push_back(i);

		return ans;
	}
*/
	/*
	 * Time Limit Exceeded
	 *  308/311 cases passed (N/A)
	 */
/*
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> s;
		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			for (int j = i + 1; j < nums.size() - 1; j++) {
				auto it = find(nums.begin() + j + 1, nums.end(), 0 - nums[i] - nums[j]);
				if (it != nums.end())
					s.insert(vector<int>{nums[i], nums[j], *it});
			}
		}

		for (auto i : s)
			ans.push_back(i);

		return ans;
	}
*/
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> s;
		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			int left = i + 1, right = nums.size() - 1, target = 0 - nums[i];
			while (left < right) {
				if (nums[left] + nums[right] > target)
					right--;
				else if (nums[left] + nums[right] < target)
					left++;
				else {
					// nums[left] + nums[right] == target
					s.insert(vector<int>{nums[i], nums[left], nums[right]});
					left++;
					right--;
				}
			}
		}

		for (auto i : s)
			ans.push_back(i);

		return ans;
	}
};
// @lc code=end

