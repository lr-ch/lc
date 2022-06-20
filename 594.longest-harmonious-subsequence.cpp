/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
public:
	int findLHS(vector<int>& nums) {
		map<int, int> counter;
		int result = 0;

		for (int n : nums)
			if (counter.find(n) == counter.end())
				counter.insert(pair<int, int>(n, 1));
			else
				counter[n]++;

		for (auto it1 = counter.begin(), it2 = it1++;
				it2 != counter.end();
				it1++, it2++)
		{
			if (it1->first - it2->first == 1)
				result = max(result, it1->second + it2->second);
		}
		return result;
	}
};
// @lc code=end

