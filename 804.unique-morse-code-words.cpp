/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
	array<string, 26> dict = {
	//   a      b       c       d       e
		".-",   "-...", "-.-.", "-..",  ".",
	//   f       g       h       i       j
		"..-.", "--.",  "....", "..",   ".---",
	//   k       l       m       n       o
		"-.-",  ".-..", "--",   "-.",   "---",
	//   p       q       r       s       t
		".--.", "--.-", ".-.",  "...",  "-",
	//   u       v       w       x       y
		"..-",  "...-", ".--",  "-..-", "-.--",
	//   z
		"--.."
	};

public:
	int uniqueMorseRepresentations(vector<string>& words) {
		set<string> wordSet;

		for (auto& word : words) {
			string tmp = "";

			for (char& ch : word)
				tmp += dict[ch - 'a'];

			wordSet.insert(tmp);
		}
		return wordSet.size();
	}
};
// @lc code=end
