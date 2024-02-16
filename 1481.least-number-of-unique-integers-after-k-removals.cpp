/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		list<int> freq;
		unordered_map<int, list<int>::iterator> table;

		for (const auto& n : arr)
			if (table.count(n) == 0) {
				freq.push_front(1);
				table[n] = freq.begin();
			} else
				(*table[n])++;

		// we don't care the key value of each freq
		freq.sort();

		while (freq.size() > 0 && k > 0)
			if (k >= freq.front()) {
				k -= freq.front();
				freq.pop_front();
			} else
				break;

		return freq.size();
	}
};
// @lc code=end
