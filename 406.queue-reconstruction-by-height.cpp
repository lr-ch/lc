/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// example:
		// original [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
		// sorted   [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
		sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
			return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
		});

		vector<vector<int>> res;
		// content of res:
		// i = 0, [[7,0]]
		// i = 1, [[7,0],[7,1]]
		// i = 2, [[7,0],[6,1],[7,1]]
		// i = 3, [[5,0],[7,0],[6,1],[7,1]]
		// i = 4, [[5,0],[7,0],[5,2],[6,1],[7,1]]
		// i = 5, [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
		// original sub index is just the index in res
		for (int i = 0; i < people.size(); i++) {
			vector<vector<int>>::iterator iter = res.begin();
			res.insert(iter + people[i][1], people[i]);
		}

		return res;
	}
};
// @lc code=end

