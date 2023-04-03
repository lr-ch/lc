/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		sort(people.begin(), people.end());

		int left = 0, right = people.size() - 1, ans = 0;
		while (left <= right) {
			ans++;

			if (people[left] + people[right] <= limit) {
				left++;
				right--;
			} else
				right--;
		}

		return ans;
	}
};
// @lc code=end
