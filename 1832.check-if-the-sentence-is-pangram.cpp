/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class SolutionMap {
	vector<char> charMap = {'a', 'b', 'c', 'd', 'e', 'f',
							'g', 'h', 'i', 'j', 'k', 'l',
							'm', 'n', 'o', 'p', 'q', 'r',
							's', 't', 'u', 'v', 'w', 'x',
							'y', 'z'};
public:
	bool checkIfPangram(string sentence) {
		for (auto& c : sentence)
			charMap[c - 'a'] = 0;
		return accumulate(charMap.begin(), charMap.end(), 0) == 0;
	}
};

class SolutionFreq {
public:
	bool checkIfPangram(string sentence) {
		array<int, 26> freq;
		fill(freq.begin(), freq.end(), 0);
		for (char& c : sentence) freq[c - 'a']++;
		for (int& i : freq) if (!i) return false;
		return true;
	}
};

class Solution {
	SolutionMap ma;
	SolutionFreq fr;
public:
	bool checkIfPangram(string sentence) {
		return ma.checkIfPangram(sentence);
	//	return fr.checkIfPangram(sentence);
	}
};
// @lc code=end
