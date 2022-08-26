/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution {
	// split number to single digits, store into an array after sorting
	void disect(int i, vector<int>& v) {
		for (int j = i; j > 0; j /= 10)
			v.push_back(j % 10);
		sort(v.begin(), v.end());
	}
	set<vector<int>> pool;
public:
	bool reorderedPowerOf2(int n) {
		vector<int> tmp;
		// generate a pool for numbers 'power of 2', from 1 to 10^9
		for (int i = 1; i < 1e9; i <<= 1) {
			tmp.clear();
			disect(i, tmp);
			pool.insert(tmp);
		}

		// the array of digits is sorted, it is unique to the pool
		tmp.clear();
		disect(n, tmp);
		return pool.find(tmp) != pool.end();
	}
};
// @lc code=end

