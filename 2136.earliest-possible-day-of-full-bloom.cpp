/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */

// @lc code=start
class Solution {
public:
	int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
		vector<pair<int, int>> ptime;
		for (int i = 0; i < plantTime.size(); i++)
			ptime.push_back({ growTime[i], plantTime[i] });

		sort(ptime.begin(), ptime.end(), [](auto& a, auto& b) {
			return a.first > b.first;
		});

		int res = 0, currPlantTime = 0;
		for (auto& [grow, plant] : ptime) {
			currPlantTime += plant;
			res = max(res, currPlantTime + grow);
		}
		return res;
	}
};
// @lc code=end
