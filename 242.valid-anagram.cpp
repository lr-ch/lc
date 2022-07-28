/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> ms;

        if (t.size() > s.size()) return false;

        for (auto& c : s)
			ms[c]++;

		for (auto& c : t) {
			auto it = ms.find(c);
			if (it != ms.end())
				it->second -= 1;
		}

		for (auto& p : ms)
			if (p.second != 0)
				return false;

		return true;
	}
};
// @lc code=end

