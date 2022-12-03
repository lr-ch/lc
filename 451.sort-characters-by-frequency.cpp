/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class SolutionArray {
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

class Solution {
public:
	string frequencySort(string s) {
		// 1. construct character dictionary of frequence
		vector<pair<char, int>> charFreq(256, pair<char, int>({ 0, 0 }));
		for (char ch : s)
			charFreq[ch] = pair<char, int>(ch, charFreq[ch].second + 1);

		// 2. sort character by its frequence
		sort(charFreq.begin(), charFreq.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
		});

		// 3. construct answer string
		string ans;
		for (auto& [c, f] : charFreq)
			if (f > 0)
				ans += string(f, c);
		return ans;
	}
};
// @lc code=end
