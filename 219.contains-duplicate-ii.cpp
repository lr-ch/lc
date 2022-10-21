/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class SolutionHashMap {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, vector<int>> table;	// <number, indices of the number>
		for (int i = 0; i < nums.size(); i++)
			table[nums[i]].push_back(i);

		for (auto& [_, indices] : table)
			if (indices.size() >= 2)
				for (int j = 0; j < indices.size() - 1; j++)
					if (indices[j + 1] - indices[j] <= k)
						return true;
		return false;
	}
};

class SolutionSlidingWindow {
	set<int> window;
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int left = 0, right = 0;

		for (; right < nums.size(); right++) {
			if (right - left > k) {
				window.erase(nums[left]);
				left++;
			}

			if (window.find(nums[right]) != window.end())
				return true;

			window.insert(nums[right]);
		}
		return false;
	}
};

class Solution {
	SolutionHashMap hash_map;
	SolutionSlidingWindow sliding_window;
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
	//	return hash_map.containsNearbyDuplicate(nums, k);
		return sliding_window.containsNearbyDuplicate(nums, k);
	}
};
// @lc code=end
