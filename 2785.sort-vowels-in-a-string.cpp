/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
class Solution {
public:
	string sortVowels(string s) {
		vector<char> vowels;
		vector<int> pos;
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowels.push_back(s[i]);
					pos.push_back(i);
					continue;
			}
		}

		sort(vowels.begin(), vowels.end());

		for (int i = 0; i < vowels.size(); i++)
			s[pos[i]] = vowels[i];

		return s;
	}
};
// @lc code=end
