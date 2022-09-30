/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
	/*
	 * two reason to select multiset<> instead of priority_queue<> or set<>
	 *  1. automatically sort the element
	 *  2. erase a group of keys with the same value
	 */
	multiset<int, greater<>> heights;

	int maxHeight() {
		if (!heights.empty()) return *heights.begin();
		return 0;
	}

	/*
	 * <offset(x), height(h)>
	 *  record the height(h) at offset(x)
	 *   for convinience,
	 *   if the scan line touch the left boundary of the building -> h is positive
	 *   if the scan line touch the right boundary of the building -> h is negative
	 *   use abs(h) to retrieve the correct height
	 */
	vector<pair<int, int>> boundary;

public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		for (auto& b : buildings) {
			boundary.push_back({ b[0],  b[2] });	// scan to left border of building
			boundary.push_back({ b[1], -b[2] });	// scan to right border of building
		}

		sort(boundary.begin(), boundary.end(), [](const auto& a, const auto& b) {
			if (a.first != b.first) return a.first < b.first;
			return a.second > b.second;
		});

		vector<vector<int>> ans;
		for (auto& b : boundary) {
			if (b.second > 0) {
				// scan line touch the left border of building
				if (b.second > maxHeight())
					ans.push_back({ b.first, b.second });
				heights.insert(b.second);
			} else {
				// scan line touch the right border of building
				int h = abs(b.second);
				heights.erase(heights.equal_range(h).first);
				if (h > maxHeight())
					ans.push_back({ b.first, maxHeight() });
			}
		}

		return ans;
	}
};
// @lc code=end

