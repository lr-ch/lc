/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int time) {
		sort(clips.begin(), clips.end());

		int start = 0, end = 0, ret = 0, i = 0;
		while (end < time) {
			while (i < clips.size() && clips[i][0] <= start)
				end = max(end, clips[i++][1]);

			if (start == end) return -1;
			start = end;
			ret++;
		}
		return ret;
	}
};
// @lc code=end
