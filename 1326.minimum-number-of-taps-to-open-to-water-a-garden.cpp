/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution {
public:
	int minTaps(int n, vector<int>& ranges) {
		vector<pair<int, int>> cover;	// (left, right)
		for (int i = 0; i < ranges.size(); i++)
			cover.push_back({i - ranges[i], i + ranges[i]});

		// sort by left offset
		sort(cover.begin(), cover.end());

		int start = 0, end = 0, ret = 0, i = 0;
		while (end < n) {
			// search for most right offset which has the best coverage
			while (i < cover.size() && cover[i].first <= start) {
				end = max(end, cover[i].second);
				i++;
			}

			// cannot find any right offset to cover
			if (start == end) return -1;

			start = end;
			ret++;
		}

		return ret;
	}
};
// @lc code=end
