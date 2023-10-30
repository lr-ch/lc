/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
	vector<int> sortByBits(vector<int>& arr) {
		sort(arr.begin(), arr.end(), [](auto &a, auto& b) {
			bitset<32> _a(a), _b(b);
			if (_a.count() == _b.count()) return a < b;
			return _a.count() < _b.count();
		});
		return arr;
	}
};
// @lc code=end
