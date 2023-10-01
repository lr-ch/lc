/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class SolutionTrivial {
	void split(string& str, vector<string>& output) {
		string ln;
		stringstream ss(str);
		while (getline(ss, ln, ' ')) output.push_back(ln);
	}
public:
	string reverseWords(string& s) {
		vector<string> splitted;
		split(s, splitted);

		string ans;
		for (auto& ss : splitted)
			ans += string(ss.rbegin(), ss.rend()) + ' ';

		// remove trailing space
		ans.pop_back();
		return ans;
	}
};

class SolutionTwoPtr {
public:
	string reverseWords(string& s) {
		int is = -1;	// index of last space
		for (int i = 0; i <= s.length(); i++) {
			if (s[i] == ' ' || s.length() == i) {
				int left = is + 1, right = i - 1;
				while (left < right) {
					swap(s[left], s[right]);
					left++;
					right--;
				}
				is = i;
			}
		}
		return s;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 29/29 cases passed (26 ms)
	 *  - Your runtime beats 14.16 % of cpp submissions
	 *  - Your memory usage beats 12.78 % of cpp submissions (16.4 MB)
	 */
	SolutionTrivial trivial;

	/*
	 * Accepted
	 *  - 29/29 cases passed (10 ms)
	 *  - Your runtime beats 92.55 % of cpp submissions
	 *  - Your memory usage beats 59.58 % of cpp submissions (10 MB)
	 */
	SolutionTwoPtr twoPtr;
public:
	string reverseWords(string s) {
	//	return trivial.reverseWords(s);
		return twoPtr.reverseWords(s);
	}
};
// @lc code=end
