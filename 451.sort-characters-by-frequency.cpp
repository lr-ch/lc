/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
	string frequencySort(string s) {
		// step.1 calculate character frequence
		array<int, 256> charFreq;	// uppercase and lowercase English letters and digits
		fill(charFreq.begin(), charFreq.end(), 0);
		for (const auto& ch : s)
			charFreq[ch]++;

		// step.2 sort the frequence of each character
		vector<pair<char, int>> freqMap;
		for (int i = 0; i < 256; i++)
			if (charFreq[i] != 0) freqMap.push_back({ i, charFreq[i] });
		sort(freqMap.begin(), freqMap.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
		});

		// step.3 construct answer to return
		string ans;
		for (const auto& f : freqMap)
			ans += string(f.second, f.first);
		return ans;
	}
};
// @lc code=end
