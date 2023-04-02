/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution {
	int bsearch(const long long& spell, const vector<int>& array, const long long& target) {
		int left = 0, right = array.size() - 1, ans = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (target > spell * array[mid]) {
				left = mid + 1;
			} else {
				ans = mid;
				right = mid - 1;
			}
		}
		return ans;
	}

public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		sort(potions.begin(), potions.end());

		vector<int> ans;
		for (const auto& s : spells) {
			int i = bsearch(s, potions, success);
			ans.push_back(i == -1 ? 0 : potions.size() - i);
		}

		return ans;
	}
};
// @lc code=end
