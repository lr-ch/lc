/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
	vector<char> st;
public:
	string removeStars(string s) {
		for (const auto& ch : s) {
			switch (ch) {
				case '*' :
					if (!st.empty()) st.pop_back();
					break;

				default :
					st.push_back(ch);
			}
		}
		return string(st.begin(), st.end());
	}
};
// @lc code=end
