/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
	/*
	 * Accepted
	 *   36/36 cases passed (14 ms)
	 *   Your runtime beats 57.46 % of cpp submissions
	 *   Your memory usage beats 7.79 % of cpp submissions (7.5 MB)
	 */
/*
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
*/
public:
	/*
	 * Accepted
	 *   36/36 cases passed (18 ms)
	 *   Your runtime beats 40.58 % of cpp submissions
	 *   Your memory usage beats 45.59 % of cpp submissions (7.4 MB)
	 */
	bool isAnagram(string s, string t) {
        if (s.size() < t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < t.size(); i++)
            if (s[i] != t[i])
                return false;
            else
                s[i] = 0;

        return accumulate(s.begin(), s.end(), 0) == 0;
	}
};
// @lc code=end

