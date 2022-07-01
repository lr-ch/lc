/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
			return a[1] > b[1];
		});

		int totalUnits = 0;
		for (auto box : boxTypes) {
			if (truckSize == 0)
				break;
			int usedBox = min(truckSize, box[0]);
			totalUnits += usedBox * box[1];
			truckSize -= usedBox;
		}
		return totalUnits;
	}
};
// @lc code=end

