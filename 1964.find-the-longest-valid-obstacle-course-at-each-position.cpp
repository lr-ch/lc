/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */

// @lc code=start
class Solution {
public:
	vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
		vector<int> memo(obstacles.size(), 1e7 + 1), ans;

		/*
		 * obstacles : [1 2 3 2]
		 * memo :                    ans :
		 *  i = 0  [1 inf inf inf]      [1] -> upper_bound(memo.begin(), memo.end(), 1)
		 *  i = 1  [1  2  inf inf]      [1 2] -> upper_bound(memo.begin(), memo.end(), 2)
		 *  i = 2  [1  2   3  inf]      [1 2 3] -> upper_bound(memo.begin(), memo.end(), 3)
		 *  i = 3  [1  2   2  inf]      [1 2 3 3] -> upper_bound(memo.begin(), memo.end(), 2)
		 */

		for (int i = 0; i < obstacles.size(); i++) {
			auto iter = upper_bound(memo.begin(), memo.end(), obstacles[i]);
			ans.push_back(iter - memo.begin() + 1);
			*iter = obstacles[i];
		}

		return ans;
	}
};
// @lc code=end
